#include "EdraSDK/Platform/Window/WindowCore.hpp"

#include "EdraSDK/Platform/EdraPlatform.hpp"

#include <Windows.h>
#include <iostream>

namespace EdraSDK::Platform
{
	class EDP_API Window
	{
	public:
		static FN_Edra_Window_Create s_CreateFunc;
		static FN_Edra_Window_Destroy s_DestroyFun;
		static HMODULE s_PlatformModule;

		Window(const WindowDesc& pWinDesc);
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		IWindow* operator->() noexcept { return mInstance; };

	private:
		IWindow* mInstance;
	};
}