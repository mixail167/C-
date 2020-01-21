#include <windows.h>
#include "resource.h"
#include <CommCtrl.h>

HWND hEdit1;
HWND hEdit2;
HWND hComboBox;
HWND hListBox;
HINSTANCE hInst;
HWND hNoModal;
HWND hProgress;
DWORD IDC_TIMER;
DWORD nCounter;
HWND hTrackBar;

HBITMAP hBMP = NULL;
HWND hPic = NULL;

CHAR s_text_1[] = { "Any" };
CHAR s_text_2[] = { 0 };


BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc1(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK DlgProc2(HWND, UINT, WPARAM, LPARAM);
HWND WINAPI CreateTrackBar(HWND, UINT, UINT, UINT, UINT);

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrebInst, LPSTR lpCmdLine, int nCmdShow)
{
	DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, DlgProc, 0);
	return 0;
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon1 = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 1, (LPARAM)hIcon1);

		hEdit1 = GetDlgItem(hwnd, IDC_EDIT1);
		hEdit2 = GetDlgItem(hwnd, IDC_EDIT2);
		hComboBox = GetDlgItem(hwnd, IDC_COMBO1);

		//SendMessage(hEdit1, WM_SETTEXT, 0, (LPARAM)s_text_1);
		//SetWindowText(hEdit1, s_text_1);
		SetDlgItemText(hwnd, IDC_EDIT1, s_text_1);
		SetFocus(hEdit1);

		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)s_text_1);
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)"номер 1");
		SendMessage(hComboBox, CB_ADDSTRING, 0, (LPARAM)"номер 2");
		SendMessage(hComboBox, CB_SETCURSEL, 0, 0);

		hListBox = GetDlgItem(hwnd, IDC_LIST1);
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)s_text_1);
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)"номер 1");
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)"номер 2");
		SendMessage(hListBox, LB_SETCURSEL, 1, 0);

		hInst = GetModuleHandle(NULL);

		hProgress = CreateWindowEx(0, PROGRESS_CLASS, (LPSTR)NULL, WS_CHILD | WS_VISIBLE | PBS_SMOOTH, 20, 280, 200, 15, hwnd, (HMENU)0, hInst, NULL);
		SendMessage(hProgress, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
		SendMessage(hProgress, PBM_SETSTEP, (WPARAM)10, 0);
		nCounter = 0;
		SetTimer(hwnd, IDC_TIMER, 100, 0);
	}
	break;
	case WM_TIMER:
	{
		nCounter++;
		SendMessage(hProgress, PBM_STEPIT, 0, 0);
		if (nCounter == 10)
		{
			KillTimer(hwnd, IDC_TIMER);
		}

	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDOK:
		{
			typedef UINT(*MYFUNC)(UINT, UINT);
			HMODULE hLib = LoadLibrary("Project2.dll");
			if (hLib == NULL)
			{
				MessageBox(hwnd, "Не могу загрузить DLL", "ERROR", NULL);
			}
			else
			{
				MYFUNC summa = (MYFUNC)GetProcAddress(hLib, "Summa");
				UINT x = summa(7, 5);
				char buf[10];
				_itoa_s(x, buf, 10);
				MessageBox(hwnd, buf, "INFO", MB_OK | MB_ICONINFORMATION);
			}
		}
		break;
		case IDCANCEL:
			EndDialog(hwnd, 0);
			return FALSE;
		case IDC_COPY:
			//SendMessage(hEdit1, WM_GETTEXT, (WPARAM)255, (LPARAM)s_text_2);
			//SendMessage(hEdit2, WM_SETTEXT, 0, (LPARAM)s_text_2);
			//GetWindowText(hEdit1, s_text_2, 255);
			//SetWindowText(hEdit2, s_text_2);
			GetDlgItemText(hwnd, IDC_EDIT1, s_text_2, 255);
			SetDlgItemText(hwnd, IDC_EDIT2, s_text_2);
			break;
		case IDC_COMBO1:
		{
			if (HIWORD(wParam) == CBN_SELENDOK)
			{
				CHAR str1[255];
				int i = SendMessage(hComboBox, CB_GETCURSEL, 0, 0);
				SendMessage(hComboBox, CB_GETLBTEXT, i, (LPARAM)str1);
				MessageBox(hwnd, str1, "INFO", NULL);
			}
		}
		break;
		case IDC_LIST1:
		{
			if (HIWORD(wParam) == LBN_DBLCLK)
			{
				CHAR str_2[255];
				int i = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
				SendMessage(hListBox, LB_GETTEXT, i, (LPARAM)str_2);
				MessageBox(hwnd, str_2, "INFO", NULL);
			}
		}
		break;
		case IDC_MODAL:
		{
			DialogBoxParam(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hwnd, DlgProc1, 0);
		}
		break;
		case IDC_MODAL2:
		{
			hNoModal = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG3), 0, DlgProc2);
			ShowWindow(hNoModal, SW_SHOW);
		}
		break;
		}
		break;
	case WM_CTLCOLORSTATIC:
	{
		if ((HWND)lParam == GetDlgItem(hwnd, IDC_STATIC1))
		{
			HDC hdc = (HDC)wParam;
			SetBkMode(hdc, TRANSPARENT);
			SetTextColor(hdc, RGB(0, 0, 178));
			return (int)GetStockObject(NULL_BRUSH);
		}
	}
	break;
	case WM_CTLCOLOREDIT:
	{
		if ((HWND)lParam == GetDlgItem(hwnd, IDC_EDIT2))
		{
			HDC hdc = (HDC)wParam;
			SetBkMode(hdc, OPAQUE);
			SetBkColor(hdc, RGB(240, 230, 140));
			HBRUSH hBrushColor = CreateSolidBrush(RGB(0, 0, 255));
			SetTextColor(hdc, RGB(178, 0, 0));
			return (LRESULT)hBrushColor;
		}
	}
	break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return TRUE;
	}
	return FALSE;
}
BOOL CALLBACK DlgProc1(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		CreateTrackBar(hwnd, 0, 100, 10, 50);
		HICON hIcon1 = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 1, (LPARAM)hIcon1);
	}
	hBMP = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	hPic = GetDlgItem(hwnd, IDC_PIC);
	break;
	case WM_PAINT:
	{
		BITMAP bmp;
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hPic, &ps);
		HDC hdcMem = CreateCompatibleDC(hdc);
		HGDIOBJ hbmOld = SelectObject(hdcMem, hBMP);
		GetObject(hBMP, sizeof(bmp), &bmp);
		BitBlt(hdc, 0, 0, bmp.bmWidth, bmp.bmHeight, hdcMem, 0, 0, SRCCOPY);
		SelectObject(hdcMem, hbmOld);
		DeleteDC(hdcMem);
		EndPaint(hPic, &ps);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_OK:
		{
			char buf[10];
			int num = SendMessage(hTrackBar, TBM_GETPOS, 0, 0);
			_itoa_s(num, buf, 10);
			MessageBox(NULL, buf, "Позиция", MB_OK);
			break;
		}
		break;
		case IDC_CANCEL:
			EndDialog(hwnd, 0);
			return TRUE;
		}
		break;
	case WM_CLOSE:
		EndDialog(hwnd, 0);
		return TRUE;
	}
	return FALSE;
}

BOOL CALLBACK DlgProc2(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		HICON hIcon1 = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));
		SendMessage(hwnd, WM_SETICON, 1, (LPARAM)hIcon1);
	}
	break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_OK:
			break;
		case IDC_CANCEL2:
			DestroyWindow(hwnd);
			return TRUE;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		return TRUE;
	}
	return FALSE;
}

HWND WINAPI CreateTrackBar(HWND hwnd, UINT iMin, UINT iMax, UINT iSelMin, UINT iSelMax)
{
	hTrackBar = CreateWindowEx(0, TRACKBAR_CLASS, "TrackBar Control", WS_CHILD | WS_VISIBLE | TBS_AUTOTICKS | TBS_ENABLESELRANGE, 10, 180, 300, 30, hwnd, NULL, hInst, NULL);
	SendMessage(hTrackBar, TBM_SETRANGE, (WPARAM)TRUE, (LPARAM)MAKELONG(iMin, iMax));
	SendMessage(hTrackBar, TBM_SETPAGESIZE, 0, (LPARAM)5);
	SendMessage(hTrackBar, TBM_SETSEL, (WPARAM)FALSE, (LPARAM)MAKELONG(iSelMin, iSelMax));
	SetFocus(hTrackBar);
	return hTrackBar;
}
