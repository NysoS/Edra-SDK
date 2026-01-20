#ifndef MODULE_HPP
#define MODULE_HPP

//#if defined(_WIN32) || defined(__CYGWIN__)
//
//#elif #elif defined(__GNUC__) && __GNUC__ >= 4
//
//#endif

#include "EdraSDK/Core/EdraCore.hpp"
#include "EdraSDK/Core/Types.hpp"
#include "EdraSDK/Core/EdraDef.hpp"

#if defined(_WIN32) || defined(__CYGWIN__)
#include <Windows.h>

#define PlatformModule HMODULE
#define LoadModule LoadLibraryA
#define ClearModule FreeLibrary
#define GetSymbol GetProcAddress

#endif // _WIN32

namespace EdraSDK::Core {
	class EDC_API Module
	{
	public:
		Module() = default;
		~Module() = default;

		Module(Module&) = delete;
		Module(const Module&) = delete;
		Module& operator=(const Module&) = delete;

		static inline EdraSDK::EdraModule load(EdraSDK::StringV pModule) noexcept
		{
			return (EdraSDK::EdraModule)LoadModule(pModule.data());;
		};

		static inline bool close(EdraSDK::EdraModule pHandle) noexcept
		{
			if (!ClearModule((PlatformModule)pHandle)) return false;
			pHandle = nullptr;
			return true;
		};

		template<typename ProcType = EdraSDK::EdraProc>
		static inline ProcType getSymbol(EdraSDK::EdraModule pModule, EdraSDK::StringV pSymbol) noexcept;
	};

	template<typename ProcType>
	inline ProcType Module::getSymbol(EdraSDK::EdraModule pModule, EdraSDK::StringV pSymbol) noexcept
	{
		if (!pModule) return nullptr;

		return reinterpret_cast<ProcType>(GetSymbol(reinterpret_cast<PlatformModule>(pModule), pSymbol.data()));
	}
}

#endif // MODULE_HPP
