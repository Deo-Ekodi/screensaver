#include "src.hpp"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    // uunreferenced parameters
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    // Register the window class for the screensaver
    WNDCLASS wc = {};
    wc.lpfnWndProc = ScreenSaverProc;
    wc.hInstance = hInstance;

    // line below compiles on g++ without any errors!
    wc.lpszClassName = "MyScreenSaverClass";

    if (!RegisterClass(&wc))
    {
        // Handle registration failure
        return 1;
    }

    // // Create a window for the screensaver (if necessary)
    // HWND hwnd = CreateWindowEx(
    //     0,
    //     "MyScreenSaverClass",
    //     "My Screensaver",
    //     WS_OVERLAPPEDWINDOW, // Or other window styles as needed
    //     CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
    //     NULL,
    //     NULL,
    //     hInstance,
    //     NULL
    // );

    // if (!hwnd)
    // {
    //     // Handle window creation failure
    //     return 1;
    // }

    // // Show and update the window
    // ShowWindow(hwnd, SW_SHOW);
    // UpdateWindow(hwnd);

    // // Run the message loop
    // MSG msg;
    // while (GetMessage(&msg, NULL, 0, 0))
    // {
    //     TranslateMessage(&msg);
    //     DispatchMessage(&msg);
    // }
    // Perform cleanup and shutdown
// uncomment below
/**/
    DialogBox(hInstance, MAKEINTRESOURCE(IDD_CONFIG_DIALOG), NULL, ScreenSaverConfigureDialog);
/**/  
    return 0;
}
