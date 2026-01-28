#ifndef WINDOW_DEF_ABI_HPP
#define WINDOW_DEF_ABI_HPP

#include "EdraSDK/Core/ABI/ABI.hpp"

namespace EdraSDK::Platform {
	struct WindowDesc;
}

EDRA_ABI_INTERFACE(Window, const EdraSDK::Platform::WindowDesc&);

#endif // !WINDOW_DEF_ABI_HPP
