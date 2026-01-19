#include "EdraSDK/Platform/Window/Window.hpp"

#include <iostream>
#include <Windows.h>

// TODO : Refacto on module system & generic ABI system 
// TODO : Cross platform module system (win32) // add linux later

namespace EdraSDK::Platform{
	FN_Edra_Window_Create Window::s_CreateFunc = nullptr;
	FN_Edra_Window_Destroy Window::s_DestroyFun = nullptr;
	EdraModule Window::s_PlatformModule = nullptr;

	static struct PlatformCleaner {
		~PlatformCleaner() {
			std::cout << "PlatformCleaner" << std::endl;
			if (Window::s_PlatformModule) {
				FreeLibrary((HMODULE)Window::s_PlatformModule);
				Window::s_PlatformModule = nullptr;
			}
		}
	};
	static PlatformCleaner g_AutoCleanup;
}

EdraSDK::Platform::Window::Window(const WindowDesc& pWinDesc)
	: mHandle(nullptr)
{
	
	if (!s_PlatformModule) {
		s_PlatformModule = (EdraModule)LoadLibraryA("PlatformOS.dll");

		if (!s_PlatformModule)
			throw std::runtime_error("Failed to load PlatformOS.dll");

		s_CreateFunc = (FN_Edra_Window_Create)GetProcAddress((HMODULE)s_PlatformModule, "Edra_Window_Create");
		s_DestroyFun = (FN_Edra_Window_Destroy)GetProcAddress((HMODULE)s_PlatformModule, "Edra_Window_Destroy");
	}

	if (s_CreateFunc) {
		mHandle = s_CreateFunc(pWinDesc);
		if (!mHandle)
			throw std::runtime_error("Failed to create Window instance via ABI");
	}
	else {
		throw std::runtime_error("ABI Create function pointer is null");
	}

	std::cout << "Win ABI attached" << std::endl;
}

EdraSDK::Platform::Window::~Window()
{
	if (s_DestroyFun && mHandle)
	{
		s_DestroyFun(mHandle);
		std::cout << "Win ABI dettached" << std::endl;
	}
}
