#include "Yamato.h"

void YamatoLogic::AimPowerSlash() {


	if (!*(bool*)(this->abilitiesarray[2] + C_CitadelBaseAbility::m_bInCastDelay))
		return;

	if (!cfg::yamato_AimPowerSlash)
		return;
	cmd->buttons &= ~IN_ATTACK;

	Aimbot::AimAbility(target, 1, this->abilitiesarray[2], 0.f, false);


}

void YamatoLogic::OnAbility1() {

	if (*(bool*)(this->abilitiesarray[3] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void YamatoLogic::OnAbility2() {

	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;


}

void YamatoLogic::OnAbility3() {

	if (*(bool*)(this->abilitiesarray[5] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!cfg::yamato_AimCrimsonSlash)
		return;

	Aimbot::AimAbility(target, 1, this->abilitiesarray[3], 0.f, false);

}

void YamatoLogic::OnAbility4() {

	if (*(bool*)(this->abilitiesarray[5] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void YamatoLogic::OnTick() {

	this->target = Aimbot::CalculateNewAimbotTarget(AimGroups::AimGroup_Player, cfg::heroes_maxdistance, cfg::heroes_fov, false);
	if (!(this->target)) return;
	Helper::get_player_data(this->target, this->targetdata);


	if (this->InputCasting1 || *(bool*)(YamatoLogic::abilitiesarray[2] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility1();
	}
	if (this->InputCasting2 || *(bool*)(YamatoLogic::abilitiesarray[3] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility2();
	}
	if (this->InputCasting3 || *(bool*)(YamatoLogic::abilitiesarray[4] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility3();
	}
	if (this->InputCasting4 || *(bool*)(YamatoLogic::abilitiesarray[5] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility4();
	}

	AimPowerSlash();

}