#pragma once

#include "..\Camera\DMCamera.h"
#include "..\TextureObjects\DMRenderFilter.h"

class DMHDR
{
public:
	DMHDR();
	~DMHDR();
	void Initialize( float width, float height, float bright_divider, float blur_divider );

	void begin();
	void postprocess_and_end( const DMCamera& camera, DMRenderFilter* );

	ID3D11ShaderResourceView* mainTexture();
	ID3D11ShaderResourceView* brightTexture();
	ID3D11ShaderResourceView* debugTexture();

private:
	struct alignas( 16 ) PSBuffer
	{
		float mainTexelSize;
		float brightTexelSize;
		float blurTexelSize;
	};

private:
	DMRenderTexture m_main_rt;
	DMRenderTexture m_bright_rt;
	DMRenderTexture m_blur_rt;
	DMRenderTexture m_downsample_rt;
	std::vector<DMRenderTexture> m_luminance_rt;
	DMCamera m_bright_camera;
	DMCamera m_blur_camera;
	ID3D11ShaderResourceView* m_debug_texture = nullptr;
	com_unique_ptr<ID3D11Buffer> m_psBuffer;
};