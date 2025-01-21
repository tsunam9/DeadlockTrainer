
#pragma once
#include "Aimbot.h"
#include "math.h"

#define M_PI 3.14159265358979323846

//get PlayerData
static uint64_t LocalPlayerController;
static PlayerData LocalPlayerData;
static uint64_t CameraManager;
static vec2* ViewAngles;
static vec2* crosshairposition;
static Helper AimbotHelperObj;
static Drawing aimbotdraw;
static std::vector<uintptr_t> abilities;
static CCitadelUserCmdPB* CUserCmd;
globals& aimbotglobs = globals::instance();

uint64_t CurrentPlayerTarget = 0;
bool aim_Aimbotting = false;
bool aim_RageBotting = false;
bool aim_LegitBotting = false;

bool IsPlayerVisible(uint64_t entity) {

	vec3 EnemyHead = Helper::GetBonePosition(entity, "head");
	vec3 LocalCameraPos = *(vec3*)(CameraManager + 0x38);
	vec3 LocalPlayerHead = Helper::GetBonePosition(Helper::get_local_player(), "head");


	bool firstvar = Helper::CheckLocationVisible(LocalPlayerHead, EnemyHead);
	bool secondvar = Helper::CheckLocationVisible(LocalCameraPos, EnemyHead);
	return secondvar && firstvar;
	

}

bool IsXpVisible(uint64_t entity) {

	xpData* TargetXPData = new xpData;
	Helper::get_xp_data(entity, TargetXPData);
	vec3 LocalCameraPos = *(vec3*)(CameraManager + 0x38);
	vec3 LocalPlayerHead = Helper::GetBonePosition(Helper::get_local_player(), "head");
	bool result = Helper::CheckLocationVisible(LocalCameraPos, TargetXPData->m_vecOrigin) && Helper::CheckLocationVisible(LocalPlayerHead, TargetXPData->m_vecOrigin);
	delete TargetXPData;
	return result;
}

bool IsNpcVisible(uint64_t entity) {

	NpcData* TargetNpcData = new NpcData; 
	Helper::get_npc_data(entity, TargetNpcData);
	vec3 LocalCameraPos = *(vec3*)(CameraManager + 0x38);
	vec3 LocalPlayerHead = Helper::GetBonePosition(Helper::get_local_player(), "head");
	int boneindex = Helper::get_bone_index(entity, "head");
	vec3 MinionHead = Helper::GetBoneVectorFromIndex(entity, boneindex);

	

	bool check1 = Helper::CheckLocationVisible(LocalCameraPos, MinionHead);
	delete TargetNpcData;
	return check1;
}

bool ClosestVisiblePosToTarget(vec3 localheadpos, vec3 target, vec3 &AimFromPos) {

	vec3 check1 = { localheadpos.x + 150, localheadpos.y, localheadpos.z };
	vec3 check2 = { localheadpos.x - 150, localheadpos.y, localheadpos.z };
	vec3 check3 = { localheadpos.x, localheadpos.y + 150, localheadpos.z };
	vec3 check4 = { localheadpos.x, localheadpos.y - 150, localheadpos.z };
	vec3 check5 = { localheadpos.x, localheadpos.y, localheadpos.z + 150 };

	if (Helper::CheckLocationVisible(check1, target)) {
		if (Helper::CheckLocationVisible(LocalPlayerData.m_vecOrigin, check1)) {
			AimFromPos = check1;
			return true;
		}
	}

	if (Helper::CheckLocationVisible(check2, target)) {
		if (Helper::CheckLocationVisible(LocalPlayerData.m_vecOrigin, check2)) {
			AimFromPos = check2;
			return true;
		}
	}

	if (Helper::CheckLocationVisible(check3, target)) {
		if (Helper::CheckLocationVisible(LocalPlayerData.m_vecOrigin, check3)) {
			AimFromPos = check3;
			return true;
		}
	}

	if (Helper::CheckLocationVisible(check4, target)) {
		if (Helper::CheckLocationVisible(LocalPlayerData.m_vecOrigin, check4)) {
			AimFromPos = check4;
			return true;
		}
	}

	if (Helper::CheckLocationVisible(check5, target)) {
		if (Helper::CheckLocationVisible(LocalPlayerData.m_vecOrigin, check5)) {
			AimFromPos = check5;
			return true;
		}
	}

	return false;

}



