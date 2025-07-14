#pragma once

#include <spdlog/spdlog.h>
#include <memory>
namespace Moon {

class Log {
public:
    static void Init();

    static std::shared_ptr<spdlog::logger>& GetCoreLogger();
    static std::shared_ptr<spdlog::logger>& GetClientLogger();

private:
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
};
}  // namespace Moon

// Core log macros
#define MOON_CORE_TRACE(...)                                               \
    ::Moon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MOON_CORE_INFO(...) ::Moon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MOON_CORE_WARN(...) ::Moon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MOON_CORE_ERROR(...)                                               \
    ::Moon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MOON_CORE_CRITICAL(...)                                            \
    ::Moon::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define MOON_TRACE(...) ::Moon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MOON_INFO(...) ::Moon::Log::GetClientLogger()->info(__VA_ARGS__)
#define MOON_WARN(...) ::Moon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MOON_ERROR(...) ::Moon::Log::GetClientLogger()->error(__VA_ARGS__)
#define MOON_CRITICAL(...)                                                 \
    ::Moon::Log::GetClientLogger()->critical(__VA_ARGS__)

#define MOON_ASSERT(x, ...)                                                \
    {                                                                      \
        if (!(x)) {                                                        \
            MOON_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);         \
            __debugbreak();                                                \
        }                                                                  \
    }
#define MOON_CORE_ASSERT(x, ...)                                           \
    {                                                                      \
        if (!(x)) {                                                        \
            MOON_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);         \
            __debugbreak();                                                \
        }                                                                  \
    }
