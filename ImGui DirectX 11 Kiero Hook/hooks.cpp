#include "hooks.h"


//CreateMove Hook
typedef void(__fastcall* f_CreateMove)(__int64* a1, int a2, char a3);
f_CreateMove CreateMove = nullptr;
f_CreateMove CreateMoveTarget = reinterpret_cast<f_CreateMove>(ClientModuleBase + Offsets::o_fCreateMove);

Aimbot objaimbot;

void detourCreateMove(__int64* a1, int a2, char a3) {

	objaimbot.RunAimbot();
	CreateMove(a1, a2, a3);

}

void CreateHooks() {

	static bool init = false;
	if (init)
		return;

	MH_CreateHook((LPVOID)CreateMoveTarget, &detourCreateMove, reinterpret_cast<LPVOID*>(&CreateMove));
	MH_EnableHook((LPVOID)CreateMoveTarget);


	init = true;
}