#ifndef EDP_OS_WIN32_WINDOW_HPP
#define EDP_OS_WIN32_WINDOW_HPP

#include "EdraSDK/Platform/Window/WindowCore.hpp"
#include "EdraSDK/PlatformOS/EdraPlatformOS.hpp"
#include "EdraSDK/Core/Aliases.hpp"

#include <Windows.h>

namespace EdraSDK::PlatformOS
{
	class EDP_OS_API Win32Window : public EDP::IWindow
	{
	public:
		Win32Window(const Edra::EDP::WindowDesc& pWinDesc);
		virtual ~Win32Window();

		virtual bool initialize();
		virtual void poolEvent();
		virtual bool destroy();

		virtual void* getNativeHandle() const;
		virtual bool shouldClose() const;

		virtual void setWindowEventCallback(EDP::IWindow::WinEventCallback pCallback);
	private:
		Edra::EDP::WindowDesc mWinDesc;
		bool mShouldClose = false;
		HWND mHandle = nullptr;

		Edra::EDP::IWindow::WinEventCallback mOnWindowEventCallback;
	};
};

#endif // EDP_OS_WIN32_WINDOW_HPP
