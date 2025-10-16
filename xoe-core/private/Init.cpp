// copyright xo 2025 all rights reserved
//------------------------------------------------------------------------------
#include <iostream>
#include <utility>

#include <hwy/highway.h>
#include <spdlog/spdlog.h>

#include <xoe-core/Init.hpp>

#if defined(XOE_UNIT_TEST)
#include <gtest/gtest.h>
#endif

//------------------------------------------------------------------------------
namespace
{
    void HighwayWarnFunc(char const* const file,
                         int const line,
                         char const* const message)
    {
#if defined(XOE_UNIT_TEST)
        ADD_FAILURE_AT(file, line) << message;
#else
        std::cerr << file << ":" << line << ": " << message << std::endl;
#endif
    }

    void HighwayAbortFunc(char const* const file,
                          int const line,
                          char const* const message)
    {
#if defined(XOE_UNIT_TEST)
        ADD_FAILURE_AT(file, line) << message;
#else
        std::cerr << file << ":" << line << ": " << message << std::endl;
        exit(-1);
#endif
    }
}  // namespace

//------------------------------------------------------------------------------
namespace xoe
{
    //--------------------------------------------------------------------------
    InitHighway::InitHighway()
    {
        hwy::SetWarnFunc(HighwayWarnFunc);
        hwy::SetAbortFunc(HighwayAbortFunc);
        m_Initialized = true;
    }

    InitHighway::~InitHighway()
    {
        if (m_Initialized)
        {
            hwy::SetWarnFunc(nullptr);
            hwy::SetAbortFunc(nullptr);
        }
    }

    InitHighway::InitHighway(InitHighway&& other)
    {
        m_Initialized       = other.m_Initialized;
        m_ErrorMessage      = std::move(other.m_ErrorMessage);
        other.m_Initialized = false;
    }
    InitHighway& InitHighway::operator=(InitHighway&& other)
    {
        m_Initialized       = other.m_Initialized;
        m_ErrorMessage      = std::move(other.m_ErrorMessage);
        other.m_Initialized = false;
        return *this;
    }

    //--------------------------------------------------------------------------
    InitSpdlog::InitSpdlog()
    {
        spdlog::info("hello world");
        m_Initialized = true;
    }

    InitSpdlog::~InitSpdlog() {}
    InitSpdlog::InitSpdlog(InitSpdlog&& other)
    {
        m_Initialized       = other.m_Initialized;
        m_ErrorMessage      = std::move(other.m_ErrorMessage);
        other.m_Initialized = false;
    }
    InitSpdlog& InitSpdlog::operator=(InitSpdlog&& other)
    {
        m_Initialized       = other.m_Initialized;
        m_ErrorMessage      = std::move(other.m_ErrorMessage);
        other.m_Initialized = false;
        return *this;
    }

}  // namespace xoe
//------------------------------------------------------------------------------