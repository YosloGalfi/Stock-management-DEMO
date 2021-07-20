// NKT.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "NKT.h"
#include "WindowHandler.h"

//#define MAX_LOADSTRING 100
//enum menuTasks { Info = 1, Inventory = 2, AddItem = 3, Projects = 4, Help = 5};

// Global Variables:
//HINSTANCE hInst;                                // current instance
//WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
//WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
//HMENU hMenu;

// Forward declarations of functions included in this code module:
//ATOM                MyRegisterClass(HINSTANCE hInstance);
//BOOL                InitInstance(HINSTANCE, int);
//LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//void AddMenus(HWND hWnd)
//{
//    hMenu = CreateMenu();
//
//    AppendMenu(hMenu, MF_STRING, menuTasks::Info, L"Info");
//    AppendMenu(hMenu, MF_STRING, menuTasks::Inventory, L"Inventory");
//    AppendMenu(hMenu, MF_STRING, menuTasks::AddItem, L"Add item");
//    AppendMenu(hMenu, MF_STRING, menuTasks::Projects, L"Projects");
//    AppendMenu(hMenu, MF_STRING, menuTasks::Help, L"Help");
//
//    /*
//    * How to add a popup menu to the menu
//    * HMENU hFileMenu = CreateMenu; // Create the extra popup menu
//    * AppendMenu(hFileMenu, MF_STRING, 1, L"New"); // Append the text to the popup menu
//    * AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"File"); // Append the popup menu, so that it will appear when the regular button is clicked
//    */
//    SetMenu(hWnd, hMenu);
//
//}



HINSTANCE hInst; // current instance
//WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
//WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
HMENU menuHandle;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    HWND windowHandle;
    
    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, WindowHandler::szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_NKT, WindowHandler::szWindowClass, MAX_LOADSTRING);
    WindowHandler::MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!WindowHandler::InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_NKT));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//    WNDCLASSEXW wcex;
//
//    wcex.cbSize = sizeof(WNDCLASSEX);
//
//    wcex.style          = CS_HREDRAW | CS_VREDRAW;
//    wcex.lpfnWndProc    = WndProc;
//    wcex.cbClsExtra     = 0;
//    wcex.cbWndExtra     = 0;
//    wcex.hInstance      = hInstance;
//    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_NKT));
//    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
//    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
//    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_NKT);
//    wcex.lpszClassName  = szWindowClass;
//    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//    return RegisterClassExW(&wcex);
//}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//   hInst = hInstance; // Store instance handle in our global variable
//
//   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//   if (!hWnd)
//   {
//      return FALSE;
//   }
//
//   ShowWindow(hWnd, nCmdShow);
//   UpdateWindow(hWnd);
//
//   return TRUE;
//}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    switch (message)
//    {
//    case WM_CREATE:
//        AddMenus(hWnd);
//    case WM_COMMAND:
//        {
//            int wmId = LOWORD(wParam);
//            // Parse the menu selections:
//            switch (wmId)
//            {
//            case menuTasks::Info:
//                MessageBeep(MB_OK);
//                break;
//            case menuTasks::Inventory:
//                MessageBeep(MB_OK);
//                break;
//            case menuTasks::AddItem:
//                MessageBeep(MB_OK);
//                break;
//            case menuTasks::Projects:
//                MessageBeep(MB_OK);
//                break;
//            case menuTasks::Help:
//                MessageBeep(MB_OK);
//                break;
//            case IDM_ABOUT:
//                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//                break;
//            case IDM_EXIT:
//                DestroyWindow(hWnd);
//                break;
//            default:
//                return DefWindowProc(hWnd, message, wParam, lParam);
//            }
//        }
//        break;
//    case WM_PAINT:
//        {
//            PAINTSTRUCT ps;
//            HDC hdc = BeginPaint(hWnd, &ps);
//            // TODO: Add any drawing code that uses hdc here...
//            EndPaint(hWnd, &ps);
//        }
//        break;
//    case WM_DESTROY:
//        PostQuitMessage(0);
//        break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}

// Message handler for about box.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}