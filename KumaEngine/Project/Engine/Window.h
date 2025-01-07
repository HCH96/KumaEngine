#pragma once

class CWindow
{
public:
	CWindow(HINSTANCE _hInstance, const wstring& _ClassName, const wstring& Title);
	~CWindow();

	bool Create(int Width, int Height, int CmdShow);
	void Show(int CmdShow);
	void Update();

	HWND GetHandle() const;

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	void RegisterWndClass();

private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	wstring m_ClassName;
	wstring m_Title;

};

