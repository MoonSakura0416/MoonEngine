#include "EngineFactory.h"
#include "Debug/Log.h"
#include <windows.h>

#define CHECK(x)                                                           \
    if (x) {                                                               \
        MOON_CORE_ERROR(                                                   \
            "Engine initialization failed, please check the problem {}",   \
            x);                                                            \
        return x;                                                          \
    }

int Init(Moon::Engine* InEngine, HINSTANCE hInstance,
         HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    int returnValue = InEngine->PreInit(Moon::WinMainCommandParameters(
        hInstance, hPrevInstance, lpCmdLine, nShowCmd));
    CHECK(returnValue)
    returnValue = InEngine->Init();
    CHECK(returnValue)
    returnValue = InEngine->PostInit();
    CHECK(returnValue)

    return returnValue;
}

void Tick(Moon::Engine* InEngine) {}

int Exit(Moon::Engine* InEngine)
{
    int returnValue = InEngine->PreExit();
    CHECK(returnValue)
    returnValue = InEngine->Exit();
    CHECK(returnValue)
    returnValue = InEngine->PostExit();
    CHECK(returnValue)

    return returnValue;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine, int nShowCmd)
{
    Moon::Log::Init();
    MOON_CORE_INFO("Initialized Log!");

    int returnValue{0};
    {
        if (auto* engine = Moon::EngineFactory::CreateEngine()) {
            returnValue =
                Init(engine, hInstance, hPrevInstance, lpCmdLine, nShowCmd);
            if (returnValue == 0) {
                // while (true) {
                //     Tick(engine);
                // }
                returnValue = Exit(engine);
            }
            delete engine;
        } else {
            returnValue = -1;
        }
    }
    return returnValue;
}
