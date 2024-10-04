
#pragma once
#include "Aimbot.h"
#include "math.h"

EntityList Aimbot_EntList;
Helper Aimbot_HelperObj;
Offsets Aimbot_Offsets;

#define M_PI 3.14159265358979323846


std::vector<uint64_t> processed_ents;

//get PlayerData
PlayerData LocalPlayerData;
uint64_t CameraManager;
vec2* ViewAngles;



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
		if (EntName == "CItemXP")
			processed_ents.push_back(entity);
		
	}	
}

vec2 Aimbot::GetAimAngles(vec3 Target) {

	vec2 AimAngles = { 0, 0 };
	vec3 CameraPos = *(vec3*)(CameraManager + 0x38);
	vec3 AbsPos = Target - CameraPos;
	AimAngles.y = atan2f(AbsPos.y, AbsPos.x) * 180 / M_PI;
	AimAngles.x = -atan2f(AbsPos.z, sqrt(AbsPos.x * AbsPos.x + AbsPos.y * AbsPos.y)) * 180 / M_PI;
	return AimAngles;
}

void Aimbot::AimAt(uintptr_t entity, const char* bone, float smooth_factor) {


	vec3 vec_target = Aimbot_HelperObj.GetBonePosition(entity, bone);
	vec2 target_angles = this->GetAimAngles(vec_target);

	// Calculate the difference between current angles and target angles

	float delta_x = target_angles.x - ViewAngles->x;
	float delta_y = target_angles.y - ViewAngles->y;
	vec2 delta = { delta_x, delta_y };

	// Smoothly interpolate between current angles and target angles
	if (smooth_factor < 1)
	{
		ViewAngles->x = target_angles.x;
		ViewAngles->y = target_angles.y;
		return;
	}

	vec2 final_delta = delta.clamp();

	ViewAngles->x += final_delta.x / smooth_factor;
	ViewAngles->y += final_delta.y / smooth_factor;
}

void Aimbot::AimAtXp(uintptr_t entity, float smooth_factor) {

	xpData TargetXPData = Aimbot_HelperObj.get_xp_data(entity);

	vec2 target_angles = this->GetAimAngles(TargetXPData.m_vecOrigin);

	float delta_x = target_angles.x - ViewAngles->x;
	float delta_y = target_angles.y - ViewAngles->y;
	vec2 delta = { delta_x, delta_y };

	// Smoothly interpolate between current angles and target angles
	if (smooth_factor < 1)
	{
		ViewAngles->x = target_angles.x;
		ViewAngles->y = target_angles.y;
		return;
	}

	vec2 final_delta = delta.clamp();

	ViewAngles->x += final_delta.x / smooth_factor;
	ViewAngles->y += final_delta.y / smooth_factor;




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
	CameraManager = *(uint64_t*)(Aimbot_HelperObj.Modulebaseaddress + Aimbot_Offsets.o_CameraManager + 0x28);
	ViewAngles = (vec2*)(CameraManager + 0x44);
	LocalPlayerData = Aimbot_HelperObj.get_player_data(Aimbot_HelperObj.get_local_player());

	if (processed_ents.empty())
		return;

	float ClosestDistance = 99999999999.0;
	int ClosestIndex = 999;
	int LowestHealth = 99999999999;
	int LowestHealthIndex = 999;
	float LowestFov = 99999999999.0;
	int lowestfovindex = 999;

	int ClosestXPDistance = 99999999999.0;
	int ClosestXPIndex = 999;
	int LowestFovXP = 99999999999.0;
	int LowestFovXPIndex = 999;

	// Sort Entities
	for (int i = 0; i < processed_ents.size(); i++) {

		if (processed_ents.empty() || !processed_ents[i])
			continue;

		std::string entClass = Aimbot_HelperObj.get_schema_name(processed_ents[i]);

		if (entClass == "CCitadelPlayerController") {
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
			angle_difference = angle_difference.clamp();

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
		if (entClass == "CItemXP") {

			xpData TargetXPData = Aimbot_HelperObj.get_xp_data(processed_ents[i]);

			if (TargetXPData.bDormant)
				continue;

			float xpdistance = Aimbot_HelperObj.GetDistance(LocalPlayerData.m_vecOrigin, TargetXPData.m_vecOrigin);
			if (xpdistance > cfg.aimbot.MaxDistance)
				continue;

			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(TargetXPData.m_vecOrigin);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float xpFOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (xpFOV > cfg.aimbot.fov)
				continue; // Skip targets outside of the FOV

			if (xpdistance < ClosestXPDistance) {
				ClosestXPDistance = xpdistance;
				ClosestXPIndex = i;
			}

			if (xpFOV < LowestFovXP) {
				LowestFovXP = xpFOV; // Update the lowest FOV
				LowestFovXPIndex = i; // Update the index of the target with the lowest FOV
			}

		}
			


	}

	if (GetAsyncKeyState(cfg.aimbot.AimKey)) {
		if (cfg.aimbot.targetSelectionMode == 0 && ClosestIndex != 999) {
			if (!processed_ents.empty() && processed_ents[ClosestIndex]) {
				AimAt(processed_ents[ClosestIndex], "head", cfg.aimbot.smooth);
			}
		}
		else if (cfg.aimbot.targetSelectionMode == 1 && LowestHealthIndex != 999) {
			if (!processed_ents.empty() && processed_ents[LowestHealthIndex]) {
				AimAt(processed_ents[LowestHealthIndex], "head", cfg.aimbot.smooth);
			}
		}
		else if (cfg.aimbot.targetSelectionMode == 2 && lowestfovindex != 999) {
			if (!processed_ents.empty() && processed_ents[lowestfovindex]) {
				AimAt(processed_ents[lowestfovindex], "head", cfg.aimbot.smooth);
			}
		}

	}
	if (cfg.aimbot.AimXp && GetAsyncKeyState(cfg.aimbot.AimKeyXp)) {
		if (cfg.aimbot.targetSelectionMode == 0 && ClosestXPIndex != 999) {
			if (!processed_ents.empty() && processed_ents[ClosestXPIndex]) {
				AimAtXp(processed_ents[ClosestXPIndex], cfg.aimbot.smooth);
			}
		}
		else if (cfg.aimbot.targetSelectionMode == 1 || cfg.aimbot.targetSelectionMode == 2 && LowestFovXPIndex != 999) {
			if (!processed_ents.empty() && processed_ents[LowestFovXPIndex]) {
				AimAtXp(processed_ents[LowestFovXPIndex], cfg.aimbot.smooth);
			}
		}

	}








}