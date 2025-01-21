#include "Esp.h"

Drawing draw;

extern Binds mainbinds;

inline globals& globs = globals::instance();

PlayerData LocalPlayerData;

void DrawBoneEsp(uintptr_t entity, bool enemy) {

	PlayerData plrdata;
	Helper::get_player_data(entity, &plrdata);


	std::vector<BoneConnection> connections = Helper::GetBoneConnections(entity, plrdata.HeroID); //really inneficient will find better solution

	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	
	for (int i = 0; i < connections.size(); i++) {
		vec3 BonePos1 = Helper::GetBoneVectorFromIndex(Pawn, connections[i].bone1);
		vec3 BonePos2 = Helper::GetBoneVectorFromIndex(Pawn, connections[i].bone2);
		vec2 ScreenPos1;
		vec2 ScreenPos2;
		if (Helper::WorldToScreen(BonePos1, ScreenPos1) && Helper::WorldToScreen(BonePos2, ScreenPos2))
			if (enemy) {
				draw.DrawLine(ScreenPos1.x, ScreenPos1.y, ScreenPos2.x, ScreenPos2.y, ImColor(cfg::colors_eSkeletoncol));
			}
			else {
				draw.DrawLine(ScreenPos1.x, ScreenPos1.y, ScreenPos2.x, ScreenPos2.y, ImColor(cfg::colors_tSkeletoncol));
			}

	}

}

void DrawXPEsp(uintptr_t entity) {

	if(!cfg::esp_DrawXp|| !entity)
		return;

	vec2 ScreenXp;
	xpData* EntInfo = new xpData;
	Helper::get_xp_data(entity, EntInfo);
	PlayerData* LocalPlayerData = new PlayerData;
	Helper::get_player_data(Helper::get_local_player(), LocalPlayerData);

	float distance = Helper::GetDistance(LocalPlayerData->m_vecOrigin, EntInfo->m_vecOrigin);


	if (EntInfo->m_bDormant) {
		delete EntInfo;
		delete LocalPlayerData;
		return;
	}

	if (distance > 2000.0f) {
		delete EntInfo;
		delete LocalPlayerData;
		return;
	}


	if (!Helper::WorldToScreen(EntInfo->m_vecOrigin, ScreenXp)) {
		delete EntInfo;
		delete LocalPlayerData;
		return;
	}


	draw.DrawCircle(ScreenXp.x, ScreenXp.y, 10, IM_COL32(255, 255, 255, 255));

	delete LocalPlayerData;
	delete EntInfo;

}

void DrawMonsterEsp(uintptr_t entity) {

	if (!cfg::esp_DrawMonsters || !entity)
		return;
	NpcData EntInfo;
	Helper::get_npc_data(entity, &EntInfo);
	PlayerData LocalPlayerData;
	Helper::get_player_data(Helper::get_local_player(), &LocalPlayerData);

	float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, EntInfo.m_vecOrigin);

	if (EntInfo.m_bDormant) {
		return;
	}

	if (distance > 2000.0f) {
		return;
	}


	// im sorry
	vec3 posleft = EntInfo.m_vecOrigin;
	vec3 posright = EntInfo.m_vecOrigin;
	vec3 posup = EntInfo.m_vecOrigin;
	vec3 posdown = EntInfo.m_vecOrigin;

	posleft.x += 50;
	posright.x -= 50;
	posup.y += 50;
	posdown.y -= 50;

	vec2 limitleft;
	vec2 limitright;
	vec2 limitup;
	vec2 limitdown;

	if (!Helper::WorldToScreen(posleft, limitleft)) {
		return;
	}
	if (!Helper::WorldToScreen(posright, limitright)) {
		return;
	}
	if (!Helper::WorldToScreen(posup, limitup)) {
		return;
	}
	if (!Helper::WorldToScreen(posdown, limitdown)) {
		return;
	}

	draw.DrawQuad(limitup, limitright, limitdown, limitleft, ImColor(cfg::colors_drawmonsterscol), 4.0f);


}

