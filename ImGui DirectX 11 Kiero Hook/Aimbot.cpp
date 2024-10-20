
#pragma once
#include "Aimbot.h"
#include "math.h"

#define M_PI 3.14159265358979323846


std::vector<uint64_t> processed_ents;

//get PlayerData
PlayerData LocalPlayerData;
uint64_t CameraManager;
vec2* ViewAngles;
vec2* crosshairposition;
Helper AimbotHelperObj;
Drawing aimbotdraw;
std::vector<uintptr_t> abilities;
CCitadelUserCmdPB* CUserCmd;


bool IsPlayerVisible(uint64_t entity) {

	vec3 EnemyHead = Helper::GetBonePosition(entity, "head");
	vec3 LocalCameraPos = *(vec3*)(CameraManager + 0x38);
	vec3 LocalPlayerHead = Helper::GetBonePosition(Helper::get_local_player(), "head");

	bool firstvar = Helper::CheckLocationVisible(LocalPlayerHead, EnemyHead);
	bool secondvar = Helper::CheckLocationVisible(LocalCameraPos, EnemyHead);
	return firstvar && secondvar;
	

}

bool IsXpVisible(uint64_t entity) {

	xpData TargetXPData = Helper::get_xp_data(entity);
	vec3 LocalCameraPos = *(vec3*)(CameraManager + 0x38);
	vec3 LocalPlayerHead = Helper::GetBonePosition(Helper::get_local_player(), "head");
	return Helper::CheckLocationVisible(LocalCameraPos, TargetXPData.m_vecOrigin) && Helper::CheckLocationVisible(LocalPlayerHead, TargetXPData.m_vecOrigin);

}

bool IsNpcVisible(uint64_t entity) {

	NpcData TargetNpcData = Helper::get_npc_data(entity);
	vec3 LocalCameraPos = *(vec3*)(CameraManager + 0x38);
	vec3 LocalPlayerHead = Helper::GetBonePosition(Helper::get_local_player(), "head");
	return Helper::CheckLocationVisible(LocalCameraPos, TargetNpcData.m_vecOrigin) && Helper::CheckLocationVisible(LocalPlayerHead, TargetNpcData.m_vecOrigin);

}

bool FindPointNearLocationVisibleToUs(vec3 location, vec3& outputspot) {



	vec3 LocalCameraPos = *(vec3*)(CameraManager + 0x38);

	vec3 check1 = { LocalCameraPos.x + 250.0f ,LocalCameraPos.y ,LocalCameraPos.z };
	vec3 check2 = { LocalCameraPos.x - 250.0f ,LocalCameraPos.y ,LocalCameraPos.z };
	vec3 check3 = { LocalCameraPos.x ,LocalCameraPos.y ,LocalCameraPos.z + 250.0f };
	vec3 check4 = { LocalCameraPos.x ,LocalCameraPos.y + 250.0f ,LocalCameraPos.z };
	vec3 check5 = { LocalCameraPos.x ,LocalCameraPos.y - 250.0f ,LocalCameraPos.z };

	if (Helper::CheckLocationVisible(LocalCameraPos, check1)) {
		if (Helper::CheckLocationVisible(LocalCameraPos, location)) {
			outputspot = check1;
			return true;
		}
	}
	if (Helper::CheckLocationVisible(LocalCameraPos, check2)) {
		if (Helper::CheckLocationVisible(LocalCameraPos, location)) {
			outputspot = check2;
			return true;
		}
	}
	if (Helper::CheckLocationVisible(LocalCameraPos, check3)) {
		if (Helper::CheckLocationVisible(LocalCameraPos, location)) {
			outputspot = check3;
			return true;
		}
	}
	if (Helper::CheckLocationVisible(LocalCameraPos, check4)) {
		if (Helper::CheckLocationVisible(LocalCameraPos, location)) {
			outputspot = check4;
			return true;
		}
	}
	if (Helper::CheckLocationVisible(LocalCameraPos, check5)) {
		if (Helper::CheckLocationVisible(LocalCameraPos, location)) {
			outputspot = check5;
			return true;
		}
	}
	return false;

}




