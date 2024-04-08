#include "src.hpp"

/**
 * fix:
 * invisible window .. WM_VIVIBLE
*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // uunreferenced parameters
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    // Register the window class for the screensaver
    // WNDCLASS wc;
    // wc.style = CS_HREDRAW | CS_VREDRAW;
    // wc.lpfnWndProc = ScreenSaverProc;
    // // wc.lpfnWndProc = DialogProc;
    // wc.cbClsExtra = 0;
    // wc.cbWndExtra = 0;
    // wc.hInstance = hInstance;
    // wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    // wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    // wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    // wc.lpszMenuName = NULL;
    // wc.lpszClassName = TEXT("MyScreenSaverClass");

    WNDCLASS cls;
    cls.hCursor = NULL;
    cls.hIcon = LoadIcon(hInstance, MAKEINTATOM(ID_APP));
    cls.lpszMenuName = NULL;
    cls.lpszClassName = "WindowsScreenSaverClass";
    cls.hbrBackground = (HBRUSH)(GetStockObject(BLACK_BRUSH));
    cls.hInstance = hInstance;
    cls.style = CS_VREDRAW | CS_HREDRAW | CS_SAVEBITS | CS_DBLCLKS;
    cls.lpfnWndProc = (WNDPROC) ScreenSaverProc;
    cls.cbWndExtra = 0;
    cls.cbClsExtra = 0;

    if (!RegisterClass(&cls))
    {
        MessageBoxA(NULL, TEXT("Window Registration Failed!"), TEXT("Error!"), MB_ICONERROR);
        return 0;
    }

    return DialogBoxParamA(GetModuleHandle(NULL), MAKEINTRESOURCEA(IDD_SETTINGS_DIALOG), NULL, (DLGPROC)ScreenSaverConfigureDialog, NULL);

}