float GetSmoothedFPS() {
	static float frameTimeAccum = 0;
	static int frameCount = 0;
	static float smoothedFPS = 0;
	static float updateTimer = 0;
	static const float UPDATE_INTERVAL = 0.1f;
	globals& g = globals::instance();

	if (!g.Globals)
		return 0.0f;

	float currentFrameTime = g.Globals->flAbsFrameTime;
	updateTimer += currentFrameTime;
	if (updateTimer >= UPDATE_INTERVAL) {
		updateTimer = 0;
		currentFrameTime *= 1000.0f;
		if (currentFrameTime >= 1.0f && currentFrameTime <= 1000.0f) {
			frameTimeAccum += currentFrameTime;
			frameCount++;
			if (frameCount >= 5) {
				smoothedFPS = 1000.0f / (frameTimeAccum / frameCount);
				frameTimeAccum = 0;
				frameCount = 0;
				if (smoothedFPS > 1000.0f) smoothedFPS = 1000.0f;
				if (smoothedFPS < 1.0f) smoothedFPS = 1.0f;
			}
		}
	}
	return smoothedFPS;
}
void RenderWatermark() {

	PlayerData plrdata;
	Helper::get_player_data(Helper::get_local_player(), &plrdata);
	// Create the watermark text
	char fullBuffer[256];

	if (iEngine->IsInGame()) {
		snprintf(fullBuffer, sizeof(fullBuffer), "Kills : %d | FPS : %.0f | JohnWickWare ",
			plrdata.kills, GetSmoothedFPS());
	}
	else {
		snprintf(fullBuffer, sizeof(fullBuffer), "Kills : %d | FPS : %.0f | JohnWickWare ",
			0, GetSmoothedFPS());
	}


	// Calculate text size
	ImVec2 textSize = ImGui::CalcTextSize(fullBuffer);
	float padding = 15.0f; // Adjust padding as needed
	ImVec2 watermarkSize(textSize.x + padding * 2, textSize.y + padding); // Set height to text height plus padding
	ImVec2 watermarkPos(ImGui::GetIO().DisplaySize.x - watermarkSize.x - 1, 1);
	ImGui::SetNextWindowPos(watermarkPos, ImGuiCond_Always);
	ImGui::SetNextWindowSize(watermarkSize, ImGuiCond_Always);
	ImGui::SetNextWindowBgAlpha(0.8f);
	ImGui::Begin("Watermark", nullptr,
		ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoInputs |
		ImGuiWindowFlags_NoResize |
		ImGuiWindowFlags_NoScrollbar);
	ImVec2 windowPos = ImGui::GetWindowPos();
	// Draw background with exact size
	ImGui::GetWindowDrawList()->AddRectFilled(
		windowPos,
		ImVec2(windowPos.x + watermarkSize.x, windowPos.y + watermarkSize.y),
		IM_COL32(0, 0, 0, 255)
	);
	// Draw top border
	float borderThickness = 2.0f;
	ImVec2 start(windowPos.x, windowPos.y);
	ImVec2 end(windowPos.x + watermarkSize.x, windowPos.y);
	ImGui::GetWindowDrawList()->AddLine(start, end, IM_COL32(255, 20, 147, 255), borderThickness);
	// Set text color
	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 0.12, 0.7, 1));
	// Set cursor position to align text with padding
	ImGui::SetCursorPos(ImVec2(padding, (watermarkSize.y - textSize.y) / 2)); // Center vertically
	// Render the text
	ImGui::Text("%s", fullBuffer);
	ImGui::PopStyleColor();
	ImGui::End();
}

void DrawTowerEsp(uintptr_t TowerEntity) {

	//if (!cfg::esp_drawTowers || !TowerEntity)
		//return;

	NpcData EntInfo;
	Helper::get_npc_data(TowerEntity, &EntInfo);

	if (EntInfo.m_bDormant)
		return;
	if (EntInfo.m_ilifestate != 0)
		return;

	float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, EntInfo.m_vecOrigin);

	if (distance > 3500.f)
		return;

	uint64_t entteamnum = 262144 + LocalPlayerData.TeamNum;
	if (EntInfo.m_iteamnum == entteamnum) {  // really awful terribleness because the number just happens to be this for minion teams
		return;
	}
	
	vec2 screen;

	vec3 textpos = EntInfo.m_vecOrigin;
	textpos.z += 125.f;

	if (!(Helper::WorldToScreen(textpos, screen)))
		return;

	draw.DrawTextA(screen.x, screen.y, IM_COL32(255, 255, 255, 255), "Tower");

	return;

}

