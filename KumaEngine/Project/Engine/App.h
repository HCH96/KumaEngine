#pragma once

class CWindow;
class CEngineCore;

class CApp
{
public:
	CApp(HINSTANCE _hInstance);
	~CApp();

	HRESULT Run();

private:
	HINSTANCE m_hInstance;
	CWindow* m_Window;
	CEngineCore* m_Engine;
};

