#ifdef _WIN32
#include "Platform/Windows/WindowsEngine.h"

namespace Moon {
int WindowsEngine::PreInit(WinMainCommandParameters InParamaters)
{
    return 0;
}

int WindowsEngine::Init()
{
    return 0;
}

int WindowsEngine::PostInit()
{
    return 0;
}

void WindowsEngine::Tick() {}

int WindowsEngine::PreExit()
{
    return 0;
}

int WindowsEngine::Exit()
{
    return 0;
}

int WindowsEngine::PostExit()
{
    return 0;
}
}  // namespace Moon
#endif
