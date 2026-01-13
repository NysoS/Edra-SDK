#ifndef EDC_ALIASES_HPP
#define EDC_ALIASES_HPP

#include <cstdint>
#include <string>

namespace EdraSDK {
	namespace Core{}
	namespace Platform{}
	namespace PlatformOS{}

	namespace EDC = Core;
	namespace EDP = Platform;
	namespace EDP_OS = PlatformOS;

	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	using i8 = int8_t;
	using i16 = int16_t;
	using i32 = int32_t;
	using i64 = int64_t;

	using f32 = float;
	using f64 = double;

	using EdraString = std::string;
	using EdraStringW = std::wstring;

	using EdraStringC = const char*;
	using EdraStringWC = const wchar_t*;
}

namespace Edra = EdraSDK;

#endif // !EDC_ALIASES_HPP
