#include "Calico.h"


void CalicoLogic::AutoAimBombs() {

	float CastingEnd = *(float*)(this->abilitiesarray[1] + C_CitadelBaseAbility::m_flCastCompletedTime); // use cooldown end because it for some reason sets the internal cd to 0.1 i guess to recast for multiple bombs?

	if (CastingEnd + 0.25 < globals::instance().Globals->flAbsCurTime) {
		return;
	}

	if (!(cfg::calico_AimBombs))
		return;

	Aimbot::AimAbility(this->target, 2, this->abilitiesarray[1], 2840.f, true);

}

void CalicoLogic::OnAbility1() {

	if (*(bool*)(this->abilitiesarray[1] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!(cfg::calico_AimBombs))
		return;

	if (!target)
		return;

	Aimbot::AimAbility(target, 2, this->abilitiesarray[1], 2840.f, true);
			
}

void CalicoLogic::OnAbility2() {

	if (*(bool*)(this->abilitiesarray[2] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void CalicoLogic::OnAbility3() {

	if (*(bool*)(this->abilitiesarray[3] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void CalicoLogic::OnAbility4() {

	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void CalicoLogic::OnTick() {

	this->target = Aimbot::CalculateNewAimbotTarget(AimGroups::AimGroup_Player, cfg::heroes_maxdistance, cfg::heroes_fov, false);
	if (!(this->target)) return;
	Helper::get_player_data(this->target, this->targetdata);


	if (this->InputCasting1 || *(bool*)(CalicoLogic::abilitiesarray[1] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility1();
	}
	if (this->InputCasting2 || *(bool*)(CalicoLogic::abilitiesarray[2] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility2();
	}
	if (this->InputCasting3 || *(bool*)(CalicoLogic::abilitiesarray[3] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility3();
	}
	if (this->InputCasting4 || *(bool*)(CalicoLogic::abilitiesarray[4] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility4();
	}

	AutoAimBombs();
	



}