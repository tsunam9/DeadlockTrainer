#include "Viscous.h"


void ViscousLogic::OnAbility1() {

	if (*(bool*)(this->abilitiesarray[1] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!cfg::viscous_AimGooGrenade)
		return;

	uint64_t target = Aimbot::GetCurrentAimbotTarget();
	if (!target)
		return;
	Aimbot::AimAbility(target, 0, this->abilitiesarray[1], 1600.f, true);

}

void ViscousLogic::OnAbility2() {

	if (*(bool*)(this->abilitiesarray[2] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void ViscousLogic::OnAbility3() {

	if (*(bool*)(this->abilitiesarray[3] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void ViscousLogic::OnAbility4() {

	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void ViscousLogic::OnTick() {

	this->target = Aimbot::CalculateNewAimbotTarget(AimGroups::AimGroup_Player, cfg::heroes_maxdistance, cfg::heroes_fov, false);
	if (!(this->target)) return;
	Helper::get_player_data(this->target, this->targetdata);


	if (this->InputCasting1 || *(bool*)(ViscousLogic::abilitiesarray[1] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility1();
	}
	if (this->InputCasting2 || *(bool*)(ViscousLogic::abilitiesarray[2] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility2();
	}
	if (this->InputCasting3 || *(bool*)(ViscousLogic::abilitiesarray[3] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility3();
	}
	if (this->InputCasting4 || *(bool*)(ViscousLogic::abilitiesarray[4] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility4();
	}


}