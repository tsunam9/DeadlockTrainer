
#include "Menu.h"
#include "D3D11.h"
#include <wrl/client.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using Microsoft::WRL::ComPtr;

extern Binds mainbinds;

extern Menu menu;

bool GlyphButton(const char* glyph, ImVec2 size, bool selecctedtab) {
	// Create base button


	std::string GlyphStr = glyph;
	std::string buttonID = "##Button" + GlyphStr;

	bool clicked = ImGui::Button(buttonID.c_str(), size);

	// Get button position and size
	ImVec2 buttonPos = ImGui::GetItemRectMin();
	ImVec2 buttonSize = ImGui::GetItemRectSize();

	// Calculate button center
	ImVec2 buttonCenter = ImVec2(
		buttonPos.x + buttonSize.x * 0.5f,
		buttonPos.y + buttonSize.y * 0.5f
	);

	// Get text size for centering
	ImVec2 textSize = ImGui::CalcTextSize(glyph);

	// Calculate offset for centering
	float offsetX = buttonCenter.x - textSize.x * 0.5f;
	float offsetY = buttonCenter.y + textSize.y * 1.0f;

	// Convert to window-relative coordinates
	ImVec2 windowPos = ImGui::GetWindowPos();
	ImVec2 relativeOffset = ImVec2(
		offsetX - windowPos.x,
		offsetY - windowPos.y
	);

	// Save current cursor position
	ImVec2 cursorPos = ImGui::GetCursorPos();

	// Position and render the glyph
	ImGui::SetCursorPos(relativeOffset);

	if (selecctedtab) {
		ImGui::PushStyleColor(ImGuiCol_Text, cfg::colors_MenuColor);
	}
	else {
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.2, 0.2f, 0.2f, 1.0f));
	}


	ImGui::Text(glyph);

	ImGui::PopStyleColor();

	ImGui::SetCursorPos(cursorPos);

	return clicked;
}


std::string ConvertUnicodeToMultiByte(const std::wstring& unicodeString) {
	// Determine the required size for the multibyte string
	int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, unicodeString.c_str(), static_cast<int>(unicodeString.length()), nullptr, 0, nullptr, nullptr);

	if (sizeNeeded <= 0) {
		// Handle error
		return "";
	}

	// Create a buffer to hold the multibyte string
	std::string multibyteString(sizeNeeded, 0);

	// Perform the conversion
	WideCharToMultiByte(CP_UTF8, 0, unicodeString.c_str(), static_cast<int>(unicodeString.length()), &multibyteString[0], sizeNeeded, nullptr, nullptr);

	return multibyteString;
}


ID3D11Texture2D* LoadTextureFromFile(ID3D11Device* device, const char* filename) {
	// Load the image using stb_image
	int width, height, channels;
	unsigned char* imageData = stbi_load(filename, &width, &height, &channels, 4); // Force 4 channels (RGBA)
	if (!imageData) {
		// Handle image loading failure
		return nullptr;
	}

	// Describe the texture
	D3D11_TEXTURE2D_DESC textureDesc = {};
	textureDesc.Width = width;
	textureDesc.Height = height;
	textureDesc.MipLevels = 1;
	textureDesc.ArraySize = 1;
	textureDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; // Full color (RGBA 8-bit per channel)
	textureDesc.SampleDesc.Count = 1;
	textureDesc.Usage = D3D11_USAGE_DEFAULT;
	textureDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;

	// Setup initial data
	D3D11_SUBRESOURCE_DATA initialData = {};
	initialData.pSysMem = imageData; // Pointer to the image data
	initialData.SysMemPitch = width * 4; // 4 bytes per pixel (RGBA)

	// Create the texture
	ID3D11Texture2D* texture = nullptr;
	HRESULT hr = device->CreateTexture2D(&textureDesc, &initialData, &texture);
	if (FAILED(hr)) {
		// Handle error (e.g., log it or throw an exception)
		stbi_image_free(imageData);
		return nullptr;
	}

	// Free the image data after creating the texture
	stbi_image_free(imageData);

	return texture;
}

ID3D11ShaderResourceView* CreateShaderResourceView(ID3D11Device* device, ID3D11Texture2D* texture) {
	// Create a shader resource view for the texture
	ID3D11ShaderResourceView* srv = nullptr;
	HRESULT hr = device->CreateShaderResourceView(texture, nullptr, &srv);
	if (FAILED(hr)) {
		// Handle error (e.g., log it or throw an exception)
		return nullptr;
	}

	return srv;
}




