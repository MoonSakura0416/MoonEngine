#pragma once

#ifdef _WIN32
#include "Core/WinMainCommandParameters.h"
#endif

namespace Moon {

class Engine {
public:
    virtual ~Engine() = default;

    virtual int PreInit(WinMainCommandParameters InParamaters) = 0;
    virtual int Init() = 0;
    virtual int PostInit() = 0;

    virtual void Tick() = 0;

    virtual int PreExit() = 0;
    virtual int Exit() = 0;
    virtual int PostExit() = 0;
};
}  // namespace Moon
