#include "EdraSDK/PlatformOS/Windows/Win32Window.hpp"

EdraSDK::PlatformOS::Win32Window::Win32Window(const Edra::EDP::WindowDesc& pWinDesc)
{
}

EdraSDK::PlatformOS::Win32Window::~Win32Window()
{
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
