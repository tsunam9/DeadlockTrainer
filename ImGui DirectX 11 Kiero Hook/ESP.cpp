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
		if (EntName == "CItemXP")
			processed_ents_esp.push_back(entity);

	}
}

//impliment safety checks

void Esp::DrawEsp(uintptr_t Entity)
{
	uintptr_t ViewMatrix = (ClientModuleBase + Offsets::o_ViewMatrix);
	if (!ViewMatrix)
		return;

	ViewMatrixObj matrix = *(ViewMatrixObj*)ViewMatrix;


	vec2 ScreenFeet;
	PlayerData EntInfo = Helper::get_player_data(Entity);
	if (!Helper::WorldToScreen(EntInfo.m_vecOrigin, ScreenFeet, matrix.matrix))
		return;


	vec2 ScreenHead;
	uint64_t PawnHandle = *(uint64_t*)(Entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	uint64_t boneindex = Helper::get_index(Pawn, "head");
	vec3 HeadPos = Helper::GetBoneVectorFromIndex(Pawn, boneindex);  // No re-declaration of TargetPos here
	Helper::WorldToScreen(HeadPos, ScreenHead, matrix.matrix);

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

}

void DrawXPEsp(uintptr_t entity) {

	if(!Config.esp.DrawXp)
		return;

	vec2 ScreenXp;
	xpData EntInfo = Helper::get_xp_data(entity);
	uintptr_t ViewMatrix = (ClientModuleBase + Offsets::o_ViewMatrix);

	PlayerData LocalPlayerData = Helper::get_player_data(Helper::get_local_player());
	float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, EntInfo.m_vecOrigin);

	if (!ViewMatrix)
		return;

	if (EntInfo.bDormant)
		return;

	if (distance > 2000.0f)
		return;


	ViewMatrixObj matrix = *(ViewMatrixObj*)ViewMatrix;


	if (!Helper::WorldToScreen(EntInfo.m_vecOrigin, ScreenXp, matrix.matrix))
		return;

	draw.DrawCircle(ScreenXp.x, ScreenXp.y, 10, IM_COL32(255, 255, 255, 255));

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
	}

}