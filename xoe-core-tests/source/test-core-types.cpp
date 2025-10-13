// copyright xo 2025 all rights reserved
//------------------------------------------------------------------------------

#include <xoe-core/core-types.hpp>

#include "gtest/gtest.h"

namespace
{
    //--------------------------------------------------------------------------
    TEST(Counter, Increment)
    {
        int i = 0;
        EXPECT_EQ(0, i++);
        EXPECT_EQ(1, i++);
        EXPECT_EQ(2, i++);
        EXPECT_EQ(3, i--);
    }

}  // namespace