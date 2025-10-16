//
// Created by xo on 10/13/25.
//
#include <xoe-core/Assert.hpp>

void xoe::LogAssertionFailure(xoe::AssertReason const& reason)
{
#if defined(XOE_HOST_OS_LINUX)
#if defined(XOE_CONFIG_DEBUG)

#else

#endif
#endif
}
