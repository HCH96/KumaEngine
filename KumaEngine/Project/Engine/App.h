#pragma once

class CWindow;
class CEngineCore;

class CApp
{
public:
	CApp(HINSTANCE _hInstance);
	~CApp();

	int Run(int _CmdShow);

private:
	HINSTANCE					m_hInstance;
	unique_ptr<CWindow>			m_Window;
	unique_ptr<CEngineCore>		m_Engine;
};

