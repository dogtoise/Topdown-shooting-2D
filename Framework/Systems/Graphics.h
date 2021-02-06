#pragma once

/*
DirectX 11
DirectX June 2010 SDK

SoftWare developmentkit

*/

/*
DX11�� �ڿ� ����
ID3D11Buffer : ��ó���� ����. �����ϰ� ������ ����, �ڷ���� ������ Ȥ�� ���������尰�� ����. CPU�� ������, Rem�� �����͸� �ӽ÷� ���ۿ� �ְ� VRem���� ������ ����

ID3D11Texture : ��� �뵵�� ������ �������� ��ü.
				Texture�� �ȼ�(1pixel�� 4byte)���� ����.

Texture�� ���õ� ���� ����
ID3D11RenderTargetView : �ȼ����� ����Ÿ�ٺ信 �׷���. ��ȭ���� ����. ��������.

ID3D11ShaderResourceView : ���̴��� �׷��� ī�忡�� ��� �������� �����ϴ� ����.
						   ���̴����� ���� �ڿ�.
						   �׷��� ������ �������� ���̴��� �ۼ��ؼ� �־���� ������ �ȴ�.
						   HLSL (High Level Shader Language) : ����� �ܰ��� ���̴� ���

ID3D11DepthStencilView : ����, ��ȭ, 3D���� ���ȴ�.

ID3D11UnorderedAccessView : �������� ���� ��.
							������ ���ܿ����� ���� �ؾߵ� ��� �װ͵��� ���ÿ� ó���ϴ� ��.

CPU��  ������ ����� ó���ϴµ� ���ÿ� ó���ϱ� ����.
�׷��� ī��� ���� ������ ������ �޷���� ó���ϴµ� �Ӹ����� ���� ���� ó���� �ȴ�.
�׷��� ī���� �ھ�� 1000�� �����̴�.
*/

/*
deviceContext : �׸���  ���͵��� �����Ǿ��ְ� ���۵Ǵ� ��.

Rendering Pipeline)
���������� ȭ�鿡 ������ ������ �׸��� �ܰ�
����)
IA - VS - RS - PS - OM

IA : Input Assembler - ���� �ܰ���� �޾���  primitive ������ ���ε��Ѵ�.
	Vertex Buffer
	IndexBuffer
	Topology - ���Ἲ ����
	InputLayout

VS : vertex Shader ���� ����� �ϴ� �ܰ�
	������ ��ġ�� ���
	������ȯ
		Local - World - View - Porjection - Viewport
		World - View - Projection ������ VS�ܰ迡�� ó��

RS : Rasterizer state
viewport ���� (NDC��ǥ�踦 ȭ�� ��ǥ��� ��ȯ���ش�)
rastrization (�ȼ�ȭ)
culling : �ĸ��߸��� (�ո����� �޸����� üũ)
Scissor Test :ȭ������� ������ ����

PS : Pixel Shader
 -> �ȼ� ���� 

OM : Output Merger


���� (vertex)
������ �������������� DX������ ��ġ ����ü �̻��� �ǹ̿� ������ ������.




*/
// 09/04
/*
Rendering pipeline : �̹��� ���� ����
2D�� ���
1. IA(Input Assembler) : �Է� ����. ������ �׸��� ���� ���� ����(��)�� �Է��Ѵ�.
						 
 : �� �׸��� ��, IndexBuffer, Topology(���Ἲ ����) : ���� ���� �̾��ִ� ��, InputLayout
	����(vertex) : ���� �̷�µ� �ʿ��� ������
				   �������� ��ǥ��(position) �̿ܿ��� �ٸ� ���� �� ���� �� �ִ�.
				   ���� �� ����(color)���� �߰� �� �� �ִ�.
				   ĳ���͸� �׸� ���� ������ ���� ������ ���ȴ�.
2. VS(VertexShader) : ������ ��ġ�� ������ִ� ��
3. RS(Rasterizer State) : �׷����� ������ �ȼ��� ä���ִ� ��.
	Backface culling : 3D���� ������ �ʴ� �޸���  �׸��� �ʴ� ��.
	NDC(Nomalized Device Coordinate) ��ǥ�� : (-1 ~ 1). ��ǥ�� viewport ��ȯ. ��Ƽ���ø�, fill mode�� ��ȯ�� ���⼭ �Ͼ��.
4. PS(Pixel Shader) : �ȼ����� ��� ������ ���� ���ϴ� ��. ������ ��� �ٿ�, �̹����� ������Ƽ��(�ﰢ��)�� �ٿ��ش�.
5. OM(Output Merger) :

���������� �ڵ��� ������ ������ VS�� PS �ܰ���̴�. �������� ���� �־��ش�.

2D���� �ϴ� �� : ������ȯ

���� ��ȯ
1.Local : ���� ����. ���� ��ü�� �� �������� ��ǥ. ��ü ���� ��ǥ
2.World : �� ����. �� ���� ��ǥ
3.View : ī�޶� ����(��ġ). ����ü ���� �ȿ� ���� �����. ī�޶��� ��ġ�� �����̴�.
4.Projection : ���� ����. ���ٰ�. �Ÿ��� ���� ������ �۾����� �ϴ� ��.
	FOV(Filed Of View) : ����. �ܾƿ�
5.Viewport : ȭ�� �۾� ����. ������â ������ ���� ����. Rasterizer �ܰ迡�� ����.

��� ������ �� ���ϱ���� �˸� ���� ����

Description�� Context�� ������
Description : �ڿ��� ��� �����޶�� �䱸. ������
Context : ���������� �ȿ� ���� ���ð�
/

/
IDXGI : DirectX Graphics Infrastructure.
		�����簡 �ٸ� �׷��� ī��(�ϵ����)�� ���ֹ��� �ʰ� ���ϰ� ����ϰ� ���ִ� ��.
SwapChain : ���� ���۸��� ���� DXGI�� �� ����.
D3DXCOLOR : RGBA ����ü.
			Red,    Green,  Blue,   Alpha
			float,  float,  float,  float
			0 ~ 1���� ����ȭ�� ���� ����Ѵ�.
			1, 0, 0, 1
			80, 0, 0
			80 / 255, 0, 0, 1


			ID3D11Device* device = nullptr; //Interface ���� �ٸ� �� ���� �����ϴ� ���� ����� �������̽�, DirectX 3D ���, DX11 ����, Device�� �ڿ� ����
	ID3D11DeviceContext* deviceContext = nullptr; //�׸��µ� �ʿ��� ��� ������ ����ִ�.
	IDXGISwapChain* swapChain = nullptr;
	ID3D11RenderTargetView* rtv = nullptr;
	D3D11_VIEWPORT viewport;
	D3DXCOLOR clearColor = 0xff555566; //�ʱ�ȭ�� ����. OM�ܰ迡 �־��� ��
*/

