
#include "Menu.h"
#include "D3D11.h"
#include <wrl/client.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using Microsoft::WRL::ComPtr;



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
	if(!refreshed)
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
			showloadConfirmPopup = false; // Close the popup
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

	ImGui::EndChild();

}

void Menu::DrawAntiAimTab() {

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
		break;
	}
	case Infernus: {
		ImGui::Text("Infernus");
		break;
	}
	case Ivy: {
		ImGui::Text("Ivy");
		break;
	}
	case Kelvin: {
		ImGui::Text("Kelvin");
		break;
	}
	case LadyGeist: {
		ImGui::Text("LadyGeist");
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
		break;
	}
	case MoAndKrill: {
		ImGui::Text("MoAndKrill");
		break;
	}
	case Paradox: {
		ImGui::Text("Paradox");
		break;
	}
	case Pocket: {
		ImGui::Text("Pocket");
		break;
	}
	case Seven: {
		ImGui::Text("Seven");
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
		break;
	}
	case Warden: {
		ImGui::Text("Warden");
		break;
	}
	case Wraith: {
		ImGui::Text("Wraith");
		break;
	}
	case Yamato: {
		ImGui::Text("Yamato");
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

void Menu::DrawAimbotTab() {



	ImGui::BeginChild("Aimbot General", ImVec2(0, 0), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);
	ImGui::Text("Aimbot");
	ImGui::Checkbox("Enabled", &Config.aimbot.bAimbot);
	ImGui::SameLine();
	Helper::HotKey(Config.aimbot.AimKey);
	ImGui::Checkbox("Silent Aim", &Config.aimbot.silentaim);
	ImGui::Checkbox("Movement Fix", &Config.aimbot.MovementFix);
	ImGui::Checkbox("Magic Bullet", &Config.aimbot.magicbullet);
	ImGui::SameLine();
	Helper::HotKey(Config.aimbot.magicbulletkey);
	ImGui::Checkbox("Auto Fire", &Config.aimbot.AutoFire);

	static const char* items[] = { "Distance", "Lowest Health", "FOV" }; // Options for the dropdown
	//static int currentItem = 0; // Index of the currently selected item
	ImGui::Combo("Target ", &Config.aimbot.targetSelectionMode, items, IM_ARRAYSIZE(items));
	ImGui::Text("Selected: %s", items[Config.aimbot.targetSelectionMode]);
	ImGui::SliderFloat("Max Distance", &Config.aimbot.MaxDistance, 0.0f, 5000.0f, "%.1f");
	ImGui::SliderFloat("FOV", &Config.aimbot.fov, 0.0f, 180.0f, "%.1f");
	ImGui::SliderFloat("Smooth", &Config.aimbot.smooth, 0.0f, 100.0f, "%.1f");
	ImGui::Checkbox("Aim at Souls", &Config.aimbot.AimXp);
	ImGui::SameLine();
	Helper::HotKey(Config.aimbot.AimKeyXp);
	ImGui::Checkbox("Aim at Minions", &Config.aimbot.AimMinions);
	ImGui::SameLine();
	Helper::HotKey(Config.aimbot.AimKeyMinions);

	ImGui::EndChild();

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
		Helper::HotKey(Config.misc.SpeedBoostKey);
	}

	ImGui::EndChild();

	ImGui::SameLine();

	// Get the current screen position of the cursor (where the child window will start)
	ImVec2 ConfigchildPos = ImGui::GetCursorScreenPos();
	ImVec2 ConfigtitlePos = ImVec2(ConfigchildPos.x + 5.0f, ConfigchildPos.y - ImGui::GetFontSize()); // Adjust Y for positioning above the border
	ImGui::GetWindowDrawList()->AddText(ConfigtitlePos, IM_COL32(255, 255, 255, 255), "Configs");

	ImGui::BeginChild("ConfigArea", ImVec2(0, 0),true);

	// Set the cursor position for the button to ensure it aligns with the other content
	ImGui::SetCursorPosY(ImGui::GetCursorPosY()); // Ensure we are at the same Y position

	// Use SameLine with a custom offset to place it far to the right
	ImGui::SameLine(ImGui::GetWindowWidth() - 200.0f); // Adjust for horizontal offset

	if (ImGui::Button("Unload Lynchware :D"))
	{

		kiero::shutdown();
		fclose(fp);
		FreeConsole();
	}


	DrawConfigs();

	ImGui::SetCursorPosY(ConfigWindowHeight - 60);

	ImGui::Text("Menu Key");
	ImGui::SameLine();
	Helper::HotKey(Config.MenuKey);
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

	

	if (ImGui::Begin("Vertical Tab Bar", NULL, ImGuiWindowFlags_NoCollapse)) {
		// Get available width and height for buttons
		float availableWidth = ImGui::GetContentRegionAvail().x;
		float availableHeight = ImGui::GetContentRegionAvail().y;

		// Total spacing height (5 pixels between buttons)
		//float spacing = 5.0f;
		//float totalSpacing = spacing * (numTabs + 1); // Space between buttons
		float buttonHeight = (availableHeight * 0.6) / numTabs; // Adjust height to account for spacing

		// Begin a vertical group for the buttons
		ImGui::BeginChild("Button Area", ImVec2(buttonHeight * 1.3, 0), true, ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse);

		ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetStyleColorVec4(ImGuiCol_FrameBgActive));
		ImGui::PushStyleColor(ImGuiCol_Border, ImGui::GetStyleColorVec4(ImGuiCol_ButtonHovered));


		if (ImGui::ImageButton(AimbotIconView, ImVec2(buttonHeight, buttonHeight), ImVec2(0, 0), ImVec2(1, 1))) {
			selectedTab = 0;
		}
		if (ImGui::ImageButton(EspIconView, ImVec2(buttonHeight, buttonHeight), ImVec2(0, 0), ImVec2(1, 1))) {
			selectedTab = 1;
		}
		if (ImGui::ImageButton(IdaLadyView, ImVec2(buttonHeight, buttonHeight), ImVec2(0, 0), ImVec2(1, 1))) {
			selectedTab = 2;
		}
		if (ImGui::ImageButton(HeroIconView, ImVec2(buttonHeight, buttonHeight), ImVec2(0, 0), ImVec2(1, 1))) {
			selectedTab = 3;
		}
		if (ImGui::ImageButton(ConfigIconView, ImVec2(buttonHeight, buttonHeight), ImVec2(0, 0), ImVec2(1, 1))) {
			selectedTab = 4;
		}

		ImGui::PopStyleColor(2);
		ImGui::EndChild(); // End the button area

		// Same line for content area
		ImGui::SameLine();

		// Begin a child for the content area
		ImGui::BeginChild("Content Area", ImVec2(0, 0), false);

		// Display content based on the selected tab
		switch (selectedTab) {
		case 0:
			DrawAimbotTab();
			break;
		case 1:
			DrawEspTab();
			break;
		case 2:
			DrawAntiAimTab();
			break;
		case 3:
			DrawHeroesTab();
			break;
		case 4:
			DrawConfigTab(fp);
			break;
		}

		ImGui::EndChild(); // End the content area
	}
	ImGui::End(); // End the window

}





