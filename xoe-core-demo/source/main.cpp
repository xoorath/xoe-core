#include <xoe-core/core-types.hpp>
#include <iostream>

int main()
{
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

    std::cout << "xoe build config:\n";

#if defined(XOE_CONFIG_DEBUG)
    std::cout << "\tBuild config: debug\n";
#elif defined(XOE_CONFIG_DEBUGOPTIMIZED)
    std::cout << "\tBuild config: debugoptimized\n";
#elif defined(XOE_CONFIG_RELEASE)
    std::cout << "\tBuild config: release\n";
#else
#error "Build config unknown"
#endif

    std::cout.flush();

    return 0;
}