
#include "Menu.h"
#include "D3D11.h"
#include <wrl/client.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using Microsoft::WRL::ComPtr;

bool GlyphButton(const char* glyph, ImVec2 size, bool selecctedtab) {
	// Create base button

	if (selecctedtab) {
		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
	}

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
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
	}
	else {
		ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.25, 0.25f, 0.25f, 1.0f));
	}


	ImGui::Text(glyph);

	ImGui::PopStyleColor();

	ImGui::SetCursorPos(cursorPos);

	if (selecctedtab) {
		ImGui::PopStyleVar();
	}

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


void Menu::DrawConfigs() {

	static bool showsaveConfirmPopup = false;
	static bool showloadConfirmPopup = false;
	static bool showDeleteConfirmPopup = false;

	static bool refreshed = false;
	if (!refreshed)
		Config.RefreshConfigs(); refreshed = true;

	if (ImGui::Button("Load Config")) {
		showloadConfirmPopup = true;
	}
	if (ImGui::Button("Save Config")) {
		showsaveConfirmPopup = true;
	}
	if (ImGui::Button("Delete Config")) {
		showDeleteConfirmPopup = true;
	}
	if (ImGui::Button("Refresh Configs")) {
		Config.RefreshConfigs();
	}

	static char newConfigName[256];

	if (ImGui::Button("Create Config")) {
		char fullConfigName[256];
		strcpy_s(fullConfigName, newConfigName);
		Config.SaveConfig(fullConfigName);
		Config.RefreshConfigs();
		strcpy_s(newConfigName, "");
	}

	ImGui::InputTextWithHint("", "New Config", newConfigName, sizeof(newConfigName));



	for (int i = 0; i < Config.configs.size(); i++) {

		auto config_name = Config.configs[i];
		bool selected = (i == Config.selectedconfig);

		if (ImGui::Selectable(config_name.c_str(), &selected)) {
			Config.selectedconfig = i;
		}

		if (selected) {
			ImGui::SetItemDefaultFocus();
		}

	}

	if (showsaveConfirmPopup) {
		ImGui::OpenPopup("Confirm Save");
	}
	if (showloadConfirmPopup) {
		ImGui::OpenPopup("Confirm Load");
	}
	if (showDeleteConfirmPopup) {
		ImGui::OpenPopup("Confirm Delete");
	}

	if (ImGui::BeginPopupModal("Confirm Save", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
		ImGui::Text("Are you sure you want to save this configuration?");
		ImGui::Separator();

		// Yes button
		if (ImGui::Button("Yes")) {
			ConfigSettings::SaveConfig(Config.configs[Config.selectedconfig]);
			showsaveConfirmPopup = false; // Close the popup
			ImGui::CloseCurrentPopup(); // Also closes the popup
		}

		// No button
		ImGui::SameLine();
		if (ImGui::Button("No")) {
			showsaveConfirmPopup = false; // Close the popup
			ImGui::CloseCurrentPopup(); // Closes the popup
		}

		ImGui::EndPopup();
	}

	if (ImGui::BeginPopupModal("Confirm Load", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
		ImGui::Text("Are you sure you want to load this configuration?");
		ImGui::Separator();

		// Yes button
		if (ImGui::Button("Yes")) {
			ConfigSettings::LoadConfig(Config.configs[Config.selectedconfig]);
			showloadConfirmPopup = false; // Close the popupn
			ImGui::CloseCurrentPopup(); // Also closes the popup
		}

		// No button
		ImGui::SameLine();
		if (ImGui::Button("No")) {
			showloadConfirmPopup = false; // Close the popup
			ImGui::CloseCurrentPopup(); // Closes the popup
		}

		ImGui::EndPopup();
	}

	if (ImGui::BeginPopupModal("Confirm Delete", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
		ImGui::Text("Are you sure you want to delete this configuration?");
		ImGui::Separator();

		// Yes button
		if (ImGui::Button("Yes")) {
			Config.DeleteConfig(Config.configs[Config.selectedconfig]);
			showDeleteConfirmPopup = false; // Close the popup
			ImGui::CloseCurrentPopup(); // Also closes the popup
		}

		// No button
		ImGui::SameLine();
		if (ImGui::Button("No")) {
			showDeleteConfirmPopup = false; // Close the popup
			ImGui::CloseCurrentPopup(); // Closes the popup
		}

		ImGui::EndPopup();
	}


}

void Menu::DrawEspTab() {

	float availableWidth = ImGui::GetContentRegionAvail().x;

	ImGui::BeginChild("Esp Drawables", ImVec2(availableWidth * 0.33, 0), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
	ImGui::Text("ESP");
	ImGui::Checkbox("Enabled", &Config.esp.bEsp);
	ImGui::Checkbox("Box Esp", &Config.esp.boxEsp);
	if (Config.esp.boxEsp) {
		ImGui::SameLine();
		ImGui::ColorEdit4("Box Color", (float*)&Config.colors.boxespcol);
	}

	ImGui::Checkbox("Skeleton Esp", &Config.esp.boneEsp);
	if (Config.esp.boneEsp) {
		ImGui::SameLine();
		ImGui::ColorEdit4("Skeleton Color", (float*)&Config.colors.skeletoncol);
	}

	ImGui::Checkbox("Health Bar", &Config.esp.HealthBar);

	ImGui::Checkbox("Tracers", &Config.esp.Tracers);

	ImGui::Checkbox("Name Esp", &Config.esp.NameEsp);

	ImGui::EndChild();

	ImGui::SameLine();

	ImGui::BeginChild("Chams", ImVec2(availableWidth * 0.33, 0), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	ImGui::Checkbox("Chams", &Config.esp.Chams);
	if (Config.esp.Chams) {
		ImGui::SameLine();
		ImGui::ColorEdit4("Chams Color", (float*)&Config.colors.ChamsCol);
		ImGui::Checkbox("Override Model Material", &Config.esp.ModelChams);
		ImGui::Checkbox("Local Chams", &Config.esp.LocalChams);
		if (Config.esp.LocalChams) {
			ImGui::SameLine();
			ImGui::ColorEdit4("Local Chams Color", (float*)&Config.colors.LocalChamsCol);
		}
	}

	ImVec2 childSize = ImGui::GetWindowSize();
	ImGui::SetCursorPosY(childSize.y / 2);
	ImGui::Separator();

	ImGui::Checkbox("World Modulation", &Config.esp.ModWorld);
	if (Config.esp.ModWorld) {
		ImGui::ColorEdit4("World Color", (float*)&Config.colors.WorldModulationColor);
	}
	ImGui::Checkbox("Light Modulation", &Config.esp.ModLights);
	if (Config.esp.ModWorld) {
		ImGui::ColorEdit4("Lights Color", (float*)&Config.colors.LightModColor);
	}

	ImGui::EndChild();

	ImGui::SameLine();

	ImGui::BeginChild("Esp Misc", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

	ImGui::Checkbox("Health Text", &Config.esp.HealthText);
	ImGui::Checkbox("Distance Esp", &Config.esp.DistanceEsp);
	ImGui::Checkbox("Draw Fov", &Config.esp.DrawFov);
	if (Config.esp.DrawFov) {
		ImGui::SameLine();
		ImGui::ColorEdit4("Fov Circle Color", (float*)&Config.colors.drawfovcol);
	}
	ImGui::Checkbox("Draw Souls", &Config.esp.DrawXp);
	if (Config.esp.DrawXp) {
		ImGui::SameLine();
		ImGui::ColorEdit4("Souls Esp Color", (float*)&Config.colors.drawxpcol);
	}
	ImGui::Checkbox("Draw Monsters", &Config.esp.DrawMonsters);
	if (Config.esp.DrawMonsters) {
		ImGui::SameLine();
		ImGui::ColorEdit4("Monster Esp Color", (float*)&Config.colors.drawmonsterscol);
	}
	ImGui::Checkbox("Draw Minions", &Config.esp.DrawMinions);
	ImGui::Checkbox("Draw Aimbot Target", &Config.esp.DrawAimbotTarget);
	if (Config.esp.DrawAimbotTarget) {
		ImGui::SameLine();
		ImGui::ColorEdit4("Aimbot Target Color", (float*)&Config.colors.aimbotTargetcol);
	}
	ImGui::Checkbox("Show Keybind List", &Config.esp.ShowKeyBindList);


	ImGui::EndChild();

}

void DrawAntiAimTab() {

	float topGap = 25.0f; // Adjust this value for the desired gap size
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + topGap);
	ImVec2 childPos = ImGui::GetCursorScreenPos();
	ImVec2 titlePos = ImVec2(childPos.x + 5.0f, childPos.y - ImGui::GetFontSize()); // Adjust Y for positioning above the border
	ImGui::GetWindowDrawList()->AddText(titlePos, IM_COL32(255, 255, 255, 255), "Anti Aim");

	ImGui::BeginChild("AntiAim", ImVec2(0, 0), true);
	ImGui::Checkbox("Enabled", &Config.antiaim.bAntiAim);
	static const char* items[] = { "Spin", "Jitter", "180 Treehouse" }; // Options for the dropdown
	static int currentItem = 0; // Index of the currently selected item
	ImGui::Combo("AAType", &currentItem, items, IM_ARRAYSIZE(items)); Config.antiaim.AAtype = currentItem;
	ImGui::Text("Selected: %s", items[currentItem]);
	ImGui::SliderFloat("Lower Jitter", &Config.antiaim.lowerjitter, -180, Config.antiaim.upperjitter, "%.1f");
	ImGui::SliderFloat("Upper Jitter", &Config.antiaim.upperjitter, Config.antiaim.lowerjitter, 180.0f, "%.1f");
	ImGui::EndChild();


}

void Menu::DrawHeroesTab() {

	float topGap = 25.0f; // Adjust this value for the desired gap size
	ImGui::SetCursorPosY(ImGui::GetCursorPosY() + topGap);
	ImVec2 childPos = ImGui::GetCursorScreenPos();
	ImVec2 titlePos = ImVec2(childPos.x + 5.0f, childPos.y - ImGui::GetFontSize()); // Adjust Y for positioning above the border
	ImGui::GetWindowDrawList()->AddText(titlePos, IM_COL32(255, 255, 255, 255), "Heroes");

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
		ImGui::Checkbox("Auto Aim Hook", &Config.bebop.AimHook);
		ImGui::Checkbox("Auto Apply Bomb", &Config.bebop.AutoBomb);
		ImGui::Checkbox("Auto UpperCut", &Config.bebop.AutoUppercut);
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
		ImGui::Checkbox("Aim Dagger", &Config.haze.AimDagger);
		break;
	}
	case Infernus: {
		ImGui::Text("Infernus");
		ImGui::Checkbox("Aim Fire", &Config.infernus.AimCatalyst);
		break;
	}
	case Ivy: {
		ImGui::Text("Ivy");
		ImGui::Checkbox("Aim Bomb", &Config.ivy.AimBomb);
		break;
	}
	case Kelvin: {
		ImGui::Text("Kelvin");
		ImGui::Checkbox("Aim Grenade", &Config.kelvin.AimGrenade);
		ImGui::Checkbox("Lockon Ice Beam", &Config.kelvin.LockBeam);
		break;
	}
	case LadyGeist: {
		ImGui::Text("LadyGeist");
		ImGui::Checkbox("Aim Grenade", &Config.ladygeist.AimBomb);
		ImGui::Checkbox("Aim Knives", &Config.ladygeist.AimMalice);
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
		ImGui::Checkbox("Aim Tornado",&Config.mirage.AimTornado);
		ImGui::Checkbox("Aim Scarabs",&Config.mirage.AimScarabs);
		break;
	}
	case MoAndKrill: {
		ImGui::Text("MoAndKrill");
		break;
	}
	case Paradox: {
		ImGui::Text("Paradox");
		ImGui::Checkbox("Aim Grenade", &Config.paradox.AimGrenade);
		ImGui::Checkbox("Aim Swap", &Config.paradox.AimSwap);
		break;
	}
	case Pocket: {
		ImGui::Text("Pocket");
		ImGui::Checkbox("Aim Barrage", &Config.pocket.AimBarrage);
		ImGui::Checkbox("Aim Cloak", &Config.pocket.AimCloak);
		break;
	}
	case Seven: {
		ImGui::Text("Seven");
		ImGui::Checkbox("Aim Lighting Ball", &Config.seven.AimLightingBall);
		ImGui::Checkbox("Auto Apply Static Charge", &Config.seven.AutoStaticCharge);
		break;
	}
	case Shiv: {
		ImGui::Text("Shiv");
		ImGui::Checkbox("Auto Aim Dagger", &Config.shiv.AutoAimDagger);
		ImGui::Checkbox("Auto Aim Dash", &Config.shiv.AutoAimDash);
		ImGui::Checkbox("Auto Execute", &Config.shiv.AutoExecute);
		break;
	}
	case Vindicta: {
		ImGui::Text("Vindicta");
		ImGui::Checkbox("Auto Aim Stake", &Config.vindicta.AutoAimStake);
		ImGui::Checkbox("Auto Aim Crow", &Config.vindicta.AutoAimCrow);
		ImGui::Checkbox("Auto Snipe", &Config.vindicta.AutoSnipe);
		// Directly use a temporary variable for the slider
		float f = Config.vindicta.AutoUltHealthPercent * 100.0f; // Temporary variable
		ImGui::SliderFloat("Auto Snipe Health %", &f, 0.0f, 100.0f, " %.0f%%");
		// Update the config value after the slider adjustment
		Config.vindicta.AutoUltHealthPercent = f / 100.0f;
		break;
	}
	case Viscous: {
		ImGui::Text("Viscous");
		ImGui::Checkbox("Aim Grenade", &Config.viscous.AimGooGrenade);
		break;
	}
	case Warden: {
		ImGui::Text("Warden");
		ImGui::Checkbox("Aim Grenade", &Config.warden.AimLightingGrenade);
		break;
	}
	case Wraith: {
		ImGui::Text("Wraith");
		break;
	}
	case Yamato: {
		ImGui::Text("Yamato");
		ImGui::Checkbox("Aim Power Slash", &Config.yamato.AimPowerSlash);
		ImGui::Checkbox("Aim Crimson Slash", &Config.yamato.AimCrimsonSlash);
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

	ImGui::BeginChild("RageBot General", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
	ImGui::Text("Aimbot");

	ImGui::Checkbox("Enabled", &Config.aimbot.bAimbot);
	ImGui::SameLine();
	Helper::HotKey(Config.aimbot.AimKey);
	ImGui::Checkbox("Silent Aim", &Config.aimbot.silentaim);
	ImGui::Checkbox("Movement Fix", &Config.aimbot.MovementFix);
	ImGui::Checkbox("Magic Bullet", &Config.aimbot.magicbullet);
	ImGui::SameLine();
	Helper::HotKey(Config.aimbot.magicbulletkey);

	static const char* items[] = { "Distance", "Lowest Health", "FOV" }; // Options for the dropdown
	//static int currentItem = 0; // Index of the currently selected item
	ImGui::Combo("Target ", &Config.aimbot.targetSelectionMode, items, IM_ARRAYSIZE(items));
	ImGui::Text("Selected: %s", items[Config.aimbot.targetSelectionMode]);
	ImGui::SliderFloat("Max Distance", &Config.aimbot.MaxDistance, 0.0f, 5000.0f, "%.1f");
	ImGui::SliderFloat("FOV", &Config.aimbot.fov, 0.0f, 180.0f, "%.1f");
	ImGui::Checkbox("Aim at Souls", &Config.aimbot.AimXp);
	ImGui::SameLine();
	Helper::HotKey(Config.aimbot.AimKeyXp);
	ImGui::Checkbox("Aim at Minions", &Config.aimbot.AimMinions);
	ImGui::SameLine();
	Helper::HotKey(Config.aimbot.AimKeyMinions);

	ImGui::EndChild();

}

void Menu::DrawLegitBotTab() {


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

	ImGui::Checkbox("No Recoil", &Config.misc.bNorecoil);
	ImGui::SliderFloat("Fov Multiplier", &Config.misc.fovmodifier, 0.1f, 2.0f, "%.3f");
	ImGui::Checkbox("Speed Boost", &Config.misc.SpeedBoost);
	if (Config.misc.SpeedBoost) {
		ImGui::SameLine();
		Helper::HotKey(Config.misc.SpeedBoostKey);
	}
	ImGui::SliderFloat("Temp Float", & Config.tempvalues.inputfloat, 0.f, 3000.f);

	ImGui::EndChild();

	ImGui::SameLine();

	// Get the current screen position of the cursor (where the child window will start)
	ImVec2 ConfigchildPos = ImGui::GetCursorScreenPos();
	ImVec2 ConfigtitlePos = ImVec2(ConfigchildPos.x + 5.0f, ConfigchildPos.y - ImGui::GetFontSize()); // Adjust Y for positioning above the border
	ImGui::GetWindowDrawList()->AddText(ConfigtitlePos, IM_COL32(255, 255, 255, 255), "Configs");

	ImGui::BeginChild("ConfigArea", ImVec2(0, 0), true);




	DrawConfigs();

	ImGui::SetCursorPosY(ConfigWindowHeight - 60);

	ImGui::Text("Menu Key");
	ImGui::SameLine();
	Helper::HotKey(Config.MenuKey);
	ImGui::SameLine();
	if (ImGui::Button("Unload"))
	{
		unloadRequested = true;
	}


	ImGui::EndChild();







}


void Menu::DrawNewMenu(FILE* fp, ID3D11Device* dx11Device) {

	static ID3D11Texture2D* AimbotIcon = LoadTextureFromFile(dx11Device, "C:/Users/Russ/Desktop/CheatIcons/menuicon_ragebot.jpg");
	static ID3D11ShaderResourceView* AimbotIconView = CreateShaderResourceView(dx11Device, AimbotIcon);

	static ID3D11Texture2D* EspIcon = LoadTextureFromFile(dx11Device, "C:/Users/Russ/Desktop/CheatIcons/menuicon_esp.jpg");
	static ID3D11ShaderResourceView* EspIconView = CreateShaderResourceView(dx11Device, EspIcon);

	static ID3D11Texture2D* ConfigIcon = LoadTextureFromFile(dx11Device, "C:/Users/Russ/Desktop/CheatIcons/menuicon_config.jpg");
	static ID3D11ShaderResourceView* ConfigIconView = CreateShaderResourceView(dx11Device, ConfigIcon);

	static ID3D11Texture2D* HeroIcon = LoadTextureFromFile(dx11Device, "C:/Users/Russ/Desktop/CheatIcons/heroicon.png");
	static ID3D11ShaderResourceView* HeroIconView = CreateShaderResourceView(dx11Device, HeroIcon);

	static ID3D11Texture2D* IdaLady = LoadTextureFromFile(dx11Device, "C:/Users/Russ/Desktop/CheatIcons/idalady.png");
	static ID3D11ShaderResourceView* IdaLadyView = CreateShaderResourceView(dx11Device, IdaLady);




	//ImGui::ShowStyleEditor();

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

		// Button styles
		ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.1f, 0.1f, 0.1f, 1.0f));
		ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.15f, 0.15f, 0.15f, 1.0f));



		// Manually position each button
		ImTextureID icons[] = { AimbotIconView, EspIconView, IdaLadyView, HeroIconView, ConfigIconView };

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



		// Draw separator at exact position
		ImVec2 cursor_pos = ImGui::GetWindowPos();
		ImGui::GetWindowDrawList()->AddLine(
			ImVec2(cursor_pos.x + buttonwidth - 1, cursor_pos.y),
			ImVec2(cursor_pos.x + buttonwidth - 1, cursor_pos.y + availableHeight),
			IM_COL32(200, 200, 200, 255),
			1.0f
		);

		ImGui::PopStyleColor(3);
		ImGui::EndChild();

		// Position content area precisely
		ImGui::SetCursorPos(ImVec2(buttonwidth, 0));

		// Content area with explicit dimensions
		ImGui::BeginChild("Content Area", ImVec2(availableWidth - buttonwidth, availableHeight), false, ImGuiWindowFlags_NoResize);

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, eight);
		ImGui::PushStyleVar(ImGuiStyleVar_FramePadding, eight);


		switch (selectedTab) {
		case 0: DrawRageBotTab(); break;
		case 1: DrawLegitBotTab(); break;
		case 2: DrawEspTab(); break;
		case 3: DrawHeroesTab(); break;
		case 4: DrawConfigTab(fp); break;
		}



		ImGui::PopStyleVar(2);
		ImGui::EndChild();

	}
	ImGui::End();

	ImGui::PopStyleVar(2);

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


