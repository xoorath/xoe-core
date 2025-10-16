#include <xoe-core/BasicTypes.hpp>

#include <hwy/highway.h>

#include <cstring>
#include <iostream>

namespace xoe
{
    void CopyBytes(byte_t* const dest,
                   byte_t const* const src,
                   uint32_t const len)
    {
        hwy::CopyBytes(src, dest, static_cast<size_t>(len));
    }
}  // namespace xoe