#include "EdraSDK/Platform/EdraPlatform.hpp"
#include "EdraSDK/Platform/Window/WindowCore.hpp"
#include "EdraSDK/Core/EdraDef.hpp"
#include "EdraSDK/Core/Types.hpp"
#include "EdraSDK/Platform/Window/WindowDefABI.hpp"

#include <iostream>

//refacto to make forward declaration of windesc into
//refacto module loading system

namespace EdraSDK::Platform
{
	class EDP_API Window
	{
	public:
		static EdraSDK::ABI::FN_Edra_Window_Create s_CreateFunc;
		static EdraSDK::ABI::FN_Edra_Window_Destroy s_DestroyFun;
		static EdraModule s_PlatformModule;

		Window(const WindowDesc& pWinDesc);
		~Window();

		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;

		IWindow* operator->() noexcept { return (IWindow*)mHandle; };

	private:
		EdraSDK::EdraHandle mHandle;
	};
}