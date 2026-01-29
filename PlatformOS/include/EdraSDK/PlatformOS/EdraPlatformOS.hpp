#ifndef EDRA_PLATFORM_OS_HPP
#define EDRA_PLATFORM_OS_HPP

    #ifdef _WIN32
        #ifdef EDRA_PLATFORM_OS_BUILD_DLL
            #define EDP_OS_API __declspec(dllexport)
        #else
            #define EDP_OS_API __declspec(dllimport)
        #endif
    #else
        #error EdraSDK only supports on Windows!
    #endif
#endif // !EDRA_PLATFORM_OS_HPP