#include "EdraSDK/Platform/Window/Window.hpp"

#include <iostream>

static std::mutex gContextMutex;
static std::shared_ptr<EdraSDK::Platform::WindowABIContext> gWinABIContext = nullptr;

EdraSDK::Platform::Window::Window(const WindowDesc& pWinDesc)
	: mHandle(nullptr)
{
	if (!gWinABIContext)
	{
		std::lock_guard<std::mutex> lLock(gContextMutex);
		if (!gWinABIContext)
		{
			gWinABIContext = std::make_shared<EdraSDK::Platform::WindowABIContext>();
			std::cout << "[SDK] New ABI Context created" << std::endl;
		}
	}

	mContext = gWinABIContext;
	std::cout << "[SDK] Reusing existing ABI Context" << std::endl;
	mHandle = mContext->create(pWinDesc);
}

EdraSDK::Platform::Window::~Window()
{
	if (mContext && mHandle)
	{
		mContext->destroy(mHandle);
	}
}
