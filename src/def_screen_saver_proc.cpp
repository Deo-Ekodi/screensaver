#include "src.hpp"

LRESULT DefScreenSaverProc(
    HWND   hWnd,                  /**/
    UINT   msg,                   /**/
    WPARAM wParam,                /**/
    LPARAM lParam                 /**/
)
{
    return DefWindowProcA(hWnd, msg, wParam, lParam);
}