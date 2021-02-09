#pragma once
#include "GameSettings.h"
#include "D3D11.h"

class SceneManager;

class Core final
{
public:
	Core();
	virtual ~Core();
	Core(const Core& t) = delete;
	Core& operator=(const Core& t) = delete;

	void AddScenes();
	HRESULT RunGame(HINSTANCE hInstance);

	static LRESULT CALLBACK WindowsProcedureStatic(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	//const GameSettings& GetGameSettings() { return m_GameSettings; }
	static GameSettings gameSettings; //TODO: gamesettings not static ? neede for camera

private:
	//Window variables
	HINSTANCE m_hInstance;
	std::wstring m_WindowClassName;
	WNDCLASS m_WindowClass;

	//Direct3D variables
	ID3D11RenderTargetView* m_pRenderTargetView;
	ID3D11Texture2D *m_pTexDepthStencilBuffer;
	ID3D11DepthStencilView* m_pDepthStencilView;
	IDXGISwapChain *m_pSwapChain;
	IDXGIFactory* m_pDXGIFactory;
	D3D11_VIEWPORT m_Viewport;
	IDXGIAdapter* m_pDXGIAdapter;
	IDXGIOutput* m_pDXGIOutput;

	int m_NumFrames;
	bool m_IsActive;

	D3D11 m_D3D11;
	SceneManager* m_pSceneManager;

	//Functions
	HRESULT InitalizeAdapterAndOutput();
	HRESULT CreateWindowClass();
	HRESULT OpenWindow();
	HRESULT InitializeDirect3D();

	enum class StateType{window, input};
	void StateChanged(StateType state, bool active);

	//Handle Windows Messages
	LRESULT WindowsProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	//report failures
	bool AlertOnFail(HRESULT hr, std::wstring originInfo = L"");

};

