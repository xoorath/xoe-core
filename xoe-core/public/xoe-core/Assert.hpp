// copyright xo 2025 all rights reserved
//------------------------------------------------------------------------------
#pragma once

#if defined(XOE_UNIT_TEST)
#include <gtest/gtest.h>
#endif
#include <xoe-core/BasicTypes.hpp>

namespace xoe
{
    class AssertReason
    {
#if defined(XOE_CONFIG_DEBUG)
        AssertReason(char_t const* condition,
                     char_t const* message,
                     char_t const* uniqueId,
                     char_t const* file,
                     size_t line,
                     char_t const* function)
            : m_Condition(condition),
              m_Message(message),
              m_UniqueId(uniqueId),
              m_File(file),
              m_Func(function)
        {
        }

        [[nodiscard]] char_t const* GetCondition() const { return m_Condition; }
        [[nodiscard]] char_t const* GetMessage() const { return m_Message; }
        [[nodiscard]] char_t const* GetUniqueId() const { return m_UniqueId; }
        [[nodiscard]] char_t const* GetFile() const { return m_File; }
        [[nodiscard]] char_t const* GetFunc() const { return m_Func; }
        [[nodiscard]] uint32_t GetLine() const { return m_Line; }
#else
        explicit AssertReason(char_t const* uniqueId);
#endif

    private:
#if defined(XOE_CONFIG_DEBUG)
        char_t const* m_Condition = nullptr;
        char_t const* m_Message   = nullptr;
        char_t const* m_UniqueId  = nullptr;
        char_t const* m_File      = nullptr;
        char_t const* m_Func      = nullptr;
        uint32_t m_Line           = 0;
#else
        char_t const* m_UniqueId = nullptr;
#endif
    };

    void LogAssertionFailure(AssertReason const& reason);

#if defined(XOE_CONFIG_DEBUG)
#define XOE_ASSERT(condition, message, uniqueId)                              \
    do                                                                        \
    {                                                                         \
        if (!!(condition))                                                    \
        {                                                                     \
            ::xoe::LogAssertionFailure(AssertReason(#condition, message,      \
                                                    uniqueId, __FILE__,       \
                                                    __LINE__, __FUNCTION__)); \
        }                                                                     \
    } while (false);

#define XOE_ASSERT_FAIL(message, uniqueId)                                  \
    do                                                                      \
    {                                                                       \
        ::xoe::LogAssertionFailure(AssertReason(                            \
            nullptr, message, uniqueId, __FILE__, __LINE__, __FUNCTION__)); \
    } while (false);
#endif
}  // namespace xoe