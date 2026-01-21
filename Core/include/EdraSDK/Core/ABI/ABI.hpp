#ifndef EDC_ABI
#define EDC_ABI

#include "EdraSDK/Core/EdraDef.hpp"

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#if defined(_WIN32) || defined(__CYGWIN__)
	#define EDRA_EXPORT_CALL_FUN(ReturnType) EXTERNC __declspec(dllexport) ReturnType
	#define EDRA_IMPORT_CALL_FUN(ReturnType) EXTERNC __declspec(dllimport) ReturnType
#elif defined(__GNUC__) && __GNUC__ >= 4
	#define EDRA_EXPORT_CALL_FUN(ReturnType) EXTERNC __attribute__((visibility("default"))) ReturnType
	#define EDRA_IMPORT_CALL_FUN(ReturnType) EXTERNC ReturnType
#endif

#define EDRA_ABI_INTERFACE(Name, ...) \
	namespace EdraSDK::ABI { \
		typedef EdraSDK::EdraHandle(*FN_Edra_##Name##_Create)(__VA_ARGS__); \
		typedef void(*FN_Edra_##Name##_Destroy)(EdraSDK::EdraHandle); \
	};

#endif // EDC_ABI
