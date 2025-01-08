#pragma once

class CWindow;
class CEngineCore;

class CApp
{
public:
	CApp(HINSTANCE _hInstance);
	~CApp();

	void Run(int _CmdShow);

private:
	void Init(int _CmdShow);
	void Tick();
	void Release();

private:
	HINSTANCE					m_hInstance;
	unique_ptr<CWindow>			m_Window;
	unique_ptr<CEngineCore>		m_Engine;
};

