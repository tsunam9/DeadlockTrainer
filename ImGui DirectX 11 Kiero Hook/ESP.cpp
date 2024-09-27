#include "Esp.h"

Drawing draw;
Helper EspHelperObj;
Offsets EspOffsetsObj;


std::vector<uint64_t> processed_ents_esp;
ConfigSettings espconfig;

inline void sort_esp_entities()
{
	int max_ents = EspHelperObj.get_max_entities();

	for (size_t i = 1; i <= static_cast<size_t>(max_ents); ++i)
	{
		uint64_t entity = EspHelperObj.get_base_entity_from_index(i);

		if (!entity)
			continue;

		std::string EntName = EspHelperObj.get_schema_name(entity);

		if (EntName == "CCitadelPlayerController" && !*(bool*)(entity + CBasePlayerController::m_bIsLocalPlayerController))
			processed_ents_esp.push_back(entity);

	}
}

//impliment safety checks
void Esp::DrawEsp(uintptr_t Entity)
{
	uintptr_t ViewMatrix = (EspHelperObj.Modulebaseaddress + EspOffsetsObj.o_ViewMatrix);
	if(!ViewMatrix)
		return;

	ViewMatrixObj matrix = *(ViewMatrixObj*)ViewMatrix;


	vec2 ScreenFeet;
	PlayerData EntInfo = EspHelperObj.get_player_data(Entity);
	if (!EspHelperObj.WorldToScreen(EntInfo.m_vecOrigin, ScreenFeet, matrix.matrix))
		return;
	

	vec2 ScreenHead;
	uint64_t PawnHandle = *(uint64_t*)(Entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = EspHelperObj.get_base_entity_from_index(EspHelperObj.CHandle_get_entry_index(PawnHandle));
	uint64_t boneindex = EspHelperObj.get_index(Pawn, "head");
	vec3 HeadPos = EspHelperObj.GetBoneVectorFromIndex(Pawn, boneindex);  // No re-declaration of TargetPos here
	EspHelperObj.WorldToScreen(HeadPos, ScreenHead, matrix.matrix);
			
	int height = ScreenFeet.y - ScreenHead.y;
	int width = height / 1.75;
	float EqualizeHeadX = ScreenHead.x = ScreenHead.x - width / 2;
	float EqualizeHeadY = ScreenHead.y = ScreenHead.y - height / 10;

	if (espconfig.boxEsp) {
		draw.DrawBox(EqualizeHeadX, EqualizeHeadY, width, height * 1.2, IM_COL32(255, 0, 0, 255));
		draw.DrawCircle(ScreenHead.x + width / 2, ScreenHead.y + height * 0.125, 15.0, IM_COL32(255, 0, 0, 255));
	}
	if (espconfig.HealthEsp) {
		std::string temp = std::to_string(EntInfo.Health);
		draw.DrawTextA(ScreenHead.x + width / 2, ScreenHead.y + height * 1.2, IM_COL32(255, 255, 255, 255), _strdup(temp.c_str()));
	}
	if (espconfig.Tracers) {
		int ScreenWidth = *(int*)(EspHelperObj.Modulebaseaddress + EspOffsetsObj.o_Resolution);
		int ScreenHeight = *(int*)(EspHelperObj.Modulebaseaddress + EspOffsetsObj.o_Resolution + 8);
		draw.DrawLine(ScreenWidth / 2, ScreenHeight, ScreenFeet.x, ScreenFeet.y, IM_COL32(255, 255, 255, 255));
	}
		



}

void Esp::DoEsp(ConfigSettings cfg) {
	espconfig = cfg;
	processed_ents_esp.clear();
	sort_esp_entities();

	for (int i = 0; i < processed_ents_esp.size(); i++) {

		if (processed_ents_esp.empty() || !processed_ents_esp[i])
			continue;


		PlayerData LocalPlayerData = EspHelperObj.get_player_data(EspHelperObj.get_local_player());
		PlayerData TargetPlayerData = EspHelperObj.get_player_data(processed_ents_esp[i]);

		if (!TargetPlayerData.isalive)
			continue;
		if (TargetPlayerData.TeamNum == LocalPlayerData.TeamNum)
			continue;

		uintptr_t entity = processed_ents_esp[i];

		this->DrawEsp(entity);
	
	}

}