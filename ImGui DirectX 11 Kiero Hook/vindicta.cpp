#include "vindicta.h"

namespace vindicta {
	uint64_t target;
	PlayerData targetdata;
	uint64_t localplayer;
	PlayerData localplayerdata;
	std::vector<uintptr_t> abilitiesarray;
}

void VindictaLogic::AutoUlt() {


	if (vindicta::targetdata.Health <= 0 || vindicta::targetdata.MaxHealth <= 0)
		return;

	float targetpercent = (float)vindicta::targetdata.Health / (float)vindicta::targetdata.MaxHealth;
	if (targetpercent < 0.50f) {

		

		vec2 angles = Aimbot::GetAimAngles(Helper::GetBonePosition(vindicta::target, "head"));
		this->cmd->cameraViewAngle->viewAngles.x = angles.x;
		this->cmd->cameraViewAngle->viewAngles.y = angles.y;

		this->cmd->buttons |= IN_ABILITY4;
		this->cmd->buttons |= IN_ATTACK;
		if (Config.aimbot.bPSilent)
			Helper::CorrectViewAngles(this->cmd);


	}
}


void VindictaLogic::OnAbility1() {

	if (!Config.vindicta.AutoAimStake)
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

void VindictaLogic::OnAbility2() {

}

void VindictaLogic::OnAbility3() {

	if (!Config.vindicta.AutoAimCrow)
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

void VindictaLogic::OnAbility4() {

}

void VindictaLogic::OnTick() {


	vindicta::target = Aimbot::GetAimbotTarget("CCitadelPlayerController");
	if (!vindicta::target) return;
	vindicta::targetdata = Helper::get_player_data(vindicta::target);
	vindicta::localplayer = Helper::get_local_player();
	vindicta::localplayerdata = Helper::get_player_data(vindicta::localplayer);
	vindicta::abilitiesarray = Helper::GetAbilities(Helper::GetPawn(vindicta::localplayer));

	if (Config.vindicta.AutoSnipe) {
		AutoUlt();
	}

}