void Menu::DrawConfigs  () {
    const std::string path = "C:/JohnWickWare/";
	static char newConfigName[64]{ "\0" };

	auto style = ImGui::GetStyle();

	ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 0.0f);

	ImGui::SetNextItemWidth(ImGui::GetContentRegionAvail().x - style.FramePadding.x);

    if (ImGui::InputTextWithHint("", "Create New Config", newConfigName, sizeof(newConfigName), ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CharsNoBlank)) {
        std::cout << "SAVED CONFIG " << newConfigName << "\n";
        cfg::save(path + newConfigName + ".json");

		mainbinds.save(path + "/binds/binds.json");

		memset(newConfigName, 0, sizeof(newConfigName));
    }

	if (!ImGui::IsItemActivated()) {
		memset(newConfigName, 0, sizeof(newConfigName));
	}

	ImGui::Separator();

	ImVec2 oldcursorpos = ImGui::GetCursorPos();

	ImVec2 regionavail = ImGui::GetContentRegionAvail();

	ImGui::SetCursorPosY(regionavail.y * 0.8);

	ImGui::Separator();


	if (ImGui::Button("Unload"))
	{
		unloadRequested = true;
	}


	ImGui::SetCursorPos(oldcursorpos);

	regionavail = ImGui::GetContentRegionAvail();

	for (const std::filesystem::directory_entry& file : std::filesystem::directory_iterator{ path }) {

		if (!file.path().extension().string().ends_with(".json")) {
			continue;
		}

		auto tempcol = cfg::colors_MenuColor; tempcol.w = 0.5;

		ImGui::PushStyleColor(ImGuiCol_Button, tempcol);

        if (ImGui::Button(file.path().stem().string().c_str(), ImVec2(regionavail.x - style.FramePadding.x, Helper::GetResolution().y * 0.0))) {
            ImGui::OpenPopup(file.path().stem().string().c_str()); // Open the popup when the button is clicked
        }

		ImGui::PopStyleColor();

		if (ImGui::BeginPopupModal(file.path().stem().string().c_str(), nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {

			if (GetAsyncKeyState(VK_ESCAPE)) {
				ImGui::CloseCurrentPopup();
			}
			
			Helper::CenterText("Select Action");

			if (ImGui::Button("Load")) {
				cfg::load(file.path().string());
				mainbinds.load(file.path().parent_path().string() + "/binds/binds.json");
				std::cout << "Loaded Config : " << file.path().stem().string() << "\n";
				ImGui::CloseCurrentPopup();
			}
			ImGui::SameLine();
				if (ImGui::Button("Save")) {
					cfg::save(file.path().string());

					mainbinds.save(file.path().parent_path().string() + "/binds/binds.json");

					std::cout << "Saved Config : " << file.path().stem().string() << "\n";
					ImGui::CloseCurrentPopup();
				}
			ImGui::SameLine();
			if (ImGui::Button("Delete")) {
				remove(file.path().string().data());
				std::cout << "Deleted Config : " << file.path().stem().string() << "\n";
				ImGui::CloseCurrentPopup();
			}
			ImGui::EndPopup();
		}


	}

	ImGui::PopStyleVar();

}

void DrawMapObjsEspTab(vec2 res) {

	auto cursorposy = ImGui::GetCursorPosY();

	float spacing_x = res.x * 0.01;
	float spacing_y = res.y * 0.02;

	ImGui::SetCursorPosX(spacing_x);
	ImGui::SetCursorPosY(cursorposy + spacing_y);

	ImVec2 regionavailable = ImGui::GetContentRegionAvail();

	ImVec2 espmisctabsize = ImVec2(regionavailable.x - (spacing_x * 2), regionavailable.y - spacing_y);

	ImGui::BeginChild("Lootables", espmisctabsize, true, ImGuiWindowFlags_AlwaysAutoResize); \

		menu.checkbox("Souls", &cfg::esp_DrawXp);
	ImGui::SameLine();
	ImGui::ColorEdit4("Souls Esp Color", (float*)&cfg::colors_drawxpcol);

	menu.checkbox("Neutral Monsters", &cfg::esp_DrawMonsters);
	ImGui::SameLine();
	ImGui::ColorEdit4("Monster Esp Color", (float*)&cfg::colors_drawmonsterscol);

	menu.checkbox("Minions", &cfg::esp_DrawMinions);
	menu.checkbox("Towers", &cfg::esp_drawTowers);


	ImGui::EndChild();

}

void DrawMiscEspTab(vec2 res) {

	auto cursorposy = ImGui::GetCursorPosY();

	float spacing_x = res.x * 0.01;
	float spacing_y = res.y * 0.02;

	ImGui::SetCursorPosX(spacing_x);
	ImGui::SetCursorPosY(cursorposy + spacing_y);

	ImVec2 regionavailable = ImGui::GetContentRegionAvail();

	ImVec2 espmisctabsize = ImVec2(regionavailable.x - (spacing_x * 2), regionavailable.y - spacing_y);

	ImGui::BeginChild("Esp Misc", espmisctabsize, true);

	menu.checkbox("World Modulation", &cfg::esp_ModWorld);
	ImGui::SameLine();
	ImGui::ColorEdit4("World Color", (float*)&cfg::colors_WorldModulationColor);

	menu.checkbox("Light Modulation", &cfg::esp_ModLights);
	ImGui::SameLine();
	ImGui::ColorEdit4("Lights Color", (float*)&cfg::colors_LightModColor);

	menu.checkbox("Aimbot Fov", &cfg::esp_DrawFov);
	ImGui::SameLine();
	ImGui::ColorEdit4("Fov Circle Color", (float*)&cfg::colors_drawfovcol);

	menu.checkbox("Aimbot Target", &cfg::esp_DrawAimbotTarget);
	ImGui::SameLine();
	ImGui::ColorEdit4("Aimbot Target Color", (float*)&cfg::colors_aimbotTargetcol);

	menu.checkbox("Show Keybind List", &cfg::esp_ShowKeyBindList);

	menu.checkbox("Show Watermark", &cfg::esp_DrawWaterMark);

	ImGui::SliderFloat("Fov", &cfg::misc_fov, 0.1f, 180.0f, "%.3f");

	ImGui::Spacing();

	ImGui::Text("Menu Color");
	ImGui::SameLine();
	ImGui::ColorEdit3("Menu Color", (float*)&cfg::colors_MenuColor);

	ImGui::EndChild();

}

void DrawTeammatesEspTab(vec2 res) {

	auto cursorposy = ImGui::GetCursorPosY();

	float spacing_x = res.x * 0.01;
	float spacing_y = res.y * 0.02;

	ImGui::SetCursorPosX(spacing_x);
	ImGui::SetCursorPosY(cursorposy + spacing_y);


	ImVec2 regionavailable = ImGui::GetContentRegionAvail();

	ImVec2 drawablestabsize = ImVec2(regionavailable.x * 0.45, regionavailable.y - spacing_y);


	ImGui::BeginChild("drawables", drawablestabsize, true);

	menu.checkbox("Enabled", &cfg::esp_bEsp);

	menu.checkbox("Bounding Box", &cfg::esp_tBoxEsp);
	ImGui::SameLine();
	ImGui::ColorEdit4("Box Color", (float*)&cfg::colors_tBoxespcol);

	menu.checkbox("Health Bar", &cfg::esp_tHealthBar);
	menu.checkbox("Health Text", &cfg::esp_tHealthText);

	menu.checkbox("Skeleton", &cfg::esp_tBoneEsp);
	ImGui::SameLine();
	ImGui::ColorEdit4("Skeleton Color", (float*)&cfg::colors_tSkeletoncol);

	menu.checkbox("Name", &cfg::esp_tNameEsp);

	menu.checkbox("Tracers", &cfg::esp_tTracers);

	menu.checkbox("Distance", &cfg::esp_tDistanceEsp);

	ImGui::EndChild();

	ImGui::SameLine(0.f, spacing_x * 2);

	regionavailable = ImGui::GetContentRegionAvail();

	ImGui::BeginChild("Models", ImVec2(regionavailable.x - (spacing_x * 2), regionavailable.y - spacing_y), true);

	menu.checkbox("Chams", &cfg::esp_tChams);
	ImGui::SameLine();
	ImGui::ColorEdit4("Chams Color", (float*)&cfg::colors_tChamsCol);

	menu.checkbox("Override Model Material", &cfg::esp_tModelChams);

	menu.checkbox("Glow", &cfg::esp_tGlowEsp);
	ImGui::SameLine();
	ImGui::ColorEdit4("Glow Color", (float*)&cfg::colors_tGlowCol);


	ImGui::EndChild();
}

void DrawEnemyPlayersEspTab(vec2 res) {

	auto cursorposy = ImGui::GetCursorPosY();

	float spacing_x = res.x * 0.01;
	float spacing_y = res.y * 0.02;

	ImGui::SetCursorPosX(spacing_x);
	ImGui::SetCursorPosY(cursorposy + spacing_y);


	ImVec2 regionavailable = ImGui::GetContentRegionAvail();

	ImVec2 drawablestabsize = ImVec2(regionavailable.x * 0.45, regionavailable.y - spacing_y);


	ImGui::BeginChild("drawables", drawablestabsize, true);

	menu.checkbox("Enabled", &cfg::esp_bEsp);

	menu.checkbox("Bounding Box", &cfg::esp_eBoxEsp);
	ImGui::SameLine();
	ImGui::ColorEdit4("Box Color", (float*)&cfg::colors_eBoxespcol);

	menu.checkbox("Health Bar", &cfg::esp_eHealthBar);
	menu.checkbox("Health Text", &cfg::esp_eHealthText);

	menu.checkbox("Skeleton", &cfg::esp_eBoneEsp);
	ImGui::SameLine();
	ImGui::ColorEdit4("Skeleton Color", (float*)&cfg::colors_eSkeletoncol);

	menu.checkbox("Name", &cfg::esp_eNameEsp);

	menu.checkbox("Tracers", &cfg::esp_eTracers);

	menu.checkbox("Distance", &cfg::esp_eDistanceEsp);

	ImGui::EndChild();

	ImGui::SameLine(0.f, spacing_x * 2);

	regionavailable = ImGui::GetContentRegionAvail();

	ImGui::BeginChild("Models", ImVec2(regionavailable.x - (spacing_x * 2), regionavailable.y - spacing_y), true);

	menu.checkbox("Chams", &cfg::esp_eChams );
	ImGui::SameLine();
	ImGui::ColorEdit4("Chams Color", (float*)&cfg::colors_eChamsCol);

	menu.checkbox("Override Model Material", &cfg::esp_eModelChams);

	menu.checkbox("Glow", &cfg::esp_eGlowEsp);
	ImGui::SameLine();
	ImGui::ColorEdit4("Glow Color", (float*)&cfg::colors_eGlowCol);


	ImGui::EndChild();



	

}

void Menu::DrawEspTab() {


	auto res = Helper::GetResolution();

	ImGui::SetCursorPos(ImVec2(res.x * 0.01, res.y * 0.013));

	ImVec2 regionavailable = ImGui::GetContentRegionAvail();

	const char* tabs[] = { "Enemies", "Teammates", "Map Objects", "Misc"};

	int numtabs = 4;

	static int selectedTab = 0;

	//ImGui::Text((const char*)u8"");

	ImVec2 esptabsize = ImVec2(regionavailable.x - res.x * 0.02, regionavailable.y * 0.1);

	ImGui::BeginChild("Esp Tabs", esptabsize, true);

	ImGuiIO& io = ImGui::GetIO();           // Get the ImGui IO structure
	ImFontAtlas* fontAtlas = io.Fonts;      // Get the font atlas
	ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);

	regionavailable = ImGui::GetContentRegionAvail();

	float esptabbuttonspacing = res.x * 0.01;

	for (int i = 0; i < numtabs; i++) {

		bool selected = false;
		if (i == selectedTab)
			selected = true;

		if (ImGui::Button(tabs[i], ImVec2(regionavailable.x * (1.f / numtabs) - esptabbuttonspacing, regionavailable.y))) {
			selectedTab = i;
		}

		ImGui::SameLine(0.f, esptabbuttonspacing);

	}

	ImGui::PopFont();
	ImGui::EndChild();

	regionavailable = ImGui::GetContentRegionAvail();

	if (selectedTab == 0) {
		DrawEnemyPlayersEspTab(res);
	}
	else if (selectedTab == 1) {
		DrawTeammatesEspTab(res);
	}
	else if (selectedTab == 2) {
		DrawMapObjsEspTab(res);
	}
	else if (selectedTab == 3) {
		DrawMiscEspTab(res);
	}

}