void DrawMinionEsp(uintptr_t entity) {

	if (!cfg::esp_DrawMinions || !entity)
		return;

	NpcData EntInfo;
	Helper::get_npc_data(entity, &EntInfo);

	float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, EntInfo.m_vecOrigin);

	ImColor red = IM_COL32(255, 0, 0, 127);
	ImColor green = IM_COL32(0, 255, 0, 127);

	if (EntInfo.m_bDormant) {
		return;
	}
	
	uint64_t entteamnum = 263168 + LocalPlayerData.TeamNum;
	if (EntInfo.m_iteamnum == entteamnum) {  // really awful terribleness because the number just happens to be this for minion teams
		return;
	}

	if (EntInfo.m_ilifestate != 0) {
		return;
	}

	if (distance > 2000.0f) {
		return;
	}


	// im sorry
	vec3 posleft = EntInfo.m_vecOrigin;
	vec3 posright = EntInfo.m_vecOrigin;
	vec3 posup = EntInfo.m_vecOrigin;
	vec3 posdown = EntInfo.m_vecOrigin;

	posleft.x += 25;
	posright.x -= 25;
	posup.y += 25;
	posdown.y -= 25;

	vec2 limitleft;
	vec2 limitright;
	vec2 limitup;
	vec2 limitdown;

	if (!Helper::WorldToScreen(posleft, limitleft)) {
		return;
	}
	if (!Helper::WorldToScreen(posright, limitright)) {
		return;
	}
	if (!Helper::WorldToScreen(posup, limitup)) {
		return;
	}
	if (!Helper::WorldToScreen(posdown, limitdown)) {
		return;
	}

	float healthpercent = (float)EntInfo.m_iHealth / (float)EntInfo.m_iMaxHealth;
	if (healthpercent <= 0.3)
		draw.DrawQuad(limitup, limitright, limitdown, limitleft, red);
	else
		draw.DrawQuad(limitup, limitright, limitdown, limitleft, green);

}

void DrawFov() {

	vec2 resolution = Helper::GetResolution();


		const uint64_t CameraManager = *(uint64_t*)(ClientModuleBase + Offsets.o_CameraManager + 0x28);
		if (!CameraManager)
			return;

		float pFov = *(float*)(CameraManager + 0x50);

		float radius = 0;

		if (cfg::legitbot_masterswitch) {
			radius = tanf(Helper::DegreesToRadians(cfg::legitbot_fov) / 2) / tanf(Helper::DegreesToRadians(pFov) / 2) * (resolution.x / 2);
		}else if (cfg::ragebot_masterswitch) {
			radius = tanf(Helper::DegreesToRadians(cfg::ragebot_aimfov) / 2) / tanf(Helper::DegreesToRadians(pFov) / 2) * (resolution.x / 2);
		}

		draw.DrawCircle(resolution.x / 2, resolution.y / 2, radius, ImColor(cfg::colors_drawfovcol));
}

void DrawAimbotTargetInfo(PlayerData* info) {

	int Heroid = info->HeroID;
	int health = info->Health;
	int maxhealth = info->MaxHealth;


    ImGui::Begin("Tiny Window", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);

	ImGui::SetWindowSize(ImVec2(100, 17), ImGuiCond_Always);

	ImGui::Text(Helper::GetHeroNameByID(Heroid).c_str());

    // Get the text size and window positionr
    ImVec2 textSize = ImGui::CalcTextSize(Helper::GetHeroNameByID(Heroid).c_str());
    ImVec2 windowPos = ImGui::GetWindowPos();
    ImVec2 barPos = ImVec2(windowPos.x, windowPos.y + textSize.y + ImGui::GetStyle().ItemSpacing.y); // Adjust Y position

    // Calculate health
    float healthRatio = static_cast<float>(health) / static_cast<float>(maxhealth);
    float barWidth = 100.0f; // Width of the health bar
    float filledWidth = barWidth * healthRatio; // Width of the filled (green) part
    float missingWidth = barWidth - filledWidth; // Width of the missing (red) part

    // Draw the filled health bar (green)
    draw.DrawFilledBox(barPos.x, barPos.y + 15, filledWidth, 5, IM_COL32(0, 255, 0, 255)); // Green
    // Draw the missing health (red) part on the right
    draw.DrawFilledBox(barPos.x + filledWidth, barPos.y + 15, missingWidth, 5, IM_COL32(255, 0, 0, 255)); // Red

    ImGui::End();
}

const char* Vec3ToCString(const vec3& vec) {
	static char buffer[50]; // Buffer to hold the C string
	snprintf(buffer, sizeof(buffer), "Position: (%.2f, %.2f, %.2f)", vec.x, vec.y, vec.z);
	return buffer;
}

