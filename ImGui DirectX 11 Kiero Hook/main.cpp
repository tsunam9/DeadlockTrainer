#include "includes.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

ConfigSettings Config;

HMODULE myhmod;
FILE* fp;


void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}

LRESULT __stdcall WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	if (true && ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
		return true;

	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}


bool init = false;
bool open = true;
HRESULT __stdcall hkPresent(IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags)
{
	if (!init)
	{
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)& pDevice)))
		{
			pDevice->GetImmediateContext(&pContext);
			DXGI_SWAP_CHAIN_DESC sd;
			pSwapChain->GetDesc(&sd);
			window = sd.OutputWindow;
			ID3D11Texture2D* pBackBuffer;
			pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)& pBackBuffer);
			pDevice->CreateRenderTargetView(pBackBuffer, NULL, &mainRenderTargetView);
			pBackBuffer->Release();
			oWndProc = (WNDPROC)SetWindowLongPtr(window, GWLP_WNDPROC, (LONG_PTR)WndProc);
			InitImGui();
			init = true;
		}

		else
			return oPresent(pSwapChain, SyncInterval, Flags);
	}

	//toggle menu
	if(GetAsyncKeyState(VK_INSERT) & 1)
		Config.MenuOpen = !Config.MenuOpen;

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	GodFunction((uintptr_t)&Config); // Main Cheat Logic

	if (Config.MenuOpen) {

		ImGui::Begin("NiggerKillerWare");
		ImGui::Checkbox("Aimbot", &Config.bAimbot);
		ImGui::Checkbox("Esp", &Config.bEsp);
		ImGui::Checkbox("BoxEsp", &Config.boxEsp);
		ImGui::Checkbox("Health Text", &Config.HealthEsp);
		ImGui::Checkbox("Tracers", &Config.Tracers);
		if (ImGui::Button("Slay them all"))
		{
			kiero::shutdown();
			fclose(fp);
			FreeConsole();
		}
		ImGui::End();
	}
	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}


DWORD WINAPI MainThread(LPVOID lpReserved)
{
	//
	AllocConsole();
	freopen_s(&fp, "CONOUT$", "w", stdout); // output only
	std::cout << "test" << std::endl;
	//



	bool init_hook = false;
	do
	{
		if (kiero::init(kiero::RenderType::D3D11) == kiero::Status::Success)
		{
			kiero::bind(8, (void**)& oPresent, hkPresent);
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