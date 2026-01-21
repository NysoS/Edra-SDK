#include "EdraSDK/Platform/Window/Window.hpp"

#include <iostream>

static std::shared_ptr<EdraSDK::Platform::WindowABIContext> getGlobalWindowABIContext()
{
	static auto sInstance = std::make_shared<EdraSDK::Platform::WindowABIContext>();
	return sInstance;
}

EdraSDK::Platform::Window::Window(const WindowDesc& pWinDesc)
	: mHandle(nullptr)
{
	mContext = ::getGlobalWindowABIContext();
	if (!mContext)
		throw std::runtime_error("[SDK] No Window ABI Context finded");
	
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
