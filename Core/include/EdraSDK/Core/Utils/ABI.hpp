#ifndef EDC_ABI
#define EDC_ABI

#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif

#define EDRA_ABI_INTERFACE(Name, Type, ...) \
	EXTERNC { \
		Type* Edra_##Name##_Create(__VA_ARGS__); \
		void Edra_##Name##_Destroy(Type* obj); \
	} \

#endif // EDC_ABI
