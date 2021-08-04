// NKT.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "NKT.h"
//#include "WindowHandler.h"

#include <QtWidgets/qpushbutton.h>
#include <QtCore/qobject.h>
#include <QtCore/qcoreapplication.h>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qframe.h>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qtablewidget.h>
#include <QtWidgets/qheaderview.h>
#include <QtWidgets/qlabel.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qstring.h>
#include <QtCore/qcontainerfwd.h>

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

//QCoreApplication* createApplication(int& argc, char* argv[])
//{
//	for (int i = 1; i < argc; i++)
//	{
//		if (!qstrcmp(argv[i], "-no-gui"))
//			return new QCoreApplication(argc, argv);
//	}
//
//	return new QApplication(argc, argv);
//}

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	QString text("Hello there");

	QWidget mainWindow;

	mainWindow.resize(960, 540);
	mainWindow.setWindowTitle("NKT inventory");
	mainWindow.setObjectName("NKT");
	app.setActiveWindow(&mainWindow);

	QFrame topFrame(&mainWindow);
	topFrame.setFrameShape(QFrame::Shape::Panel);
	topFrame.setFrameShadow(QFrame::Shadow::Raised);
	topFrame.setLineWidth(3);
	topFrame.setGeometry(0, 0, 960, 30);

	QPushButton inventoryButton(static_cast<QWidget*>(&topFrame));
	inventoryButton.setText("Inventory");
	inventoryButton.setGeometry(10, 5, 160, 20);

	QPushButton projectsButton(static_cast<QWidget*>(&topFrame));
	projectsButton.setText("Projects");
	projectsButton.setGeometry(180, 5, 160, 20);

	QPushButton graphicsButton(static_cast<QWidget*>(&topFrame));
	graphicsButton.setText("Graphical view");
	graphicsButton.setGeometry(350, 5, 160, 20);

	QTableWidget itemList(&mainWindow);
	itemList.setGeometry(10, 50, 780, 460);
	itemList.setFrameShape(QFrame::Shape::Panel);
	itemList.setFrameShadow(QFrame::Shadow::Sunken);
	itemList.setLineWidth(5);
	itemList.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	itemList.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
	itemList.setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
	itemList.setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
	itemList.setRowCount(10);
	itemList.setColumnCount(5);

	// ERROR HÄR...
	// UNRESOLVED EXTERNALS
	QStringList labels = { "Name", "Location", "Amount", "Serial number" };
	//labels.append("Name");
	
	//labels.append("Location");
	//labels.append("Amount");
	//labels.append("Serial number");

	itemList.setHorizontalHeaderLabels(labels);

	//QHeaderView defaultView(Qt::Orientation::Horizontal, &itemList);
	//
	//itemList.setHorizontalHeader(&defaultView);

	QTableWidgetItem temp("Bottenplatta");
	itemList.setItem(0, 0, &temp);
	

	//itemList.addItem("First item");
	//itemList.addItem("Second item");

	mainWindow.show();

	return app.exec();
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	char* argv['0'];
	main(0, argv);
}

//HINSTANCE hInst; // current instance
////WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
////WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
//HMENU menuHandle;
//
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//                     _In_opt_ HINSTANCE hPrevInstance,
//                     _In_ LPWSTR    lpCmdLine,
//                     _In_ int       nCmdShow)
//{
//    UNREFERENCED_PARAMETER(hPrevInstance);
//    UNREFERENCED_PARAMETER(lpCmdLine);
//
//    HWND windowHandle;
//    
//    // TODO: Place code here.
//
//    // Initialize global strings
//    LoadStringW(hInstance, IDS_APP_TITLE, WindowHandler::szTitle, MAX_LOADSTRING);
//    LoadStringW(hInstance, IDC_NKT, WindowHandler::szWindowClass, MAX_LOADSTRING);
//    WindowHandler::MyRegisterClass(hInstance);
//
//    // Perform application initialization:
//    if (!WindowHandler::InitInstance (hInstance, nCmdShow))
//    {
//        return FALSE;
//    }
//
//    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_NKT));
//
//    MSG msg;
//
//    // Main message loop:
//    while (GetMessage(&msg, nullptr, 0, 0))
//    {
//        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//        {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//    }
//
//    return (int) msg.wParam;
//}



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