/*


*/




class D3DEnumAdapterInfo;
class D3DEnumOutputInfo;
class Graphics : public SingletonBase<Graphics>
{

public:
	friend class SingletonBase<Graphics>;

	

	//void Init();
	//void CreateBackbuffer();
	///////////////////////////////////
	

	ID3D11Device* GetDevice()
	{
		return device;
	}

	ID3D11DeviceContext* GetDC()
	{
		return deviceContext;
	}

	void Resize(const UINT& width, const UINT& height);
	void SetViewport(const UINT& width, const UINT& height);
	void InitViewport();

	void Begin();
	void End();

	void GUI();
private :
	void CreateSwapchain();
	void CreateRenderTargetView();
	void DeleteSurface();

 
private:
	Graphics();
	~Graphics();

private :
	void EnumerateAdapters();
	bool EnumerateAdapterOutput(D3DEnumAdapterInfo* adapterInfo);

private:
	ID3D11Device* device = nullptr; //DirectX11�� ����ϴ� ��ü���� �����ϴ� ����
	ID3D11DeviceContext* deviceContext = nullptr; //�׸��� �Ϳ� ���õ� ��� �������� ������ �ִ� ��ü
	IDXGISwapChain* swapChain = nullptr;
	ID3D11RenderTargetView* rtv = nullptr;
	D3D11_VIEWPORT viewport;
	D3DXCOLOR clearColor = 0xff555566;

	UINT numerator = 0;
	UINT denominator = 1;

	UINT gpuMemorySize;
	wstring gpuName;

	// VRAM�� ���� ū�� ���� �׷���
	vector<D3DEnumAdapterInfo*> adapterInfos;
	int selectedAdapterIndex = 0;

	// ���� ����ȭ
	bool bVsync = true;

	/*Rendering Pipeline
	*/
};

class D3DEnumAdapterInfo
{
public:
	~D3DEnumAdapterInfo();

	UINT adapterOrdinal = 0;
	IDXGIAdapter1* adapter = nullptr;
	DXGI_ADAPTER_DESC1 adapterDesc = { 0 };

	D3DEnumOutputInfo* outputInfo = nullptr;
};

class D3DEnumOutputInfo
{
public :
	~D3DEnumOutputInfo();

	IDXGIOutput *output = nullptr;
	DXGI_OUTPUT_DESC outputDesc = { 0 };

	// ���� ����ȭ
	UINT numerator = 0;
	UINT denominator = 1;
};

/*
COM Interface


*/
