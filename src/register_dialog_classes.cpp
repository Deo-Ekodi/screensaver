#include "src.hpp"

BOOL WINAPI RegisterDialogClasses(HANDLE hInst)
{
    // Define and register your custom dialog class
    WNDCLASSEX wc = {};
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.lpfnWndProc = DefDlgProc;
    wc.hInstance = (HINSTANCE)hInst;
    wc.lpszClassName = "MyCustomDialogClass";

    if (!RegisterClassEx(&wc))
    {
        // Handle registration failure
        return FALSE;
    }

    // If registration is successful, return TRUE
    return TRUE;
}