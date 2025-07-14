#include "Core/WinMainCommandParameters.h"

namespace Moon {

WinMainCommandParameters::WinMainCommandParameters(HINSTANCE hInstance,
                                                   HINSTANCE hPrevInstance,
                                                   LPSTR     lpCmdLine,
                                                   int       nShowCmd)
    : m_hInstance(hInstance),
      m_hPrevInstance(hPrevInstance),
      m_lpCmdLine(lpCmdLine),
      m_nShowCmd(nShowCmd)
{
}
}  // namespace Moon
