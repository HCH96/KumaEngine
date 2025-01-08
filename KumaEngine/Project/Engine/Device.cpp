#include "pch.h"
#include "Device.h"

#include "Window.h"

CDevice::CDevice()
	: m_Device(nullptr)
	, m_Context(nullptr)
	, m_SwapChain(nullptr)
	, m_RTTex(nullptr)
	, m_RTView(nullptr)
	, m_DSTex(nullptr)
	, m_DSView(nullptr)
{
}

CDevice::~CDevice()
{

}

int CDevice::Init()
{
	// Device 초기화
	UINT CreateDeviceFlags = 0;
#if defined(_DEBUG)
	CreateDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	const D3D_FEATURE_LEVEL FeatureLevels[2] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_9_3 };
	D3D_FEATURE_LEVEL FeatureLevel;

	D3D_FEATURE_LEVEL eLevel = D3D_FEATURE_LEVEL_11_0;

	if (FAILED(D3D11CreateDevice( nullptr
								, D3D_DRIVER_TYPE_HARDWARE, nullptr
								, CreateDeviceFlags
								, FeatureLevels, ARRAYSIZE(FeatureLevels), D3D11_SDK_VERSION
								, m_Device.GetAddressOf(), &FeatureLevel, m_Context.GetAddressOf())))
	{
		MessageBox(nullptr, L"Device, Context 생성 실패", L"Device 초기화 실패", MB_OK);
		return E_FAIL;
	}

	// SwapChain 생성 
	if (FAILED(CreateSwapChain()))
	{
		MessageBox(nullptr, L"SwapChain 생성 실패", L"Device 초기화 실패", MB_OK);
		return E_FAIL;
	}

	// 렌더타겟, 렌더타겟 뷰, 뎁스스텐실 타겟, 뎁스 스텐실 뷰 생성
	if (FAILED(CreateTargetView()))
	{
		MessageBox(nullptr, L"타겟 및 View 생성 실패", L"Device 초기화 실패", MB_OK);
		return E_FAIL;
	}

	SetViewport(GWindow->GetResolution().x, GWindow->GetResolution().y);

	return S_OK;
}

void CDevice::ClearRenderTarget(float(&Color)[4])
{
	m_Context->ClearRenderTargetView(m_RTView.Get(), Color);
	m_Context->ClearDepthStencilView(m_DSView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.f, 0);
}

void CDevice::Present()
{
	m_SwapChain->Present(0, 0);
}

void CDevice::SetViewport(float _Width, float _Height)
{
	D3D11_VIEWPORT ViewportDesc = {};

	ViewportDesc.MinDepth = 0;
	ViewportDesc.MaxDepth = 1.f;

	ViewportDesc.TopLeftX = 0;
	ViewportDesc.TopLeftY = 0;
	ViewportDesc.Width = _Width;
	ViewportDesc.Height = _Height;

	m_Context->RSSetViewports(1, &ViewportDesc);
}

int CDevice::CreateSwapChain()
{
	// SwapChain 생성 구조체
	DXGI_SWAP_CHAIN_DESC tDesc = {};

	// SwapChain 이 관리하는 Buffer(RenderTarget) 의 구성 정보
	tDesc.BufferCount = 1;
	tDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	tDesc.BufferDesc.Width = (UINT)GWindow->GetResolution().x;
	tDesc.BufferDesc.Height = (UINT)GWindow->GetResolution().y;
	tDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	tDesc.BufferDesc.RefreshRate.Denominator = 1;
	tDesc.BufferDesc.RefreshRate.Numerator = 60;
	tDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	tDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	tDesc.Flags = 0;

	tDesc.SampleDesc.Count = 1;
	tDesc.SampleDesc.Quality = 0;

	tDesc.Windowed = true; // 창모드
	tDesc.OutputWindow = GWindow->GetHandle(); // SwapChain 의 출력 윈도우 지정


	// 스왚체인 생성기능을 가지고 있는 Factory 에 접근한다.
	ComPtr<IDXGIDevice>		pIdxgiDevice = nullptr;
	ComPtr<IDXGIAdapter>	pAdapter = nullptr;
	ComPtr<IDXGIFactory>	pFactory = nullptr;

	m_Device->QueryInterface(__uuidof(IDXGIDevice), (void**)pIdxgiDevice.GetAddressOf());
	pIdxgiDevice->GetParent(__uuidof(IDXGIAdapter), (void**)pAdapter.GetAddressOf());
	pAdapter->GetParent(__uuidof(IDXGIFactory), (void**)pFactory.GetAddressOf());

	// SwapChain 생성
	if (FAILED(pFactory->CreateSwapChain(m_Device.Get(), &tDesc, m_SwapChain.GetAddressOf())))
	{
		return E_FAIL;
	}

	return S_OK;
}

int CDevice::CreateTargetView()
{
	// 렌더타겟 텍스쳐를 스왚체인으로부터 얻어온다.
	m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)m_RTTex.GetAddressOf());

	// RenderTargetView
	m_Device->CreateRenderTargetView(m_RTTex.Get(), nullptr, m_RTView.GetAddressOf());

	// DepthStencilTexture 생성
	D3D11_TEXTURE2D_DESC Desc = {};

	// 픽셀 포맷은 Depth 3바이트 Stencil 1바이트
	Desc.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;

	// DepthStencilState 텍스쳐 해상도는 반드시 RenderTargetTexture 와 동일해야한다.
	Desc.Width = (UINT)GWindow->GetResolution().x;
	Desc.Height = (UINT)GWindow->GetResolution().y;

	// DepthStencil 용도의 텍스쳐
	Desc.BindFlags = D3D11_BIND_DEPTH_STENCIL;

	// CPU 접근 불가
	Desc.CPUAccessFlags = 0;
	Desc.Usage = D3D11_USAGE_DEFAULT;

	// 샘플링
	Desc.SampleDesc.Count = 1;
	Desc.SampleDesc.Quality = 0;

	// 저퀄리티 버전의 사본 생성여부
	Desc.MipLevels = 1;
	Desc.MiscFlags = 0;

	Desc.ArraySize = 1;

	if (FAILED(m_Device->CreateTexture2D(&Desc, nullptr, m_DSTex.GetAddressOf())))
	{
		return E_FAIL;
	}

	// DepthStencilView
	m_Device->CreateDepthStencilView(m_DSTex.Get(), nullptr, m_DSView.GetAddressOf());

	// OM(Output Merge State) 에 RenderTargetTexture 와 DepthStencilTexture 를 전달한다.
	m_Context->OMSetRenderTargets(1, m_RTView.GetAddressOf(), m_DSView.Get());

	return S_OK;
}

