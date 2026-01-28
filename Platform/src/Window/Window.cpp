#include "EdraSDK/Platform/Window/Window.hpp"

#include <iostream>

static std::shared_ptr<EdraSDK::Platform::WindowABIContext> getGlobalWindowABIContext()
{
	static auto sInstance = std::make_shared<EdraSDK::Platform::WindowABIContext>();
	return sInstance;
}

EdraSDK::Platform::Window::Window(const WindowDesc& pWinDesc)
	: mHandle(nullptr)
	, mShouldClose(false)
	, mContext(nullptr)
{
	mContext = ::getGlobalWindowABIContext();
	if (!mContext)
		throw std::runtime_error("[SDK] No Window ABI Context finded");

	std::cout << "[SDK] Reusing existing ABI Context" << std::endl;
	mHandle = mContext->create(pWinDesc);

	if (mHandle)
	{
		get()->setWindowEventCallback(std::bind(&Window::OnDestroyNotify, this, std::placeholders::_1));
	}
}

void EdraSDK::Platform::Window::OnDestroyNotify(void* pEvent)
{
	int event = (int)(uintptr_t)pEvent;
	if (event == 18)
	{
		if (mContext && mHandle)
		{
			mContext->destroy(mHandle);
			mHandle = nullptr;
			mShouldClose = true;
		}
	}
}

EdraSDK::Platform::Window::~Window()
{
	if (mContext && mHandle)
	{
		mContext->destroy(mHandle);
	}
}

bool EdraSDK::Platform::Window::init()
{
	return get()->initialize();
}

bool EdraSDK::Platform::Window::shouldClose()
{
	if (mShouldClose) return true;

	if (get())
	{
		return get()->shouldClose();
	}

	return false;
}

void EdraSDK::Platform::Window::poolEvent()
{
	if (!get()) return;

	get()->poolEvent();
}

std::unique_ptr<EdraSDK::Platform::Window> EdraSDK::Platform::Window::create(const WindowDesc& pWinDesc)
{
	return std::unique_ptr<Window>(new Window(pWinDesc));
}
