#ifndef EDRA_PLATFORM_HPP
#define EDRA_PLATFORM_HPP

    #ifdef EDRA_PLATFORM_BUILD_DLL
        #define EDP_API __declspec(dllexport)
    #else
        #define EDP_API __declspec(dllimport)
    #endif

#endif // !EDRA_PLATFORM_HPP
