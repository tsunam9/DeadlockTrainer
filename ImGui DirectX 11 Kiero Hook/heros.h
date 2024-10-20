#pragma once
#include "helper.h"

class Hero {

public:
	CCitadelUserCmdPB* cmd;
	uint64_t LocalPlayer;
	uint64_t target;
	PlayerData targetdata;
	PlayerData localplayerdata;
	std::vector<uintptr_t> abilitiesarray;



	void RunScript(CCitadelUserCmdPB* cmd);
private:
	virtual void OnAbility1();
	virtual void OnAbility2();
	virtual void OnAbility3();
	virtual void OnAbility4();
	virtual void OnTick();

};


