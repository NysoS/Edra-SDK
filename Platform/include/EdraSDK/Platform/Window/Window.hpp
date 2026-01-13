#include "EdraSDK/Platform/Window/WindowCore.hpp"

#include "EdraSDK/Platform/EdraPlatform.hpp"

namespace EdraSDK::Platform
{
	class EDP_API Window
	{
	public:
		Window(const WindowDesc& pWinDesc);
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		IWindow* operator->() noexcept { return mInstance; };

	private:
		IWindow* mInstance;
		void* mModule;
	};
}