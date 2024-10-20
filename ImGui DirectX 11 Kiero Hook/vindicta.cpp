#include "vindicta.h"

namespace vindicta {
	uint64_t target;
	PlayerData targetdata;
}

void VindictaLogic::AutoUlt() {

	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	int remainingcharges = *(int*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_iRemainingCharges);
	if (remainingcharges <= 0)
		return;

	bool rechargetime = *(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal);
	if (rechargetime)
		return;
	
	if (vindicta::targetdata.Health <= 0 || vindicta::targetdata.MaxHealth <= 0)
		return;

	float targetpercent = (float)vindicta::targetdata.Health / (float)vindicta::targetdata.MaxHealth;
	if (targetpercent < 0.50f) {

		

		vec2 angles = Aimbot::GetAimAngles(Helper::GetBonePosition(vindicta::target, "head"));
		this->cmd->cameraViewAngle->viewAngles.x = angles.x;
		this->cmd->cameraViewAngle->viewAngles.y = angles.y;

		this->cmd->buttons |= IN_ABILITY4;
		this->cmd->buttons |= IN_ATTACK;
		Helper::CorrectMovement(this->cmd, this->cmd->pBaseUserCMD->forwardMove, this->cmd->pBaseUserCMD->sideMove);
		if (Config.aimbot.bPSilent)
			Helper::CorrectViewAngles(this->cmd);


	}
}


void VindictaLogic::OnAbility1() {

	if (*(bool*)(this->abilitiesarray[1] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!Config.vindicta.AutoAimStake)
		return;

	uint64_t target = Aimbot::GetAimbotTarget("CCitadelPlayerController");
	if (!target)
		return;
	Aimbot::AimAbility(target, 2, this->abilitiesarray[1]);

}

void VindictaLogic::OnAbility2() {

	if (*(bool*)(this->abilitiesarray[2] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;


}

void VindictaLogic::OnAbility3() {

	if (*(bool*)(this->abilitiesarray[3] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!Config.vindicta.AutoAimCrow)
		return;

	uint64_t target = Aimbot::GetAimbotTarget("CCitadelPlayerController");
	if (!target)
		return;
	Aimbot::AimAbility(target, 1, this->abilitiesarray[3]);

}

void VindictaLogic::OnAbility4() {

	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void VindictaLogic::OnTick() {

	if (cmd->buttons & IN_ABILITY4) {
		cmd->buttons &= ~IN_ATTACK;
	}

	float scopetime = *(float*)(this->abilitiesarray[4] + CCitadel_Ability_Hornet_Snipe::m_flScopeStartTime);
	if (scopetime) {
		this->cmd->buttons |= (1 << 11);
		this->cmd->buttons &= ~(1 << 0);
	}

	vindicta::target = Aimbot::GetAimbotTarget("CCitadelPlayerController");
	if (!vindicta::target) return;
	vindicta::targetdata = Helper::get_player_data(vindicta::target);

	if (Config.vindicta.AutoSnipe) {
		AutoUlt();
	}

}