#include "Debug/Log.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Moon {
std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

void Log::Init()
{
    spdlog::set_pattern("%^[%T] %n: %v%$");
    s_CoreLogger = spdlog::basic_logger_mt("MOON", "MoonLog.txt");
    s_CoreLogger->set_level(spdlog::level::trace);

    s_ClientLogger = spdlog::stdout_color_mt("APP");
    s_ClientLogger->set_level(spdlog::level::trace);
}

std::shared_ptr<spdlog::logger>& Log::GetCoreLogger()
{
    return s_CoreLogger;
}
std::shared_ptr<spdlog::logger>& Log::GetClientLogger()
{
    return s_ClientLogger;
}

}  // namespace Moon