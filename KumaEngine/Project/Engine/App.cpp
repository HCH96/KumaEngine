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

void CApp::Run(int _CmdShow)
{
	Init(_CmdShow);
	Tick();
	Release();
}

void CApp::Init(int _CmdShow)
{
	m_Window->Create(1280, 720, _CmdShow);
}

void CApp::Tick()
{
	MSG msg;

	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			GEngine->Tick();
		}
	}
}

void CApp::Release()
{
}