void Menu::DrawHeroesTab() {

	float topGap = 25.0f; // Adjust this value for the desired gap size
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + topGap);
	ImVec2 childPos = ImGui::GetCursorScreenPos();
	ImVec2 titlePos = ImVec2(childPos.x + 5.0f, childPos.y - ImGui::GetFontSize()); // Adjust Y for positioning above the border
	ImGui::GetWindowDrawList()->AddText(titlePos, IM_COL32(255, 255, 255, 255), "Heroes");

	if (!(iEngine->IsInGame())) {
		ImGui::Text("Join a game to use the hero tab.");
		return;
	}

	ImGui::BeginChild("main_heroes", ImVec2(0, ImGui::GetContentRegionAvail().y / 2), true, ImGuiWindowFlags_AlwaysAutoResize);

	ImGui::SliderFloat("Abilities Max Distance", &cfg::heroes_maxdistance, 0.f, 5000.f);
	ImGui::SliderFloat("Abilites FOV", &cfg::heroes_fov, 0.f, 180.f);

	ImGui::EndChild();


	ImGui::BeginChild("Heroes", ImVec2(0, 0), true);
	PlayerData* plrdata = new PlayerData;
	Helper::get_player_data(Helper::get_local_player(), plrdata);
	switch (plrdata->HeroID) {

	case Abrams: {
		ImGui::Text("Abrams");
		break;
	}
	case Bebop: {
		ImGui::Text("Bebop");
		menu.checkbox("Auto Aim Hook", &cfg::bebop_AimHook);
		menu.checkbox("Auto Apply Bomb", &cfg::bebop_AutoBomb);
		menu.checkbox("Auto UpperCut", &cfg::bebop_AutoUppercut);
		break;
	}
	case Dynamo: {
		ImGui::Text("Dynamo");
		break;
	}
	case GreyTalon: {
		ImGui::Text("GreyTalon");
		break;
	}
	case Haze: {
		ImGui::Text("Haze");
		menu.checkbox("Aim Dagger", &cfg::haze_AimDagger);
		break;
	}
	case Infernus: {
		ImGui::Text("Infernus");
		menu.checkbox("Aim Fire", &cfg::infernus_AimCatalyst);
		break;
	}
	case Ivy: {
		ImGui::Text("Ivy");
		menu.checkbox("Aim Bomb", &cfg::ivy_AimBomb);
		break;
	}
	case Kelvin: {
		ImGui::Text("Kelvin");
		menu.checkbox("Aim Grenade", &cfg::kelvin_AimGrenade);
		menu.checkbox("Lockon Ice Beam", &cfg::kelvin_LockBeam);
		break;
	}
	case LadyGeist: {
		ImGui::Text("LadyGeist");
		menu.checkbox("Aim Grenade", &cfg::ladygeist_AimBomb);
		menu.checkbox("Aim Knives", &cfg::ladygeist_AimMalice);
		break;
	}
	case Lash: {
		ImGui::Text("Lash");
		break;
	}
	case McGinnis: {
		ImGui::Text("McGinnis");
		break;
	}
	case Mirage: {
		ImGui::Text("Mirage");
		menu.checkbox("Aim Tornado",&cfg::mirage_AimTornado);
		menu.checkbox("Aim Scarabs",&cfg::mirage_AimScarabs);
		break;
	}
	case MoAndKrill: {
		ImGui::Text("MoAndKrill");
		break;
	}
	case Paradox: {
		ImGui::Text("Paradox");
		menu.checkbox("Aim Grenade", &cfg::paradox_AimGrenade);
		menu.checkbox("Aim Swap", &cfg::paradox_AimSwap);
		break;
	}
	case Pocket: {
		ImGui::Text("Pocket");
		menu.checkbox("Aim Barrage", &cfg::pocket_AimBarrage);
		menu.checkbox("Aim Cloak", &cfg::pocket_AimCloak);
		break;
	}
	case Seven: {
		ImGui::Text("Seven");
		menu.checkbox("Aim Lighting Ball", &cfg::seven_AimLightingBall);
		menu.checkbox("Auto Apply Static Charge", &cfg::seven_AutoStaticCharge);
		break;
	}
	case Shiv: {
		ImGui::Text("Shiv");
		menu.checkbox("Auto Aim Dagger", &cfg::shiv_AutoAimDagger);
		menu.checkbox("Auto Aim Dash", &cfg::shiv_AutoAimDash);
		menu.checkbox("Auto Execute", &cfg::shiv_AutoExecute);
		break;
	}
	case Vindicta: {
		ImGui::Text("Vindicta");
		menu.checkbox("Auto Aim Stake", &cfg::vindicta_AutoAimStake);
		menu.checkbox("Auto Aim Crow", &cfg::vindicta_AutoAimCrow);
		menu.checkbox("Auto Snipe", &cfg::vindicta_AutoSnipe);
		ImGui::SameLine();
		// Directly use a temporary variable for the slider
		float f = cfg::vindicta_AutoUltHealthPercent * 100.0f; // Temporary variable
		ImGui::SliderFloat("HP%", &f, 0.0f, 100.0f, " %.0f%%");
		// Update the config value after the slider adjustment
		cfg::vindicta_AutoUltHealthPercent = f / 100.0f;
		break;
	}
	case Viscous: {
		ImGui::Text("Viscous");
		menu.checkbox("Aim Grenade", &cfg::viscous_AimGooGrenade);
		break;
	}
	case Warden: {
		ImGui::Text("Warden");
		menu.checkbox("Aim Grenade", &cfg::warden_AimLightingGrenade);
		break;
	}
	case Wraith: {
		ImGui::Text("Wraith");
		menu.checkbox("Aim Cards", &cfg::wraith_AimCards);
		break;
	}
	case Yamato: {
		ImGui::Text("Yamato");
		menu.checkbox("Aim Power Slash", &cfg::yamato_AimPowerSlash);
		menu.checkbox("Aim Crimson Slash", &cfg::yamato_AimCrimsonSlash);
		break;
	}
	case Calico: {
		ImGui::Text("Calico");
		menu.checkbox("Aim Bombs", &cfg::calico_AimBombs);
		menu.checkbox("Aim Dash", &cfg::calico_AimDash);
		break;
	}
	default: {
		ImGui::Text("Please Enter A Game");
		break;
	}
	}

	delete plrdata;

	ImGui::EndChild();

}