inline void sort_entities()
{
	int max_ents = Helper::get_max_entities();

	for (size_t i = 1; i <= static_cast<size_t>(max_ents); ++i)
	{
		uint64_t entity = Helper::get_base_entity_from_index(i);

		if (!entity)
			continue;

		std::string EntName = Helper::get_schema_name(entity);

		if (EntName == "CCitadelPlayerController" && !*(bool*)(entity + CBasePlayerController::m_bIsLocalPlayerController))
			processed_ents.push_back(entity);
		if (EntName == "CItemXP" && Config.aimbot.AimXp)
			processed_ents.push_back(entity);
		if (EntName == "C_NPC_Trooper" && Config.aimbot.AimMinions)
			processed_ents.push_back(entity);

		
	}	
}

uint64_t Aimbot::GetAimbotTarget(std::string TargetEntityType) {


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

	int ClosestminionDistance = 99999999999.0;
	int ClosestminionIndex = 999;
	int LowestMinionHealth = 99999999999;
	int LowestMinionHealthIndex = 999;
	int LowestFovminion = 99999999999.0;
	int LowestFovminionIndex = 999;

	// Sort Entities
	for (int i = 0; i < processed_ents.size(); i++) {

		if (processed_ents.empty() || !processed_ents[i])
			continue;

		std::string entClass = Helper::get_schema_name(processed_ents[i]);

		if (entClass == "CCitadelPlayerController" && TargetEntityType == "CCitadelPlayerController") {
			PlayerData TargetPlayerData = Helper::get_player_data(processed_ents[i]);

			if (!TargetPlayerData.isalive)
				continue;
			if (TargetPlayerData.TeamNum == LocalPlayerData.TeamNum)
				continue;
			if (Config.aimbot.VisibleCheck && IsPlayerVisible(processed_ents[i]) == false)
				continue;

			vec3 TargetPos = { 0, 0, 0 };
			TargetPos = Helper::GetBonePosition(processed_ents[i], "head");

			if (TargetPos.x == 0 && TargetPos.y == 0 && TargetPos.z == 0)
				continue; // Skip invalid targets (no position data)

			// Closest
			// Calculate distance between targetpos and localplayer
			float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetPos);

			if (distance > Config.aimbot.MaxDistance)
				continue;

			// Fov

			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(TargetPos);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float FOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (FOV > Config.aimbot.fov)
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
		else if (entClass == "CItemXP" && TargetEntityType == "CItemXP") {

			xpData TargetXPData = Helper::get_xp_data(processed_ents[i]);
			float GameTime = Helper::GetGameTime();

			if (TargetXPData.m_bDormant)
				continue;
			if (GameTime < TargetXPData.m_flLaunchtime + 0.21f)
				continue;


			if (Config.aimbot.VisibleCheck && IsXpVisible(processed_ents[i]) == false)
				continue;

			float xpdistance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetXPData.m_vecOrigin);
			if (xpdistance > Config.aimbot.MaxDistance)
				continue;

			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(TargetXPData.m_vecOrigin);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float xpFOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (xpFOV > Config.aimbot.fov)
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
		else if (entClass == "C_NPC_Trooper" && TargetEntityType == "C_NPC_Trooper") {

			NpcData TargetNpcData = Helper::get_npc_data(processed_ents[i]);

			if (TargetNpcData.m_bDormant)
				continue;

			uint64_t entteamnum = 263169 + LocalPlayerData.TeamNum;
			if (TargetNpcData.m_iteamnum != entteamnum) // really awful terribleness because the number just happens to be this for minion teams
				continue;

			if (TargetNpcData.m_ilifestate != 0)
				continue;

			if (Config.aimbot.VisibleCheck && IsNpcVisible(processed_ents[i]) == false)
				continue;

			float MinionDistance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetNpcData.m_vecOrigin);
			if (MinionDistance > Config.aimbot.MaxDistance)
				continue;

			if (MinionDistance > 2000.0f)
				continue;

			int boneindex = Helper::get_bone_index(processed_ents[i], "head");
			if (!boneindex)
				continue;
			vec3 HeadPos = Helper::GetBoneVectorFromIndex(processed_ents[i], boneindex);  // No re-declaration of TargetPos here
			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(HeadPos);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float minionfov = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (minionfov > Config.aimbot.fov)
				continue; // Skip targets outside of the FOV

			if (MinionDistance < ClosestminionDistance) {
				ClosestminionDistance = MinionDistance;
				ClosestminionIndex = i;
			}

			if (minionfov < LowestFovminion) {
				LowestFovminion = minionfov; // Update the lowest FOV
				LowestFovminionIndex = i; // Update the index of the target with the lowest FOV
			}

		}
	}
	



	if (TargetEntityType == "CCitadelPlayerController") {
		switch (Config.aimbot.targetSelectionMode) {
		case 0:
			if (ClosestIndex == 999) {
				return 0;
			}
			return processed_ents[ClosestIndex];
		case 1:
			return processed_ents[LowestHealthIndex];
			if (LowestHealthIndex == 999) {
				return 0;
			}
		case 2:
			if (lowestfovindex == 999) {
				return 0;
			}
			return processed_ents[lowestfovindex];
		}
	}

	if (TargetEntityType == "CItemXP") {
		switch (Config.aimbot.targetSelectionMode) {
		case 0:
			if (ClosestXPIndex == 999) {
				return 0;
			}
			return processed_ents[ClosestXPIndex];
		case 1:
			if (LowestFovXPIndex == 999) {
				return 0;
			}
			return processed_ents[LowestFovXPIndex];
		case 2:
			if (LowestFovXPIndex == 999) {
				return 0;
			}
			return processed_ents[LowestFovXPIndex];
		}
	}

	if (TargetEntityType == "C_NPC_Trooper") {
		switch (Config.aimbot.targetSelectionMode) {
		case 0:
			if (ClosestminionIndex == 999) {
				return 0;
			}
			return processed_ents[ClosestminionIndex];
		case 1:
			if (LowestMinionHealthIndex == 999) {
				return 0;
			}
			return processed_ents[LowestMinionHealthIndex];
		case 2:
			if (LowestMinionHealthIndex == 999) {
				return 0;
			}
			return processed_ents[LowestFovminionIndex];
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

void Aimbot::AimAbility(uintptr_t entity, int aimpos, uintptr_t ability) {

	if (!entity)
		return;
	if (!ability)
		return;

	auto targetdata = Helper::get_player_data(entity);

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

	vec3 predictedposition = Aimbot::PredictPosition(vec_target, targetdata.m_vecVelocity, 15000.0f);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);
	CUserCmd->cameraViewAngle->viewAngles.x = target_angles.x;
	CUserCmd->cameraViewAngle->viewAngles.y = target_angles.y;
	Helper::CorrectMovement(CUserCmd, CUserCmd->pBaseUserCMD->forwardMove, CUserCmd->pBaseUserCMD->sideMove);
	if (Config.aimbot.bPSilent)
		Helper::CorrectViewAngles(CUserCmd);

}

void Aimbot::AimAt(uintptr_t entity, const char* bone) {

	float BulletSpeed = 30000.0f;
	vec3 vec_target = Helper::GetBonePosition(entity, bone);
	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	vec3 vec_velocity = *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);

	if (Config.aimbot.AutoFire) {
		CUserCmd->buttons |= IN_ATTACK;
	}


	vec3 predictedposition = Aimbot::PredictPosition(vec_target, vec_velocity, BulletSpeed);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);



	if (false) {
		vec3 AimFrom;
		if (FindPointNearLocationVisibleToUs(predictedposition, AimFrom));
		
		vec2 screenaimfrom;
		if (Helper::WorldToScreen(AimFrom, screenaimfrom)) {
			aimbotdraw.DrawBox(100, 100, 100, 100, IM_COL32(255, 0, 0, 255));
		}




			CUserCmd->origin->m_vecOrigin.x = AimFrom.x;
			CUserCmd->origin->m_vecOrigin.y = AimFrom.y;
			CUserCmd->origin->m_vecOrigin.z = AimFrom.z;


			vec2 aimgles = GetAim(AimFrom, predictedposition);

			CUserCmd->cameraViewAngle->viewAngles.x = aimgles.x;
			CUserCmd->cameraViewAngle->viewAngles.y = aimgles.y;
			Helper::CorrectMovement(CUserCmd, CUserCmd->pBaseUserCMD->forwardMove, CUserCmd->pBaseUserCMD->sideMove);



	}
		//magic bullet

	if (Config.aimbot.silentaim) { // silent aim


		if (!(CUserCmd->buttons & IN_ATTACK)) {
			return;
		}

		uintptr_t localweapon = Helper::get_localplr_weapon();
		if (localweapon == -1)
			return;
		float NextAttack = *(float*)(localweapon + CCitadel_Ability_PrimaryWeapon::m_flNextPrimaryAttack);
		float LocalPlayerSimTime = *(float*)(Helper::get_local_player() + C_BaseEntity::m_flSimulationTime);
		NextAttack -= 0.017;



		if (NextAttack > LocalPlayerSimTime)
			return;



		CUserCmd->cameraViewAngle->viewAngles.x = target_angles.x;
		CUserCmd->cameraViewAngle->viewAngles.y = target_angles.y;
		crosshairposition->x = target_angles.x;
		crosshairposition->y = target_angles.y;
		Helper::CorrectMovement(CUserCmd, CUserCmd->pBaseUserCMD->forwardMove, CUserCmd->pBaseUserCMD->sideMove);
		return;

	}
	// Smoothly interpolate between current angles and target angles
	if (Config.aimbot.smooth < 1)
	{
		ViewAngles->x = target_angles.x;
		ViewAngles->y = target_angles.y;
		return;
	}


	// Calculate the difference between current angles and target angles

	float delta_x = target_angles.x - ViewAngles->x;
	float delta_y = target_angles.y - ViewAngles->y;
	vec2 delta = { delta_x, delta_y };

	vec2 final_delta = delta.clamp();

	ViewAngles->x += final_delta.x / Config.aimbot.smooth;
	ViewAngles->y += final_delta.y / Config.aimbot.smooth;
}

