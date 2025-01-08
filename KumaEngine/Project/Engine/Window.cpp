#include "pch.h"
#include "Window.h"

#include <dwmapi.h>

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

void CWindow::AdjustWindowSize()
{
    RECT rt = { 0,0,(int)m_Resolution.x, (int)m_Resolution.y };
    SetMenu(m_hWnd, nullptr);
    AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
}

void CWindow::SetWindowPos(Vec2 _pos)
{
    RECT rt;
    GetWindowRect(m_hWnd, &rt);
    ::SetWindowPos(m_hWnd, nullptr, (int)_pos.x, (int)_pos.y, (int)rt.right - (int)rt.left, (int)rt.bottom - (int)rt.top, 0);
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

    m_Resolution = Vec2(_Width, _Height);

    if (!m_hWnd)
    {
        return false;
    }

    // TitleBar Drak Mode
    BOOL USE_DARK_MODE = true;
    DwmSetWindowAttribute(m_hWnd, DWMWINDOWATTRIBUTE::DWMWA_USE_IMMERSIVE_DARK_MODE, &USE_DARK_MODE, sizeof(USE_DARK_MODE));


    Show(_CmdShow);
    AdjustWindowSize();
    SetWindowPos(Vec2(50, 50));

    return true;
}

void CWindow::Show(int _CmdShow) 
{
    ShowWindow(m_hWnd, _CmdShow);
    UpdateWindow(m_hWnd);
}


HWND CWindow::GetHandle() const 
{
    return m_hWnd;
}

Vec2 CWindow::GetResolution() const
{
    return m_Resolution;
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