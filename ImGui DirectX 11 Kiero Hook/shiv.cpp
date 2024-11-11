#include "shiv.h"



void ShivLogic::AutoUlt() {

	if (*(bool*)(this->abilitiesarray[5] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	int rlevel = *(int*)(this->abilitiesarray[5] + C_CitadelBaseAbility::m_nUpgradeBits);
	float UltimateExecutehealth = 0.2f;
	if (rlevel >= 7)
		UltimateExecutehealth = 0.28f;
	if (targetdata->Health <= 0)
		return;

	float targetpercent = (float)targetdata->Health / (float)targetdata->MaxHealth;
	if (targetpercent < UltimateExecutehealth) {
		vec2 angles = Aimbot::GetAimAngles(targetdata->m_vecOrigin);
		this->cmd->cameraViewAngle->viewAngles.x = angles.x;
		this->cmd->cameraViewAngle->viewAngles.y = angles.y;
		this->cmd->buttons |= IN_ABILITY4;
	}
}

void ShivLogic::OnAbility1() {

	if (*(bool*)(this->abilitiesarray[2] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!Config.shiv.AutoAimDagger)
		return;

	Aimbot::AimAbility(target, 1, this->abilitiesarray[2],5000.0f, true);
}

void ShivLogic::OnAbility2() {

	if (*(bool*)(this->abilitiesarray[3] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!Config.shiv.AutoAimDash)
		return;

	vec3 vec_target = Helper::GetBonePosition(target, "head");
	uint64_t PawnHandle = *(uint64_t*)(target + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	vec3 vec_velocity = *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);
	vec3 predictedposition = Aimbot::PredictPosition(vec_target, vec_velocity, 15000.0f);
	vec2 target_angles = Aimbot::GetAimAngles(predictedposition);

	this->cmd->pBaseUserCMD->playerViewAngle->viewAngles.x = target_angles.x;
	this->cmd->pBaseUserCMD->playerViewAngle->viewAngles.y = target_angles.y;
	this->cmd->cameraViewAngle->viewAngles.x = target_angles.x;
	this->cmd->cameraViewAngle->viewAngles.y = target_angles.y;
}

void ShivLogic::OnAbility3(){

}

void ShivLogic::OnAbility4() {

}

void ShivLogic::OnTick() {


	 this->target = Aimbot::GetCurrentAimbotTarget();
	 if (!this->target)
		 return;

	 Helper::get_player_data(this->target, this->targetdata);


	 vec3 old_viewangles = cmd->pBaseUserCMD->playerViewAngle->viewAngles;
	 float old_forwardmove = cmd->pBaseUserCMD->forwardMove;
	 float old_sidemove = cmd->pBaseUserCMD->sideMove;

	 if (this->InputCasting1 || *(bool*)(ShivLogic::abilitiesarray[1] + C_CitadelBaseAbility::m_bInCastDelay)) {
		 OnAbility1();
	 }
	 if (this->InputCasting2 || *(bool*)(ShivLogic::abilitiesarray[2] + C_CitadelBaseAbility::m_bInCastDelay)) {
		 OnAbility2();
	 }
	 if (this->InputCasting3 || *(bool*)(ShivLogic::abilitiesarray[3] + C_CitadelBaseAbility::m_bInCastDelay)) {
		 OnAbility3();
	 }
	 if (this->InputCasting4 || *(bool*)(ShivLogic::abilitiesarray[4] + C_CitadelBaseAbility::m_bInCastDelay)) {
		 OnAbility4();
	 }

	 if (Config.shiv.AutoExecute) {
		 AutoUlt();
	 }

	 if (Config.aimbot.MovementFix) {
		 auto camera = Helper::get_Camera();
		 vec3 OldAngles = *(vec3*)(camera + 0x44);
		 Helper::CorrectMovement(cmd, cmd->pBaseUserCMD->forwardMove, cmd->pBaseUserCMD->sideMove, OldAngles);
	 }

	

}