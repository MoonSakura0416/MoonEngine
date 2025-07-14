#include "EngineFactory.h"

#ifdef _WIN32
#include "Platform/Windows/WindowsEngine.h"
#endif

namespace Moon {

Engine* Moon::EngineFactory::CreateEngine()
{
    return new WindowsEngine{};
}
}  // namespace Moon
