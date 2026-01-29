#ifndef WINDOW_ABI_CONTEXT_HPP
#define WINDOW_ABI_CONTEXT_HPP

#include "EdraSDK/Core/edrapch.hpp"
#include "EdraSDK/Core/EdraDef.hpp"
#include "EdraSDK/Core/Module/Module.hpp"
#include "EdraSDK/Platform/Window/WindowDefABI.hpp"

#include <iostream>

namespace EdraSDK::Platform {
	#ifndef __WIN32
	static constexpr EdraSDK::StringC sPlatformDllName = "PlatformOS.dll";
	#endif
	
	struct WindowDesc;

	class WindowABIContext {
	public:
		WindowABIContext() = default;
		~WindowABIContext() {
			std::cout << "Close WindowABIContext" << std::endl;
			if (EdraSDK::Core::Module::close(mModule))
			{
				mModule = nullptr;
				mCreateFunc = nullptr;
				mDestroyFunc = nullptr;
				std::cout << "Close Module and reset WindowABIContext values" << std::endl;
			}
		}

		EdraSDK::EdraHandle create(const WindowDesc& pWinDesc) {
			if (!mModule.load())
			{
				std::lock_guard<std::mutex> lGuard(mModuleMutex);

				if (!mModule.load())
				{
					EdraSDK::EdraModule mModuleLoaded = EdraSDK::Core::Module::load(sPlatformDllName);
					if (!mModuleLoaded)
						throw std::runtime_error("Failed to load PlatformOS.dll");

					mCreateFunc = EdraSDK::Core::Module::getSymbol<EdraSDK::ABI::FN_Edra_Window_Create>(mModuleLoaded, "Edra_Window_Create");
					mDestroyFunc = EdraSDK::Core::Module::getSymbol<EdraSDK::ABI::FN_Edra_Window_Destroy>(mModuleLoaded, "Edra_Window_Destroy");
					
					mModule.store(mModuleLoaded);
				}
			}

			if (!mCreateFunc)
				throw std::runtime_error("ABI Create function pointer is null");

			EdraSDK::EdraHandle lWinHandle = mCreateFunc(pWinDesc);
			if (!lWinHandle)
				throw std::runtime_error("Failed to create Window instance via ABI");

			return lWinHandle;
		}

		void destroy(EdraSDK::EdraHandle pObj)
		{
			if (!pObj) return;

			if (!mDestroyFunc)
				throw std::runtime_error("ABI Destroy function pointer is null");

			mDestroyFunc(pObj);
		}

	private:
		std::atomic<EdraSDK::EdraModule> mModule = nullptr;
		std::mutex mModuleMutex;

		EdraSDK::ABI::FN_Edra_Window_Create mCreateFunc = nullptr;
		EdraSDK::ABI::FN_Edra_Window_Destroy mDestroyFunc = nullptr;
	};
}

#endif // !WINDOW_ABI_CONTEXT_HPP
