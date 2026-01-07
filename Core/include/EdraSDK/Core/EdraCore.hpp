#ifndef EDRA_CORE_HPP
#define EDRA_CORE_HPP

    #ifdef _WIN32
        #ifdef EDRA_CORE_BUILD_DLL
            #define EDC_API __declspec(dllexport)
        #else
            #define EDC_API __declspec(dllimport)
        #endif
    #else
        #error EdraSDK only supports on Windows!
    #endif
#endif // !EDRA_CORE_HPP