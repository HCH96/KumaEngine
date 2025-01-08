#include "pch.h"

#include "App.h"
#include "Window.h"
#include "EngineCore.h"

CApp::CApp(HINSTANCE _hInstance)
	: m_hInstance(_hInstance)
{
	m_Engine = make_unique<CEngineCore>();
	m_Window = make_unique<CWindow>(_hInstance, L"KumaEngine", L"KumaEngine");

	GEngine = m_Engine.get();
	GWindow = m_Window.get();
}

CApp::~CApp()
{
	GEngine = nullptr;
	GWindow = nullptr;
}

int CApp::Run(int _CmdShow)
{
	if (m_Window->Create(1280, 720, _CmdShow))
	{
		return m_Window->Tick();
	}
	
	return FALSE;
}