uint64_t Aimbot::GetCurrentAimbotTarget() {
		return CurrentPlayerTarget;
}

bool Aimbot::IsAimbotting() {
	return aim_Aimbotting;
}

bool Aimbot::IsRageBotting() {
	return aim_RageBotting;
}

bool Aimbot::IsLegitBotting() {
	return aim_LegitBotting;
}

bool Aimbot::LegitGetAimbotTarget(uint32_t group, int &closestbone, uint64_t& aimtarget) {

	float ClosestDistance = 99999.f;
	int ClosestIndex = 999;
	int LowestHealth = 99999.f;
	int LowestHealthIndex = 999;
	float LowestFov = 99999.f;
	int lowestfovindex = 999;

	for (int i = 0; i < aimbotglobs.entlist.active->size(); i++) {

		std::string entClass = Helper::get_schema_name((*aimbotglobs.entlist.active)[i]);

		if (entClass == "CCitadelPlayerController" && group == AimGroup_Player) {

			PlayerData TargetPlayerData;
			Helper::get_player_data((*aimbotglobs.entlist.active)[i], &TargetPlayerData);


			if (!TargetPlayerData.isalive) {
				continue;
			}

			if (TargetPlayerData.TeamNum == LocalPlayerData.TeamNum) {
				continue;
			}

			if (IsPlayerVisible((*aimbotglobs.entlist.active)[i]) == false) {
				continue;
			}


			float distance = 0.f;
			int hitboxessize = legitbot_hitboxes.size();

			if (hitboxessize > 0) {

				vec3 TargetPos = { 0, 0, 0 };
				TargetPos = Helper::GetBonePosition((*aimbotglobs.entlist.active)[i], legitbot_hitboxes[0].c_str());
				if (TargetPos.x == 0 && TargetPos.y == 0 && TargetPos.z == 0) {
					continue;
				}
				distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetPos);
			}
			if (!(distance > 0.f || distance > 3000.f)) {
				continue;
			}

			for (int hitboxindex = 0; hitboxindex < hitboxessize; hitboxindex++) {

				vec3 TargetPos = { 0, 0, 0 };
				TargetPos = Helper::GetBonePosition((*aimbotglobs.entlist.active)[i], legitbot_hitboxes[hitboxindex].c_str());
				if (TargetPos.x == 0 && TargetPos.y == 0 && TargetPos.z == 0) {
					continue;
				}

				vec2 AimAngles = GetAimAngles(TargetPos);
				vec2 angle_difference = AimAngles - *ViewAngles;
				angle_difference = angle_difference.clamp();

				float FOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

				if (FOV > cfg::legitbot_fov) {
					continue; // Skip targets outside of the FOV
				}

				if (FOV < LowestFov) {
					LowestFov = FOV; // Update the lowest FOV
					lowestfovindex = i; // Update the index of the target with the lowest FOV
					closestbone = hitboxindex;
				}

			}




		}




	}

	if (group == AimGroup_Player) {

			if (lowestfovindex == 999) {
				CurrentPlayerTarget = 0;
				return false;
			}
			CurrentPlayerTarget = (*aimbotglobs.entlist.active)[lowestfovindex];
			aimtarget = (*aimbotglobs.entlist.active)[lowestfovindex];
			return true;
	}

	return false;
}



