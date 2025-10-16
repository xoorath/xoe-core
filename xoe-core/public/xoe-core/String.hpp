// copyright xo 2025 all rights reserved
//------------------------------------------------------------------------------
#pragma once

// Includes
//------------------------------------------------------------------------------

// xoe
#include <xoe-core/BasicTypes.hpp>

// standard library
#include <algorithm>
#include <cstdlib>
#include <format>

namespace xoe
{
    //--------------------------------------------------------------------------
    // Gets the length of a string
    uint32_t StrLen(char_t const* str);

    //--------------------------------------------------------------------------
    enum class FreeStringMemory : bool_t
    {
        DoNotFree = false,
        Free      = true
    };

    //--------------------------------------------------------------------------
    class String
    {
    public:
        String();
        String(char_t const* str);
        String& operator=(char_t const* str);
        String(String const& other);
        String& operator=(String const& other);
        String(String&& other);
        String& operator=(String&& other);
        ~String();

        [[nodiscard]] char_t const* Get() const { return m_Str; }
        [[nodiscard]] char_t* Get() { return m_Str; }

        [[nodiscard]] uint32_t GetLength() const { return m_Length; }
        [[nodiscard]] uint32_t GetCapacity() const { return m_Capacity; }
        [[nodiscard]] bool IsEmpty() const { return m_Length == 0; }
        void Clear(bool andFreeMemory = false);

        void Reserve(uint32_t capacity);
        void SetLength(uint32_t newLength);

        String operator+(char_t const* other) const;
        String operator+(String const& other) const;
        String& operator+=(char_t const* other);
        String& operator+=(String const& other);

        bool operator==(char_t const* other) const;
        bool operator!=(char_t const* other) const;
        bool operator==(String const& other) const;
        bool operator!=(String const& other) const;

        bool operator()() const { return !IsEmpty(); };

        template <typename... Args>
        void Format(char const* const fmt, Args&&... args)
        {
            size_t const len =
                std::formatted_size(fmt, std::forward<Args>(args)...);
            if (len + 1 > m_Capacity)
            {
                uint32_t nextCapacity = std::max<uint32_t>(m_Capacity << 1, 1);
                while (nextCapacity < len + 1)
                    nextCapacity <<= 1;
                m_Capacity = nextCapacity;
                if (m_ShouldFree == FreeStringMemory::Free)
                {
                    m_Str = reinterpret_cast<char_t*>(
                        std::realloc(m_Str, nextCapacity));
                }
                else
                {
                    m_Str = new char_t[](nextCapacity);
                    m_ShouldFree == FreeStringMemory::Free;
                }
            }
            m_Length = len;
            std::vformat_to(/*out*/ m_Str,
                            /*fmt*/ fmt, std::forward<Args>(args)...);
        }

    protected:
        char_t* m_Str;
        uint32_t m_Length                  = 0;
        uint32_t m_Capacity           : 31 = 0;
        FreeStringMemory m_ShouldFree : 1  = FreeStringMemory::DoNotFree;

        static char_t s_EmptyString[1];
    };

    //--------------------------------------------------------------------------
    template <uint32_t SIZE = 256>
    class StackString : public String
    {
    public:
        StackString() : m_Buffer({0})
        {
            m_Str        = reinterpret_cast<char_t*>(m_Buffer);
            m_Length     = 0;
            m_Capacity   = sizeof(m_Buffer);
            m_ShouldFree = FreeStringMemory::DoNotFree;
        }

        StackString(char_t const* str)
        {
            size_t const len = StrLen(str) + 1;
            if (len == 0)
            {
                m_Str        = reinterpret_cast<char_t*>(m_Buffer);
                m_Length     = 0;
                m_Capacity   = sizeof(m_Buffer);
                m_ShouldFree = FreeStringMemory::DoNotFree;
            }
            else if (len + 1 > SIZE)
            {
                m_Str        = nullptr;
                m_Length     = 0;
                m_Capacity   = 0;
                m_ShouldFree = FreeStringMemory::DoNotFree;
                SetLength(len);
                CopyBytes(/*dest*/ reinterpret_cast<byte_t*>(m_Str),
                          /*source*/ reinterpret_cast<byte_t const*>(str),
                          len + 1);
            }
            else
            {
                m_Str        = reinterpret_cast<char_t*>(m_Buffer);
                m_Length     = len;
                m_Capacity   = sizeof(m_Buffer);
                m_ShouldFree = FreeStringMemory::DoNotFree;
                CopyBytes(/*dest*/ reinterpret_cast<byte_t*>(m_Str),
                          /*source*/ reinterpret_cast<byte_t const*>(str),
                          len + 1);
            }
        }

        StackString& operator=(char_t const* str)
        {
            String::operator=(str);
            return *this;
        }

        StackString(String const& other)
        {
            m_Str        = reinterpret_cast<char_t*>(m_Buffer);
            m_Capacity   = sizeof(m_Buffer);
            m_Length     = 0;
            m_ShouldFree = FreeStringMemory::DoNotFree;
            String::operator=(other);
        }

        StackString& operator=(StackString const& other)
        {
            String::operator=(other);
            return *this;
        }

        StackString(StackString&& other)
        {
            m_Str              = m_Buffer;
            m_Length           = 0;
            m_Capacity         = sizeof(m_Buffer);
            m_ShouldFree       = FreeStringMemory::DoNotFree;
            uint32_t const len = other.m_Length;
            if (len + 1 < SIZE)
            {
                CopyBytes(
                    /*dest*/ reinterpret_cast<byte_t*>(m_Str),
                    /*source*/ reinterpret_cast<byte_t const*>(other.Get()),
                    len + 1);
                m_Length = len;
                if (other.m_ShouldFree == FreeStringMemory::Free)
                {
                    delete[] other.m_Str;
                    other.m_Str        = nullptr;
                    other.m_Capacity   = 0;
                    other.m_Length     = 0;
                    other.m_ShouldFree = FreeStringMemory::DoNotFree;
                }
                else
                {
                    other.m_Str    = nullptr;
                    other.m_Length = 0;
                }
                return;
            }
        }

        StackString& operator=(StackString&& other);
        ~StackString();

    private:
        byte_t m_Buffer[SIZE - sizeof(String)];
        static_assert(SIZE > 32, "SIZE must be > 32");
        static_assert((SIZE & (SIZE - 1)) == 0, "SIZE must be a power of 2");
        static_assert(SIZE < (1 << 31), "SIZE must be < 2^31");
    };

}  // namespace xoe
//------------------------------------------------------------------------------