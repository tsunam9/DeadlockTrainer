#include "Wraith.h"


void WraithLogic::AutoAimCard() {

	if (!(*(bool*)(this->abilitiesarray[1] + CCitadel_Ability_CardToss::m_bCardIsFlying)))
		return;

	vec2 angles = Aimbot::GetAimAngles(targetdata->m_vecOrigin);
	cmd->cameraViewAngle->viewAngles.x = angles.x;
	cmd->cameraViewAngle->viewAngles.y = angles.y;

	return;
}

void WraithLogic::OnAbility1() {

	if (*(bool*)(this->abilitiesarray[1] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!Config.mirage.AimTornado)
		//return;

		uint64_t target = Aimbot::GetCurrentAimbotTarget();
	if (!target)
		return;
	Aimbot::AimAbility(target, 1, this->abilitiesarray[1], 1050.f, true);

}

void WraithLogic::OnAbility2() {

	if (*(bool*)(this->abilitiesarray[2] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

	if (!Config.mirage.AimScarabs)
		//return;

		uint64_t target = Aimbot::GetCurrentAimbotTarget();
	if (!target)
		return;
	Aimbot::AimAbility(target, 0, this->abilitiesarray[2], 2350.f, true);


}

void WraithLogic::OnAbility3() {

	if (*(bool*)(this->abilitiesarray[3] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void WraithLogic::OnAbility4() {

	if (*(bool*)(this->abilitiesarray[4] + C_CitadelBaseAbility::m_bIsCoolingDownInternal))
		return;

}

void WraithLogic::OnTick() {

	this->target = Aimbot::GetCurrentAimbotTarget();
	if (!(this->target)) return;
	Helper::get_player_data(this->target, this->targetdata);


	if (this->InputCasting1 || *(bool*)(WraithLogic::abilitiesarray[1] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility1();
	}
	if (this->InputCasting2 || *(bool*)(WraithLogic::abilitiesarray[2] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility2();
	}
	if (this->InputCasting3 || *(bool*)(WraithLogic::abilitiesarray[3] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility3();
	}
	if (this->InputCasting4 || *(bool*)(WraithLogic::abilitiesarray[4] + C_CitadelBaseAbility::m_bInCastDelay)) {
		OnAbility4();
	}

	if (Config.wraith.AimCards)
		AutoAimCard();


}