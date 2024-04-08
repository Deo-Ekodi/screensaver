#include "src.hpp"

// Dialog procedure function
INT_PTR CALLBACK DialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HFONT hFont = NULL;
    switch (message)
    {
    case WM_INITDIALOG:
        // Initialize dialog controls or data
        return TRUE; // Return TRUE to set the focus to the first control
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case IDC_BROWSE_BUTTON:
            /**
             * select font
            */
            CHOOSEFONT cf;
            LOGFONTA lf;
            ZeroMemory(&cf, sizeof(CHOOSEFONT));
            ZeroMemory(&lf, sizeof(LOGFONT));
            cf.lStructSize = sizeof(CHOOSEFONT);
            cf.hwndOwner = hwnd;
            cf.lpLogFont = &lf;
            cf.Flags = CF_SCREENFONTS | CF_EFFECTS;
            if (ChooseFont(&cf))
            {
                // Font selected, apply it to the controls
                hFont = CreateFontIndirect(&lf);
                /**
                 * replace IDC_STATIC_TEXT with exact ID to change font
                */
                SendMessage(GetDlgItem(hwnd, IDC_SELECTED_FILE_EDIT), WM_SETFONT, (WPARAM)hFont, TRUE);
            }
            break;
        case IDC_SELECTED_FILE_EDIT:
            /**
             * enter text & send to display
            */
            break;
        case IDC_PHOTO_RADIO:
            /**
             * select photo and send to background
            */
            break;
        case IDC_VIDEO_RADIO:
            /**
             * select video and use as background
            */
            break;
        case IDC_SLIDESHOW_RADIO:
            /**
             * select images from directory and use as background
            */
            break;
        case IDC_STATIC:
            /**
             * ...
            */
            break;
        case IDC_WEATHER_PARAM:
            /**
             * check to insert weather to screen
            */
            break;
        case IDC_TEMPERATURE_PARAM:
            /**
             * check to insert temperature to screen
            */
            break;
        case IDC_PREVIEW_BUTTON:
            // Handle Preview button click to display preview of the selected file
            break;
        case IDOK:
            // Handle OK button click
            EndDialog(hwnd, IDOK);
            return TRUE;
        case IDCANCEL:
            // Handle Cancel button click
            EndDialog(hwnd, IDCANCEL);
            return TRUE;

        }
        break;
    case WM_CLOSE:
        // Handle dialog close event
        EndDialog(hwnd, IDCANCEL);
        return TRUE;
    }
    return FALSE; // Return FALSE for messages not processed
}
