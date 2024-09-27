
#pragma once
#include "Aimbot.h"
#include "math.h"

EntityList Aimbot_EntList;
Helper Aimbot_HelperObj;
Offsets Aimbot_Offsets;

#define M_PI 3.14159265358979323846


std::vector<uint64_t> processed_ents;

inline void sort_entities()
{
	int max_ents = Aimbot_HelperObj.get_max_entities();

	for (size_t i = 1; i <= static_cast<size_t>(max_ents); ++i)
	{
		uint64_t entity = Aimbot_HelperObj.get_base_entity_from_index(i);

		if (!entity)
			continue;

		std::string EntName = Aimbot_HelperObj.get_schema_name(entity);

		if (EntName == "CCitadelPlayerController" && !*(bool*)(entity + CBasePlayerController::m_bIsLocalPlayerController))
			processed_ents.push_back(entity);
		
	}	
}



void Aimbot::AimAt(vec3 Target) {
	uint64_t CameraManager = *(uint64_t*)(Aimbot_HelperObj.Modulebaseaddress + Aimbot_Offsets.o_CameraManager + 0x28);
	vec2* ViewAngles = (vec2*)(CameraManager + 0x44);
	vec3 CameraPos = *(vec3*)(CameraManager + 0x38);
	vec3 AbsPos = Target - CameraPos;
	ViewAngles->y = atan2f(AbsPos.y, AbsPos.x) * 180 / M_PI;
	ViewAngles->x = -atan2f(AbsPos.z, sqrt(AbsPos.x * AbsPos.x + AbsPos.y * AbsPos.y)) * 180 / M_PI;
}

void Aimbot::AimAtPlayer(uintptr_t entity, bool orb) {
	if(!entity)
		return;
	vec3 TargetPos;
	TargetPos.x = 0;
	TargetPos.y = 0;
	TargetPos.z = 0;
	if (orb) {
		uint64_t GameSceneNode = *(uint64_t*)(entity + C_BaseEntity::m_pGameSceneNode);
		vec3 TargetPos = *(vec3*)(GameSceneNode + CGameSceneNode::m_vecAbsOrigin);
	}
	else {
		//Get PlayerPawn
		uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
		uint64_t Pawn = Aimbot_HelperObj.get_base_entity_from_index(Aimbot_HelperObj.CHandle_get_entry_index(PawnHandle));
		std::string bonechoice = "head";
		int boneindex = Aimbot_HelperObj.get_index(Pawn, bonechoice);
		TargetPos = Aimbot_HelperObj.GetBoneVectorFromIndex(Pawn, boneindex);
	}
	this->AimAt(TargetPos); // Aim at the target
}

void Aimbot::RunAimbot() {
	processed_ents.clear();
	sort_entities();

	float ClosestDistance = 99999999999.0;
	int ClosestIndex = 0;

	uint64_t aimbotTarget = 0;
	vec3 TargetPos = { 0, 0, 0 };  // Initialize TargetPos here

	// Sort the entities by distance to the player
	for (int i = 0; i < processed_ents.size(); i++) {

		if (processed_ents.empty() || !processed_ents[i])
			continue;
		

		PlayerData LocalPlayerData = Aimbot_HelperObj.get_player_data(Aimbot_HelperObj.get_local_player());
		PlayerData TargetPlayerData = Aimbot_HelperObj.get_player_data(processed_ents[i]);

		if (!TargetPlayerData.isalive)
			continue;
		if(TargetPlayerData.TeamNum == LocalPlayerData.TeamNum)
			continue;


		uintptr_t entity = processed_ents[i];
		std::string EntName = Aimbot_HelperObj.get_schema_name(entity);

		// Reset TargetPos for each entity iteration
		TargetPos = { 0, 0, 0 };

		if (EntName == "CCitadelPlayerController") {
			uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
			uint64_t Pawn = Aimbot_HelperObj.get_base_entity_from_index(Aimbot_HelperObj.CHandle_get_entry_index(PawnHandle));
			uint64_t boneindex = Aimbot_HelperObj.get_index(Pawn, "head");
			TargetPos = Aimbot_HelperObj.GetBoneVectorFromIndex(Pawn, boneindex);  // No re-declaration of TargetPos here
			

		}
		else if (EntName == "CItemXP") {
			uint64_t GameSceneNode = *(uint64_t*)(entity + C_BaseEntity::m_pGameSceneNode);
			TargetPos = *(vec3*)(GameSceneNode + CGameSceneNode::m_vecAbsOrigin);  // No re-declaration of TargetPos here
		}

		if (TargetPos.x == 0 && TargetPos.y == 0 && TargetPos.z == 0)
			continue; // Skip invalid targets (no position data)
		

		// Calculate distance between targetpos and localplayer
		vec3 LocalPlayerPos = LocalPlayerData.m_vecOrigin;

		float distanceSquared = (TargetPos.x - LocalPlayerPos.x) * (TargetPos.x - LocalPlayerPos.x) +
			(TargetPos.y - LocalPlayerPos.y) * (TargetPos.y - LocalPlayerPos.y) +
			(TargetPos.z - LocalPlayerPos.z) * (TargetPos.z - LocalPlayerPos.z);
		float distance = sqrt(distanceSquared);
	

		if (distance < ClosestDistance) {
			ClosestDistance = distance;
			ClosestIndex = i;
		}
	}

	// Make sure we have a valid target
	if (!processed_ents.empty() && processed_ents[ClosestIndex]) {
		this->AimAtPlayer(processed_ents[ClosestIndex], false);		
	}
}