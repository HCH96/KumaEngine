#pragma once

class CWindow
{
public:
	CWindow(HINSTANCE _hInstance, const wstring& _ClassName, const wstring& _Title);
	~CWindow();

	bool Create(int _Width, int _Height, int _CmdShow);
	int  Tick();

	HWND GetHandle() const;

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	void Show(int _CmdShow);
	void RegisterWndClass();

private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	wstring m_ClassName;
	wstring m_Title;

};

