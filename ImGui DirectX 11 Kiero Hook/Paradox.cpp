#include "Paradox.h"


void ParadoxLogic::OnAbility1() {

	if (*(bool*)(this->abilitiesarray[1] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!cfg::paradox_AimGrenade)
		return;

		uint64_t target = Aimbot::GetCurrentAimbotTarget();
	if (!target)
		return;
	Aimbot::AimAbility(target, 2, this->abilitiesarray[1], 1500.f, true);

}

void ParadoxLogic::OnAbility2() {

	if (*(bool*)(this->abilitiesarray[2] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;
}

void ParadoxLogic::OnAbility3() {

	if (*(bool*)(this->abilitiesarray[3] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void ParadoxLogic::OnAbility4() {

	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!cfg::paradox_AimSwap)
		return;

	uint64_t target = Aimbot::GetCurrentAimbotTarget();
	if (!target)
		return;
	Aimbot::AimAbility(target, 1, this->abilitiesarray[4], 2350.f, true);

}

void ParadoxLogic::OnTick() {

	this->target = Aimbot::CalculateNewAimbotTarget(AimGroups::AimGroup_Player, cfg::heroes_maxdistance, cfg::heroes_fov, false);
	if (!(this->target)) return;
	Helper::get_player_data(this->target, this->targetdata);


	if (this->InputCasting1 || *(bool*)(ParadoxLogic::abilitiesarray[1] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility1();
	}
	if (this->InputCasting2 || *(bool*)(ParadoxLogic::abilitiesarray[2] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility2();
	}
	if (this->InputCasting3 || *(bool*)(ParadoxLogic::abilitiesarray[3] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility3();
	}
	if (this->InputCasting4 || *(bool*)(ParadoxLogic::abilitiesarray[4] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility4();
	}


}