
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

uint64_t CurrentPlayerTarget = 0;

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

uint64_t Aimbot::GetAimbotTarget(std::string TargetEntityType) {


	float ClosestDistance = 99999999999.0;
	int ClosestIndex = 999;
	int LowestHealth = 99999999999;
	int LowestHealthIndex = 999;
	float LowestFov = 99999999999.0;
	int lowestfovindex = 999;

	// Sort Entities
	for (int i = 0; i < GlobalVars.entlist.active->size(); i++) {

		if (GlobalVars.entlist.active->empty() || (!(*GlobalVars.entlist.active)[i]))
			continue;

		std::string entClass = Helper::get_schema_name((*GlobalVars.entlist.active)[i]);

		if (TargetEntityType == "CCitadelPlayerController" && entClass == "CCitadelPlayerController") {
			PlayerData* TargetPlayerData = new PlayerData;
			Helper::get_player_data((*GlobalVars.entlist.active)[i], TargetPlayerData);


			if (!TargetPlayerData->isalive) {
				delete TargetPlayerData;
				continue;
			}
			if (TargetPlayerData->TeamNum == LocalPlayerData.TeamNum) {
				delete TargetPlayerData;
				continue;
			}

			if(!Config.aimbot.magicbullet || !Helper::KeyBindHandler(Config.aimbot.magicbulletkey.key)){ // if magic bullet then obviously dont do vischeck 
				if (IsPlayerVisible((*GlobalVars.entlist.active)[i]) == false) {
					delete TargetPlayerData;
					continue;
				}
			}




			vec3 TargetPos = { 0, 0, 0 };
			TargetPos = Helper::GetBonePosition((*GlobalVars.entlist.active)[i], "head");

			if (TargetPos.x == 0 && TargetPos.y == 0 && TargetPos.z == 0) {
				delete TargetPlayerData;
				continue;
			}

			// Closest
			// Calculate distance between targetpos and localplayer
			float distance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetPos);

			if (distance > Config.aimbot.MaxDistance) {
				delete TargetPlayerData;
				continue;
			}

			// Fov

			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(TargetPos);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float FOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (FOV > Config.aimbot.fov) {
				delete TargetPlayerData;
				continue; // Skip targets outside of the FOV
			}

			if (distance < ClosestDistance) {
				ClosestDistance = distance;
				ClosestIndex = i;
			}

			if (TargetPlayerData->Health < LowestHealth) {
				LowestHealth = TargetPlayerData->Health;
				LowestHealthIndex = i;
			}

			if (FOV < LowestFov) {
				LowestFov = FOV; // Update the lowest FOV
				lowestfovindex = i; // Update the index of the target with the lowest FOV
			}

			delete TargetPlayerData;



		}
		else if (entClass == "CItemXP" && TargetEntityType == "CItemXP") {

			xpData* TargetXPData = new xpData;
			Helper::get_xp_data((*GlobalVars.entlist.active)[i], TargetXPData);
			float GameTime = Helper::GetGameTime();
			float launchtime = TargetXPData->m_flLaunchtime;

			if (TargetXPData->m_bDormant)
				continue;
			if (GameTime < TargetXPData->m_flLaunchtime + 0.184)
				continue;

			if (IsXpVisible((*GlobalVars.entlist.active)[i]) == false)
				continue;

			float xpdistance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetXPData->m_vecOrigin);
			if (xpdistance > Config.aimbot.MaxDistance)
				continue;

			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(TargetXPData->m_vecOrigin);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float xpFOV = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (xpFOV > Config.aimbot.fov)
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
		else if (entClass == "C_NPC_Trooper" && TargetEntityType == "C_NPC_Trooper") {

			NpcData* TargetNpcData = new NpcData;
			Helper::get_npc_data((*GlobalVars.entlist.active)[i], TargetNpcData);


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

			if (IsNpcVisible((*GlobalVars.entlist.active)[i]) == false) {
				delete TargetNpcData;
				continue;	
			}

			float MinionDistance = Helper::GetDistance(LocalPlayerData.m_vecOrigin, TargetNpcData->m_vecOrigin);
			if (MinionDistance > Config.aimbot.MaxDistance) {
				delete TargetNpcData;
				continue;
			}

			if (MinionDistance > 2000.0f) {
				delete TargetNpcData;
				continue;
			}

			int boneindex = Helper::get_bone_index((*GlobalVars.entlist.active)[i], "head");
			if (!boneindex) {
				delete TargetNpcData;
				continue;
			}

			vec3 HeadPos = Helper::GetBoneVectorFromIndex((*GlobalVars.entlist.active)[i], boneindex);  // No re-declaration of TargetPos here
			vec2 LocalPlayerAngles = { ViewAngles->x, ViewAngles->y };
			vec2 AimAngles = GetAimAngles(HeadPos);
			vec2 angle_difference = AimAngles - LocalPlayerAngles;
			angle_difference = angle_difference.clamp();

			float minionfov = sqrt(angle_difference.x * angle_difference.x + angle_difference.y * angle_difference.y);

			if (minionfov > Config.aimbot.fov) {
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
	



	if (TargetEntityType == "CCitadelPlayerController") {
		switch (Config.aimbot.targetSelectionMode) {
		case 0:
			if (ClosestIndex == 999) {
				CurrentPlayerTarget = 0;
				return 0;
			}
			CurrentPlayerTarget = (*GlobalVars.entlist.active)[ClosestIndex];
			return (*GlobalVars.entlist.active)[ClosestIndex];
		case 1:
			if (LowestHealthIndex == 999) {
				CurrentPlayerTarget = 0;
				return 0;
			}
			CurrentPlayerTarget = (*GlobalVars.entlist.active)[LowestHealthIndex];
			return (*GlobalVars.entlist.active)[LowestHealthIndex];
		case 2:
			if (lowestfovindex == 999) {
				CurrentPlayerTarget = 0;
				return 0;
			}
			CurrentPlayerTarget = (*GlobalVars.entlist.active)[lowestfovindex];
			return (*GlobalVars.entlist.active)[lowestfovindex];
		}
	}

	if (TargetEntityType == "CItemXP") {
		switch (Config.aimbot.targetSelectionMode) {
		case 0:
			if (ClosestIndex == 999) {
				return 0;
			}
			return (*GlobalVars.entlist.active)[ClosestIndex];
		case 1:
			if (lowestfovindex == 999) {
				return 0;
			}
			return (*GlobalVars.entlist.active)[lowestfovindex];
		case 2:
			if (lowestfovindex == 999) {
				return 0;
			}
			return (*GlobalVars.entlist.active)[lowestfovindex];
		}
	}

	if (TargetEntityType == "C_NPC_Trooper") {
		switch (Config.aimbot.targetSelectionMode) {
		case 0:
			if (ClosestIndex == 999) {
				return 0;
			}
			return (*GlobalVars.entlist.active)[ClosestIndex];
		case 1:
			if (LowestHealthIndex == 999) {
				return 0;
			}
			return (*GlobalVars.entlist.active)[LowestHealthIndex];
		case 2:
			if (lowestfovindex == 999) {
				return 0;
			}
			return (*GlobalVars.entlist.active)[lowestfovindex];
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

void Aimbot::AimAbility(uintptr_t entity, int aimpos, uintptr_t ability, float projectilespeed) {

	if (!entity)
		return;
	if (!ability)
		return;

	PlayerData* targetdata = new PlayerData;
	Helper::get_player_data(entity, targetdata);


	vec3 vec_target;
	if (aimpos == 0) {
		vec_target = Helper::GetBonePosition(entity, "head");
	}
	else if (aimpos == 1) {
		vec_target = Helper::GetBonePosition(entity, "pelvis");
	}
	else {
		vec_target = targetdata->m_vecOrigin;
	}

	vec3 predictedposition = Aimbot::PredictPosition(vec_target, targetdata->m_vecVelocity, projectilespeed);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);
	CUserCmd->cameraViewAngle->viewAngles.x = target_angles.x;
	CUserCmd->cameraViewAngle->viewAngles.y = target_angles.y;

	delete targetdata;

}

void Aimbot::ShootMagicBullet(uint64_t entity, const char* bone) {

	float BulletSpeed = 30000.0f;
	vec3 vec_target = Helper::GetBonePosition(entity, bone);
	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	vec3 vec_velocity = *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);

	vec3 predictedposition = Aimbot::PredictPosition(vec_target, vec_velocity, BulletSpeed);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);

		vec3 AimFrom;

		vec3 localheadpos = Helper::GetBonePosition(Helper::get_local_player(), "head");


		if (ClosestVisiblePosToTarget(localheadpos, predictedposition, AimFrom)) {

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

void Aimbot::AimAt(uintptr_t entity, const char* bone) {

	float BulletSpeed = 30000.0f;
	vec3 vec_target = Helper::GetBonePosition(entity, bone);
	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	vec3 vec_velocity = *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);

	if (!Config.aimbot.magicbullet || !Helper::KeyBindHandler(Config.aimbot.magicbulletkey.key)) {
		if (Config.aimbot.AutoFire) {
			CUserCmd->buttons |= IN_ATTACK;
		}
	}



	vec3 predictedposition = Aimbot::PredictPosition(vec_target, vec_velocity, BulletSpeed);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);



	if (Config.aimbot.silentaim) { // silent aim

		if (!(CUserCmd->buttons & IN_ATTACK) && !(CUserCmd->buttons & IN_ZOOM)) {
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

	xpData* TargetXPData = new xpData;
	Helper::get_xp_data(entity, TargetXPData);
	vec2 target_angles = Aimbot::GetAimAngles(TargetXPData->m_vecOrigin);

	if (Config.aimbot.AutoFire) {
		CUserCmd->buttons |= IN_ATTACK;
	}

	if (Config.aimbot.silentaim) { // silent aim

		if (!(CUserCmd->buttons & IN_ATTACK) && !(CUserCmd->buttons & IN_ZOOM)) {
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

	delete TargetXPData;

}

void Aimbot::AimAtMinions(uintptr_t entity) {

	NpcData* targetnpcdata = new NpcData;
	Helper::get_npc_data(entity, targetnpcdata);

	if(targetnpcdata->m_bDormant)
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


		if (!(CUserCmd->buttons & IN_ATTACK) && !(CUserCmd->buttons & IN_ZOOM)) {
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

	delete targetnpcdata;

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
	GlobalVars.SortEnts();



	crosshairposition = (vec2*)(CameraManager + Offsets.o_crosshairposfromcameramanager);
	CameraManager = *(uint64_t*)(ClientModuleBase + Offsets.o_CameraManager + 0x28);
	ViewAngles = (vec2*)(CameraManager + 0x44); // RESET to 0x44
	LocalPlayerController = Helper::get_local_player();
	PlayerData* tempplrdata = new PlayerData;
	Helper::get_player_data(LocalPlayerController, tempplrdata);
	LocalPlayerData = *tempplrdata;	

	abilities = Helper::GetAbilities(Helper::GetPawn(Helper::get_local_player()));

	
	if (GlobalVars.entlist.active->empty()) {
		delete tempplrdata;
		return;
	}

	uint64_t aimtarget = Aimbot::GetAimbotTarget("CCitadelPlayerController");
	uint64_t xp_target = 0; // make sure unassigned is always zero 
	uint64_t minion_target = 0;

	if(Config.aimbot.AimXp)
		 xp_target = Aimbot::GetAimbotTarget("CItemXP");
	if(Config.aimbot.AimMinions)
	 minion_target = Aimbot::GetAimbotTarget("C_NPC_Trooper");


	if (Config.aimbot.magicbullet && Helper::KeyBindHandler(Config.aimbot.magicbulletkey.key) && aimtarget ) {
		ShootMagicBullet(aimtarget, "head");
		delete tempplrdata;
		return;
	}

	if (Helper::KeyBindHandler(Config.aimbot.AimKey.key)  && aimtarget ) {
		AimAt(aimtarget, "head");
		delete tempplrdata;
		return;
	}

	if (Helper::KeyBindHandler(Config.aimbot.AimKeyXp.key) && xp_target ) {
		AimAtXp(xp_target);
		delete tempplrdata;
		return;
	}

	if (Helper::KeyBindHandler(Config.aimbot.AimKeyMinions.key) && minion_target) {
		AimAtMinions(minion_target);
		delete tempplrdata;
		return;
	}


}