#include "pch.h"
#include "Test.h"

#include "Device.h"

Vtx g_vtx[3] = {};

// 정점을 저장하는 정점버퍼
ComPtr<ID3D11Buffer>	g_VB = nullptr;

// InputLayout 정점하나의 구조를 알리는 객체
ComPtr<ID3D11InputLayout> g_Layout = nullptr;

ComPtr<ID3DBlob> g_VSBlob = nullptr;
ComPtr<ID3DBlob> g_PSBlob = nullptr;
ComPtr<ID3DBlob> g_ErrBlob = nullptr;


ComPtr<ID3D11VertexShader> g_VS = nullptr;
ComPtr<ID3D11PixelShader> g_PS = nullptr;

int TestInit()
{
	//// 전역변수에 삼각형 위치 설정
	////      0(Red)
	////    /    \
	////  2(G) -- 1(Blue)
	//g_vtx[0].vPos = Vec3(0.f, 1.f, 0.f);
	//g_vtx[0].vColor = Vec4(1.f, 0.f, 0.f, 1.f);
	//g_vtx[0].vUV = Vec2(0.f, 0.f);

	//g_vtx[1].vPos = Vec3(1.f, -1.f, 0.f);
	//g_vtx[1].vColor = Vec4(0.f, 0.f, 1.f, 1.f);
	//g_vtx[1].vUV = Vec2(0.f, 0.f);

	//g_vtx[2].vPos = Vec3(-1.f, -1.f, 0.f);
	//g_vtx[2].vColor = Vec4(0.f, 1.f, 0.f, 1.f);
	//g_vtx[2].vUV = Vec2(0.f, 0.f);


	//// 버텍스 버퍼 생성
	//D3D11_BUFFER_DESC BufferDesc = {};

	//BufferDesc.ByteWidth = sizeof(Vtx) * 3;
	//BufferDesc.StructureByteStride = sizeof(Vtx);
	//BufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

	//BufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	//BufferDesc.Usage = D3D11_USAGE_DYNAMIC;

	//// g_Vtx 배열의 데이터를 초기 데이터로 설정
	//D3D11_SUBRESOURCE_DATA tSubData = {};
	//tSubData.pSysMem = g_vtx;

	//// 버텍스 버퍼 생성
	//if (FAILED(DEVICE->CreateBuffer(&BufferDesc, &tSubData, g_VB.GetAddressOf())))
	//{
	//	MessageBox(nullptr, L"버텍스 버퍼 생성 실패", L"TestInit 오류", MB_OK);
	//	return E_FAIL;
	//}

	//// 정점 구조정보(Layout) 생성
	//D3D11_INPUT_ELEMENT_DESC arrElement[3] = {};

	//arrElement[0].InputSlot = 0;
	//arrElement[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	//arrElement[0].SemanticName = "POSITION";
	//arrElement[0].SemanticIndex = 0;
	//arrElement[0].InstanceDataStepRate = 0;
	//arrElement[0].AlignedByteOffset = 0;
	//arrElement[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;

	//arrElement[1].InputSlot = 0;
	//arrElement[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	//arrElement[1].SemanticName = "COLOR";
	//arrElement[1].SemanticIndex = 0;
	//arrElement[1].InstanceDataStepRate = 0;
	//arrElement[1].AlignedByteOffset = 12;
	//arrElement[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;

	//arrElement[2].InputSlot = 0;
	//arrElement[2].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	//arrElement[2].SemanticName = "TEXCOORD";
	//arrElement[2].SemanticIndex = 0;
	//arrElement[2].InstanceDataStepRate = 0;
	//arrElement[2].AlignedByteOffset = 28;
	//arrElement[2].Format = DXGI_FORMAT_R32G32_FLOAT;




	//// 버텍스 쉐이더
	//// HLSL 버텍스 쉐이더 함수 컴파일
	//wstring strFilePath = CPathMgr::GetContentPath();

	//if (FAILED(D3DCompileFromFile(wstring(strFilePath + L"shader\\std2d.fx").c_str()
	//	, nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE
	//	, "VS_Std2D", "vs_5_0", D3DCOMPILE_DEBUG, 0
	//	, g_VSBlob.GetAddressOf(), g_ErrBlob.GetAddressOf())))
	//{
	//	if (nullptr != g_ErrBlob)
	//	{
	//		char* pErrMsg = (char*)g_ErrBlob->GetBufferPointer();
	//		MessageBoxA(nullptr, pErrMsg, "Shader Compile Failed!!", MB_OK);
	//	}

	//	return E_FAIL;
	//}

	//DEVICE->CreateVertexShader(g_VSBlob->GetBufferPointer()
	//	, g_VSBlob->GetBufferSize(), nullptr
	//	, g_VS.GetAddressOf());

	//// Layout 생성
	//DEVICE->CreateInputLayout(arrElement, 3
	//	, g_VSBlob->GetBufferPointer()
	//	, g_VSBlob->GetBufferSize()
	//	, g_Layout.GetAddressOf());


	//// 픽셀 쉐이더 생성
	//// 픽셀 쉐이더 컴파일
	//if (FAILED(D3DCompileFromFile(wstring(strFilePath + L"shader\\std2d.fx").c_str()
	//	, nullptr, D3D_COMPILE_STANDARD_FILE_INCLUDE
	//	, "PS_Std2D", "ps_5_0", D3DCOMPILE_DEBUG, 0
	//	, g_PSBlob.GetAddressOf(), g_ErrBlob.GetAddressOf())))
	//{
	//	if (nullptr != g_ErrBlob)
	//	{
	//		char* pErrMsg = (char*)g_ErrBlob->GetBufferPointer();
	//		MessageBoxA(nullptr, pErrMsg, "Shader Compile Failed!!", MB_OK);
	//	}

	//	return E_FAIL;
	//}

	//DEVICE->CreatePixelShader(g_PSBlob->GetBufferPointer()
	//	, g_PSBlob->GetBufferSize(), nullptr
	//	, g_PS.GetAddressOf());

	return S_OK;

}

void TestUpdate()
{
}
