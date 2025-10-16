// copyright xo 2025 all rights reserved
//------------------------------------------------------------------------------

// Includes
//------------------------------------------------------------------------------
// xoe
#include <xoe-core/String.hpp>

// third party
#include <gtest/gtest.h>

// standard library
#include <string>

//------------------------------------------------------------------------------
namespace
{
    //--------------------------------------------------------------------------
    TEST(String, ConstructAndAssign)
    {
        // Simple constructed and assigned strings
        {
            xoe::String constructed("constructed");
            GTEST_ASSERT_FALSE(constructed.IsEmpty());
            xoe::String assigned;
            GTEST_ASSERT_TRUE(assigned.IsEmpty());
            assigned = "assigned";
            GTEST_ASSERT_FALSE(assigned.IsEmpty());
            GTEST_ASSERT_EQ(constructed, assigned);
            GTEST_ASSERT_EQ(strcmp("constructed", constructed.Get()), 0);
            GTEST_ASSERT_EQ(strcmp("assigned", assigned.Get()), 0);
        }

        // Empty constructed and assigned strings
        {
            xoe::String emptyConstructed("");
            GTEST_ASSERT_TRUE(emptyConstructed.IsEmpty());
            xoe::String emptyAssigned;
            GTEST_ASSERT_TRUE(emptyAssigned.IsEmpty());
            emptyAssigned = "";
            GTEST_ASSERT_TRUE(emptyAssigned.IsEmpty());
            GTEST_ASSERT_EQ(emptyConstructed, emptyAssigned);
            GTEST_ASSERT_EQ(strcmp("", emptyConstructed.Get()), 0);
            GTEST_ASSERT_EQ(strcmp("", emptyAssigned.Get()), 0);
        }

        // Copy constructed and assigned strings
        {
            xoe::String constructed("constructed");
            xoe::String copyConstructed(constructed);
            xoe::String copyAssigned;
            copyAssigned = constructed;
        }

        {
            xoe::String constructed("constructed");
            xoe::String moveConstructed(std::move(constructed));
            xoe::String doubleMoveConstructed(std::move(constructed));
            xoe::String assigned;
            assigned                       = "assigned";
            xoe::String moveAssigned       = std::move(assigned);
            xoe::String doubleMoveAssigned = std::move(moveAssigned);
        }
    }

    //--------------------------------------------------------------------------
    TEST(String, Concat)
    {
        {
            xoe::String emptyStr1;
            xoe::String emptyStr2;
            xoe::String emptyStr3 = emptyStr1 + emptyStr2;
        }

        {
            xoe::String tinyStr1("a");
            xoe::String tinyStr2("b");
            xoe::String tinyStr3 = tinyStr1 + tinyStr2;
        }

        {
            xoe::String bigStr1(
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit. "
                "Morbi aliquet sodales consectetur. Sed at metus quis felis "
                "maximus malesuada at eget velit. Ut non lacus massa. In hac "
                "habitasse platea dictumst. Cras ultricies lacus sit amet nisi "
                "ullamcorper, in consectetur dolor mollis. Nam cursus pretium "
                "massa id convallis. Vivamus semper sit amet metus ut "
                "tincidunt. Nullam sed purus at velit ultricies rutrum. "
                "Pellentesque habitant morbi tristique senectus et netus et "
                "malesuada fames ac turpis egestas. Sed ac metus a ex blandit "
                "mattis eu non nibh. Etiam nisi tortor, venenatis nec elit id, "
                "tincidunt condimentum ligula. Mauris consequat, risus a "
                "posuere feugiat, felis eros feugiat dolor, vel gravida dui "
                "est nec metus. Aliquam ut aliquet metus, vitae dignissim "
                "ipsum. Aenean iaculis, nibh vitae iaculis rhoncus, arcu metus "
                "porttitor nisl, non porta augue elit quis nisi. Nullam quis "
                "massa eu magna rhoncus bibendum. Fusce accumsan luctus "
                "mollis.");

            xoe::String bigStr2(
                "Mauris pellentesque in tortor non auctor. Pellentesque "
                "convallis turpis eget mauris molestie bibendum. Mauris "
                "pharetra pulvinar nisl, at dictum urna pharetra non. Nunc id "
                "dolor tortor. Donec semper massa sed tortor posuere, eget "
                "facilisis metus imperdiet. Ut mattis tristique magna, non "
                "egestas lectus dictum a. Duis ut magna nec est cursus "
                "imperdiet. Morbi hendrerit tristique nibh eget sagittis. "
                "Suspendisse vestibulum odio vel elit mollis, sed ullamcorper "
                "nibh efficitur. Pellentesque urna nulla, iaculis id bibendum "
                "at, mollis at ante. Donec sagittis turpis accumsan, tristique "
                "orci ac, ornare elit. Phasellus sollicitudin nunc eu elit "
                "imperdiet ullamcorper. Quisque sit amet eros sit amet arcu "
                "pulvinar malesuada. Integer condimentum hendrerit dui, nec "
                "tempor sem dapibus sed. ");

            xoe::String bigStr3 = bigStr1 + bigStr2;
        }
    }

    TEST(String, XXH3)
    {
        GTEST_ASSERT_EQ(xoe::immediate::StrHash(""), 0);
        // compared with https://md5calc.com/hash/xxh3/Hello+World
        GTEST_ASSERT_EQ(xoe::immediate::StrHash("Hello World"),
                        0xe34615aade2e6333);
        GTEST_ASSERT_EQ(xoe::immediate::StrHash(
                            "Hello World\0Some more text after the string"),
                        0xe34615aade2e6333);

        xoe::String dynamicHelloWorld("Hello World");
        GTEST_ASSERT_EQ(dynamicHelloWorld.ComputeHash(), 0xe34615aade2e6333);
    }

}  // namespace
//------------------------------------------------------------------------------