uint64_t Aimbot::RageGetAimbotTarget(uint32_t group) {

	float ClosestDistance = 99999999999.0;
	int ClosestIndex = 999;
	int LowestHealth = 99999999999;
	int LowestHealthIndex = 999;
	float LowestFov = 99999999999.0;
	int lowestfovindex = 999;

	//(*aimbotglobs.entlist.active)

	// Sort Entities
	for (int i = 0; i < aimbotglobs.entlist.active->size(); i++) {

		if ( aimbotglobs.entlist.active->empty())
			continue;

		std::string entClass = Helper::get_schema_name((*aimbotglobs.entlist.active)[i]);

		if (entClass == "CCitadelPlayerController" && group == AimGroup_Player) {

			PlayerData TargetPlayerData;
			if (!Helper::get_player_data((*aimbotglobs.entlist.active)[i], &TargetPlayerData)) {
				continue;
			}

			if (TargetPlayerData.dormant) {
				continue;
			}

			if (!(TargetPlayerData.isalive)) {
				continue;
			}

			if (TargetPlayerData.TeamNum == LocalPlayerData.TeamNum) {
				continue;
			}

			if(!cfg::ragebot_magicbullet){ // if magic bullet then obviously dont do vischeck 
				if (IsPlayerVisible((*aimbotglobs.entlist.active)[i]) == false) {
					continue;
				}
			}

			vec3 TargetPos = { 0, 0, 0 };
			TargetPos = Helper::GetBonePosition((*aimbotglobs.entlist.active)[i], "head");

			if (TargetPos.x == 0 && TargetPos.y == 0 && TargetPos.z == 0) {
				continue;
			}

			// Closest
			// Calculate distance between targetpos and localplayer
			float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetPos);

			if (distance > cfg::ragebot_maxdistance) {
				continue;
			}

			// Fov

			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(TargetPos);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float FOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (FOV > cfg::ragebot_aimfov) {
				continue; // Skip targets outside of the FOV
			}

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
		else if (entClass == "CItemXP" && group == AimGroup_Soul) {

			xpData* TargetXPData = new xpData;
			Helper::get_xp_data((*aimbotglobs.entlist.active)[i], TargetXPData);
			float GameTime = globals::instance().Globals->flAbsCurTime;
			float launchtime = TargetXPData->m_flLaunchtime;

			if (TargetXPData->m_bDormant)
				continue;
			if (GameTime < TargetXPData->m_flLaunchtime + 0.184)
				continue;

			if (IsXpVisible((*aimbotglobs.entlist.active)[i]) == false)
				continue;

			float xpdistance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetXPData->m_vecOrigin);
			if (xpdistance > cfg::ragebot_maxdistance)
				continue;

			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(TargetXPData->m_vecOrigin);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float xpFOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (xpFOV > cfg::ragebot_aimfov)
				continue; // Skip targets outside of the FOV

			if (xpdistance < ClosestIndex) {
				ClosestDistance = xpdistance;
				ClosestIndex = i;
			}

			if (xpFOV < LowestFov) {
				LowestFov = xpFOV; // Update the lowest FOV
				lowestfovindex = i; // Update the index of the target with the lowest FOV
			}

			delete TargetXPData;

		}
		else if (entClass == "C_NPC_Trooper" && group == AimGroup_Minion) {

			NpcData* TargetNpcData = new NpcData;
			Helper::get_npc_data((*aimbotglobs.entlist.active)[i], TargetNpcData);


			if (TargetNpcData->m_bDormant) {
				delete TargetNpcData;
				continue;
			}

			uint64_t entteamnum = 263168 + LocalPlayerData.TeamNum;
			if (TargetNpcData->m_iteamnum == entteamnum) {  // really awful terribleness because the number just happens to be this for minion teams
				delete TargetNpcData;
				continue;
			}

			if (TargetNpcData->m_ilifestate != 0) {
				delete TargetNpcData;
				continue;
			}

			if (IsNpcVisible((*aimbotglobs.entlist.active)[i]) == false) {
				delete TargetNpcData;
				continue;	
			}

			float MinionDistance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetNpcData->m_vecOrigin);
			if (MinionDistance > cfg::ragebot_maxdistance) {
				delete TargetNpcData;
				continue;
			}

			if (MinionDistance > 2000.0f) {
				delete TargetNpcData;
				continue;
			}

			int boneindex = Helper::get_bone_index((*aimbotglobs.entlist.active)[i], "head");
			if (!boneindex) {
				delete TargetNpcData;
				continue;
			}

			vec3 HeadPos = Helper::GetBoneVectorFromIndex((*aimbotglobs.entlist.active)[i], boneindex);  // No re-declaration of TargetPos here
			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(HeadPos);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float minionfov = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (minionfov > cfg::ragebot_aimfov) {
				delete TargetNpcData;
				continue;
			} // Skip targets outside of the FOV

			if (MinionDistance < ClosestDistance) {
				ClosestDistance = MinionDistance;
				ClosestIndex = i;
			}

			if (TargetNpcData->m_iHealth < LowestHealth) {
				LowestHealth = TargetNpcData->m_iHealth;
				LowestHealthIndex = i;
			}

			if (minionfov < LowestFov) {
				LowestFov = minionfov; // Update the lowest FOV
				lowestfovindex = i; // Update the index of the target with the lowest FOV
			}

			delete TargetNpcData;

		}
	}
	



	if (group == AimGroup_Player) {
		switch (cfg::ragebot_TargetSelectMode) {
		case 0:
			if (ClosestIndex == 999) {
				CurrentPlayerTarget = 0;
				return 0;
			}
			CurrentPlayerTarget = (*aimbotglobs.entlist.active)[ClosestIndex];
			return (*aimbotglobs.entlist.active)[ClosestIndex];
		case 1:
			if (LowestHealthIndex == 999) {
				CurrentPlayerTarget = 0;
				return 0;
			}
			CurrentPlayerTarget = (*aimbotglobs.entlist.active)[LowestHealthIndex];
			return (*aimbotglobs.entlist.active)[LowestHealthIndex];
		case 2:
			if (lowestfovindex == 999) {
				CurrentPlayerTarget = 0;
				return 0;
			}
			CurrentPlayerTarget = (*aimbotglobs.entlist.active)[lowestfovindex];
			return (*aimbotglobs.entlist.active)[lowestfovindex];
		}
	}
	else if (group == AimGroup_Soul) {
		switch (cfg::ragebot_TargetSelectMode) {
		case 0:
			if (ClosestIndex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[ClosestIndex];
		case 1:
			if (lowestfovindex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[lowestfovindex];
		case 2:
			if (lowestfovindex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[lowestfovindex];
		}
	}
	else if (group == AimGroup_Minion) {
		switch (cfg::ragebot_TargetSelectMode) {
		case 0:
			if (ClosestIndex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[ClosestIndex];
		case 1:
			if (LowestHealthIndex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[LowestHealthIndex];
		case 2:
			if (lowestfovindex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[lowestfovindex];
		}
	}
}

uint64_t Aimbot::CalculateNewAimbotTarget(uint32_t group, float maxdistance, float aim_fov, bool aim_teammates) {

	float ClosestDistance = 99999999999.0;
	int ClosestIndex = 999;
	int LowestHealth = 99999999999;
	int LowestHealthIndex = 999;
	float LowestFov = 99999999999.0;
	int lowestfovindex = 999;

	//(*aimbotglobs.entlist.active)

	// Sort Entities
	for (int i = 0; i < aimbotglobs.entlist.active->size(); i++) {

		if (aimbotglobs.entlist.active->empty())
			continue;

		std::string entClass = Helper::get_schema_name((*aimbotglobs.entlist.active)[i]);

		if (entClass == "CCitadelPlayerController" && group == AimGroup_Player) {

			PlayerData TargetPlayerData;
			if (!Helper::get_player_data((*aimbotglobs.entlist.active)[i], &TargetPlayerData)) {
				continue;
			}

			if (TargetPlayerData.dormant) {
				continue;
			}

			if (!(TargetPlayerData.isalive)) {
				continue;
			}

			if (TargetPlayerData.TeamNum == LocalPlayerData.TeamNum && !aim_teammates) {
				continue;
			}

			if (aim_teammates) {
				if (TargetPlayerData.TeamNum != LocalPlayerData.TeamNum) {
					continue;
				}
			}

			if (!cfg::ragebot_magicbullet) { // if magic bullet then obviously dont do vischeck 
				if (IsPlayerVisible((*aimbotglobs.entlist.active)[i]) == false) {
					continue;
				}
			}

			vec3 TargetPos = { 0, 0, 0 };
			TargetPos = Helper::GetBonePosition((*aimbotglobs.entlist.active)[i], "head");

			if (TargetPos.x == 0 && TargetPos.y == 0 && TargetPos.z == 0) {
				continue;
			}

			// Closest
			// Calculate distance between targetpos and localplayer
			float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetPos);

			if (distance > maxdistance) {
				continue;
			}

			// Fov

			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(TargetPos);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float FOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (FOV > aim_fov) {
				continue; // Skip targets outside of the FOV
			}

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
		else if (entClass == "CItemXP" && group == AimGroup_Soul) {

			xpData* TargetXPData = new xpData;
			Helper::get_xp_data((*aimbotglobs.entlist.active)[i], TargetXPData);
			float GameTime = globals::instance().Globals->flAbsCurTime;
			float launchtime = TargetXPData->m_flLaunchtime;

			if (TargetXPData->m_bDormant)
				continue;
			if (GameTime < TargetXPData->m_flLaunchtime + 0.184)
				continue;

			if (IsXpVisible((*aimbotglobs.entlist.active)[i]) == false)
				continue;

			float xpdistance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetXPData->m_vecOrigin);
			if (xpdistance > maxdistance)
				continue;

			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(TargetXPData->m_vecOrigin);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float xpFOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (xpFOV > aim_fov)
				continue; // Skip targets outside of the FOV

			if (xpdistance < ClosestIndex) {
				ClosestDistance = xpdistance;
				ClosestIndex = i;
			}

			if (xpFOV < LowestFov) {
				LowestFov = xpFOV; // Update the lowest FOV
				lowestfovindex = i; // Update the index of the target with the lowest FOV
			}

			delete TargetXPData;

		}
		else if (entClass == "C_NPC_Trooper" && group == AimGroup_Minion) {

			NpcData* TargetNpcData = new NpcData;
			Helper::get_npc_data((*aimbotglobs.entlist.active)[i], TargetNpcData);


			if (TargetNpcData->m_bDormant) {
				delete TargetNpcData;
				continue;
			}

			uint64_t entteamnum = 263168 + LocalPlayerData.TeamNum;
			if (TargetNpcData->m_iteamnum == entteamnum) {  // really awful terribleness because the number just happens to be this for minion teams
				delete TargetNpcData;
				continue;
			}

			if (TargetNpcData->m_ilifestate != 0) {
				delete TargetNpcData;
				continue;
			}

			if (IsNpcVisible((*aimbotglobs.entlist.active)[i]) == false) {
				delete TargetNpcData;
				continue;
			}

			float MinionDistance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetNpcData->m_vecOrigin);
			if (MinionDistance > cfg::ragebot_maxdistance) {
				delete TargetNpcData;
				continue;
			}

			if (MinionDistance > maxdistance) {
				delete TargetNpcData;
				continue;
			}

			int boneindex = Helper::get_bone_index((*aimbotglobs.entlist.active)[i], "head");
			if (!boneindex) {
				delete TargetNpcData;
				continue;
			}

			vec3 HeadPos = Helper::GetBoneVectorFromIndex((*aimbotglobs.entlist.active)[i], boneindex);  // No re-declaration of TargetPos here
			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(HeadPos);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float minionfov = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (minionfov > aim_fov) {
				delete TargetNpcData;
				continue;
			} // Skip targets outside of the FOV

			if (MinionDistance < ClosestDistance) {
				ClosestDistance = MinionDistance;
				ClosestIndex = i;
			}

			if (TargetNpcData->m_iHealth < LowestHealth) {
				LowestHealth = TargetNpcData->m_iHealth;
				LowestHealthIndex = i;
			}

			if (minionfov < LowestFov) {
				LowestFov = minionfov; // Update the lowest FOV
				lowestfovindex = i; // Update the index of the target with the lowest FOV
			}

			delete TargetNpcData;

		}
	}




	if (group == AimGroup_Player) {
		switch (cfg::ragebot_TargetSelectMode) {
		case 0:
			if (ClosestIndex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[ClosestIndex];
		case 1:
			if (LowestHealthIndex == 999) {
				CurrentPlayerTarget = 0;
				return 0;
			}
			return (*aimbotglobs.entlist.active)[LowestHealthIndex];
		case 2:
			if (lowestfovindex == 999) {
				CurrentPlayerTarget = 0;
				return 0;
			}
			return (*aimbotglobs.entlist.active)[lowestfovindex];
		}
	}
	else if (group == AimGroup_Soul) {
		switch (cfg::ragebot_TargetSelectMode) {
		case 0:
			if (ClosestIndex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[ClosestIndex];
		case 1:
			if (lowestfovindex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[lowestfovindex];
		case 2:
			if (lowestfovindex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[lowestfovindex];
		}
	}
	else if (group == AimGroup_Minion) {
		switch (cfg::ragebot_TargetSelectMode) {
		case 0:
			if (ClosestIndex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[ClosestIndex];
		case 1:
			if (LowestHealthIndex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[LowestHealthIndex];
		case 2:
			if (lowestfovindex == 999) {
				return 0;
			}
			return (*aimbotglobs.entlist.active)[lowestfovindex];
		}
	}
}



vec3 Aimbot::PredictPosition(vec3 Target, vec3 Velocity, float bulletspeed) {

	if (bulletspeed < 0) { // error checking and helpful vindicta sniper check if we pass in -1 for bulletspeed when sniping
		return Target;
	}
	vec3 localpos = LocalPlayerData.m_vecOrigin;
	float distance = Helper::GetDistance(localpos, Target);
	float time = distance / bulletspeed;
	Target.x += (Velocity.x * time);
	Target.y += (Velocity.y * time);
	Target.z += (Velocity.z * time);
	return Target;

}

vec2 GetAim(vec3 CameraPos, vec3 Target) {
	vec2 angles;
	vec3 AbsPos = Target - CameraPos;
	angles.y = atan2f(AbsPos.y, AbsPos.x) * 180 / M_PI;
	angles.x = -atan2f(AbsPos.z, sqrt(AbsPos.x * AbsPos.x + AbsPos.y * AbsPos.y)) * 180 / M_PI;
	return angles;
}

vec2 Aimbot::GetAimAngles(vec3 Target) {
	vec2 AimAngles = { 0, 0 };
	vec3 CameraPos = *(vec3*)(CameraManager + 0x38);
	return GetAim(CameraPos, Target);
}

void Aimbot::AimAbility(uintptr_t entity, int aimpos, uintptr_t ability, float projectilespeed, bool projectile) { // 0 head, 1 pelvis, else origin aimpos

	if (!entity)
		return;
	if (!ability)
		return;

	PlayerData targetdata;
	Helper::get_player_data(entity, &targetdata);


	vec3 vec_target;
	if (aimpos == 0) {
		vec_target = Helper::GetBonePosition(entity, "head");
	}
	else if (aimpos == 1) {
		vec_target = Helper::GetBonePosition(entity, "pelvis");
	}
	else {
		vec_target = targetdata.m_vecOrigin;
	}

	if (!projectile) {
		vec2 target_angles = Aimbot::GetAimAngles(vec_target);
		CUserCmd->cameraViewAngle->viewAngles.x = target_angles.x;
		CUserCmd->cameraViewAngle->viewAngles.y = target_angles.y;
		return;
	}

	vec3 predictedposition = Aimbot::PredictPosition(vec_target, targetdata.m_vecVelocity, projectilespeed);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);
	CUserCmd->cameraViewAngle->viewAngles.x = target_angles.x;
	CUserCmd->cameraViewAngle->viewAngles.y = target_angles.y;

}

void Aimbot::ShootMagicBullet(uint64_t entity) {

	float BulletSpeed = globals::instance().BulletVelocity;
	vec3 vec_target = Helper::GetBonePosition(entity, "head");
	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	vec3 vec_velocity = *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);

	vec3 predictedposition = Aimbot::PredictPosition(vec_target, vec_velocity, BulletSpeed);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);

		vec3 AimFrom;

		vec3 localheadpos = Helper::GetBonePosition(Helper::get_local_player(), "head");


		if (ClosestVisiblePosToTarget(localheadpos, predictedposition, AimFrom)) {

			aim_RageBotting = true; 
			aim_Aimbotting = true;

			CUserCmd->buttons |= IN_ATTACK;
			CUserCmd->origin->m_vecOrigin.x = AimFrom.x;
			CUserCmd->origin->m_vecOrigin.y = AimFrom.y;
			CUserCmd->origin->m_vecOrigin.z = AimFrom.z;
			vec2 aimgles = GetAim(AimFrom, predictedposition);
			CUserCmd->cameraViewAngle->viewAngles.x = aimgles.x;
			CUserCmd->cameraViewAngle->viewAngles.y = aimgles.y;

		}

	return;
}


bool readyToFire() {

	if (!iEngine->IsConnected() || !iEngine->IsInGame()) {
		return false;
	}

	uintptr_t localweapon = Helper::get_localplr_weapon();

	if (!localweapon)
		return false;

	float NextAttack = *(float*)(localweapon + CCitadel_Ability_PrimaryWeapon::m_flNextPrimaryAttack);
	float LocalPlayerSimTime = *(float*)(Helper::get_local_player() + C_BaseEntity::m_flSimulationTime);
	NextAttack -= 0.017;
	if (NextAttack > LocalPlayerSimTime)
		return false;
	return true;
}

void Aimbot::RageAimAt(uint64_t entity) {

	if (cfg::ragebot_magicbullet) // dont interfere if magic bullet is currently shooting
		return;

	if (LocalPlayerData.HeroID == Bebop) {
		CUserCmd->buttons |= IN_ATTACK;
	}

	float BulletSpeed = globals::instance().BulletVelocity;
	vec3 vec_target = Helper::GetBonePosition(entity, "head");
	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	vec3 vec_velocity = *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);

	vec3 predictedposition = Aimbot::PredictPosition(vec_target, vec_velocity, BulletSpeed);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);


	if (cfg::ragebot_silentaim) { // silent aim

		if (!readyToFire())
			return;

		aim_RageBotting = true;
		aim_Aimbotting = true;

		CUserCmd->buttons |= IN_ATTACK;
		CUserCmd->cameraViewAngle->viewAngles.x = target_angles.x;
		CUserCmd->cameraViewAngle->viewAngles.y = target_angles.y;

		return;

	}


	aim_RageBotting = true;
	aim_Aimbotting = true;

	CUserCmd->buttons |= IN_ATTACK;
	ViewAngles->x = target_angles.x;
	ViewAngles->y = target_angles.y;
	return;
}

void Aimbot::RageAimAtXp(uintptr_t entity) {

	xpData TargetXPData;
	Helper::get_xp_data(entity, &TargetXPData);
	vec2 target_angles = Aimbot::GetAimAngles(TargetXPData.m_vecOrigin);

	if (cfg::ragebot_silentaim) { // silent aim

		if (!readyToFire())
			return;

		aim_RageBotting = true;
		aim_Aimbotting = true;

		CUserCmd->buttons |= IN_ATTACK;

		CUserCmd->cameraViewAngle->viewAngles.x = target_angles.x;
		CUserCmd->cameraViewAngle->viewAngles.y = target_angles.y;

		return;
	}

	if (!readyToFire())
		return;

	aim_RageBotting = true;
	aim_Aimbotting = true;

	CUserCmd->buttons |= IN_ATTACK;

	ViewAngles->x = target_angles.x;
	ViewAngles->y = target_angles.y;


	return;

}

void Aimbot::RageAimAtMinions(uintptr_t entity) {

	NpcData targetnpcdata;
	Helper::get_npc_data(entity, &targetnpcdata);

	if(targetnpcdata.m_bDormant)
		return;

	int boneindex = Helper::get_bone_index(entity, "head");
	if (!boneindex)
		return;
	vec3 HeadPos = Helper::GetBoneVectorFromIndex(entity, boneindex);  // No re-declaration of TargetPos here
	vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };

	vec2 target_angles = Aimbot::GetAimAngles(HeadPos);


	if (cfg::ragebot_silentaim) { // silent aim

		if (!readyToFire())
			return;

		aim_RageBotting = true;
		aim_Aimbotting = true;

		CUserCmd->buttons |= IN_ATTACK;
		CUserCmd->cameraViewAngle->viewAngles.x = target_angles.x;
		CUserCmd->cameraViewAngle->viewAngles.y = target_angles.y;


		return;

	}


	aim_RageBotting = true;
	aim_Aimbotting = true;

	CUserCmd->buttons |= IN_ATTACK;
	ViewAngles->x = target_angles.x;
	ViewAngles->y = target_angles.y;

}

void Aimbot::LegitAimAt(uint64_t entity, std::string bone) {


	float BulletSpeed = globals::instance().BulletVelocity;
	vec3 vec_target = Helper::GetBonePosition(entity, bone.c_str());
	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	vec3 vec_velocity = *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);


	vec3 predictedposition = Aimbot::PredictPosition(vec_target, vec_velocity, BulletSpeed);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);

	aim_LegitBotting = true;
	aim_Aimbotting = true;

	float delta_x = target_angles.x - ViewAngles->x;
	float delta_y = target_angles.y - ViewAngles->y;
	vec2 delta = { delta_x, delta_y };

	vec2 final_delta = delta.clamp();

	if (cfg::legitbot_pitchcorrection) {
		ViewAngles->x += (cfg::legitbot_pitchcorrectammount) * (final_delta.x / cfg::legitbot_smooth);
	}
	if (cfg::legitbot_yawcorrection) {
		ViewAngles->y += (cfg::legitbot_yawcorrectammount) * (final_delta.y / cfg::legitbot_smooth);
	}

	return;




}



float GetAngleDifference(float angle1, float angle2) {
	float diff = fmod(angle1 - angle2 + 180.0f, 360.0f);
	if (diff < 0) {
		diff += 360.0f;
	}
	return diff - 180.0f; // Normalize to [-180, 180]
}



void Aimbot::RunAimbot(CCitadelUserCmdPB* usercmd) { // ran in CreateMove hook

	if (!usercmd)
		return;

	CUserCmd = usercmd;


	aimbotglobs.SortEnts();
	 
	crosshairposition = (vec2*)(CameraManager + Offsets.o_crosshairposfromcameramanager);
	CameraManager = *(uint64_t*)(ClientModuleBase + Offsets.o_CameraManager + 0x28);
	ViewAngles = (vec2*)(CameraManager + 0x44); // RESET to 0x44
	LocalPlayerController = Helper::get_local_player();
	Helper::get_player_data(LocalPlayerController, &LocalPlayerData);
	abilities = Helper::GetAbilities(Helper::GetPawn(Helper::get_local_player()));



	
	if (aimbotglobs.entlist.active->empty()){
		return;
	}

	if (cfg::ragebot_masterswitch) { // ragebot

		uint64_t aimtarget = Aimbot::RageGetAimbotTarget(AimGroup_Player);
		uint64_t xp_target = 0; // make sure unassigned is always zero 
		uint64_t minion_target = 0;

		if (cfg::ragebot_AimXp)
			xp_target = Aimbot::RageGetAimbotTarget(AimGroup_Soul);
		if (cfg::ragebot_AimMinions)
			minion_target = Aimbot::RageGetAimbotTarget(AimGroup_Minion);

		if (cfg::ragebot_magicbullet && aimtarget) {
			ShootMagicBullet(aimtarget);
			return;
		}

		if (cfg::ragebot_bAimbot && aimtarget) {
			RageAimAt(aimtarget);
			return;
		}

		if (cfg::ragebot_AimXp && xp_target) {
				RageAimAtXp(xp_target);
				return;
		}

		if (cfg::ragebot_AimMinions && minion_target) {
				RageAimAtMinions(minion_target);
				return;
		}




		return;
	}
	else {

		if (!cfg::legitbot_masterswitch)
			return;

		int closestbone = 0;
		uint64_t aimtarget = 0;

		bool result = Aimbot::LegitGetAimbotTarget(AimGroup_Player, closestbone, aimtarget);

		uint64_t xp_target = 0; // make sure unassigned is always zero 
		uint64_t minion_target = 0;

		static float timeaquiredtarget = 0.0f;
		static bool settime = false;

		if (aimtarget && !settime) {
			timeaquiredtarget = aimbotglobs.Globals->flAbsCurTime;
			settime = true;
		}
		else {
			if (!aimtarget) {
				timeaquiredtarget = 0.0f;
				settime = false;
			}
		}

		if (cfg::legitbot_aimdelayinms != 0 && aimtarget) {
			float delay = (float)(cfg::legitbot_aimdelayinms / 1000.0f);
			if (!(aimbotglobs.Globals->flAbsCurTime > timeaquiredtarget + delay)) {
				return;
			}
		}




		if (cfg::legitbot_bLegitBot && aimtarget) {
				LegitAimAt(aimtarget, legitbot_hitboxes[closestbone]);
				return;
		}

		return;

	}






	return;

}