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
    WNDCLASS wc;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = ScreenSaverProc;
    // wc.lpfnWndProc = DialogProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = TEXT("MyScreenSaverClass");

    if (!RegisterClass(&wc))
    {
        MessageBox(NULL, TEXT("Window Registration Failed!"), TEXT("Error!"), MB_ICONERROR);
        return 0;
    }

    // Create window
    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles
        TEXT("MyScreenSaverClass"),     // Window class
        TEXT("My Screen Saver"),        // Window title
        WS_POPUP | WS_VISIBLE,          // Window style (fullscreen and visible)
        0, 0,                           // Initial position (top-left corner)
        GetSystemMetrics(SM_CXSCREEN),  // Width of the screen
        GetSystemMetrics(SM_CYSCREEN),  // Height of the screen
        NULL,                           // Parent window
        NULL,                           // Menu
        hInstance,                      // Instance handle
        NULL                            // Additional application data
    );

    if (!hwnd)
    {
        MessageBox(NULL, TEXT("Window Creation Failed!"), TEXT("Error!"), MB_ICONERROR);
        return 0;
    }

    // Enter message loop
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // return msg.wParam;
    return DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_SETTINGS_DIALOG), hwnd, DialogProc);
}
