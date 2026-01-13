#ifndef EDRA_WINDOW_CORE_HPP
#define EDRA_WINDOW_CORE_HPP

#include "EdraSDK/Platform/EdraPlatform.hpp"

#include <string>
#include <functional>

namespace EdraSDK::Platform 
{
	struct WindowDesc {
		std::wstring mTitle = L"Window";
		const uint32_t mWidth = 800;
		const uint32_t mHeight = 800;
		const bool mResizable = false;
	};

	struct IWindow
	{
		using WinEventCallback = std::function<void(void*)>;

		virtual ~IWindow() = default;

		virtual bool initialize() = 0;
		virtual void poolEvent() = 0;
		virtual bool destroy() = 0;

		virtual void* getNativeHandle() const = 0;
		virtual bool shouldClose() const = 0;

		virtual void setWindowEventCallback(WinEventCallback pCallback) = 0;
	};
}

#endif // !EDRA_WINDOW_CORE_HPP
