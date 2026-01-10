#ifndef EDRA_PLATFORM_HPP
#define EDRA_PLATFORM_HPP

    #ifdef _WIN32
        #ifdef EDRA_PLATFORM_BUILD_DLL
            #define EDP_API __declspec(dllexport)
        #else
            #define EDP_API __declspec(dllimport)
        #endif
    #else
        #error EdraSDK only supports on Windows!
    #endif
#endif // !EDRA_PLATFORM_HPP
