// copyright xo 2025 all rights reserved
//------------------------------------------------------------------------------

// Includes
//------------------------------------------------------------------------------
#include <xoe-core/String.hpp>

// third party
#include <hwy/highway.h>

// standard
#include <cstring>

namespace xoe
{
    // A globally shared empty string
    /*static*/ char_t String::s_EmptyString[1] = {'\0'};

    // Internal functions
    //--------------------------------------------------------------------------
    namespace
    {
        uint32_t StringLength(char const* str)
        {
            return static_cast<uint32_t>(strlen(str));
        }

        char_t* StringAlloc(uint32_t const size)
        {
            char_t* const buff = new char_t[size];
            return buff;
        }

        uint32_t CalculateReservedSize(uint32_t const actualSize)
        {
            uint32_t reservedSize = 1;
            while (reservedSize <= actualSize)
            {
                reservedSize *= 2;
            }
            return reservedSize;
        }

    }  // namespace

    // Free functions
    //--------------------------------------------------------------------------
    uint32_t StrLen(char const* str)
    {
        // hwy::CopyBytes()
    }

    // String methods
    //--------------------------------------------------------------------------
    String::String()
        : m_Str(s_EmptyString),
          m_Length(0),
          m_Capacity(0),
          m_ShouldFree(FreeStringMemory::DoNotFree)
    {
    }

    String::String(char const* str)
    {
        m_Length   = StringLength(str);
        m_Capacity = CalculateReservedSize(m_Length);
        m_Str      = StringAlloc(m_Capacity);
        memcpy(m_Str, str, m_Length + 1);
        m_ShouldFree = FreeStringMemory::Free;
    }

    String& String::operator=(char const* str)
    {
        if (str != m_Str)
        {
            uint32_t const len = StringLength(str);

            if (len + 1 > m_Capacity)
            {
                if (m_ShouldFree == FreeStringMemory::DoNotFree)
                {
                    uint32_t const reserved = CalculateReservedSize(len);
                    m_Str                   = new char_t[reserved];
                    m_Length                = len;
                    m_Capacity              = reserved;
                    m_ShouldFree            = FreeStringMemory::DoNotFree;
                    memcpy(m_Str, str, len + 1);
                    return *this;
                }
            }
            m_Length   = StringLength(str);
            m_Capacity = CalculateReservedSize(m_Length);
            m_Str      = new char_t[m_Capacity];
            memcpy(m_Str, str, m_Length + 1);
            m_ShouldFree = FreeStringMemory::Free;
        }
        return *this;
    }
    String::String(String const& other) {}

    String& String::operator=(String const& other)
    {
        return *this;
    }

    String::String(String&& other)
        : m_Str(other.m_Str),
          m_Length(other.m_Length),
          m_Capacity(other.m_Capacity),
          m_ShouldFree((other.m_ShouldFree))
    {
        other.m_Str        = nullptr;
        other.m_Length     = 0;
        other.m_Capacity   = 0;
        other.m_ShouldFree = FreeStringMemory::DoNotFree;
    }

    String& String::operator=(String&& other)
    {
        if (this != &other)
        {
            if (m_ShouldFree == FreeStringMemory::Free)
            {
                delete[] m_Str;
            }
            m_Str        = other.m_Str;
            m_Length     = other.m_Length;
            m_Capacity   = other.m_Capacity;
            m_ShouldFree = other.m_ShouldFree;

            other.m_Str        = nullptr;
            other.m_Length     = 0;
            other.m_Capacity   = 0;
            other.m_ShouldFree = FreeStringMemory::DoNotFree;
        }
        return *this;
    }
    String::~String()
    {
        if (m_ShouldFree == FreeStringMemory::Free)
        {
            delete[] m_Str;
            m_Str        = nullptr;
            m_Length     = 0;
            m_Capacity   = 0;
            m_ShouldFree = FreeStringMemory::DoNotFree;
        }
    }

    void String::Clear(bool const andFreeMemory /*=false*/)
    {
        if (andFreeMemory)
        {
            if (m_ShouldFree == FreeStringMemory::Free)
            {
                delete[] m_Str;
                m_Str        = s_EmptyString;
                m_Capacity   = 0;
                m_ShouldFree = FreeStringMemory::DoNotFree;
            }
            m_Length = 0;
        }
        else
        {
            m_Length = 0;
            if (m_Capacity > 0)
            {
                m_Str[0] = '\0';
            }
        }
    }

}  // namespace xoe
//------------------------------------------------------------------------------