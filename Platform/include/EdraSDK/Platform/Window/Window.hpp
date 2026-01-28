#include "EdraSDK/Core/edrapch.hpp"
#include "EdraSDK/Platform/EdraPlatform.hpp"
#include "EdraSDK/Platform/Window/WindowCore.hpp"
#include "EdraSDK/Core/EdraDef.hpp"
#include "EdraSDK/Core/Types.hpp"
#include "EdraSDK/Platform/Window/WindowABIContext.hpp"

#include <iostream>

namespace EdraSDK::Platform
{
	class EDP_API Window
	{
	public:
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		bool init();
		bool shouldClose();
		void poolEvent();

		static std::unique_ptr<Window> create(const WindowDesc& pWinDesc);

	private:
		Window(const WindowDesc& pWinDesc);
		void OnDestroyNotify(void* pEvent);

		IWindow* get() noexcept { return (IWindow*)mHandle; };

		EdraSDK::EdraHandle mHandle;
		bool mShouldClose;
		std::shared_ptr<EdraSDK::Platform::WindowABIContext> mContext;
	};
}