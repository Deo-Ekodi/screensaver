#include "src.hpp"

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
    static TCHAR szDate[64];
    static SYSTEMTIME sysTime;
    static time_t t;
    static struct tm * timeinfo;

    switch (message)
    {
    case WM_CREATE:
        // Create a font for the clock
        hFont = CreateFont(40, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                           CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
        SetTimer(hWnd, 1, 1000, NULL); // Set a timer to update the clock every second
        break;

    case WM_TIMER:
        // Get the system time and format it as a string
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

    case WM_DESTROY:
        // Clean up resources
        KillTimer(hWnd, 1);
        DeleteObject(hFont);
        PostQuitMessage(0);
        break;

    default:
        return DefScreenSaverProc(hWnd, message, wParam, lParam);
    }

    return 0;
}
