#ifndef EDC_ABI
#define EDC_ABI

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#define EDRA_ABI_INTERFACE_EXPORT(Name, Type, ...) \
	EXTERNC { \
		__declspec(dllexport) Type* Edra_##Name##_Create(__VA_ARGS__); \
		__declspec(dllexport) void Edra_##Name##_Destroy(Type* obj); \
	} \

#define EDRA_ABI_INTERFACE_IMPORT(Name, Type, ...) \
	EXTERNC { \
		__declspec(dllimport) Type* Edra_##Name##_Create(__VA_ARGS__); \
		__declspec(dllimport) void Edra_##Name##_Destroy(Type* obj); \
	} \

#endif // EDC_ABI