void Aimbot::AimAtXp(uintptr_t entity) {

	xpData TargetXPData = Helper::get_xp_data(entity);
	vec2 target_angles = Aimbot::GetAimAngles(TargetXPData.m_vecOrigin);

	if (Config.aimbot.AutoFire) {
		CUserCmd->buttons |= IN_ATTACK;
	}

	if (Config.aimbot.silentaim) { // silent aim


		if (!CUserCmd->buttons & IN_ATTACK) {
			return;
		}
		uintptr_t localweapon = Helper::get_localplr_weapon();
		float NextAttack = *(float*)(localweapon + CCitadel_Ability_PrimaryWeapon::m_flNextPrimaryAttack);
		float LocalPlayerSimTime = *(float*)(Helper::get_local_player() + C_BaseEntity::m_flSimulationTime);
		NextAttack -= 0.017;
		if (NextAttack > LocalPlayerSimTime)
			return;
		CUserCmd->cameraViewAngle->viewAngles.x = target_angles.x;
		CUserCmd->cameraViewAngle->viewAngles.y = target_angles.y;
		crosshairposition->x = target_angles.x;
		crosshairposition->y = target_angles.y;
		Helper::CorrectMovement(CUserCmd, CUserCmd->pBaseUserCMD->forwardMove, CUserCmd->pBaseUserCMD->sideMove);
		return;
	}

	if (Config.aimbot.smooth < 1)
	{
		ViewAngles->x = target_angles.x;
		ViewAngles->y = target_angles.y;
		return;
	}

	float delta_x = target_angles.x - ViewAngles->x;
	float delta_y = target_angles.y - ViewAngles->y;
	vec2 delta = { delta_x, delta_y };
	vec2 final_delta = delta.clamp();

	ViewAngles->x += final_delta.x / Config.aimbot.smooth;
	ViewAngles->y += final_delta.y / Config.aimbot.smooth;

}

