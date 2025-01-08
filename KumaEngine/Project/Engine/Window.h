#pragma once

class CWindow
{
public:
	CWindow(HINSTANCE _hInstance, const wstring& _ClassName, const wstring& _Title);
	~CWindow();

	bool Create(int _Width, int _Height, int _CmdShow);

	HWND GetHandle() const;
	Vec2 GetResolution() const;

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	void Show(int _CmdShow);
	void RegisterWndClass();
	void AdjustWindowSize();
	void SetWindowPos(Vec2 _Pos);

private:
	HINSTANCE	m_hInstance;
	HWND		m_hWnd;
	wstring		m_ClassName;
	wstring		m_Title;
	Vec2		m_Resolution;
};

