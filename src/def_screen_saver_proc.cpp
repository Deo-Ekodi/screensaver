#include "src.hpp"

LRESULT DefScreenSaverProc(
    HWND   hWnd,                  /**/
    UINT   msg,                   /**/
    WPARAM wParam,                /**/
    LPARAM lParam                 /**/
)
{
    return DefWindowProc(hWnd, msg, wParam, lParam);
}