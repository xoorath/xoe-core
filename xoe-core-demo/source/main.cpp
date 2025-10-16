
#include <iostream>
#include <xoe-core/BasicTypes.hpp>
#include <xoe-core/Init.hpp>

#include <spdlog/spdlog.h>

int main()
{
    xoe::InitSpdlog const iniSpdlog;
    if (!iniSpdlog.IsInitialized())
    {
        std::cerr << "Failed to initialize highway.\n"
                  << iniSpdlog.GetErrorMessage().Get() << std::endl;
        return -1;
    }
    (void)iniSpdlog;

    spdlog::info("wazzzzup");

    xoe::InitHighway const initHighway;
    if (!initHighway.IsInitialized())
    {
        std::cerr << "Failed to initialize highway.\n"
                  << initHighway.GetErrorMessage().Get() << std::endl;
        return -1;
    }
    (void)initHighway;

    std::cout << "xoe build environment:\n";

#if defined(XOE_HOST_ARCH_X86_64)
    std::cout << "\tHost Arch:     x86_64\n";
#elif defined(XOE_HOST_ARCH_AARCH)
    std::cout << "\tHost Arch:     aarch\n";
#else
#error "Host Arch unknown"
#endif

#if defined(XOE_HOST_OS_LINUX)
    std::cout << "\tHost OS:       Linux\n";
#elif defined(XOE_HOST_OS_MACOS)
    std::cout << "\tHost OS:       macOS\n";
#elif defined(XOE_HOST_OS_WINDOWS)
    std::cout << "\tHost OS:       Windows\n";
#else
#error "Host OS unknown"
#endif

#if defined(XOE_HOST_COMPILER_CLANG)
    std::cout << "\tHost Compiler: Clang\n";
#elif defined(XOE_HOST_COMPILER_GCC)
    std::cout << "\tHost Compiler: GCC\n";
#elif defined(XOE_HOST_COMPILER_MSVC)
    std::cout << "\tHost Compiler: MSVC\n";
#else
#error "Host compiler unknown"
#endif

    std::cout << "xoe target environment:\n";

#if defined(XOE_TARGET_ARCH_X86_64)
    std::cout << "\tTarget Arch:   x86_64\n";
#elif defined(XOE_TARGET_ARCH_AARCH)
    std::cout << "\tTarget Arch:   aarch\n";
#else
#error "Target Arch unknown"
#endif

#if defined(XOE_TARGET_OS_LINUX)
    std::cout << "\tTarget OS:     Linux\n";
#elif defined(XOE_TARGET_OS_MACOS)
    std::cout << "\tTarget OS:     macOS\n";
#elif defined(XOE_TARGET_OS_WINDOWS)
    std::cout << "\tTarget OS:     Windows\n";
#else
#error "Target OS unknown"
#endif

    std::cout << "xoe build config:\n";

#if defined(XOE_CONFIG_DEBUG)
    std::cout << "\tBuild config:  debug\n";
#elif defined(XOE_CONFIG_DEBUGOPTIMIZED)
    std::cout << "\tBuild config:  debugoptimized\n";
#elif defined(XOE_CONFIG_RELEASE)
    std::cout << "\tBuild config:  release\n";
#else
#error "Build config unknown"
#endif

    std::cout.flush();

    xoe::InitHighway();

    return 0;
}