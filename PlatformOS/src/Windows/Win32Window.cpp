#include "EdraSDK/PlatformOS/Windows/Win32Window.hpp"
#include "EdraSDK/Core/ABI/ABI.hpp"
#include "EdraSDK/Core/EdraDef.hpp"

#include <iostream>

EDRA_EXPORT_CALL_FUN(EdraSDK::EdraHandle) Edra_Window_Create(const EdraSDK::Platform::WindowDesc& pWinDesc)
{
	return (EdraSDK::EdraHandle)(new EdraSDK::PlatformOS::Win32Window(pWinDesc));
}

EDRA_EXPORT_CALL_FUN(void) Edra_Window_Destroy(EdraSDK::EdraHandle pObj)
{
	if (pObj)
	{
		EdraSDK::Platform::IWindow* lWin = (EdraSDK::Platform::IWindow*)pObj;
		lWin->destroy();
		delete lWin;
	}
}

EdraSDK::PlatformOS::Win32Window::Win32Window(const EdraSDK::Platform::WindowDesc& pWinDesc)
	: EdraSDK::Platform::IWindow()
	, mShouldClose(false)
	, mHandle(nullptr)
	, mWinDesc(pWinDesc)
{
	std::cout << "PlatformOS window on Windows created" << std::endl;
}

EdraSDK::PlatformOS::Win32Window::~Win32Window()
{
	std::cout << "PlatformOS window on Windows destroyed" << std::endl;
}

bool EdraSDK::PlatformOS::Win32Window::initialize()
{
	const char* lWindowClassName = "Win32Window";

	WNDCLASSEXA lWC{};
	lWC.cbSize = sizeof(WNDCLASSEXA);
	lWC.style = CS_HREDRAW | CS_VREDRAW;
	lWC.lpfnWndProc = Win32Window::WindowProc;
	lWC.cbClsExtra = 0;
	lWC.cbWndExtra = sizeof(LONG_PTR);
	lWC.hInstance = HINST_THISCOMPONENT;
	lWC.hbrBackground = NULL;
	lWC.lpszMenuName = NULL;
	lWC.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	lWC.lpszClassName = (LPSTR)lWindowClassName;

	if (!GetClassInfoEx(HINST_THISCOMPONENT, lWindowClassName, &lWC))
	{
		if (!RegisterClassEx(&lWC))
		{
			DWORD lErr = GetLastError();
			std::wcerr << L"[PlatformOS] Register Windows class failed" << std::endl;
			return false;
		}
	}

	mHandle = CreateWindowExA(
		WS_EX_APPWINDOW,
		lWC.lpszClassName,
		mWinDesc.mTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		mWinDesc.mWidth,
		mWinDesc.mHeight,
		NULL,
		NULL,
		HINST_THISCOMPONENT,
		this
	);

	if (!mHandle) return false;

	ShowWindow(mHandle, SW_SHOWNORMAL);
	UpdateWindow(mHandle);

	return true;
}

void EdraSDK::PlatformOS::Win32Window::poolEvent()
{
	MSG lMsg;

	while (PeekMessage(&lMsg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&lMsg);
		DispatchMessage(&lMsg);

		if (mShouldClose) return;

		if (lMsg.message == WM_QUIT || lMsg.message == WM_CLOSE)
		{
			mShouldClose = true;
		}

		if (mOnWindowEventCallback)
		{
			mOnWindowEventCallback((void*)lMsg.message);
		}
	}
}

bool EdraSDK::PlatformOS::Win32Window::destroy()
{
	return true;
}

void* EdraSDK::PlatformOS::Win32Window::getNativeHandle() const
{
	return mHandle;	
}

bool EdraSDK::PlatformOS::Win32Window::shouldClose() const
{
	return mShouldClose;
}

void EdraSDK::PlatformOS::Win32Window::setWindowEventCallback(EdraSDK::Platform::IWindow::WinEventCallback pCallback)
{
	mOnWindowEventCallback = pCallback;
}

LRESULT EdraSDK::PlatformOS::Win32Window::WindowProc(HWND pHwnd, UINT pMessage, WPARAM pWParam, LPARAM pLParam)
{
	LRESULT lResult = 0;

	if (pMessage == WM_CREATE)
	{
		LPCREATESTRUCTA lStruct = (LPCREATESTRUCTA)(pLParam);
		Win32Window* lWin = reinterpret_cast<Win32Window*>(lStruct->lpCreateParams);

		::SetWindowLongPtr(pHwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(lWin));
		return 1;
	}

	Win32Window* lSelf = reinterpret_cast<Win32Window*>(::GetWindowLongPtr(pHwnd, GWLP_USERDATA));
	if (!lSelf) return DefWindowProc(pHwnd, pMessage, pWParam, pLParam);

	bool lWasHandled = false;

	switch (pMessage)
	{
	case WM_SIZE:
	{
		std::cout << "Resize" << std::endl;
		lWasHandled = true;
	}
	break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		lWasHandled = true;
		lResult = 1;
	}
		break;
	}

	if (!lWasHandled)
	{
		lResult = DefWindowProc(pHwnd, pMessage, pWParam, pLParam);
	}

	return lResult;
}
