#pragma once
#include "helper.h"
#include "heros.h"
#include "Aimbot.h"
#include "offsets.h"

class VindictaLogic : public Hero {

private:

	void OnAbility1() override;
	void OnAbility2() override;
	void OnAbility3() override;
	void OnAbility4() override;
	void OnTick() override;
	void AutoUlt();

};