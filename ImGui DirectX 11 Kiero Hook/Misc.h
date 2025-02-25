#pragma once
#include "includes.h"
#include "mem.h"
#include "Globals.h"

#include "Security.h"


class Misc {

public:


	void DoMisc();
	void DoSkyModulation();

	static void AutoActiveReload(CCitadelUserCmdPB* cmd);

};