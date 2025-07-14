#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    MessageBoxA(nullptr, "Hello, DirectX 12 world!", "My First App", MB_OK | MB_ICONINFORMATION);
    return 0;
}
