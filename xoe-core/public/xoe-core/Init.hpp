// copyright xo 2025 all rights reserved
// xoe-core/Init.h
// RAII types for managing the global initialization and shutdown of xoe-core
// features and external dependencies.
//------------------------------------------------------------------------------
#pragma once

#include <xoe-core/BasicTypes.hpp>
#include <xoe-core/String.hpp>

namespace xoe
{
    class InitProcedure
    {
    public:
        bool_t IsInitialized() const { return m_Initialized; }
        String const& GetErrorMessage() const { return m_ErrorMessage; }

    protected:
        bool_t m_Initialized = false;
        String m_ErrorMessage;
    };

    // Lets the application tell xoe-core about itself
    //--------------------------------------------------------------------------
    class InitAppKnowledge : public InitProcedure
    {
    public:
        InitAppKnowledge() = delete;
        explicit InitAppKnowledge(char_t const* appName);
        ~InitAppKnowledge();
        InitAppKnowledge(InitAppKnowledge&&);
        InitAppKnowledge& operator=(InitAppKnowledge&&);
        InitAppKnowledge(InitAppKnowledge const&)            = delete;
        InitAppKnowledge& operator=(InitAppKnowledge const&) = delete;
    };

    // Google Highway (SIMD library)
    // https://google.github.io/highway/en/master/index.html
    //--------------------------------------------------------------------------
    class InitHighway : public InitProcedure
    {
    public:
        InitHighway();
        ~InitHighway();
        InitHighway(InitHighway&&);
        InitHighway& operator=(InitHighway&&);
        InitHighway(InitHighway const&)            = delete;
        InitHighway& operator=(InitHighway const&) = delete;
    };

    // spdlog
    // https://github.com/gabime/spdlog
    //--------------------------------------------------------------------------
    class InitSpdlog : public InitProcedure
    {
    public:
        InitSpdlog();
        ~InitSpdlog();
        InitSpdlog(InitSpdlog&&);
        InitSpdlog& operator=(InitSpdlog&&);
        InitSpdlog(InitSpdlog const&)            = delete;
        InitSpdlog& operator=(InitSpdlog const&) = delete;
    };

}  // namespace xoe

//------------------------------------------------------------------------------