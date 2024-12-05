#include "vindicta.h"


static bool CommandQuedNextTick = false;
static bool justshot = false;
static bool checking = false;

void VindictaLogic::AutoUlt() {

	float scopetime = *(float*)(this->abilitiesarray[4] + CCitadel_Ability_Hornet_Snipe::m_flScopeStartTime);
	float gametime = globals::instance().Globals->flAbsCurTime;

	if (justshot) {
		if (scopetime) {
			checking = true;
			cmd->buttons &= ~IN_ATTACK;
			cmd->buttons |= IN_ZOOM;
			CommandQuedNextTick = false;
		}
		if (checking) {
			if (!scopetime) {
				justshot = false;
				checking = false;
			}
		}
	}


	//Helper::KeyBindHandler(Config.aimbot.magicbulletkey);
	if (cfg::ragebot_magicbullet)
		return;


	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	int remainingcharges = *(int*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_iRemainingCharges);
	if (remainingcharges <= 0)
		return;

	bool rechargetime = *(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal);
	if (rechargetime)
		return;
	
	if (this->targetdata->Health <= 0 || this->targetdata->MaxHealth <= 0)
		return;


	float targetpercent = (float)this->targetdata->Health / (float)this->targetdata->MaxHealth;
	if (targetpercent < cfg::vindicta_AutoUltHealthPercent) {

		

		vec2 angles = Aimbot::GetAimAngles(Helper::GetBonePosition(this->target, "head"));
		this->cmd->cameraViewAngle->viewAngles.x = angles.x;
		this->cmd->cameraViewAngle->viewAngles.y = angles.y;

		if (!CommandQuedNextTick) {
			this->cmd->buttons &= ~IN_ATTACK;
			this->cmd->buttons &= ~IN_ZOOM;
			CommandQuedNextTick = true;
			return;
		}
		else {
			this->cmd->buttons |= IN_ATTACK;
			this->cmd->buttons |= IN_ABILITY4;
			CommandQuedNextTick = false;
			justshot = true;
			return;
		}
	}
}


void VindictaLogic::OnAbility1() {

	if (*(bool*)(this->abilitiesarray[1] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!cfg::vindicta_AutoAimStake)
		return;

	uint64_t target = Aimbot::GetCurrentAimbotTarget();
	if (!target)
		return;
	Aimbot::AimAbility(target, 2, this->abilitiesarray[1],1000.0f,true);

}

void VindictaLogic::OnAbility2() {

	if (*(bool*)(this->abilitiesarray[2] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;


}

void VindictaLogic::OnAbility3() {

	if (*(bool*)(this->abilitiesarray[3] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!cfg::vindicta_AutoAimCrow)
		return;

	uint64_t target = Aimbot::GetCurrentAimbotTarget();
	if (!target)
		return;
	Aimbot::AimAbility(target, 1, this->abilitiesarray[3],3500.f,true);

}

void VindictaLogic::OnAbility4() {

	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void VindictaLogic::OnTick() {

	this->target = Aimbot::GetCurrentAimbotTarget();
	if (!(this->target)) return;


	Helper::get_player_data(this->target, this->targetdata);


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

	static bool checking = false;

	if (cfg::vindicta_AutoSnipe) {
		AutoUlt();
	}

}