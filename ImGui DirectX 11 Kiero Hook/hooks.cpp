#include "hooks.h"


//CreateMove Hook
typedef void(__fastcall* f_CreateMove)(__int64* a1, int a2, char a3);
f_CreateMove CreateMove = nullptr;
f_CreateMove CreateMoveTarget = reinterpret_cast<f_CreateMove>(ClientModuleBase + Offsets::o_fCreateMove);

//	tracelol.TraceShape(&ray,Input1, botpos, &filter, &trace);

typedef void(__fastcall* f_TraceShape)(__int64* a1, __int64 a2, unsigned __int64* a3, __int64 a4, TraceFilter_t* Filter, GameTrace_t* trace);
f_TraceShape TraceShape = nullptr;
f_TraceShape TraceShapeTarget = reinterpret_cast<f_TraceShape>(ClientModuleBase + Offsets::o_ftraceShape);

void detourtraceshape(__int64* a1, __int64 a2, unsigned __int64* a3, __int64 a4, TraceFilter_t* Filter, GameTrace_t* trace){

	TraceShape(a1, a2, a3, a4, Filter, trace);

}

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


	MH_CreateHook((LPVOID)TraceShapeTarget, &detourtraceshape, reinterpret_cast<LPVOID*>(&TraceShape));
	MH_EnableHook((LPVOID)TraceShapeTarget);


	init = true;
}