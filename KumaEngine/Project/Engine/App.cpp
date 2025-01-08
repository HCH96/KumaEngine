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
	// 메모리 누수 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(231);

	// Window 생성
	m_Window->Create(1280, 720, _CmdShow);

	// Engine 초기화
	m_Engine->Init();
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