void Aimbot::AimAtMinions(uintptr_t entity) {

	NpcData targetnpcdata = Helper::get_npc_data(entity);

	if(targetnpcdata.m_bDormant)
		return;

	int boneindex = Helper::get_bone_index(entity, "head");
	if (!boneindex)
		return;
	vec3 HeadPos = Helper::GetBoneVectorFromIndex(entity, boneindex);  // No re-declaration of TargetPos here
	vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };

	vec2 target_angles = Aimbot::GetAimAngles(HeadPos);

	if (Config.aimbot.AutoFire) {
		CUserCmd->buttons |= IN_ATTACK;
	}

	if (Config.aimbot.silentaim) { // silent aim


		if (!CUserCmd->buttons & IN_ATTACK) {
			return;
		}
		uintptr_t localweapon = Helper::get_localplr_weapon();
		float NextAttack = *(float*)(localweapon + CCitadel_Ability_PrimaryWeapon::m_flNextPrimaryAttack);
		float LocalPlayerSimTime = *(float*)(Helper::get_local_player() + C_BaseEntity::m_flSimulationTime);
		NextAttack -= 0.017;
		if (NextAttack > LocalPlayerSimTime)
			return;
		CUserCmd->cameraViewAngle->viewAngles.x = target_angles.x;
		CUserCmd->cameraViewAngle->viewAngles.y = target_angles.y;
		crosshairposition->x = target_angles.x;
		crosshairposition->y = target_angles.y;
		Helper::CorrectMovement(CUserCmd, CUserCmd->pBaseUserCMD->forwardMove, CUserCmd->pBaseUserCMD->sideMove);
		return;
	}

	if (Config.aimbot.smooth < 1)
	{
		ViewAngles->x = target_angles.x;
		ViewAngles->y = target_angles.y;
		return;
	}

	float delta_x = target_angles.x - ViewAngles->x;
	float delta_y = target_angles.y - ViewAngles->y;
	vec2 delta = { delta_x, delta_y };
	vec2 final_delta = delta.clamp();

	ViewAngles->x += final_delta.x / Config.aimbot.smooth;
	ViewAngles->y += final_delta.y / Config.aimbot.smooth;

}



