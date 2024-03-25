
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
#include "settings/res.hpp"

// Define resource identifiers
// #define IDD_SETTINGS_DIALOG  101
// #define IDC_BROWSE_BUTTON    102
// #define IDC_SELECTED_FILE_EDIT 103
// #define IDC_PREVIEW_BUTTON   104
// #define IDC_PHOTO_RADIO      105
// #define IDC_VIDEO_RADIO      106
// #define IDC_SLIDESHOW_RADIO  107

// global variables
// int g_setting1 = 0;
// bool g_setting2 = false;


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

BOOL ScreenSaverConfigureDialog(
    HWND   hDlg,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
);

LRESULT ScreenSaverProc(
    HWND   hWnd,
    UINT   message,
    WPARAM wParam,
    LPARAM lParam
);

BOOL WINAPI RegisterDialogClasses(
    HANDLE hInst
);



/*settings*/
// dialog procedure for settings function
BOOL CALLBACK SettingsDialogProc(
    HWND hwnd, 
    UINT message, 
    WPARAM wParam, 
    LPARAM lParam
);

INT_PTR CALLBACK DialogProc(
    HWND hwnd, 
    UINT message, 
    WPARAM wParam, 
    LPARAM lParam
);


