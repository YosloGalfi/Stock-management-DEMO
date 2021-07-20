#pragma once

#include "framework.h"
#include "Resource.h"

#define MAX_LOADSTRING 100

namespace WindowHandler
{
	enum menuTasks { Info = 1, Inventory = 2, AddItem = 3, Projects = 4, Help = 5 };

    static WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
    static WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

    void AddMenus(HWND windowHandle, HMENU menuHandler)
    {
        menuHandle = CreateMenu();

        AppendMenu(menuHandle, MF_STRING, menuTasks::Info, L"Info");
        AppendMenu(menuHandle, MF_STRING, menuTasks::Inventory, L"Inventory");
        AppendMenu(menuHandle, MF_STRING, menuTasks::AddItem, L"Add item");
        AppendMenu(menuHandle, MF_STRING, menuTasks::Projects, L"Projects");
        AppendMenu(menuHandle, MF_STRING, menuTasks::Help, L"Help");

        SetMenu(windowHandle, menuHandle);
    }

    INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
    {
        UNREFERENCED_PARAMETER(lParam);
        switch (message)
        {
        case WM_INITDIALOG:
            return (INT_PTR)TRUE;

        case WM_COMMAND:
            if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
            {
                EndDialog(hDlg, LOWORD(wParam));
                return (INT_PTR)TRUE;
            }
            break;
        }
        return (INT_PTR)FALSE;
    }

	LRESULT CALLBACK    WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, HMENU hMenu) 
	{
        switch (message)
        {
        case WM_CREATE:
            AddMenus(hWnd, hMenu);
        case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case menuTasks::Info:
                MessageBeep(MB_OK);
                break;
            case menuTasks::Inventory:
                MessageBeep(MB_OK);
                break;
            case menuTasks::AddItem:
                MessageBeep(MB_OK);
                break;
            case menuTasks::Projects:
                MessageBeep(MB_OK);
                break;
            case menuTasks::Help:
                MessageBeep(MB_OK);
                break;
                case IDM_ABOUT:
                    DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                    break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        return 0;
	}

    ATOM MyRegisterClass(HINSTANCE hInstance)
    {
        WNDCLASSEXW wcex;

        wcex.cbSize = sizeof(WNDCLASSEX);

        wcex.style = CS_HREDRAW | CS_VREDRAW;
        wcex.lpfnWndProc = WndProc;
        wcex.cbClsExtra = 0;
        wcex.cbWndExtra = 0;
        wcex.hInstance = hInstance;
        wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_NKT));
        wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
        wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_NKT);
        wcex.lpszClassName = szWindowClass;
        wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

        return RegisterClassExW(&wcex);
    }

    BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
    {
        hInst = hInstance; // Store instance handle in our global variable

        HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

        if (!hWnd)
        {
            return FALSE;
        }

        ShowWindow(hWnd, nCmdShow);
        UpdateWindow(hWnd);

        return TRUE;
    }

	void AddControllers();

}
