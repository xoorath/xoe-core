#include <xoe-core/core-types.hpp>

#if !(defined(XOE_HOST_OS_LINUX) && defined(XOE_HOST_ARCH_X86_64))\
 && !(defined(XOE_HOST_OS_MACOS) && defined(XOE_HOST_ARCH_AARCH))\
 && !(defined(XOE_HOST_OS_WINDOWS) && defined(XOE_HOST_ARCH_X86_64))
#error No supported xoe host platform was detected.
#endif

void foo() {
	
}