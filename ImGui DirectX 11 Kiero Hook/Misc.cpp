
#include "Misc.h"


void InitializeOriginalBytes(char(&original_bytes)[5]) {
	std::memcpy(original_bytes, reinterpret_cast<void*>(ClientModuleBase + Offsets::o_fApplyRecoil), sizeof(original_bytes));
}


void Misc::SimpleNoRecoil(){
	static char original_bytes[5]; // Declare the array
	static bool patched = false;

		if (patched && !Config.misc.bNorecoil) {
			DWORD oldProtect;
			VirtualProtect((void*)(ClientModuleBase + Offsets::o_fApplyRecoil), 5, PAGE_EXECUTE_READWRITE, &oldProtect);
			std::memcpy(reinterpret_cast<void*>(ClientModuleBase + Offsets::o_fApplyRecoil), original_bytes, sizeof(original_bytes));
			VirtualProtect((void*)(ClientModuleBase + Offsets::o_fApplyRecoil), 5, oldProtect, &oldProtect);
			patched = false;
			return;
		}

		if (!patched && Config.misc.bNorecoil) {
			DWORD oldProtect;
			VirtualProtect((void*)(ClientModuleBase + Offsets::o_fApplyRecoil), 5, PAGE_EXECUTE_READWRITE, &oldProtect);
			InitializeOriginalBytes(original_bytes);
			std::memcpy(reinterpret_cast<void*>(ClientModuleBase + Offsets::o_fApplyRecoil), "\x90\x90\x90\x90\x90", 5);
			VirtualProtect((void*)(ClientModuleBase + Offsets::o_fApplyRecoil), 5, oldProtect, &oldProtect);
			patched = true;
		}

}


Drawing testdraw;

CGameTraceManager tracelol;

uint64_t localplayerpawn = Helper::GetPawn(Helper::get_local_player());

PlayerData localplr = Helper::get_player_data(Helper::get_local_player());


vec3 Input2 = Helper::GetBonePosition(Helper::get_local_player(), "head") + vec3{0,500,0};

//0x1C3003

TraceFilter_t filter(0x1C1003, localplayerpawn, 4, 7);

Ray_t ray = {};
GameTrace_t trace = {};




void testbed() {

	vec3 Input1 = Helper::GetBonePosition(Helper::get_local_player(), "head");

	auto bot = Helper::get_base_entity_from_index(2);
	vec3 botpos = Helper::GetBonePosition(bot, "head");


	vec2 LineStart;
	vec2 LineEnd;


	tracelol.TraceShape(&ray,Input1, botpos, &filter, &trace);

	if (Helper::WorldToScreen(Input1, LineStart)) {
		Helper::WorldToScreen(botpos, LineEnd);
		if (trace.m_pHitEntity != 0) {
			testdraw.DrawLine(LineStart.x, LineStart.y, LineEnd.x, LineEnd.y, IM_COL32(0, 255, 0, 255));
		}
		else {
			testdraw.DrawLine(LineStart.x, LineStart.y, LineEnd.x, LineEnd.y, IM_COL32(255, 0, 0, 255));
		}
	}
	std::cout << trace.m_flFraction << std::endl;

}



void Misc::DoMisc() {
		SimpleNoRecoil();
		testbed();
}