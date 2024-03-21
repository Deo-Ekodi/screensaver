#include "src.hpp"

BOOL CALLBACK SettingsDialogProc(
    HWND hwnd,
    UINT message, 
    WPARAM wParam, 
    LPARAM lParam
)
{
    switch (message)
    {
        case WM_INITDIALOG:
            // Initialize dialog controls with current settings values
            // For example: SetDlgItemInt(hwnd, IDC_SETTING1_EDIT, g_setting1, FALSE);
            //               CheckDlgButton(hwnd, IDC_SETTING2_CHECK, g_setting2 ? BST_CHECKED : BST_UNCHECKED);
            return TRUE;

        case WM_COMMAND:
            switch (LOWORD(wParam))
            {
                case IDOK:
                    // Retrieve settings values from dialog controls and update global variables
                    // For example: g_setting1 = GetDlgItemInt(hwnd, IDC_SETTING1_EDIT, NULL, FALSE);
                    //               g_setting2 = IsDlgButtonChecked(hwnd, IDC_SETTING2_CHECK) == BST_CHECKED;
                    EndDialog(hwnd, TRUE);
                    return TRUE;

                case IDCANCEL:
                    EndDialog(hwnd, FALSE);
                    return TRUE;
            }
            break;
    }
    return FALSE;
}