void Menu::DrawRageBotTab() {


	auto res = Helper::GetResolution();
	bool rageboton = cfg::ragebot_masterswitch;

	if (!rageboton) {
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.25f, 0.25f, 0.25f, 1.0f));
	}


	ImGui::SetCursorPos(ImVec2(res.x * 0.01, res.y * 0.013));

	ImVec2 regionavailable = ImGui::GetContentRegionAvail();

	float spacing = res.x * 0.02; 
	float childWidth = (regionavailable.x - spacing) / 2; 

	ImGui::BeginChild("MainRage", ImVec2(childWidth, regionavailable.y - res.y * 0.02), true);

	menu.checkbox("RageBot", &cfg::ragebot_masterswitch);
	menu.checkbox("Enabled", &cfg::ragebot_bAimbot);

	menu.checkbox("Silent Aim", &cfg::ragebot_silentaim);

	static const char* items[] = { "Distance", "Lowest Health", "FOV" }; // Options for the dropdown
	//static int currentItem = 0; // Index of the currently selected item
	ImGui::Combo("Target ", &cfg::ragebot_TargetSelectMode, items, IM_ARRAYSIZE(items));
	ImGui::SliderFloat("Distance", &cfg::ragebot_maxdistance, 0.0f, 5000.0f, "%.1f");
	ImGui::SliderFloat("FOV", &cfg::ragebot_aimfov, 0.0f, 180.0f, "%.1f");
	menu.checkbox("Souls", &cfg::ragebot_AimXp);
	menu.checkbox("Minions", &cfg::ragebot_AimMinions);


	ImGui::EndChild();


	ImGui::SameLine(0.f, spacing);

	regionavailable = ImGui::GetContentRegionAvail();

	float antiAimWidth = regionavailable.x - childWidth - spacing;

	ImGui::BeginChild("AntiAim", ImVec2(antiAimWidth, regionavailable.y * 0.45), true);
	ImGui::Text("Anti Aim");
	menu.checkbox("Enabled", &cfg::antiaim_bAntiAim);
	static const char* AAitems[] = { "Spin", "Jitter", "180 Treehouse" }; // Options for the dropdown
	static int AAcurrentItem = 0; // Index of the currently selected item
	ImGui::Combo("Type", &AAcurrentItem, AAitems, IM_ARRAYSIZE(AAitems)); cfg::antiaim_AAtype = AAcurrentItem;

	if (cfg::antiaim_AAtype == 0) {
		ImGui::SliderFloat("Speed X", &cfg::antiaim_SpinPitchChange, 1.0f, 100.0f);
		ImGui::SliderFloat("Speed Y", &cfg::antiaim_SpinYawChange,1.0f,100.0f);
	}
	else if (cfg::antiaim_AAtype == 1) {
		ImGui::SliderFloat("Range Low", &cfg::antiaim_lowerjitter, -180, cfg::antiaim_upperjitter, "%.1f");
		ImGui::SliderFloat("Range High", &cfg::antiaim_upperjitter, cfg::antiaim_lowerjitter, 180.0f, "%.1f");
	}

	ImGui::EndChild();

	ImGui::SetCursorPos(ImVec2(childWidth + spacing * 1.5, regionavailable.y * 0.5));

	regionavailable = ImGui::GetContentRegionAvail();

	ImGui::BeginChild("RageBotMisc", ImVec2(antiAimWidth, regionavailable.y - (res.y * 0.02)), true);

	menu.checkbox("Magic Bullet", &cfg::ragebot_magicbullet);

	ImGui::EndChild();


	if (!rageboton) {
		ImGui::PopStyleColor();
	}




}

