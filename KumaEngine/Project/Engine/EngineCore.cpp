#include "pch.h"
#include "EngineCore.h"

#include "Device.h"

CEngineCore::CEngineCore()
{
	m_Device = make_unique<CDevice>();

	GDevice = m_Device.get();
}

CEngineCore::~CEngineCore()
{
	GDevice = nullptr;
}

int CEngineCore::Init()
{
	if (FAILED(m_Device->Init()))
	{
		MessageBox(nullptr, L"Device �ʱ�ȭ ����", L"�ʱ�ȭ ����", MB_OK);
		return E_FAIL;
	}

	return S_OK;
}

void CEngineCore::Tick()
{
	float ClearColor[4] = { 0.3f, 0.3f, 0.3f, 1.f };
	m_Device->ClearRenderTarget(ClearColor);


	m_Device->Present();
}
