
#include "Misc.h"
#include "CCitadelBulletManager.h"


void InitializeOriginalBytes(char(&original_bytes)[5]) {
	std::memcpy(original_bytes, reinterpret_cast<void*>(ClientModuleBase + Offsets.o_fApplyRecoil), sizeof(original_bytes));
}


void Misc::SimpleNoRecoil(){
	static char original_bytes[5]; // Declare the array
	static bool patched = false;

		if (patched && !cfg::misc_bNorecoil) {
			DWORD oldProtect;
			VirtualProtect((void*)(ClientModuleBase + Offsets.o_fApplyRecoil), 5, PAGE_EXECUTE_READWRITE, &oldProtect);
			std::memcpy(reinterpret_cast<void*>(ClientModuleBase + Offsets.o_fApplyRecoil), original_bytes, sizeof(original_bytes));
			VirtualProtect((void*)(ClientModuleBase + Offsets.o_fApplyRecoil), 5, oldProtect, &oldProtect);
			patched = false;
			return;
		}

		if (!patched && cfg::misc_bNorecoil) {
			DWORD oldProtect;
			VirtualProtect((void*)(ClientModuleBase + Offsets.o_fApplyRecoil), 5, PAGE_EXECUTE_READWRITE, &oldProtect);
			InitializeOriginalBytes(original_bytes);
			std::memcpy(reinterpret_cast<void*>(ClientModuleBase + Offsets.o_fApplyRecoil), "\x90\x90\x90\x90\x90", 5);
			VirtualProtect((void*)(ClientModuleBase + Offsets.o_fApplyRecoil), 5, oldProtect, &oldProtect);
			patched = true;
		}

}

void Misc::DoSkyModulation(){

	for (int i = 0; i < globals::instance().entlist.active->size(); i++) {

		

		uint64_t Entity = (*globals::instance().entlist.active)[i];
			if (!Entity)
				return;

		auto plrstring = Helper::get_schema_name(Entity);

		if (!(plrstring == "CEnvSky"))
			return;

		std::cout << Entity << std::endl;


	}
}

void Misc::settargetfov(float fov) {

	static uint64_t offset = MEM::PatternScanOffset((void*)ClientModuleBase, "48 8b 05 ? ? ? ? 48 8b 40 ? f3 0f 10 00 48 8d 44 24", 3, 7);

	if (!iEngine->IsInGame()) {
		return;
	}

	auto layer = *(uint64_t*)(ClientModuleBase + offset);
	float* realfov = (float*)(layer + 0x40);

	if (*realfov != fov) {
		*realfov = fov;
	}

	return;
}


void Misc::AutoActiveReload(CCitadelUserCmdPB* cmd) {

	if (!(iEngine->IsInGame()))
		return;

	if (!cfg::misc_autoactivereload)
		return;

	static globals& globals = globals::instance();

	auto weapon = Helper::get_localplr_weapon();

	if (!weapon) {
		return;
	}


	bool inreload = *(bool*)(weapon + CCitadel_Ability_PrimaryWeapon::m_bInReload);

	if (inreload) {

		bool canactivereload = *(bool*)(weapon + CCitadel_Ability_PrimaryWeapon::m_bCanActiveReload);
		if (!canactivereload) {
			return;
		}

		float delaystarttime = *(float*)(weapon + CCitadel_Ability_PrimaryWeapon::m_flNextAttackDelayStartTime);
		float delayendtime = *(float*)(weapon + CCitadel_Ability_PrimaryWeapon::m_flNextAttackDelayEndTime);
		float reloadtime = delayendtime - delaystarttime;

		float reloadprogress = (globals.Globals->flAbsCurTime - delaystarttime) / reloadtime;

		if (reloadprogress > 0.45) {

			cmd->buttons |= IN_RELOAD;

		}

	}

}

void testbed() {

	if (!(iEngine->IsInGame()))
		return;
	

}

void Misc::DoMisc() {

		SimpleNoRecoil();

		settargetfov(cfg::misc_fov);

		testbed();
		//DoSkyModulation();
}