#pragma once
#include "helper.h"
#include "heros.h"
#include "Aimbot.h"

class ShivLogic : public Hero {
	
private:

	void OnAbility1();
	void OnAbility2();
	void OnAbility3();
	void OnAbility4();
	void OnTick() override;
	void AutoUlt();

};