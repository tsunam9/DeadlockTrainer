
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

vec2 Aimbot::GetAimAngles(vec3 Target) {

	vec2 AimAngles = { 0, 0 };

	uint64_t CameraManager = *(uint64_t*)(Aimbot_HelperObj.Modulebaseaddress + Aimbot_Offsets.o_CameraManager + 0x28);
	vec3 CameraPos = *(vec3*)(CameraManager + 0x38);
	vec3 AbsPos = Target - CameraPos;
	AimAngles.y = atan2f(AbsPos.y, AbsPos.x) * 180 / M_PI;
	AimAngles.x = -atan2f(AbsPos.z, sqrt(AbsPos.x * AbsPos.x + AbsPos.y * AbsPos.y)) * 180 / M_PI;
	return AimAngles;
}

void Aimbot::AimAt(uintptr_t entity, const char* bone) {

	const uint64_t CameraManager = *(uint64_t*)(Aimbot_HelperObj.Modulebaseaddress + Aimbot_Offsets.o_CameraManager + 0x28);
	vec2* ViewAngles = (vec2*)(CameraManager + 0x44);

	vec3 vec_target = { 0, 0, 0 };
	vec_target = Aimbot_HelperObj.GetBonePosition(entity, bone);
	
	vec2 aimangles = this->GetAimAngles(vec_target);
	ViewAngles->x = aimangles.x;
	ViewAngles->y = aimangles.y;

}

float GetAngleDifference(float angle1, float angle2) {
	float diff = fmod(angle1 - angle2 + 180.0f, 360.0f);
	if (diff < 0) {
		diff += 360.0f;
	}
	return diff - 180.0f; // Normalize to [-180, 180]
}


void Aimbot::RunAimbot(ConfigSettings cfg) {
	processed_ents.clear();
	sort_entities();

	float ClosestDistance = 99999999999.0;
	int ClosestIndex = 999;

	int LowestHealth = 99999999999;
	int LowestHealthIndex = 999;
	
	float LowestFov = 99999999999.0;
	int lowestfovindex = 999;

	//get PlayerData
	PlayerData LocalPlayerData = Aimbot_HelperObj.get_player_data(Aimbot_HelperObj.get_local_player());
	const uint64_t CameraManager = *(uint64_t*)(Aimbot_HelperObj.Modulebaseaddress + Aimbot_Offsets.o_CameraManager + 0x28);
	vec2* ViewAngles = (vec2*)(CameraManager + 0x44);

	// Sort Entities
	for (int i = 0; i < processed_ents.size(); i++) {

		if (processed_ents.empty() || !processed_ents[i])
			continue;

		PlayerData TargetPlayerData = Aimbot_HelperObj.get_player_data(processed_ents[i]);

		if (!TargetPlayerData.isalive)
			continue;
		if (TargetPlayerData.TeamNum == LocalPlayerData.TeamNum)
			continue;

		vec3 TargetPos = { 0, 0, 0 };
		TargetPos = Aimbot_HelperObj.GetBonePosition(processed_ents[i], "head");

		if (TargetPos.x == 0 && TargetPos.y == 0 && TargetPos.z == 0)
			continue; // Skip invalid targets (no position data)

		// Closest
		// Calculate distance between targetpos and localplayer
		float distance = Aimbot_HelperObj.GetDistance(LocalPlayerData.m_vecOrigin, TargetPos);

		if (distance > cfg.aimbot.MaxDistance)
			continue;

		// Fov

		vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
		vec2 AimAngles = GetAimAngles(TargetPos);
		vec2 angle_difference = AimAngles - LocalPlayerAngles;
		if (angle_difference.x > 180) angle_difference.x -= 360;
		if (angle_difference.x < -180) angle_difference.x += 360;
		if (angle_difference.y > 180) angle_difference.y -= 360;
		if (angle_difference.y < -180) angle_difference.y += 360;
		float FOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

		if (FOV > cfg.aimbot.fov)
			continue; // Skip targets outside of the FOV

		if (distance < ClosestDistance) {
			ClosestDistance = distance;
			ClosestIndex = i;
		}

		if (TargetPlayerData.Health < LowestHealth) {
			LowestHealth = TargetPlayerData.Health;
			LowestHealthIndex = i;
		}

		if (FOV < LowestFov) {
			LowestFov = FOV; // Update the lowest FOV
			lowestfovindex = i; // Update the index of the target with the lowest FOV
		}


	}
	if (cfg.aimbot.targetSelectionMode == 0 && ClosestIndex !=999) {
		if (!processed_ents.empty() && processed_ents[ClosestIndex]) {
			AimAt(processed_ents[ClosestIndex], "head");
		}
	}
	else if (cfg.aimbot.targetSelectionMode == 1 && LowestHealthIndex != 999) {
		if (!processed_ents.empty() && processed_ents[LowestHealthIndex]) {
			AimAt(processed_ents[LowestHealthIndex], "head");
		}
	}
	else if (cfg.aimbot.targetSelectionMode == 2 && lowestfovindex != 999) {
		if (!processed_ents.empty() && processed_ents[lowestfovindex]) {
			AimAt(processed_ents[lowestfovindex], "head");
		}
	}

}