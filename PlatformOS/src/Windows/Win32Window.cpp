#include "EdraSDK/PlatformOS/Windows/Win32Window.hpp"
#include "EdraSDK/Core/Utils/ABI.hpp"
#include "EdraSDK/Core/EdraDef.hpp"

#include <iostream>
#include <windows.h>

EDRA_EXPORT_CALL_FUN(EdraHandle) Edra_Window_Create(const EdraSDK::Platform::WindowDesc& pWinDesc)
{
	return (EdraHandle)(new EdraSDK::PlatformOS::Win32Window(pWinDesc));
}

EDRA_EXPORT_CALL_FUN(void) Edra_Window_Destroy(EdraHandle pObj)
{
	if (pObj)
	{
		EdraSDK::Platform::IWindow* lWin = (EdraSDK::Platform::IWindow*)pObj;
		delete lWin;
	}
}

EdraSDK::PlatformOS::Win32Window::Win32Window(const EdraSDK::Platform::WindowDesc& pWinDesc)
	: EdraSDK::Platform::IWindow()
	, mShouldClose(false)
	, mHandle(nullptr)
{
	std::cout << "PlatformOS window on Windows created" << std::endl;
}

EdraSDK::PlatformOS::Win32Window::~Win32Window()
{
	std::cout << "PlatformOS window on Windows destroyed" << std::endl;
}

bool EdraSDK::PlatformOS::Win32Window::initialize()
{
	return false;
}

void EdraSDK::PlatformOS::Win32Window::poolEvent()
{
}

bool EdraSDK::PlatformOS::Win32Window::destroy()
{
	return false;
}

void* EdraSDK::PlatformOS::Win32Window::getNativeHandle() const
{
	return nullptr;
}

bool EdraSDK::PlatformOS::Win32Window::shouldClose() const
{
	return false;
}

void EdraSDK::PlatformOS::Win32Window::setWindowEventCallback(EdraSDK::Platform::IWindow::WinEventCallback pCallback)
{
}
