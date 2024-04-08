
#pragma once
/**
 * important functions
 * 01.  DefWindowProc
 * 02.  ScreenSaverProc
 * 03.  ScreenSaverConfigureDialog
 * 04.  RegisterDialogClasses
*/

// #include <Windows.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include <scrnsave.h>
#include <wchar.h>
#include "settings/res.hpp"

// inline char* WideCharToChar(const wchar_t* wideStr);

// function declarations
LRESULT ScreenSaverProc(
    HWND   hWnd,              /*identifier of window*/
    UINT   message,           /*message to window*/
    WPARAM wParam,            /*additional message specific info*/
    LPARAM lParam             /*additional message specifie info*/
);

LRESULT DefScreenSaverProc(
    HWND   hWnd,                  /**/
    UINT   msg,                   /**/
    WPARAM wParam,                /**/
    LPARAM lParam                 /**/
);

BOOL WINAPI ScreenSaverConfigureDialog(
    HWND   hDlg,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
);

// LRESULT ScreenSaverProc(
//     HWND   hWnd,
//     UINT   message,
//     WPARAM wParam,
//     LPARAM lParam
// );

BOOL WINAPI RegisterDialogClasses(
    HANDLE hInst
);


INT_PTR CALLBACK DialogProc(
    HWND hwnd, 
    UINT message, 
    WPARAM wParam, 
    LPARAM lParam
);


/**
 * helper functions
*/

// char* WideCharToChar(const wchar_t* wideStr)
// {
//     int size = WideCharToMultiByte(CP_UTF8, 0, wideStr, -1, NULL, 0, NULL, NULL);
//     char* buffer = new char[size];
//     WideCharToMultiByte(CP_UTF8, 0, wideStr, -1, buffer, size, NULL, NULL);
//     return buffer;
// }