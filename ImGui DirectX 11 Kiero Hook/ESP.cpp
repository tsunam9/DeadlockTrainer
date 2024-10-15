#include "Esp.h"

Drawing draw;


std::vector<uint64_t> processed_ents_esp;

inline void sort_esp_entities()
{
	int max_ents = Helper::get_max_entities();

	for (size_t i = 1; i <= static_cast<size_t>(max_ents); ++i)
	{
		uint64_t entity = Helper::get_base_entity_from_index(i);

		if (!entity)
			continue;

		std::string EntName = Helper::get_schema_name(entity);

		if (EntName == "CCitadelPlayerController" && !*(bool*)(entity + CBasePlayerController::m_bIsLocalPlayerController))
			processed_ents_esp.push_back(entity);
		if (EntName == "CItemXP" && Config.esp.DrawXp)
			processed_ents_esp.push_back(entity);
		if (EntName == "C_NPC_TrooperNeutral" && Config.esp.DrawMonsters)
			processed_ents_esp.push_back(entity);
		if (EntName == "C_NPC_Trooper" && Config.esp.DrawMinions)
			processed_ents_esp.push_back(entity);

	}
}

//impliment safety checks


void DrawBoneEsp(uintptr_t entity) {

	std::vector<BoneConnection> connections = Helper::GetBoneConnections(entity); //really inneficient will find better solution

	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	
	for (int i = 0; i < connections.size(); i++) {
		vec3 BonePos1 = Helper::GetBoneVectorFromIndex(Pawn, connections[i].bone1);
		vec3 BonePos2 = Helper::GetBoneVectorFromIndex(Pawn, connections[i].bone2);
		vec2 ScreenPos1;
		vec2 ScreenPos2;
		if (Helper::WorldToScreen(BonePos1, ScreenPos1) && Helper::WorldToScreen(BonePos2, ScreenPos2))
			draw.DrawLine(ScreenPos1.x, ScreenPos1.y, ScreenPos2.x, ScreenPos2.y, IM_COL32(255, 255, 255, 255));
	}

}

void DrawXPEsp(uintptr_t entity) {

	if(!Config.esp.DrawXp || !entity)
		return;

	vec2 ScreenXp;
	xpData EntInfo = Helper::get_xp_data(entity);
	PlayerData LocalPlayerData = Helper::get_player_data(Helper::get_local_player());
	float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, EntInfo.m_vecOrigin);


	if (EntInfo.m_bDormant)
		return;

	if (distance > 2000.0f)
		return;



	if (!Helper::WorldToScreen(EntInfo.m_vecOrigin, ScreenXp))
		return;

	draw.DrawCircle(ScreenXp.x, ScreenXp.y, 10, IM_COL32(255, 255, 255, 255));
}

void DrawMonsterEsp(uintptr_t entity) {

	if (!Config.esp.DrawMonsters || !entity)
		return;
	NpcData EntInfo = Helper::get_npc_data(entity);
	PlayerData LocalPlayerData = Helper::get_player_data(Helper::get_local_player());
	float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, EntInfo.m_vecOrigin);

	if (EntInfo.m_bDormant)
		return;

	if (distance > 2000.0f)
		return;


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

	if (!Helper::WorldToScreen(posleft, limitleft))
		return;
	if (!Helper::WorldToScreen(posright, limitright))
		return;
	if (!Helper::WorldToScreen(posup, limitup))
		return;
	if (!Helper::WorldToScreen(posdown, limitdown))
		return;
	draw.DrawQuad(limitup, limitright, limitdown, limitleft, IM_COL32(85, 6, 238, 177));

}

void DrawMinionEsp(uintptr_t entity) {

	if (!Config.esp.DrawMinions || !entity)
		return;



	NpcData EntInfo = Helper::get_npc_data(entity);
	PlayerData LocalPlayerData = Helper::get_player_data(Helper::get_local_player());
	float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, EntInfo.m_vecOrigin);

	ImColor red = IM_COL32(255, 0, 0, 127);
	ImColor green = IM_COL32(0, 255, 0, 127);

	if (EntInfo.m_bDormant)
		return;
	
	uint64_t entteamnum = 263169 + LocalPlayerData.TeamNum;
	if (EntInfo.m_iteamnum != entteamnum) // really awful terribleness because the number just happens to be this for minion teams
		return;

	if(EntInfo.m_ilifestate != 0)
		return;

	if (distance > 2000.0f)
		return;


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

	if (!Helper::WorldToScreen(posleft, limitleft))
		return;
	if (!Helper::WorldToScreen(posright, limitright))
		return;
	if (!Helper::WorldToScreen(posup, limitup))
		return;
	if (!Helper::WorldToScreen(posdown, limitdown))
		return;

	float healthpercent = (float)EntInfo.m_iHealth / (float)EntInfo.m_iMaxHealth;
	if (healthpercent <= 0.3)
		draw.DrawQuad(limitup, limitright, limitdown, limitleft, red);
	else
		draw.DrawQuad(limitup, limitright, limitdown, limitleft, green);

}

