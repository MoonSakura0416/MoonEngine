#pragma once

#ifdef _WIN32
#include "Core/Engine.h"

namespace Moon {

class WindowsEngine final : public Engine {
public:
    ~WindowsEngine() override = default;

    int PreInit(WinMainCommandParameters InParamaters) override;
    int Init() override;
    int PostInit() override;

    void Tick() override;

    int PreExit() override;
    int Exit() override;
    int PostExit() override;
};
}  // namespace Moon
#endif
