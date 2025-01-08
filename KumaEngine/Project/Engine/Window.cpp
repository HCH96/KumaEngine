#include "pch.h"
#include "Window.h"

CWindow::CWindow(HINSTANCE _hInstance, const wstring& _ClassName, const wstring& _Title)
    : m_hInstance(_hInstance), m_ClassName(_ClassName), m_Title(_Title), m_hWnd(nullptr) 
{
    RegisterWndClass();
}

CWindow::~CWindow() {
    UnregisterClassW(m_ClassName.c_str(), m_hInstance);
}


void CWindow::RegisterWndClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WindowProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = m_hInstance;
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszClassName = m_ClassName.c_str();
    
    wcex.lpszMenuName = nullptr;
    wcex.hIcon = nullptr;
    wcex.hIconSm = nullptr;

    RegisterClassExW(&wcex);
}

bool CWindow::Create(int _Width, int _Height, int _CmdShow) 
{
    m_hWnd = CreateWindowW(
        m_ClassName.c_str(), m_Title.c_str(),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        _Width, _Height,
        nullptr, nullptr, m_hInstance, nullptr
    );

    if (!m_hWnd)
    {
        return false;
    }

    Show(_CmdShow);

    return true;
}

void CWindow::Show(int _CmdShow) 
{
    ShowWindow(m_hWnd, _CmdShow);
    UpdateWindow(m_hWnd);
}

int CWindow::Tick()
{
    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

HWND CWindow::GetHandle() const 
{
    return m_hWnd;
}


LRESULT CALLBACK CWindow::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}