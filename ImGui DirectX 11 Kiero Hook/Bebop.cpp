#include "Bebop.h"

void BebopLogic::AutoBomb() {

	if (*(bool*)(this->abilitiesarray[2] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	PlayerData localdata;
	Helper::get_player_data(Helper::get_local_player(), &localdata);

	float dist = Helper::GetDistance(localdata.m_vecOrigin, targetdata->m_vecOrigin);
	if (dist > 270.f)
		return;

	Aimbot::AimAbility(target, 1, this->abilitiesarray[3], 0, false);
	cmd->buttons |= IN_ABILITY2;


}

void BebopLogic::AutoUpperCut() {

	if (*(bool*)(this->abilitiesarray[1] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;


	PlayerData localdata;
	Helper::get_player_data(Helper::get_local_player(), &localdata);

	float dist = Helper::GetDistance(localdata.m_vecOrigin, targetdata->m_vecOrigin);
	if (dist > 240.f)
		return;

	Aimbot::AimAbility(target, 1, this->abilitiesarray[3], 0, false);
	cmd->buttons |= IN_ABILITY1;


}


void BebopLogic::OnAbility1() {


}

void BebopLogic::OnAbility2() {

	if (*(bool*)(this->abilitiesarray[2] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void BebopLogic::OnAbility3() {

	if (*(bool*)(this->abilitiesarray[3] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!cfg::bebop_AimHook)
		return;

	uint64_t target = Aimbot::GetCurrentAimbotTarget();
	if (!target)
		return;
	Aimbot::AimAbility(target, 1, this->abilitiesarray[3], 2840.f, true);

}

void BebopLogic::OnAbility4() {

	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void BebopLogic::OnTick() {

	this->target = Aimbot::CalculateNewAimbotTarget(AimGroups::AimGroup_Player, cfg::heroes_maxdistance, cfg::heroes_fov, false);
	if (!(this->target)) return;
	Helper::get_player_data(this->target, this->targetdata);


	if (this->InputCasting1 || *(bool*)(BebopLogic::abilitiesarray[1] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility1();
	}
	if (this->InputCasting2 || *(bool*)(BebopLogic::abilitiesarray[2] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility2();
	}
	if (this->InputCasting3 || *(bool*)(BebopLogic::abilitiesarray[3] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility3();
	}
	if (this->InputCasting4 || *(bool*)(BebopLogic::abilitiesarray[4] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility4();
	}

	if (cfg::bebop_AutoBomb) {
		AutoBomb();
	}
	if (cfg::bebop_AutoUppercut) {
		AutoUpperCut();
	}

}