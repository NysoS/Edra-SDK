#ifndef EDP_WINDOW_CORE_HPP
#define EDP_WINDOW_CORE_HPP

#include "EdraSDK/Platform/EdraPlatform.hpp"

#include "EdraSDK/Core/Aliases.hpp"
#include "EdraSDK/Core/Utils/ABI.hpp"

#include <string>
#include <functional>

namespace EdraSDK::Platform 
{
	struct WindowDesc {
		EdraStringWC mTitle = L"Window";
		const u32 mWidth = 800;
		const u32 mHeight = 800;
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

	EDRA_ABI_INTERFACE(Window, IWindow, const WindowDesc& pWinDesc);
}

#endif // !EDP_WINDOW_CORE_HPP
