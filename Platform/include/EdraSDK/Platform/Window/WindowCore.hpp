#ifndef EDP_WINDOW_CORE_HPP
#define EDP_WINDOW_CORE_HPP

#include "EdraSDK/Core/edrapch.hpp"
#include "EdraSDK/Platform/EdraPlatform.hpp"
#include "EdraSDK/Core/Types.hpp"

namespace EdraSDK::Platform
{
	struct EDP_API WindowDesc {
		StringC mTitle = "Window";
		const u32 mWidth = 800;
		const u32 mHeight = 800;
		const bool mResizable = false;
	};

	struct EDP_API IWindow
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
};

#endif // !EDP_WINDOW_CORE_HPP