void Esp::DoEsp() {


	if (cfg::esp_DrawFov) {
		DrawFov();
	}
	if (cfg::esp_DrawWaterMark) {
		RenderWatermark();
	}
	
	Helper::get_player_data(Helper::get_local_player(), &LocalPlayerData);
	
	if (cfg::esp_ShowKeyBindList) {
		mainbinds.think();
		mainbinds.paint();
	}

	globs.SortEntsEsp();

	if (!cfg::esp_bEsp)
		return;


	for (int i = 0; i < globs.espEntList.active->size(); i++) {

		if (globs.espEntList.active->empty() || !(*globs.espEntList.active)[i])
			continue;


		std::string EntName = Helper::get_schema_name((*globs.espEntList.active)[i]);

		if (EntName == "CCitadelPlayerController") {

			PlayerData TargetPlayerData;
			if (!Helper::get_player_data((*globs.espEntList.active)[i], &TargetPlayerData)) {
				continue;
			}

			if (TargetPlayerData.dormant)
				continue;

			if (!TargetPlayerData.isalive)
				continue;

			Esp::DrawEsp((*globs.espEntList.active)[i], &TargetPlayerData, &LocalPlayerData);


		}
		else if (EntName == "CItemXP") {
			DrawXPEsp((*globs.espEntList.active)[i]);
		}
		else if (EntName == "C_NPC_TrooperNeutral" && cfg::esp_DrawMonsters) {
			DrawMonsterEsp((*globs.espEntList.active)[i]);
		}
		else if (EntName == "C_NPC_Trooper" && cfg::esp_DrawMinions) {
			DrawMinionEsp((*globs.espEntList.active)[i]);
		}
		else if (EntName == "C_NPC_TrooperBoss" && cfg::esp_drawTowers) {
			DrawTowerEsp((*globs.espEntList.active)[i]);
		}
	}

}

