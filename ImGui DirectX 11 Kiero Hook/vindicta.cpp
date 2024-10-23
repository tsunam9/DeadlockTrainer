#include "vindicta.h"

namespace vindicta {
	uint64_t target;
	PlayerData targetdata;
}

static bool CommandQuedNextTick = false;
static bool justshot = true;

void VindictaLogic::AutoUlt() {

	if (Config.aimbot.magicbullet && Helper::KeyBindHandler(Config.aimbot.magicbulletkey.key))
		return;

	float scopetime = *(float*)(this->abilitiesarray[4] + CCitadel_Ability_Hornet_Snipe::m_flScopeStartTime);
	if (scopetime) {
		this->cmd->buttons |= (1 << 11);
		this->cmd->buttons &= ~(1 << 0);
	}

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

		if (!CommandQuedNextTick) {
			this->cmd->buttons &= ~IN_ATTACK;
			this->cmd->buttons &= ~IN_ZOOM;
			CommandQuedNextTick = true;
		}
		else {
			this->cmd->buttons |= IN_ATTACK;
			this->cmd->buttons |= IN_ABILITY4;
			this->cmd->buttons &= ~IN_ZOOM;
			CommandQuedNextTick = false;
			justshot = true;
		}
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
	Aimbot::AimAbility(target, 2, this->abilitiesarray[1],1000.0f);

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
	Aimbot::AimAbility(target, 1, this->abilitiesarray[3],2500.0f);

}

void VindictaLogic::OnAbility4() {

	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void VindictaLogic::OnTick() {

	vindicta::target = Aimbot::GetAimbotTarget("CCitadelPlayerController");
	if (!vindicta::target) return;
	vindicta::targetdata = Helper::get_player_data(vindicta::target);

	if (this->InputCasting1 || *(bool*)(VindictaLogic::abilitiesarray[1] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility1();
	}
	if (this->InputCasting2 || *(bool*)(VindictaLogic::abilitiesarray[2] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility2();
	}
	if (this->InputCasting3 || *(bool*)(VindictaLogic::abilitiesarray[3] + C_CitadelBaseAbility::m_bInCastDelay)){
		OnAbility3();
	}
	if (this->InputCasting4 || *(bool*)(VindictaLogic::abilitiesarray[4] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility4();
	}

	if (Config.vindicta.AutoSnipe) {
		AutoUlt();
	}

}