float GetAngleDifference(float angle1, float angle2) {
	float diff = fmod(angle1 - angle2 + 180.0f, 360.0f);
	if (diff < 0) {
		diff += 360.0f;
	}
	return diff - 180.0f; // Normalize to [-180, 180]
}



void Aimbot::RunAimbot(CCitadelUserCmdPB* usercmd) { // ran in CreateMove hook

	CUserCmd = usercmd;
	processed_ents.clear();
	sort_entities();

	crosshairposition = (vec2*)(CameraManager + Offsets.o_crosshairposfromcameramanager);
	CameraManager = *(uint64_t*)(ClientModuleBase + Offsets.o_CameraManager + 0x28);
	ViewAngles = (vec2*)(CameraManager + 0x44); // RESET to 0x44
	LocalPlayerData = Helper::get_player_data(Helper::get_local_player());
	abilities = Helper::GetAbilities(Helper::GetPawn(Helper::get_local_player()));

	
	if (processed_ents.empty())
		return;

	uint64_t aimtarget = Aimbot::GetAimbotTarget("CCitadelPlayerController");
	uint64_t xp_target = Aimbot::GetAimbotTarget("CItemXP");
	uint64_t minion_target = Aimbot::GetAimbotTarget("C_NPC_Trooper");


	if (Helper::KeyBindHandler(Config.aimbot.AimKey.key)  && aimtarget && !processed_ents.empty()) {
		AimAt(aimtarget, "head");
	}

	if (Helper::KeyBindHandler(Config.aimbot.AimKeyXp.key) && xp_target && !processed_ents.empty()) {
		AimAtXp(xp_target);
	}

	if (Helper::KeyBindHandler(Config.aimbot.AimKeyMinions.key) && minion_target && !processed_ents.empty()) {
		AimAtMinions(minion_target);
	}

}