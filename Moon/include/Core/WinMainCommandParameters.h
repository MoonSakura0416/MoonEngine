#pragma once

#ifdef _WIN32
#include <windows.h>

namespace Moon {
class WinMainCommandParameters {
public:
    WinMainCommandParameters(HINSTANCE hInstance, HINSTANCE hPrevInstance,
                             LPSTR lpCmdLine, int nShowCmd);

public:
    HINSTANCE m_hInstance;
    HINSTANCE m_hPrevInstance;
    LPSTR     m_lpCmdLine;
    int       m_nShowCmd;
};
}  // namespace Moon
#endif
