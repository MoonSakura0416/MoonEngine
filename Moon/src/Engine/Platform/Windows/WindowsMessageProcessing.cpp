#include "Platform/Windows/WindowsMessageProcessing.h"

namespace Moon {
LRESULT EngineWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}
}  // namespace Moon