void DrawFov() {

	vec2 resolution = Helper::GetResolution();


		const uint64_t CameraManager = *(uint64_t*)(ClientModuleBase + Offsets::o_CameraManager + 0x28);
		if (!CameraManager)
			return;

		float pFov = *(float*)(CameraManager + 0x50);
		float radius = tanf(Helper::DegreesToRadians(Config.aimbot.fov) / 2) / tanf(Helper::DegreesToRadians(pFov) / 2) * (resolution.x / 2);

		draw.DrawCircle(resolution.x / 2, resolution.y / 2, radius, IM_COL32(255, 255, 255, 255));
}


void Esp::DoEsp() {
	processed_ents_esp.clear();
	sort_esp_entities();

	if (Config.esp.DrawFov) {
		DrawFov();
	}

	for (int i = 0; i < processed_ents_esp.size(); i++) {

		if (processed_ents_esp.empty() || !processed_ents_esp[i])
			continue;

		std::string EntName = Helper::get_schema_name(processed_ents_esp[i]);

		if (EntName == "CCitadelPlayerController") {
			PlayerData LocalPlayerData = Helper::get_player_data(Helper::get_local_player());
			PlayerData TargetPlayerData = Helper::get_player_data(processed_ents_esp[i]);

			if (!TargetPlayerData.isalive)
				continue;
			if (TargetPlayerData.TeamNum == LocalPlayerData.TeamNum)
				continue;

			this->DrawEsp(processed_ents_esp[i]);
		}
		else if (EntName == "CItemXP") {
			DrawXPEsp(processed_ents_esp[i]);
		}
		else if (EntName == "C_NPC_TrooperNeutral" && Config.esp.DrawMonsters) {
			DrawMonsterEsp(processed_ents_esp[i]);
		}
		else if (EntName == "C_NPC_Trooper" && Config.esp.DrawMinions) {
			DrawMinionEsp(processed_ents_esp[i]);
		}
	}

}

void Esp::DrawEsp(uintptr_t Entity)
{


	vec2 ScreenFeet;
	PlayerData EntInfo = Helper::get_player_data(Entity);
	if (!Helper::WorldToScreen(EntInfo.m_vecOrigin, ScreenFeet))
		return;


	vec2 ScreenHead;
	uint64_t PawnHandle = *(uint64_t*)(Entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	uint64_t boneindex = Helper::get_bone_index(Pawn, "head");
	vec3 HeadPos = Helper::GetBoneVectorFromIndex(Pawn, boneindex);  // No re-declaration of TargetPos here
	Helper::WorldToScreen(HeadPos, ScreenHead);

	int height = ScreenFeet.y - ScreenHead.y;
	int width = height / 1.75;
	vec2 BoxHead;
	BoxHead.x = ScreenHead.x - width / 2;
	BoxHead.y = ScreenHead.y - height / 10;
	vec2 resolution = Helper::GetResolution();

	if (Config.esp.boxEsp) {
		draw.DrawBox(BoxHead.x, BoxHead.y, width, height * 1.2, IM_COL32(255, 0, 0, 255));
	}
	if (Config.esp.HealthEsp) {
		std::string Health = std::to_string(EntInfo.Health);
		std::string MaxHealth = std::to_string(EntInfo.MaxHealth);
		std::string HealthDisplay = "Health: " + Health + " / " + MaxHealth;

		draw.DrawTextA(BoxHead.x, BoxHead.y + height * 1.2, IM_COL32(0, 255, 0, 255), _strdup(HealthDisplay.c_str()));
	}
	if (Config.esp.Tracers) {
		draw.DrawLine(resolution.x / 2, resolution.y, ScreenFeet.x, ScreenFeet.y, IM_COL32(255, 255, 255, 255));
	}
	if (Config.esp.DistanceEsp) {

		PlayerData LocalPlayerData = Helper::get_player_data(Helper::get_local_player());
		std::string temp = std::to_string(Helper::GetDistance(LocalPlayerData.m_vecOrigin, EntInfo.m_vecOrigin));
		draw.DrawTextA(BoxHead.x, BoxHead.y + height * 1.5, IM_COL32(255, 255, 255, 255), _strdup(temp.c_str()));
	}
	if (Config.esp.NameEsp) {
		draw.DrawTextA(BoxHead.x, BoxHead.y - height * 0.1, IM_COL32(255, 255, 255, 255), Helper::GetHeroNameByID(EntInfo.HeroID).c_str());
	}
	if (Config.esp.HealthBar) {
		float missinghealth = 1.0f - ((float)EntInfo.Health / (float)EntInfo.MaxHealth);
		draw.DrawFilledBox(BoxHead.x - 6, BoxHead.y, 4, height * 1.2, IM_COL32(0, 255, 0, 255));
		draw.DrawFilledBox(BoxHead.x - 6, BoxHead.y, 4, height * 1.2 * missinghealth, IM_COL32(255, 0, 0, 255));
	}
	if (Config.esp.boneEsp) {
		DrawBoneEsp(Entity);
	}

}