#pragma once

/////////////
// LINKING //
/////////////
/*
#pragma comment( lib, "dxgi.lib")
#pragma comment( lib, "d3d11.lib")
#pragma comment( lib, "d3dx11.lib")
#pragma comment( lib, "d3dx10.lib")
*/
//////////////
// INCLUDES //
//////////////


#include "DirectX.h"
#include <list>
#include <memory>
#include "..\..\..\Utils\utilites.h"

class DMD3D
{
private:
	DMD3D(  );
	DMD3D( const DMD3D& ) = delete;
	DMD3D& operator=( const DMD3D& ) = delete;
	static DMD3D* m_instance;

public:
	static DMD3D& instance();
	static void close();
	~DMD3D();

	bool Initialize( int, int, bool, HWND, bool, float, float );
	void Shutdown( );

	void BeginScene( float, float, float, float );
	void EndScene( );

	ID3D11Device* GetDevice( );
	ID3D11DeviceContext* GetDeviceContext( );

	void GetVideoCardInfo( char*, int& );

	void TurnZBufferOn( );
	void TurnZBufferOff( );

	void TurnDefaultRS( );
	void TurnBackFacesRS();
	void TurnShadowRS();
	void TurnCullingNoneRS( );

	void TurnOnWireframe( );
	void TurnOffWireframe( );

	void TurnOnAlphaBlending( );
	void TurnOffAlphaBlending( );

	ID3D11DepthStencilView* GetDepthStencilView( );
	void SetBackBufferRenderTarget( );
	void ResetViewport( );

	void TurnOnTransparancy( );
	void TurnOffTransparancy( );

	bool createShaderConstantBuffer( size_t byte_size, com_unique_ptr<ID3D11Buffer> &, const D3D11_SUBRESOURCE_DATA * = nullptr );
	bool createVertexBuffer( com_unique_ptr<ID3D11Buffer> &, void* data, size_t sizeInByte );
	bool createIndexBuffer( com_unique_ptr<ID3D11Buffer> &, void* data, size_t sizeInByte );
	bool CreateBuffer( const D3D11_BUFFER_DESC *pDesc, const D3D11_SUBRESOURCE_DATA *pInitialData, com_unique_ptr<ID3D11Buffer>& );

private:
	bool m_vsync_enabled;
	int m_videoCardMemory;
	char m_videoCardDescription[128];
	IDXGISwapChain* m_swapChain;
	ID3D11Device* m_device;
	ID3D11DeviceContext* m_deviceContext;
	ID3D11RenderTargetView* m_renderTargetView;
	ID3D11Texture2D* m_depthStencilBuffer;
	ID3D11DepthStencilState* m_depthStencilState;
	ID3D11DepthStencilView* m_depthStencilView;
	ID3D11RasterizerState* m_rasterState;
	ID3D11RasterizerState* m_rasterStateNoCulling;
	ID3D11RasterizerState* m_raster_state_shadow;
	ID3D11RasterizerState* m_raster_state_front_culling;
	ID3D11RasterizerState* m_rasterStateWireframe;
	
	ID3D11DepthStencilState* m_depthDisabledStencilState;
	

	ID3D11BlendState* m_alphaEnableBlendingState;
	ID3D11BlendState* m_alphaDisableBlendingState;

	ID3D11BlendState* m_blendStateTransparency;

	D3D11_VIEWPORT m_viewport;

	std::list<IUnknown*> m_interfaces;
};

