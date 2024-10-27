
#include "Menu.h"



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
	ImGui::SameLine();
	if (ImGui::Button("Save Config")) {
		showsaveConfirmPopup = true;
	}
	ImGui::SameLine();
	if (ImGui::Button("Delete Config")) {
		showDeleteConfirmPopup = true;
	}
	ImGui::SameLine();
	if (ImGui::Button("Refresh Configs")) {
		Config.RefreshConfigs();
	}

	static char newConfigName[256];

	ImGui::InputTextWithHint("", "New Config", newConfigName, sizeof(newConfigName));
	ImGui::SameLine();
	if (ImGui::Button("Create Config")) {
		char fullConfigName[256];
		strcpy_s(fullConfigName, newConfigName);
		Config.SaveConfig(fullConfigName); 
		Config.RefreshConfigs();           
		strcpy_s(newConfigName, "");
	}
	


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
				ImGui::Checkbox("Visible Check", &Config.aimbot.VisibleCheck);

				ImGui::Checkbox("Silent Aim", &Config.aimbot.silentaim);

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



		// Second tab
		if (ImGui::BeginTabItem("Esp"))
		{
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

				ImGui::Checkbox("Health Bar", &Config.esp.HealthBar);

				ImGui::Checkbox("Name Esp", &Config.esp.NameEsp);

				ImGui::Checkbox("Health Text", &Config.esp.HealthEsp);

				ImGui::Checkbox("Tracers", &Config.esp.Tracers);
				if (Config.esp.Tracers) {
					ImGui::SameLine();
					ImGui::ColorEdit4("Tracers Color", (float*)&Config.colors.tracerscol);
				}

				ImGui::Checkbox("Distance Esp", &Config.esp.DistanceEsp);

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

				//ImGui::Checkbox("Draw Aimbot Prediction", &Config.esp.DrawAimbotPrediction);
			}
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

			ImGui::Checkbox("No Recoil", &Config.misc.bNorecoil);
			ImGui::SliderFloat("Fov Multiplier", &Config.misc.fovmodifier, 0.1f, 2.0f, "%.3f");
			ImGui::Checkbox("Speed Boost", &Config.misc.SpeedBoost);
			if (Config.misc.SpeedBoost) {
				Helper::HotKey(Config.misc.SpeedBoostKey);
			}

			ImGui::Checkbox("Test Checkbox", &Config.tempvalues.checkbox);
			ImGui::SliderFloat("Slider1", &Config.tempvalues.slider1, 0.0f, 1000.0f);
			ImGui::SliderFloat("Slider2", &Config.tempvalues.slider2, 0.0f, 1000.0f);
			ImGui::InputInt("Input Int", &Config.tempvalues.inputint);
			DrawConfigs();


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
