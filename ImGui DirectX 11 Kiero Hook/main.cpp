#pragma once
#include "includes.h"
#include "Menu.h"
#include "IconsFontAwesome6.h"
#include "offsets.h"
#include "mem.h"
#include "Font/fontawesome_data.h"


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
offsets Offsets;


Present oPresent;
ResizeBuffers oResizeBuffers;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

ID3D11RenderTargetView* originalRTV = nullptr;

HMODULE myhmod;
FILE* fp;

ImFont* cascadia = nullptr;
ImFont* Franklin = nullptr;
ImFont* segoesc = nullptr;
ImFont* awesome = nullptr;

ImFont* minitext = nullptr;

Menu menu;



void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
	//cascadia = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\CascadiaMono.ttf", 20.0f, NULL, io.Fonts->GetGlyphRangesDefault());
	segoesc = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\CORBEL.ttf", 20.0f, NULL, io.Fonts->GetGlyphRangesDefault());
	Franklin = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\FRAMD.ttf", 15.0f, NULL, io.Fonts->GetGlyphRangesDefault());

	ImGui::SetColorEditOptions(196776);

	//colors

	io.Fonts->AddFontDefault();
	static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	ImFontConfig icons_config;
	icons_config.MergeMode = true;
	icons_config.PixelSnapH = true;
	//assert(std::filesystem::exists("assets/fonts/fa-regular-400.ttf"));
	awesome = io.Fonts->AddFontFromMemoryTTF(Font_Awesome_6_Free_Solid_900_otf, sizeof(Font_Awesome_6_Free_Solid_900_otf), 70.f, &icons_config, icons_ranges);


	ImGuiStyle& style = ImGui::GetStyle(); // Get the global ImGui style
	// Change default style variables
	style.FrameRounding = 6.f;

	minitext = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ARIAL.ttf", 10.f, NULL, io.Fonts->GetGlyphRangesDefault());




}

/*	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;*/

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);

	if (cfg::menu_open && !unloadRequested) {
		if ((uMsg >= WM_MOUSEFIRST && uMsg <= WM_MOUSELAST) || (uMsg >= WM_KEYFIRST && uMsg <= WM_KEYLAST)) {
			return CallWindowProcA(oWndProc, hWnd, uMsg, 0, 0);
		}
	}

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

DWORD WINAPI UnloadThread(LPVOID lpParameter) {
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	FreeLibraryAndExitThread((HMODULE)lpParameter, 0);
	return 0;
}

bool init = false;
bool open = true;

//dx11 ResizeBuffers Hook
HRESULT hkResizeBuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags)
{
	//free resources

	if (mainRenderTargetView) {
		mainRenderTargetView->Release();
		mainRenderTargetView = nullptr;
	}

	//call original

	HRESULT hr = oResizeBuffers(pSwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
	if (FAILED(hr)) return hr;

	//recreate back buffer rendertargetview

	ID3D11Texture2D* pBackBuffer = nullptr;
	pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer);
	pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &mainRenderTargetView);
	pBackBuffer->Release();

	ImGui_ImplDX11_InvalidateDeviceObjects();
	ImGui_ImplDX11_CreateDeviceObjects();

	return hr;
}

HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{

	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
			pContext->OMGetRenderTargets(1, &originalRTV, NULL);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtrA(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	if (unloadRequested) {

		DXGI_SWAP_CHAIN_DESC sd;
		pSwapChain->GetDesc(&sd);
		window = sd.OutputWindow;


		iEngine->ClientCmd_Unrestricted("hud_free_cursor -1");
		SetWindowLongPtrA(window, GWLP_WNDPROC, (LONG_PTR)oWndProc);
		kiero::shutdown();
		fclose(fp);
		FreeConsole();
		unloadRequested = false;
		CreateThread(nullptr, 0, UnloadThread, myhmod, 0, nullptr);
		return oPresent(pSwapChain, SyncInterval, Flags);
	}

	if (GetAsyncKeyState(VK_INSERT) & 1) {
		cfg::menu_open = !cfg::menu_open;
	}

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	// Set the background color HERE

	ImGui::PushFont(Franklin);
	GodFunction();
	ImGui::PopFont();

	if (cfg::menu_open) {

		menu.DrawBackround();

		menu.DrawNewMenu(fp, pDevice);
		iEngine->ClientCmd_Unrestricted("hud_free_cursor 1");
	}
	else {
		iEngine->ClientCmd_Unrestricted("hud_free_cursor -1");
	}	
	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	pContext->OMSetRenderTargets(1, &originalRTV, NULL);

	if (originalRTV) originalRTV->Release();

	return oPresent(pSwapChain, SyncInterval, Flags);
}

void setConsoleColor(int textColor, int bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{

	AllocConsole();
	freopen_s(&fp, "CONOUT$", "w", stdout); // output only

	setConsoleColor(5, 0);

	std::cout << "[+] JohnWickWare Loaded\n";
	std::cout << "[+] Press INSERT to open menu\n";

	setConsoleColor(2, 0);

	static bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)&oPresent, hkPresent);
			kiero::bind(13, (void**)&oResizeBuffers, hkResizeBuffers);
			init_hook = true;
		}
	} while (!init_hook);


	return TRUE;
}

BOOL WINAPI DllMain(HMODULE hMod, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		myhmod = hMod;
		CreateThread(nullptr, 0, MainThread, hMod, 0, nullptr);
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}