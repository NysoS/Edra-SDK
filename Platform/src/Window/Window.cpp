#include "EdraSDK/Platform/Window/Window.hpp"
#include "EdraSDK/Core/Module/Module.hpp"

#include <iostream>

// TODO : Refacto on module system & generic ABI system 
// TODO : Cross platform module system (win32) // add linux later

namespace EdraSDK::Platform{
	EdraSDK::ABI::FN_Edra_Window_Create Window::s_CreateFunc = nullptr;
	EdraSDK::ABI::FN_Edra_Window_Destroy Window::s_DestroyFun = nullptr;
	EdraSDK::EdraModule Window::s_PlatformModule = nullptr;

	static struct PlatformCleaner {
		~PlatformCleaner() {
			std::cout << "PlatformCleaner" << std::endl;
			if (Window::s_PlatformModule) {
				EdraSDK::Core::Module::close(Window::s_PlatformModule);
			}
		}
	};
	static PlatformCleaner g_AutoCleanup;
}

EdraSDK::Platform::Window::Window(const WindowDesc& pWinDesc)
	: mHandle(nullptr)
{
	if (!s_PlatformModule) {
		s_PlatformModule = EdraSDK::Core::Module::load("PlatformOS.dll");

		if (!s_PlatformModule)
			throw std::runtime_error("Failed to load PlatformOS.dll");

		s_CreateFunc = EdraSDK::Core::Module::getSymbol<EdraSDK::ABI::FN_Edra_Window_Create>(s_PlatformModule, "Edra_Window_Create");
		s_DestroyFun = EdraSDK::Core::Module::getSymbol<EdraSDK::ABI::FN_Edra_Window_Destroy>(s_PlatformModule, "Edra_Window_Destroy");
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
