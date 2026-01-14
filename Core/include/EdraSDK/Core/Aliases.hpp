#ifndef EDC_ALIASES_HPP
#define EDC_ALIASES_HPP

#include <cstdint>
#include <string>

namespace EdraSDK {
	namespace Core{}
	namespace Platform{}
	namespace PlatformOS{}

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

	using String = std::string;
	using StringW = std::wstring;

	using StringC = const char*;
	using StringWC = const wchar_t*;
}

namespace EDC = EdraSDK::Core;
namespace EDP = EdraSDK::Platform;
namespace EDP_OS = EdraSDK::PlatformOS;

#endif // !EDC_ALIASES_HPP
