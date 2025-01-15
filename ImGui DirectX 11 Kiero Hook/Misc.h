#pragma once
#include "includes.h"
#include "mem.h"
#include "Globals.h"

#include "Security.h"


class Misc {

public:


	void DoMisc();
	void SimpleNoRecoil();
	void DoSkyModulation();
	static void settargetfov(float fov);

	static void AutoActiveReload(CCitadelUserCmdPB* cmd);

};