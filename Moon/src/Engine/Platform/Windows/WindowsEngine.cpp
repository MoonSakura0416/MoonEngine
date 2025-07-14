#ifdef _WIN32
#include "Platform/Windows/WindowsEngine.h"
#include "Platform/Windows/WindowsMessageProcessing.h"
#include "Debug/Log.h"

namespace Moon {
int WindowsEngine::PreInit(WinMainCommandParameters InParamaters)
{
    if (InitWindows(InParamaters)) {
    }
    MOON_CORE_INFO("PreInit completed!");
    return 0;
}

int WindowsEngine::Init()
{
    MOON_CORE_INFO("Init completed!");
    return 0;
}

int WindowsEngine::PostInit()
{
    MOON_CORE_INFO("PostInit completed!");
    return 0;
}

void WindowsEngine::Tick() {}

int WindowsEngine::PreExit()
{
    MOON_CORE_INFO("PreExit completed!");
    return 0;
}

int WindowsEngine::Exit()
{
    MOON_CORE_INFO("Exit completed!");
    return 0;
}

int WindowsEngine::PostExit()
{
    MOON_CORE_INFO("PostExit completed!");
    return 0;
}

bool WindowsEngine::InitWindows(
    const WinMainCommandParameters& InParamaters)
{
    WNDCLASSEX wcex{};
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.cbClsExtra = 0;
    wcex.hbrBackground = nullptr;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hIcon = nullptr;
    wcex.hIconSm = nullptr;
    wcex.hInstance = InParamaters.m_hInstance;
    wcex.lpszClassName = L"MoonEngine";
    wcex.lpszMenuName = nullptr;
    wcex.style = CS_VREDRAW | CS_HREDRAW;
    wcex.lpfnWndProc = EngineWindowProc;

    if (ATOM registerAtom = RegisterClassEx(&wcex); !registerAtom) {
        MessageBox(nullptr, L"Failed to register Window Class", L"Error",
                   MB_OK);
    }

    RECT rect{0, 0, 1280, 720};

    AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

    auto windowWidth = rect.right - rect.left;
    auto windowHeight = rect.bottom - rect.top;

    HWND hwnd = CreateWindowEx(0, L"MoonEngine", L"Moon Engine",
                               WS_OVERLAPPEDWINDOW, 100, 100, windowWidth,
                               windowHeight, nullptr, nullptr,
                               InParamaters.m_hInstance, nullptr);
    if (!hwnd) {
        MessageBox(0, L"Failed to create Window", L"Error", MB_OK);
        return false;
    }

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    MOON_CORE_INFO("Window created successfully!");
    return true;
}
}  // namespace Moon
#endif
