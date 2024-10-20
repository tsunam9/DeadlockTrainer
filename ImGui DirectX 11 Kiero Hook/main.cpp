#include "includes.h"


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
ImFont* impact = nullptr;

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags = ImGuiConfigFlags_NoMouseCursorChange;
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
	cascadia = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\CascadiaMono.ttf", 20.0f, NULL, io.Fonts->GetGlyphRangesDefault());
	cascadia = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\impact.ttf", 50.0f, NULL, io.Fonts->GetGlyphRangesDefault());

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

	ImGui::PushFont(impact);
	GodFunction();
	ImGui::PopFont();

	if (Config.MenuOpen) {

		ImGui::Begin("LynchWare");

		if (ImGui::BeginTabBar("Cheat"))
		{
			// First tab
			if (ImGui::BeginTabItem("Aimbot"))
			{

				ImGui::Checkbox("Aimbot", &Config.aimbot.bAimbot);
				ImGui::SameLine();
				Helper::HotKey(Config.aimbot.AimKey);
				ImGui::SameLine();
				ImGui::Checkbox("Visible Check", &Config.aimbot.VisibleCheck);
				ImGui::Checkbox("Silent Aim", &Config.aimbot.silentaim);
				if (Config.aimbot.silentaim) {
					ImGui::SameLine();
					ImGui::Checkbox("PSilent", &Config.aimbot.bPSilent);
				}
				ImGui::Checkbox("Auto Fire", &Config.aimbot.AutoFire);
				static const char* items[] = { "Distance", "Lowest Health", "FOV" }; // Options for the dropdown
				static int currentItem = 0; // Index of the currently selected item
				ImGui::Combo("Target ", &currentItem, items, IM_ARRAYSIZE(items)); Config.aimbot.targetSelectionMode = currentItem;
				ImGui::Text("Selected: %s", items[currentItem]);
				ImGui::SliderFloat("Max Distance", &Config.aimbot.MaxDistance, 0.0f, 5000.0f, "%.1f");
				ImGui::SliderFloat("FOV", &Config.aimbot.fov, 0.0f, 180.0f, "%.1f");
				ImGui::SliderFloat("Smooth", &Config.aimbot.smooth, 0.0f, 100.0f, "%.1f");
				ImGui::Checkbox("Aim at XP", &Config.aimbot.AimXp);
				ImGui::SameLine();
				Helper::HotKey(Config.aimbot.AimKeyXp);
				ImGui::Checkbox("Aim At Minions", &Config.aimbot.AimMinions);
				ImGui::SameLine();
				Helper::HotKey(Config.aimbot.AimKeyMinions);




				ImGui::EndTabItem();
			}



			// Second tab
			if (ImGui::BeginTabItem("Esp"))
			{	
				ImVec2 availableSize = ImGui::GetContentRegionAvail();
				float childHeight = availableSize.y * 0.5f; // Set to half

				ImGui::BeginChild("Top EspChild", ImVec2(0, childHeight), true);

				ImGui::Checkbox("Esp", &Config.esp.bEsp);
				ImGui::Checkbox("Box Esp", &Config.esp.boxEsp);
				ImGui::Checkbox("Skeleton", &Config.esp.boneEsp);
				ImGui::Checkbox("Health Bar", &Config.esp.HealthBar);
				ImGui::Checkbox("Name Esp", &Config.esp.NameEsp);

				ImGui::EndChild();

				ImGui::BeginChild("Bottom EspChild", ImVec2(0, childHeight), true);

				ImGui::Checkbox("Health Text", &Config.esp.HealthEsp);
				ImGui::Checkbox("Tracers", &Config.esp.Tracers);
				ImGui::Checkbox("Distance Esp", &Config.esp.DistanceEsp);
				ImGui::Checkbox("Draw Fov", &Config.esp.DrawFov);
				ImGui::Checkbox("Draw Xp", &Config.esp.DrawXp);
				ImGui::Checkbox("Draw Monsters", &Config.esp.DrawMonsters);
				ImGui::Checkbox("Draw Minions", &Config.esp.DrawMinions);
				//ImGui::Checkbox("Draw Aimbot Prediction", &Config.esp.DrawAimbotPrediction);
				ImGui::EndChild();
				ImGui::EndTabItem();
			}

			if (ImGui::BeginTabItem("AntiAim")) {

				ImGui::Checkbox("AntiAim", &Config.antiaim.bAntiAim);
				static const char* items[] = { "Spin", "Jitter", "180 Treehouse" }; // Options for the dropdown
				static int currentItem = 0; // Index of the currently selected item
				ImGui::Combo("Target ", &currentItem, items, IM_ARRAYSIZE(items)); Config.antiaim.AAtype = currentItem;
				ImGui::PushFont(impact);
				ImGui::Text("Selected: %s", items[currentItem]);
				ImGui::PopFont();
				ImGui::SliderFloat("Lower Jitter", &Config.antiaim.lowerjitter, -180, Config.antiaim.upperjitter, "%.1f");
				ImGui::SliderFloat("Upper Jitter", &Config.antiaim.upperjitter, Config.antiaim.lowerjitter, 180.0f, "%.1f");
				ImGui::EndTabItem();

			}

			if (ImGui::BeginTabItem("Heroes")) {
				switch (Helper::get_player_data(Helper::get_local_player()).HeroID) {

				case Abrams:
					ImGui::Text("Abrams");
					break;
				case Bebop:
					ImGui::Text("Bebop");
					break;
				case Dynamo:
					ImGui::Text("Dynamo");
					break;
				case GreyTalon:
					ImGui::Text("GreyTalon");
					break;
				case Haze:
					ImGui::Text("Haze");
					break;
				case Infernus:
					ImGui::Text("Infernus");
					break;
				case Ivy:
					ImGui::Text("Ivy");
					break;
				case Kelvin:
					ImGui::Text("Kelvin");
					break;
				case LadyGeist:
					ImGui::Text("LadyGeist");
					break;
				case Lash:
					ImGui::Text("Lash");
					break;
				case McGinnis:
					ImGui::Text("McGinnis");
					break;
				case Mirage:
					ImGui::Text("Mirage");
					break;
				case MoAndKrill:
					ImGui::Text("MoAndKrill");
					break;
				case Paradox:
					ImGui::Text("Paradox");
					break;
				case Pocket:
					ImGui::Text("Pocket");
					break;
				case Seven:
					ImGui::Text("Seven");
					break;
				case Shiv:
					ImGui::Text("Shiv");
					ImGui::Checkbox("Auto Aim Dagger", &Config.shiv.AutoAimDagger);
					ImGui::Checkbox("Auto Aim Dash", &Config.shiv.AutoAimDash);
					ImGui::Checkbox("Auto Execute", &Config.shiv.AutoExecute);
					ImGui::Checkbox("Block Manual R", &Config.shiv.BlockManualR);
					break;
				case Vindicta:
					ImGui::Text("Vindicta");
					ImGui::Checkbox("Auto Aim Stake", &Config.vindicta.AutoAimStake);
					ImGui::Checkbox("Auto Aim Crow", &Config.vindicta.AutoAimCrow);
					ImGui::Checkbox("Auto Snipe", &Config.vindicta.AutoSnipe);
					break;
				case Viscous:
					ImGui::Text("Viscous");
					break;
				case Warden:
					ImGui::Text("Warden");
					break;
				case Wraith:
					ImGui::Text("Wraith");
					break;
				case Yamato:
					ImGui::Text("Yamato");
					break;
				}

				ImGui::EndTabItem();
			}

			// Third tab
			if (ImGui::BeginTabItem("Misc"))
			{
				
				ImGui::Checkbox("No Recoil", &Config.misc.bNorecoil); 
				ImGui::SliderFloat("Fov Multiplier", &Config.misc.fovmodifier, 0.1f, 2.0f, "%.3f");

				if (ImGui::Button("Slay them all"))
				{
					
					kiero::shutdown();
					fclose(fp);
					FreeConsole();
				}

				ImGui::EndTabItem();
			}

			ImGui::EndTabBar();
		}
		ImGui::End();
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

	const std::string red = "\033[31m";
	const std::string green = "\033[32m";
	const std::string yellow = "\033[33m";
	const std::string blue = "\033[34m";
	const std::string reset = "\033[0m"; // Reset to default color

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
	std::cout << "[+] Aimbot: " << Config.aimbot.bAimbot << std::endl;


		                                                                                                                                                       

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