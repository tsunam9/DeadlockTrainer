#pragma once
#include "helper.h"

class Hero {

public:

	bool InputCasting1 = false;
	bool InputCasting2 = false;
	bool InputCasting3 = false;
	bool InputCasting4 = false;

	CCitadelUserCmdPB* cmd;
	uint64_t LocalPlayer;
	uint64_t target;
	PlayerData targetdata;
	PlayerData localplayerdata;
	std::vector<uintptr_t> abilitiesarray;



	void RunScript(CCitadelUserCmdPB* cmd);
private:

	virtual void OnTick();

};