void Menu::DrawLegitBotTab() {

	auto res = Helper::GetResolution();

	bool legitboton = cfg::legitbot_masterswitch;

	if (!legitboton) {
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.25f, 0.25f, 0.25f, 1.0f));
	}

	ImGui::SetCursorPos(ImVec2(res.x * 0.01, res.y * 0.013));

	ImVec2 regionavailable = ImGui::GetContentRegionAvail();

	float spacing = res.x * 0.02;
	float childWidth = (regionavailable.x - spacing);

	ImGui::BeginChild("MainLegit", ImVec2(childWidth, regionavailable.y - res.y * 0.02), true);

	menu.checkbox("LegitBot", &cfg::legitbot_masterswitch);

	menu.checkbox("Enabled", &cfg::legitbot_bLegitBot);

	menu.checkbox("Pitch Correction", &cfg::legitbot_pitchcorrection);
		ImGui::SameLine();
		ImGui::SliderFloat("##PitchAmmount", &cfg::legitbot_pitchcorrectammount, 0.0f, 1.0f, "%.2f");

	menu.checkbox("Yaw Correction", &cfg::legitbot_yawcorrection);
		ImGui::SameLine();
		ImGui::SliderFloat("##YawAmmount", &cfg::legitbot_yawcorrectammount, 0.0f, 1.0f, "%.2f");

	ImGui::SliderInt("Aim Delay(MS)", &cfg::legitbot_aimdelayinms, 0, 1000);

	ImGui::SliderFloat("FOV", &cfg::legitbot_fov, 0.0f, 90.0f);
	ImGui::SliderFloat("Smooth", &cfg::legitbot_smooth, 1.0f, 200.0f);

	ImGui::EndChild();

	if (!legitboton) {
		ImGui::PopStyleColor();
	}

	

}

