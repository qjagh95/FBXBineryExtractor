#pragma once

PUN_BEGIN

class PUN_DLL CDevice
{
private:
	HWND					m_hWnd;
	ID3D11Device*			m_pDevice;
	ID3D11DeviceContext*	m_pContext;
	IDXGISwapChain*			m_pSwapChain;
	ID3D11RenderTargetView*	m_pTargetView;
	ID3D11DepthStencilView*	m_pDepthView;
	Resolution				m_tRS;

private:
	// 2D Interface
	ID2D1RenderTarget*	m_p2DTarget;
	ID2D1Factory*		m_p2DFactory;

public:
	ID3D11Device*			GetDevice()	const;
	ID3D11DeviceContext*	GetContext()	const;
	IDXGISwapChain*			GetSwapChain()	const;
	Resolution				GetResolution()	const;
	Vector2					GetWindowToDeviceResolution()	const;
	ID2D1RenderTarget*		Get2DRenderTarget()	const;

public:
	bool Init(HWND hWnd, unsigned int iWidth, 
		unsigned int iHeight, bool bWindowMode);
	bool EditInit(HWND hWnd, unsigned int iWidth,
		unsigned int iHeight, bool bWindowMode);
	void Clear(float fClearColor[4]);
	void Present();

	DECLARE_SINGLE(CDevice)
};

PUN_END