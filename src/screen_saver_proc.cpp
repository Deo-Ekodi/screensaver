#include "src.hpp"

/**
 * this function may call DEFSCREENSAVERPROC
 * incomplete
*/

LRESULT ScreenSaverProc(
    HWND   hWnd,              /*identifier of window*/
    UINT   message,           /*message to window*/
    WPARAM wParam,            /*additional message specific info*/
    LPARAM lParam             /*additional message specifie info*/
)
{
    static HFONT hFont;
    static RECT rect;
    static TCHAR szTime[9];
    static SYSTEMTIME sysTime;

    switch (message)
    {
    case WM_CREATE:
        // Create a font for the clock
        /**
         * Retrieve any initialization data from the Regedit.ini file. 
         * Set a window timerfor the screen saver window. Perform any other required initialization.
        */
        hFont = CreateFont(40, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                           CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
        SetTimer(hWnd, 1, 1000, NULL); // Set a timer to update the clock every second
        break;

    case WM_TIMER:
        // Get the system time and format it as a string
        /**
         * Perform drawing operations.
        */
        GetLocalTime(&sysTime);
        wsprintf(szTime, TEXT("%.2d:%.2d:%.2d"), sysTime.wHour, sysTime.wMinute, sysTime.wSecond);

        // Update the window
        InvalidateRect(hWnd, NULL, TRUE);
        UpdateWindow(hWnd);
        break;

    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);

            // Draw the clock
            SelectObject(hdc, hFont);
            SetTextColor(hdc, RGB(255, 255, 255));
            SetBkMode(hdc, TRANSPARENT);
            GetClientRect(hWnd, &rect);
            DrawText(hdc, szTime, -1, &rect, DT_CENTER | DT_VCENTER);

            EndPaint(hWnd, &ps);
        }
        break;

    case WM_ERASEBKGND:
            // The WM_ERASEBKGND message is issued before the 
            // WM_TIMER message, allowing the screen saver to 
            // paint the background as appropriate.
        break;

    case WM_SETCURSOR:
        /**
         * Set the cursor to the null cursor, removing it from the screen.
        */
        break;
    
    /**
     * cases to terminate screensaver
    */

    case WM_LBUTTONDOWN:
        break;
    case WM_MBUTTONDOWN:
        break;
    case WM_RBUTTONDOWN:
        break;
    case WM_KEYDOWN:
        break;
    case WM_MOUSEMOVE:
        break;
    case WM_ACTIVATE:
        break;

    /**
     * end of cases to terminate screensaver
    */

    case WM_DESTROY:
        // Clean up resources
        /**
         * Perform any additional required cleanup.
        */
        KillTimer(hWnd, 1);
        DeleteObject(hFont);
        PostQuitMessage(0);
        break;

    }
/**
 * defscreensaverproc processes any additional messages.
*/
    return DefScreenSaverProc(hWnd, message, wParam, lParam);

    return 0;
}
