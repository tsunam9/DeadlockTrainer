#pragma once
#include "helper.h"

class Hero {

public:
	CCitadelUserCmdPB* cmd;
	void RunScript(CCitadelUserCmdPB* cmd);
private:
	virtual void OnAbility1();
	virtual void OnAbility2();
	virtual void OnAbility3();
	virtual void OnAbility4();
	virtual void OnTick();

};

