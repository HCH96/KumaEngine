#pragma once

class CDevice
{
public:
	CDevice();
	~CDevice();

public:
    int Init();
	void ClearRenderTarget(float(&Color)[4]);
	void Present();

	void SetViewport(float _Width, float _Height);

	ID3D11Device* GetDevice() const { return m_Device.Get(); }
	ID3D11DeviceContext* GetContext() const { return m_Context.Get(); }

private:
    int CreateSwapChain();
	int CreateTargetView();

    //int CreateBuffer();
    //int CreateRasterizerState();
    //int CreateDepthStencilState();
    //int CreateBlendState();
    //int CreateConstBuffer();
    //int CreateSamplerState();

private:
	ComPtr<ID3D11Device>			m_Device;	// GPU 메모리 관리, 객체 생성
	ComPtr<ID3D11DeviceContext>		m_Context;	// GPU 렌더링 명령 

	ComPtr<IDXGISwapChain>			m_SwapChain; // 스왚체인(출력 버퍼 지정)

	//ComPtr<ID3D11RasterizerState> m_arrRS[(UINT)RS_TYPE::END];   // 레스터라이저
	//ComPtr<ID3D11DepthStencilState> m_arrDS[(UINT)DS_TYPE::END]; // 깊이스탠실
	//ComPtr<ID3D11BlendState> m_arrBS[(UINT)BS_TYPE::END];        // 블랜드

	//ComPtr<ID3D11SamplerState> m_arrSS[(UINT)SS_TYPE::END]; // Sampler

	//CConstBuffer* m_arrCB[(UINT)CB_TYPE::END]; // Constant Buffer

	// OM(OutputMergeState)
	ComPtr<ID3D11Texture2D>			m_RTTex;     // 렌더타겟 텍스쳐
	ComPtr<ID3D11RenderTargetView>	m_RTView;    // 렌더타겟 뷰

	ComPtr<ID3D11Texture2D>			m_DSTex;	 // 뎊스 스텐실 텍스쳐	
	ComPtr<ID3D11DepthStencilView>	m_DSView;	 // 뎊스 스텐실 뷰

};

