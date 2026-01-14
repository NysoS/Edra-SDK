#ifndef EDC_ABI
#define EDC_ABI

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#define EDRA_EXPORT_CALL_FUN(ReturnType) __declspec(dllexport) ReturnType __stdcall
#define EDRA_IMPORT_CALL_FUN(ReturnType) __declspec(dllimport) ReturnType __stdcall

#define EDRA_ABI_IMPL(Name, Type, ...) \
	EXTERNC { \
		EDRA_EXPORT_CALL_FUN(Type*) Edra_##Name##_Create(__VA_ARGS__); \
		EDRA_EXPORT_CALL_FUN(void) Edra_##Name##_Destroy(Type* obj); \
	} \

#define EDRA_ABI_INTERFACE(Name, Type, ...) \
	EXTERNC { \
		EDRA_IMPORT_CALL_FUN(Type*) Edra_##Name##_Create(__VA_ARGS__); \
		EDRA_IMPORT_CALL_FUN(void) Edra_##Name##_Destroy(Type* obj); \
	} \

#endif // EDC_ABI