void Menu::DrawConfigTab(FILE* fp) {

	float ConfigWindowWidth = ImGui::GetContentRegionAvail().x;
	float ConfigWindowHeight = ImGui::GetContentRegionAvail().y;

	float topGap = 25.0f; // Adjust this value for the desired gap size
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + topGap);

	ImVec2 childPos = ImGui::GetCursorScreenPos();
	ImVec2 titlePos = ImVec2(childPos.x + 5.0f, childPos.y - ImGui::GetFontSize()); // Adjust Y for positioning above the border
	ImGui::GetWindowDrawList()->AddText(titlePos, IM_COL32(255, 255, 255, 255), "Miscellaneous");

	ImGui::BeginChild("MainMisc", ImVec2(ConfigWindowWidth * 0.5, 0.0f), true);

	menu.checkbox("No Recoil", &cfg::misc_bNorecoil);

	menu.checkbox("Auto Active Reload", &cfg::misc_autoactivereload);

	ImGui::EndChild();

	ImGui::SameLine();

	// Get the current screen position of the cursor (where the child window will start)
	ImVec2 ConfigchildPos = ImGui::GetCursorScreenPos();
	ImVec2 ConfigtitlePos = ImVec2(ConfigchildPos.x + 5.0f, ConfigchildPos.y - ImGui::GetFontSize()); // Adjust Y for positioning above the border
	ImGui::GetWindowDrawList()->AddText(ConfigtitlePos, IM_COL32(255, 255, 255, 255), "Configs");

	ImGui::BeginChild("ConfigArea", ImVec2(0, 0), true);




	DrawConfigs();


	ImGui::EndChild();

}

