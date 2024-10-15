#include "hooks.h"


//CreateMove Hook
typedef void(__fastcall* f_CreateMove)(__int64* a1, int a2, char a3);
f_CreateMove CreateMove = nullptr;
f_CreateMove CreateMoveTarget = reinterpret_cast<f_CreateMove>(ClientModuleBase + Offsets::o_fCreateMove);


Aimbot objaimbot;

void detourCreateMove(__int64* a1, int a2, char a3) {

	CCitadelUserCmdPB* cmd = Helper::GetCurrentUserCmd();
	uint64_t CameraManager = Helper::get_Camera();
	vec2 ViewAngles = *(vec2*)(CameraManager + 0x44);

	CreateMove(a1, a2, a3);
	if (Config.aimbot.bAimbot) {
		objaimbot.RunAimbot();
		if(!Config.antiaim.bAntiAim)
			Helper::CorrectViewAngles(ViewAngles, cmd);
	}

	if (Config.antiaim.bAntiAim) {
		AntiAim::DoAntiAim();
	}
	


}

void CreateHooks() {

	static bool init = false;
	if (init)
		return;

	MH_CreateHook((LPVOID)CreateMoveTarget, &detourCreateMove, reinterpret_cast<LPVOID*>(&CreateMove));
	MH_EnableHook((LPVOID)CreateMoveTarget);


	init = true;
}