void Esp::DrawEsp(uintptr_t Entity, PlayerData* EntInfo, PlayerData* LocalInfo)
{


	vec2 ScreenFeet;
	
	vec3 feetpos = EntInfo->m_vecOrigin;

	vec2 ScreenHead;
	uint64_t PawnHandle = *(uint64_t*)(Entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	uint64_t boneindex = Helper::get_bone_index(Pawn, "head");
	vec3 HeadPos = Helper::GetBoneVectorFromIndex(Pawn, boneindex);  // No re-declaration of TargetPos here

	bool w2sresult = Helper::WorldToScreen(feetpos, ScreenFeet);
	Helper::WorldToScreen(HeadPos, ScreenHead);

	int height = (ScreenFeet.y + 5) - ScreenHead.y;
	int boxheight = height * 1.2;
	int width = height / 1.55;
	vec2 BoxHead;
	BoxHead.x = ScreenHead.x - width / 2;
	BoxHead.y = ScreenHead.y - height / 5;



	vec2 resolution = Helper::GetResolution();

	if (cfg::esp_DrawAimbotTarget && Aimbot::GetCurrentAimbotTarget() == Entity) {
		if (w2sresult) {
			vec2 point1;
			vec2 point2;
			vec2 point3;

			point1.x = BoxHead.x + (0.5 * width);
			point1.y = BoxHead.y - 25.0f;

			point2.x = (BoxHead.x + (0.5 * width)) + 8;
			point2.y = BoxHead.y - 35.0f;

			point3.x = (BoxHead.x + (0.5 * width)) - 8;
			point3.y = BoxHead.y - 35.0f;

			draw.DrawTriangleFilled(point1, point2, point3, ImColor(cfg::colors_aimbotTargetcol));
		}
		DrawAimbotTargetInfo(EntInfo);
	}
	
	if (w2sresult) {

		if (EntInfo->TeamNum == LocalInfo->TeamNum) { // draw team esp
			if (cfg::esp_tBoxEsp) {
				draw.DrawBox(BoxHead.x, BoxHead.y, width, height * 1.2, ImColor(cfg::colors_tBoxespcol));
			}
			if (cfg::esp_tHealthEsp) {
				std::string Health = std::to_string(EntInfo->Health);
				std::string MaxHealth = std::to_string(EntInfo->MaxHealth);
				std::string HealthDisplay = "Health: " + Health + " / " + MaxHealth;

				draw.DrawTextA(BoxHead.x, BoxHead.y + height * 1.2, ImColor(cfg::colors_tHealthtextcolesp), _strdup(HealthDisplay.c_str()));
			}
			if (cfg::esp_tTracers) {
				draw.DrawLine(resolution.x / 2, resolution.y, ScreenFeet.x, ScreenFeet.y, ImColor(cfg::colors_tTracerscol));
			}
			if (cfg::esp_tDistanceEsp) {


				std::string temp = std::to_string(Helper::GetDistance(LocalInfo->m_vecOrigin, EntInfo->m_vecOrigin));
				draw.DrawTextA(BoxHead.x + (0.5 * width), BoxHead.y + height * 1.2 + 25, ImColor(cfg::colors_tDistancecolesp), _strdup(temp.c_str()));
			}
			if (cfg::esp_tNameEsp) {
				draw.DrawTextA(BoxHead.x + (0.5 * width), BoxHead.y + height * 1.2, ImColor(cfg::colors_tNamecoloresp), Helper::GetHeroNameByID(EntInfo->HeroID).c_str());
			}
			if (cfg::esp_tHealthBar) {
				float health_ratio = (float)EntInfo->Health / (float)EntInfo->MaxHealth;
				float scaled_height = height * 1.2f;

				float bar_x = BoxHead.x - 6;
				float top_y = BoxHead.y;
				float bottom_y = top_y + scaled_height;
				float health_y = bottom_y - (scaled_height * health_ratio);
				draw.DrawLine(
					bar_x, top_y,
					bar_x, bottom_y,
					IM_COL32(0, 0, 0, 85),
					3.0f
				);
				draw.DrawLine(
					bar_x, bottom_y,
					bar_x, health_y,
					IM_COL32(0, 255, 0, 255),
					3.0f
				);

				auto io = ImGui::GetIO();
				ImFontAtlas* fontAtlas = io.Fonts;      // Get the font atlas
				ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[3]);

				if (health_ratio < 1.0f) {
					draw.DrawTextA(
						bar_x,
						health_y - 10,
						IM_COL32(255, 255, 255, 255),
						std::to_string((int)(health_ratio * 100)).c_str()
					);
				}

				ImGui::PopFont();
			}
			if (cfg::esp_tBoneEsp) {
				DrawBoneEsp(Entity, false);
			}
		}
		else {
			if (cfg::esp_eBoxEsp) {
				draw.DrawBox(BoxHead.x, BoxHead.y, width, height * 1.2, ImColor(cfg::colors_eBoxespcol));
			}
			if (cfg::esp_eHealthEsp) {
				std::string Health = std::to_string(EntInfo->Health);
				std::string MaxHealth = std::to_string(EntInfo->MaxHealth);
				std::string HealthDisplay = "Health: " + Health + " / " + MaxHealth;

				draw.DrawTextA(BoxHead.x, BoxHead.y + height * 1.2, ImColor(cfg::colors_eHealthtextcolesp), _strdup(HealthDisplay.c_str()));
			}
			if (cfg::esp_eTracers) {
				draw.DrawLine(resolution.x / 2, resolution.y, ScreenFeet.x, ScreenFeet.y, ImColor(cfg::colors_eTracerscol));
			}
			if (cfg::esp_eDistanceEsp) {


				std::string temp = std::to_string(Helper::GetDistance(LocalInfo->m_vecOrigin, EntInfo->m_vecOrigin));
				draw.DrawTextA(BoxHead.x + (0.5 * width), BoxHead.y + height * 1.2 + 25, ImColor(cfg::colors_eDistancecolesp), _strdup(temp.c_str()));
			}
			if (cfg::esp_eNameEsp) {
				draw.DrawTextA(BoxHead.x + (0.5 * width), BoxHead.y + height * 1.2, ImColor(cfg::colors_eNamecoloresp), Helper::GetHeroNameByID(EntInfo->HeroID).c_str());
			}
			if (cfg::esp_eHealthBar) {
				float health_ratio = (float)EntInfo->Health / (float)EntInfo->MaxHealth;
				float scaled_height = height * 1.2f;

				float bar_x = BoxHead.x - 6;
				float top_y = BoxHead.y;
				float bottom_y = top_y + scaled_height;
				float health_y = bottom_y - (scaled_height * health_ratio);
				draw.DrawLine(
					bar_x, top_y,
					bar_x, bottom_y,
					IM_COL32(0, 0, 0, 85),
					3.0f
				);
				draw.DrawLine(
					bar_x, bottom_y,
					bar_x, health_y,
					IM_COL32(0, 255, 0, 255),
					3.0f
				);

				auto io = ImGui::GetIO();
				ImFontAtlas* fontAtlas = io.Fonts;      // Get the font atlas
				ImGui::PushFont(ImGui::GetIO().Fonts->Fonts[3]);

				if (health_ratio < 1.0f) {
					draw.DrawTextA(
						bar_x,
						health_y - 10,
						IM_COL32(255, 255, 255, 255),
						std::to_string((int)(health_ratio * 100)).c_str()
					);
				}

				ImGui::PopFont();
			}
			if (cfg::esp_eBoneEsp) {
				DrawBoneEsp(Entity, true);
			}
		}


	}
	//do not delete entinfo its deleted afterwards trust :D 
}