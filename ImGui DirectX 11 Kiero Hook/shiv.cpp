#include "shiv.h"


namespace shiv {
	uint64_t target;
	PlayerData targetdata;
	uint64_t localplayer;
	PlayerData localplayerdata;
	std::vector<uintptr_t> abilitiesarray;
}
void ShivLogic::AutoUlt() {

	int rlevel = *(int*)(shiv::abilitiesarray[4] + C_CitadelBaseAbility::m_nUpgradeBits);
	float UltimateExecutehealth = 0.2f;
	if (rlevel >= 7)
		UltimateExecutehealth = 0.28f;
	if (shiv::targetdata.Health <= 0 || shiv::targetdata.MaxHealth <= 0)
		return;

	float targetpercent = (float)shiv::targetdata.Health / (float)shiv::targetdata.MaxHealth;
	if (targetpercent < UltimateExecutehealth) {
		vec2 angles = Aimbot::GetAimAngles(shiv::targetdata.m_vecOrigin);
		this->cmd->cameraViewAngle->viewAngles.x = angles.x;
		this->cmd->cameraViewAngle->viewAngles.y = angles.y;
		Helper::CorrectMovement(this->cmd, this->cmd->pBaseUserCMD->forwardMove, this->cmd->pBaseUserCMD->sideMove);
		if (Config.aimbot.bPSilent)
			Helper::CorrectViewAngles(this->cmd);
		this->cmd->buttons |= IN_ABILITY4;
	}
}

void ShivLogic::OnAbility1() {

	if (!Config.shiv.AutoAimDagger)
		return;

	uint64_t target = Aimbot::GetAimbotTarget("CCitadelPlayerController");
	if (!target)
		return;
	vec3 vec_target = Helper::GetBonePosition(target, "head");
	uint64_t PawnHandle = *(uint64_t*)(target + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	vec3 vec_velocity = *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);
	vec3 predictedposition = Aimbot::PredictPosition(vec_target, vec_velocity, 15000.0f);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);

	this->cmd->cameraViewAngle->viewAngles.x = target_angles.x;
	this->cmd->cameraViewAngle->viewAngles.y = target_angles.y;
	Helper::CorrectMovement(this->cmd, this->cmd->pBaseUserCMD->forwardMove, this->cmd->pBaseUserCMD->sideMove);
	if (Config.aimbot.bPSilent)
		Helper::CorrectViewAngles(this->cmd);
}

void ShivLogic::OnAbility2() {

	if (!Config.shiv.AutoAimDash)
		return;

	uint64_t target = Aimbot::GetAimbotTarget("CCitadelPlayerController");
	if (!target)
		return;
	vec3 vec_target = Helper::GetBonePosition(target, "head");
	uint64_t PawnHandle = *(uint64_t*)(target + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	vec3 vec_velocity = *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);
	vec3 predictedposition = Aimbot::PredictPosition(vec_target, vec_velocity, 15000.0f);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);

	this->cmd->cameraViewAngle->viewAngles.x = target_angles.x;
	this->cmd->cameraViewAngle->viewAngles.y = target_angles.y;
	Helper::CorrectMovement(this->cmd, this->cmd->pBaseUserCMD->forwardMove, this->cmd->pBaseUserCMD->sideMove);
}

void ShivLogic::OnAbility3(){

}

void ShivLogic::OnAbility4() {

}

void ShivLogic::OnTick() {


	 shiv::target = Aimbot::GetAimbotTarget("CCitadelPlayerController");
	 if (!shiv::target) return;
	 shiv::targetdata = Helper::get_player_data(shiv::target);
	 shiv::localplayer = Helper::get_local_player();
	 shiv::localplayerdata = Helper::get_player_data(shiv::localplayer);
	 shiv::abilitiesarray = Helper::GetAbilities(Helper::GetPawn(shiv::localplayer));

	 if (Config.shiv.AutoExecute) {
		 AutoUlt();
	 }
	

}