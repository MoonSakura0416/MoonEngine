#pragma once

#include "Core/Engine.h"

namespace Moon {

class EngineFactory {
public:
    static Engine* CreateEngine();
};
}  // namespace Moon
