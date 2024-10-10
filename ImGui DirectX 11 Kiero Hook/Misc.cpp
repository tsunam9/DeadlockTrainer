
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

void testbed() {

}



void Misc::DoMisc() {
		SimpleNoRecoil();
		//testbed();
}