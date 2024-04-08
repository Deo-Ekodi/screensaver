#include "src.hpp"

BOOL WINAPI RegisterDialogClasses(HANDLE hInst)
{
    // // Define and register your custom dialog class
    // WNDCLASS cls;
    // cls.hCursor = NULL;
    // cls.hIcon = LoadIcon(hInst, MAKEINTATOM(ID_APP));
    // cls.lpszMenuName = NULL;
    // cls.lpszClassName = "WindowsScreenSaverClass";
    // cls.hbrBackground = GetStockObject(BLACK_BRUSH);
    // cls.hInstance = hInst;
    // cls.style = CS_VREDRAW | CS_HREDRAW | CS_SAVEBITS | CS_DBLCLKS;
    // cls.lpfnWndProc = (WNDPROC) ScreenSaverProc;
    // cls.cbWndExtra = 0;
    // cls.cbClsExtra = 0;

    // if (!RegisterClassEx(&cls))
    // {
    //     // Handle registration failure
    //     return FALSE;
    // }

    // If registration is successful, return TRUE
    return TRUE;
}