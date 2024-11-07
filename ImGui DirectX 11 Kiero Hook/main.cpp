#include "includes.h"
#include "Menu.h"
#include "IconsFontAwesome6.h"


extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

Present oPresent;
HWND window = NULL;
WNDPROC oWndProc;
ID3D11Device* pDevice = NULL;
ID3D11DeviceContext* pContext = NULL;
ID3D11RenderTargetView* mainRenderTargetView;

HMODULE myhmod;
FILE* fp;

ImFont* cascadia = nullptr;
ImFont* Franklin = nullptr;
ImFont* segoesc = nullptr;
ImFont* awesome = nullptr;


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
	ImVec4* colors = ImGui::GetStyle().Colors;
	colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
	colors[ImGuiCol_Border] = ImVec4(1.00f, 0.00f, 0.53f, 0.24f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.24f, 0.24f, 0.24f, 0.54f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(1.00f, 0.00f, 0.36f, 0.40f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.67f, 0.00f, 0.24f, 0.40f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.65f, 0.00f, 0.40f, 1.00f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.65f, 0.00f, 0.40f, 1.00f);
	colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 0.00f, 0.48f, 1.00f);
	colors[ImGuiCol_SliderGrab] = ImVec4(0.72f, 0.11f, 0.35f, 1.00f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.92f, 0.06f, 0.41f, 1.00f);
	colors[ImGuiCol_Button] = ImVec4(0.72f, 0.11f, 0.35f, 1.00f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(1.00f, 0.00f, 0.40f, 1.00f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.85f, 0.06f, 0.74f, 1.00f);
	colors[ImGuiCol_Separator] = ImVec4(1.00f, 0.00f, 0.65f, 0.50f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 0.00f, 0.53f, 0.24f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 0.00f, 0.53f, 0.24f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 0.00f, 0.53f, 0.68f);
	colors[ImGuiCol_Tab] = ImVec4(0.65f, 0.00f, 0.40f, 1.00f);
	colors[ImGuiCol_TabHovered] = ImVec4(1.00f, 0.00f, 0.62f, 1.00f);
	colors[ImGuiCol_TabActive] = ImVec4(1.00f, 0.00f, 0.62f, 1.00f);

	io.Fonts->AddFontDefault();
	static const ImWchar icons_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	ImFontConfig icons_config;
	icons_config.MergeMode = true;
	icons_config.PixelSnapH = true;
	//assert(std::filesystem::exists("assets/fonts/fa-regular-400.ttf"));
	awesome = io.Fonts->AddFontFromFileTTF("c:\\Users\\Russ\\Appdata\\Local\\Microsoft\\Windows\\Fonts\\Font Awesome 6 Free-Solid-900.otf", 70.f, &icons_config, icons_ranges);

	ImGuiStyle& style = ImGui::GetStyle(); // Get the global ImGui style
	// Change default style variables
	style.FrameRounding = 6.f;




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



	if(GetAsyncKeyState(Config.MenuKey.key) & 1)
		Config.MenuOpen = !Config.MenuOpen;

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ImGui::PushFont(Franklin);
	GodFunction();
	ImGui::PopFont();

	if (Config.MenuOpen) {
		Menu::DrawNewMenu(fp, pDevice);
		//Menu::DrawMenu(fp);
	}
	ImGui::Render();

	pContext->OMSetRenderTargets(1, &mainRenderTargetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SyncInterval, Flags);
}

void setConsoleColor(int textColor, int bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	//
	AllocConsole();
	freopen_s(&fp, "CONOUT$", "w", stdout); // output only


	setConsoleColor(5, 0);

	std::cout << R"(
                                                                                                                                                                       
M""MMMMMMMM                            dP       M""MMM""MMM""M                            
M  MMMMMMMM                            88       M  MMM  MMM  M                            
M  MMMMMMMM dP    dP 88d888b. .d8888b. 88d888b. M  MMP  MMP  M .d8888b. 88d888b. .d8888b. 
M  MMMMMMMM 88    88 88'  `88 88'  `"" 88'  `88 M  MM'  MM' .M 88'  `88 88'  `88 88ooood8 
M  MMMMMMMM 88.  .88 88    88 88.  ... 88    88 M  `' . '' .MM 88.  .88 88       88.  ... 
M         M `8888P88 dP    dP `88888P' dP    dP M    .d  .dMMM `88888P8 dP       `88888P' 
MMMMMMMMMMM      .88                            MMMMMMMMMMMMMM                            
             d8888P                                                                              

)" << '\n';

	std::cout << "[+] LynchWare Loaded\n";
	std::cout << "[+] Press INSERT to open menu\n";

	setConsoleColor(2, 0);


		                                                                                                                                                       

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