#ifndef EDP_OS_WIN32_WINDOW_HPP
#define EDP_OS_WIN32_WINDOW_HPP

#include "EdraSDK/Platform/Window/WindowCore.hpp"
#include "EdraSDK/PlatformOS/EdraPlatformOS.hpp"
#include "EdraSDK/Core/EdraDef.hpp"

namespace EdraSDK::PlatformOS
{
	#ifndef HINST_THISCOMPONENT
		EXTERN_C IMAGE_DOS_HEADER __ImageBase;
	#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)
	#endif // !HINST_THISCOMPONENT

	class EDP_OS_API Win32Window : public EdraSDK::Platform::IWindow
	{
	public:
		Win32Window(const EdraSDK::Platform::WindowDesc& pWinDesc);
		virtual ~Win32Window();

		virtual bool initialize();
		virtual void poolEvent();
		virtual bool destroy();

		virtual void* getNativeHandle() const;
		virtual bool shouldClose() const;

		virtual void setWindowEventCallback(EdraSDK::Platform::IWindow::WinEventCallback pCallback);
	private:
		static LRESULT CALLBACK WindowProc(HWND pHwnd, UINT pMessage, WPARAM pWParam, LPARAM pLParam);

		EdraSDK::Platform::WindowDesc mWinDesc;
		bool mShouldClose;
		HWND mHandle;

		EdraSDK::Platform::IWindow::WinEventCallback mOnWindowEventCallback;
	};
};

#endif // EDP_OS_WIN32_WINDOW_HPP