void Menu::DrawMenu(FILE* fp) {



	ImGui::Begin("LynchWare",NULL, ImGuiWindowFlags_NoResize + ImGuiWindowFlags_NoCollapse);
	if (ImGui::BeginTabBar("Cheat"))
	{
		// First tab
		if (ImGui::BeginTabItem("Aimbot"))
		{

			ImGui::Checkbox("Aimbot", &Config.aimbot.bAimbot);
			if (Config.aimbot.bAimbot) {
				ImGui::SameLine();
				Helper::HotKey(Config.aimbot.AimKey);
				ImGui::SameLine();

				ImGui::Checkbox("Silent Aim", &Config.aimbot.silentaim);

				ImGui::Checkbox("Movement Fix", &Config.aimbot.MovementFix);

				ImGui::Checkbox("Magic Bullet", &Config.aimbot.magicbullet);
				ImGui::SameLine();
				Helper::HotKey(Config.aimbot.magicbulletkey);

				ImGui::Checkbox("Auto Fire", &Config.aimbot.AutoFire);
				static const char* items[] = { "Distance", "Lowest Health", "FOV" }; // Options for the dropdown
				//static int currentItem = 0; // Index of the currently selected item
				ImGui::Combo("Target ", &Config.aimbot.targetSelectionMode, items, IM_ARRAYSIZE(items));
				ImGui::Text("Selected: %s", items[Config.aimbot.targetSelectionMode]);
				ImGui::SliderFloat("Max Distance", &Config.aimbot.MaxDistance, 0.0f, 5000.0f, "%.1f");
				ImGui::SliderFloat("FOV", &Config.aimbot.fov, 0.0f, 180.0f, "%.1f");
				ImGui::SliderFloat("Smooth", &Config.aimbot.smooth, 0.0f, 100.0f, "%.1f");
				ImGui::Checkbox("Aim at XP", &Config.aimbot.AimXp);
				ImGui::SameLine();
				Helper::HotKey(Config.aimbot.AimKeyXp);
				ImGui::Checkbox("Aim At Minions", &Config.aimbot.AimMinions);
				ImGui::SameLine();
				Helper::HotKey(Config.aimbot.AimKeyMinions);

			}

			ImGui::EndTabItem();
		}



		if (ImGui::BeginTabItem("Esp"))
		{
			// Get the available width for the children
			float halfWidth = ImGui::GetContentRegionAvail().x * 0.5f;

			// Layout for Player Visuals
			ImGui::Text("Player Visuals");
			ImGui::BeginChild("LeftSubview", ImVec2(halfWidth, 0), true); // Border added
			ImGui::Checkbox("Esp", &Config.esp.bEsp);
			if (Config.esp.bEsp) {
				ImGui::Checkbox("Box Esp", &Config.esp.boxEsp);
				if (Config.esp.boxEsp) {
					ImGui::SameLine();
					ImGui::ColorEdit4("Box Color", (float*)&Config.colors.boxespcol);
				}

				ImGui::Checkbox("Skeleton", &Config.esp.boneEsp);
				if (Config.esp.boneEsp) {
					ImGui::SameLine();
					ImGui::ColorEdit4("Bone Color", (float*)&Config.colors.skeletoncol);
				}

				ImGui::Checkbox("Chams", &Config.esp.Chams);
				if (Config.esp.Chams) {
					ImGui::SameLine();
					ImGui::Checkbox("Model Override", &Config.esp.ModelChams);
					ImGui::SameLine();
					ImGui::ColorEdit4("Chams Color", (float*)&Config.colors.ChamsCol);
				}

				ImGui::Checkbox("Health Bar", &Config.esp.HealthBar);
				ImGui::Checkbox("Name Esp", &Config.esp.NameEsp);
				ImGui::Checkbox("Health Text", &Config.esp.HealthEsp);
				ImGui::Checkbox("Tracers", &Config.esp.Tracers);
				if (Config.esp.Tracers) {
					ImGui::SameLine();
					ImGui::ColorEdit4("Tracers Color", (float*)&Config.colors.tracerscol);
				}

				ImGui::Checkbox("Distance Esp", &Config.esp.DistanceEsp);
			}
			ImGui::EndChild();

			ImGui::SameLine(); // Move to the same line for the next child

			// Layout for Misc Visuals
			ImGui::Text("Misc Visuals");
			ImGui::SameLine(); // Ensure "Misc Visuals" appears on the same line as "Player Visuals"
			ImGui::BeginChild("RightSubView", ImVec2(halfWidth, 0), true); // Border added
			if (Config.esp.bEsp) {
				ImGui::Checkbox("Draw Fov", &Config.esp.DrawFov);
				if (Config.esp.DrawFov) {
					ImGui::SameLine();
					ImGui::ColorEdit4("Fov Circle Color", (float*)&Config.colors.drawfovcol);
				}

				ImGui::Checkbox("Draw Xp", &Config.esp.DrawXp);
				if (Config.esp.DrawXp) {
					ImGui::SameLine();
					ImGui::ColorEdit4("XP Color", (float*)&Config.colors.drawxpcol);
				}

				ImGui::Checkbox("Draw Monsters", &Config.esp.DrawMonsters);
				if (Config.esp.DrawMonsters) {
					ImGui::SameLine();
					ImGui::ColorEdit4("Monster Indicator Color", (float*)&Config.colors.drawmonsterscol);
				}

				ImGui::Checkbox("Draw Minions", &Config.esp.DrawMinions);
				ImGui::Checkbox("Draw Aimbot Target", &Config.esp.DrawAimbotTarget);
				if (Config.esp.DrawAimbotTarget) {
					ImGui::SameLine();
					ImGui::ColorEdit4("Aimbot Indicator Color", (float*)&Config.colors.aimbotTargetcol);
				}
			}
			ImGui::EndChild();

			ImGui::EndTabItem();
		}




		if (ImGui::BeginTabItem("AntiAim")) {

			ImGui::Checkbox("AntiAim", &Config.antiaim.bAntiAim);
			static const char* items[] = { "Spin", "Jitter", "180 Treehouse" }; // Options for the dropdown
			static int currentItem = 0; // Index of the currently selected item
			ImGui::Combo("Target ", &currentItem, items, IM_ARRAYSIZE(items)); Config.antiaim.AAtype = currentItem;
			ImGui::Text("Selected: %s", items[currentItem]);
			ImGui::SliderFloat("Lower Jitter", &Config.antiaim.lowerjitter, -180, Config.antiaim.upperjitter, "%.1f");
			ImGui::SliderFloat("Upper Jitter", &Config.antiaim.upperjitter, Config.antiaim.lowerjitter, 180.0f, "%.1f");
			ImGui::EndTabItem();

		}

		if (ImGui::BeginTabItem("Heroes")) {
			PlayerData* plrdata = new PlayerData;
			Helper::get_player_data(Helper::get_local_player(), plrdata);
			switch (plrdata->HeroID) {

			case Abrams: {
				ImGui::Text("Abrams");
				break;
			}
			case Bebop: {
				ImGui::Text("Bebop");
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
				break;
			}
			case Infernus:{
				ImGui::Text("Infernus");
				break;
			}
			case Ivy: {
				ImGui::Text("Ivy");
				break;
			}
			case Kelvin: {
				ImGui::Text("Kelvin");
				break;
			}
			case LadyGeist: {
				ImGui::Text("LadyGeist");
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
				break;
			}
			case MoAndKrill: {
				ImGui::Text("MoAndKrill");
				break;
			}
			case Paradox: {
				ImGui::Text("Paradox");
				break;
			}
			case Pocket: {
				ImGui::Text("Pocket");
				break;
			}
			case Seven: {
				ImGui::Text("Seven");
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
				break;
			}
			case Warden: {
				ImGui::Text("Warden");
				break;
			}
			case Wraith: {
				ImGui::Text("Wraith");
				break;
			}
			case Yamato: {
				ImGui::Text("Yamato");
				break;
			}
			default: {
				ImGui::Text("Please Enter A Game");
				break;
			}
			}

			delete plrdata;

			ImGui::EndTabItem();
		}

		// Third tab
		if (ImGui::BeginTabItem("Misc"))
		{

			ImGui::EndTabItem();
		}

		ImGui::EndTabBar();
	}
	ImGui::End();



}
