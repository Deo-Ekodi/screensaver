
#pragma once
/**
 * important functions
 * 01.  DefWindowProc
 * 02.  ScreenSaverProc
 * 03.  ScreenSaverConfigureDialog
 * 04.  RegisterDialogClasses
*/

#include <windows.h>
#include <time.h>
#include <string>
#include "settings/settings.rc"


// global variables
int g_setting1 = 0;
bool g_setting2 = false;


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