void Menu::checkbox(const char* label, bool* v) {


	static bool waswaiting = false;

	ImGui::Checkbox(label, v);

	std::string uniqueId = std::string(label) + "_" + std::to_string(reinterpret_cast<uintptr_t>(v));

	if (ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
		ImGui::OpenPopup(uniqueId.c_str());
		waswaiting = true;
	}

	auto findCfgVar = [v]() -> cfgvar* const
		{
			for (cfgvar* const cfg_var : getInsts<cfgvar>())
			{
				if (cfg_var->m_data != v) {
					continue;
				}

				return cfg_var;
			}

			return nullptr;
	};

	cfgvar* cfg_var{ findCfgVar() };

	if (ImGui::BeginPopup(uniqueId.c_str())) {

		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f,1.f,1.f,1.f));

		static int newkey = 0;

		static bool waitingforkey = false;

		if (waswaiting) {
			waitingforkey = false;
			waswaiting = false;
		}


		static char bindname[64]{ "\0" };
		static int type;
		const char* items[] = { "Toggle", "Hold" };
		

		ImGui::InputTextWithHint("", "Bind Name", bindname, sizeof(bindname));

		if (waitingforkey) {
			ImGui::Button("...");
			for (auto key : KeyCodes) {
				if (GetAsyncKeyState(key) & 0x8000) {

					if (key == VK_ESCAPE) {
						memset(bindname, 0, sizeof(bindname));
						type = 0;
						newkey = 0;
						ImGui::CloseCurrentPopup();
					}

					newkey = key;
					waitingforkey = false;
				}
			}
		}
		else {
			if (ImGui::Button(KeyNames[newkey])) {
				waitingforkey = true;
			}
		}

		ImGui::Combo("Mode", &type, items, IM_ARRAYSIZE(items));

		if(ImGui::Button("Save")) {

			Bind newbind;

			newbind.type = type;
			newbind.name = bindname;
			newbind.configvar = cfg_var;
			newbind.val_off = false;
			newbind.val_on = true;
			newbind.key = newkey;

			mainbinds.addbind(newbind);

			memset(bindname, 0, sizeof(bindname));
			type = 0;
			newkey = 0;

			ImGui::CloseCurrentPopup();

		}

		ImGui::PopStyleColor();

		ImGui::EndPopup();


	}



}

static bool searching = false;

