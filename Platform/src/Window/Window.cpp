#include "EdraSDK/Platform/Window/Window.hpp"

#include <iostream>

// TODO : Refacto on module system & generic ABI system 
// TODO : Cross platform module system (win32) // add linux later

namespace EdraSDK::Platform{
	FN_Edra_Window_Create Window::s_CreateFunc = nullptr;
	FN_Edra_Window_Destroy Window::s_DestroyFun = nullptr;
	HMODULE Window::s_PlatformModule = nullptr;

	static struct PlatformCleaner {
		~PlatformCleaner() {
			std::cout << "PlatformCleaner" << std::endl;
			if (Window::s_PlatformModule) {
				FreeLibrary(Window::s_PlatformModule);
				Window::s_PlatformModule = nullptr;
			}
		}
	};
	static PlatformCleaner g_AutoCleanup;
}

EdraSDK::Platform::Window::Window(const WindowDesc& pWinDesc)
	: mInstance(nullptr)
{
	
	if (!s_PlatformModule) {
		s_PlatformModule = LoadLibraryA("PlatformOS.dll");
		if (s_PlatformModule) {
			s_CreateFunc = (FN_Edra_Window_Create)GetProcAddress(s_PlatformModule, "Edra_Window_Create");
			s_DestroyFun = (FN_Edra_Window_Destroy)GetProcAddress(s_PlatformModule, "Edra_Window_Destroy");
		}
	}

	if (s_CreateFunc)
	{
		mInstance = s_CreateFunc(pWinDesc);
	}

	std::cout << "Win ABI attached" << std::endl;
}

EdraSDK::Platform::Window::~Window()
{
	if (s_DestroyFun && mInstance)
	{
		s_DestroyFun(mInstance);
		std::cout << "Win ABI dettached" << std::endl;
	}
}
