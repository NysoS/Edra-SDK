#ifndef EDP_OS_WIN32_WINDOW_HPP
#define EDP_OS_WIN32_WINDOW_HPP

#include "EdraSDK/Platform/Window/WindowCore.hpp"

#include <Windows.h>

namespace EDP {
	using namespace EdraSDK::Platform;
}

namespace EdraSDK::PlatformOS
{
	class Win32Window : public EDP::IWindow
	{
	public:
		Win32Window(const EDP::WindowDesc& pWinDesc);
	};
}

#endif // EDP_OS_WIN32_WINDOW_HPP
