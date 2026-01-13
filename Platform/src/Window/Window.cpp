#include "EdraSDK/Platform/Window/Window.hpp"

#include <iostream>

EdraSDK::Platform::Window::Window(const WindowDesc& pWinDesc)
	: mInstance(nullptr)
	, mModule(nullptr)
{
	if (!mInstance)
		throw;

	std::cout << "Win ABI attached" << std::endl;
}

EdraSDK::Platform::Window::~Window()
{
	if (mInstance)
	{
		std::cout << "Win ABI dettached" << std::endl;
	}
}
