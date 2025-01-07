#include "pch.h"

// Engine
#ifdef _DEBUG
#pragma comment(lib, "Engine\\Engine_d.lib")
#else
#pragma comment(lib, "Engine\\Engine.lib")
#endif

#include "Client.h"

#include <Engine/App.h>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    CApp KumaEngine(hInstance);
    KumaEngine.Run();
    
    return 0;
}
