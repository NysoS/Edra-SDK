#include "EdraSDK/PlatformOS/Windows/Win32Window.hpp"
#include "EdraSDK/Core/Utils/ABI.hpp"

#include <iostream>

//EDRA_ABI_IMPL(Window, EDP::IWindow, const EDP::WindowDesc& pWinDesc)
EDRA_ABI_IMPL(Window, EDP::IWindow, const EDP::WindowDesc& pWinDesc);

EDRA_EXPORT_CALL_FUN(EDP::IWindow*) Edra_Window_Create(const EDP::WindowDesc& pWinDesc) 
{
	return new EdraSDK::PlatformOS::Win32Window(pWinDesc);
}

EDRA_EXPORT_CALL_FUN(void) Edra_Window_Destroy(EDP::IWindow* pObj)
{
	delete pObj;
}

EdraSDK::PlatformOS::Win32Window::Win32Window(const EDP::WindowDesc& pWinDesc)
	: EDP::IWindow()
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

void EdraSDK::PlatformOS::Win32Window::setWindowEventCallback(EDP::IWindow::WinEventCallback pCallback)
{
}
