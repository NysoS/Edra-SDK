#ifndef EDRA_CORE_HPP
#define EDRA_CORE_HPP

    #ifdef EDRA_CORE_BUILD_DLL
        #define EDC_API __declspec(dllexport)
    #else
        #define EDC_API __declspec(dllimport)
    #endif

#endif // !EDRA_CORE_HPP