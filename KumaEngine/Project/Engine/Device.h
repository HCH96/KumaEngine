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
	ComPtr<ID3D11Device>			m_Device;	// GPU �޸� ����, ��ü ����
	ComPtr<ID3D11DeviceContext>		m_Context;	// GPU ������ ��� 

	ComPtr<IDXGISwapChain>			m_SwapChain; // ����ü��(��� ���� ����)

	//ComPtr<ID3D11RasterizerState> m_arrRS[(UINT)RS_TYPE::END];   // �����Ͷ�����
	//ComPtr<ID3D11DepthStencilState> m_arrDS[(UINT)DS_TYPE::END]; // ���̽��Ľ�
	//ComPtr<ID3D11BlendState> m_arrBS[(UINT)BS_TYPE::END];        // ����

	//ComPtr<ID3D11SamplerState> m_arrSS[(UINT)SS_TYPE::END]; // Sampler

	//CConstBuffer* m_arrCB[(UINT)CB_TYPE::END]; // Constant Buffer

	// OM(OutputMergeState)
	ComPtr<ID3D11Texture2D>			m_RTTex;     // ����Ÿ�� �ؽ���
	ComPtr<ID3D11RenderTargetView>	m_RTView;    // ����Ÿ�� ��

	ComPtr<ID3D11Texture2D>			m_DSTex;	 // �X�� ���ٽ� �ؽ���	
	ComPtr<ID3D11DepthStencilView>	m_DSView;	 // �X�� ���ٽ� ��

};

