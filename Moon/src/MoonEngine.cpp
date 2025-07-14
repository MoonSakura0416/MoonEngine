#include <windows.h>
#include "EngineFactory.h"

#define CHECK(x)                                                           \
    if (x) {                                                               \
        return x;                                                          \
    }

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nShowCmd)
{
    int returnValue{0};
    {
        if (auto* engine = Moon::EngineFactory::CreateEngine()) {
            returnValue = engine->PreInit(Moon::WinMainCommandParameters(
                hInstance, hPrevInstance, lpCmdLine, nShowCmd));
            CHECK(returnValue)
            returnValue = engine->Init();
            CHECK(returnValue)
            returnValue = engine->PostInit();
            CHECK(returnValue)
            // while (true) {
            //     engine->Tick();
            // }

            returnValue = engine->PreExit();
            CHECK(returnValue)
            returnValue = engine->Exit();
            CHECK(returnValue)
            returnValue = engine->PostExit();
            CHECK(returnValue)
            returnValue = 0;
        } else {
            returnValue = -1;
        }
    }
    return returnValue;
}