void Menu::DrawNewMenu(FILE* fp, ID3D11Device* dx11Device) {


	/*if (ImGui::Begin("CustomMaterialInput")) {

		// Multi-line text input for material buffer
		ImGui::InputTextMultiline("##MaterialBuffer", quickiterationmaterial, sizeof(quickiterationmaterial),
			ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 8),
			ImGuiInputTextFlags_AllowTabInput);

		if (ImGui::Button("Create Material")) {
			if (!firstreplacedmaterial)
				firstreplacedmaterial = true;
			replacedmaterial = true;
		}

		ImGui::End();
	}
	*/



	ImVec4* colors = ImGui::GetStyle().Colors;

	ImVec4 menuColor = ImVec4(cfg::colors_MenuColor.x, cfg::colors_MenuColor.y, cfg::colors_MenuColor.z, 1.0f); // Get the menu color

		colors[ImGuiCol_Border] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 0.24f);
		colors[ImGuiCol_TitleBg] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 1.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 0.85);
		colors[ImGuiCol_SliderGrab] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 0.85);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 0.85);
		colors[ImGuiCol_ButtonHovered] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 0.95);
		colors[ImGuiCol_ButtonActive] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 1.00f);
		colors[ImGuiCol_Separator] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 0.50f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 0.24f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 0.24f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 0.68f);
		colors[ImGuiCol_Tab] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 1.00f);
		colors[ImGuiCol_TabHovered] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 1.00f);
		colors[ImGuiCol_TabActive] = ImVec4(menuColor.x, menuColor.y, menuColor.z, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 0.98f);


	// Variable to hold the selected tab
	static int selectedTab = 0;

	// Number of tabs
	const int numTabs = 5;

	auto minsize = ImVec2(500, 500);
	auto maxsize = ImVec2(3840, 1440);

	ImGui::SetNextWindowSizeConstraints(minsize, maxsize);

	const ImVec2 zero(0.0f, 0.0f);
	const ImVec2 eight(8.0f, 8.0f);

	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, zero);
	ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, zero);
	
	/*	if (ImGui::Begin("Search", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {

		static char searchbuffer[32]{ '\0' };

		if (ImGui::InputTextWithHint(" ", "Search", searchbuffer, sizeof(searchbuffer), ImGuiInputTextFlags_EnterReturnsTrue | ImGuiInputTextFlags_CharsNoBlank)) {
		}

		std::string search = searchbuffer; // Search string

		if (!(search.empty())) {

			for (cfgvar* const var : getInsts<cfgvar>()) {

				std::string varname = var->m_name; // Access the variable name

				// Convert both strings to lowercase
				std::transform(varname.begin(), varname.end(), varname.begin(), ::tolower);
				std::transform(search.begin(), search.end(), search.begin(), ::tolower);

				// Check if the search string is found in the variable name
				if (varname.find(search) != std::string::npos) {
					// Display and edit the variable based on its type
					if (var->typehash == typeid(bool).hash_code()) {
						ImGui::Checkbox(var->m_name.c_str(), reinterpret_cast<bool*>(var->m_data));
					}
					else if (var->typehash == typeid(int).hash_code()) {
						ImGui::SliderInt(var->m_name.c_str(), reinterpret_cast<int*>(var->m_data), 1, 100);
					}
					else {
						ImGui::Text("Unsupported Type");
					}
				}

			}

		}

		ImGui::End();

	}*/

	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
	ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 0.0f);

	if (ImGui::Begin("Sovereign", NULL, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar)) {
		// Force all relevant style properties to zero


		float availableWidth = ImGui::GetWindowWidth();
		float availableHeight = ImGui::GetWindowHeight();
		float buttonHeight = availableHeight / numTabs;
		float buttonwidth = 130;

		// Create button area child with explicit border flag off
		ImGui::BeginChild("Button Area", ImVec2(buttonwidth, availableHeight), true,
			ImGuiWindowFlags_NoScrollbar |
			ImGuiWindowFlags_NoScrollWithMouse);

		ImGui::PopStyleVar(4); // padding and spacing

		// Button styles
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.1f, 0.1f, 0.1f, 1.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));


		const char* glphs[] = { (const char*)u8"" , (const char*)u8"" , (const char*)u8"" , (const char*)u8"", (const char*)u8"" };


		if (buttonHeight < 80)
			buttonHeight = 80;


		ImGuiIO& io = ImGui::GetIO();           // Get the ImGui IO structure
		ImFontAtlas* fontAtlas = io.Fonts;      // Get the font atlas
		ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[2]);

		for (int i = 0; i < numTabs; i++) {

			bool selected = false;
			if (i == selectedTab)
				selected = true;

			if (GlyphButton(glphs[i], ImVec2(buttonwidth, buttonHeight), selected)) {
				selectedTab = i;
			}


		}



		//ImGui::Text((const char*)u8"");

		ImGui::PopFont();

		ImGui::PopStyleColor(3);
		ImGui::EndChild();

		ImGui::SameLine();

		// Content area with explicit dimensions
		ImGui::BeginChild("Content Area", ImVec2(availableWidth - buttonwidth, availableHeight), false, ImGuiWindowFlags_NoResize);

		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, ImVec2(6.f, 6.f));



		ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4(0.05f,0.05f,0.05f,1.0f));

		switch (selectedTab) {
		case 0: DrawRageBotTab(); break;
		case 1: DrawLegitBotTab(); break;
		case 2: DrawEspTab(); break;
		case 3: DrawHeroesTab(); break;
		case 4: DrawConfigTab(fp); break;
		}

		ImGui::PopStyleVar();
		ImGui::PopStyleColor();
		ImGui::EndChild();

	}
	ImGui::End();

}

void Menu::DrawBackround() {
	// Remove any padding or margins
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);

	// Create a child window that covers the entire viewport
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
	ImGui::Begin("Background", nullptr,
		ImGuiWindowFlags_NoDecoration
		| ImGuiWindowFlags_NoInputs |
		ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBackground);

	ImDrawList* drawList = ImGui::GetWindowDrawList();

	// Draw semi-transparent dark background
	drawList->AddRectFilled(
		ImVec2(0, 0), ImGui::GetIO().DisplaySize, IM_COL32(0, 0, 0, 128)); // Semi-transparent black

	ImGui::End(); // End the "Background" window

	// Reset style variables (good practice)
	ImGui::PopStyleVar(2);
}


