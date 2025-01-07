#include "pch.h"

#include "App.h"
#include "Window.h"
#include "EngineCore.h"

CApp::CApp(HINSTANCE _hInstance)
	: m_hInstance(_hInstance)
{
}

CApp::~CApp()
{
}

HRESULT CApp::Run()
{
	m_Engine = new CEngineCore();
	GEngine = m_Engine;

	m_Window = new CWindow(m_hInstance, L"KumaEngine", L"KumaEngine");
	m_Window->Create(1280, 720, SW_SHOW);
	m_Window->Update();

	return S_OK;
}
