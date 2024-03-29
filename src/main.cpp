#include "src.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // uunreferenced parameters
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    // Register the window class for the screensaver
    WNDCLASS cls = {}; 
    cls.hCursor        = NULL; 
    cls.hIcon          = LoadIcon(hInstance, MAKEINTATOM(ID_APP)); 
    cls.lpszMenuName   = NULL; 
    cls.lpszClassName  = "WindowsScreenSaverClass"; 
    // cls.hbrBackground  = GetStockObject(BLACK_BRUSH); 
    cls.hInstance      = hInstance; 
    cls.style          = CS_VREDRAW  | CS_HREDRAW | CS_SAVEBITS | CS_DBLCLKS; 
    cls.lpfnWndProc    = (WNDPROC) ScreenSaverProc; 
    cls.cbWndExtra     = 0; 
    cls.cbClsExtra     = 0;

    RegisterClass(&cls);

    if (!RegisterClass(&cls))
    {
        // Handle registration failure
        return 1;
    }

    DialogBox(hInstance, MAKEINTRESOURCE(IDD_SETTINGS_DIALOG), NULL, DialogProc);
    // DialogBox(hInstance, MAKEINTRESOURCE(IDD_CONFIG_DIALOG), NULL, ScreenSaverConfigureDialog);
/**/  
    return 0;
}
