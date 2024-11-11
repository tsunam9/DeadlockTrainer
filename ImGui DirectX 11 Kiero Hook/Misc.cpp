
#include "Misc.h"
#include "CCitadelBulletManager.h"


void InitializeOriginalBytes(char(&original_bytes)[5]) {
	std::memcpy(original_bytes, reinterpret_cast<void*>(ClientModuleBase + Offsets.o_fApplyRecoil), sizeof(original_bytes));
}


void Misc::SimpleNoRecoil(){
	static char original_bytes[5]; // Declare the array
	static bool patched = false;

		if (patched && !Config.misc.bNorecoil) {
			DWORD oldProtect;
			VirtualProtect((void*)(ClientModuleBase + Offsets.o_fApplyRecoil), 5, PAGE_EXECUTE_READWRITE, &oldProtect);
			std::memcpy(reinterpret_cast<void*>(ClientModuleBase + Offsets.o_fApplyRecoil), original_bytes, sizeof(original_bytes));
			VirtualProtect((void*)(ClientModuleBase + Offsets.o_fApplyRecoil), 5, oldProtect, &oldProtect);
			patched = false;
			return;
		}

		if (!patched && Config.misc.bNorecoil) {
			DWORD oldProtect;
			VirtualProtect((void*)(ClientModuleBase + Offsets.o_fApplyRecoil), 5, PAGE_EXECUTE_READWRITE, &oldProtect);
			InitializeOriginalBytes(original_bytes);
			std::memcpy(reinterpret_cast<void*>(ClientModuleBase + Offsets.o_fApplyRecoil), "\x90\x90\x90\x90\x90", 5);
			VirtualProtect((void*)(ClientModuleBase + Offsets.o_fApplyRecoil), 5, oldProtect, &oldProtect);
			patched = true;
		}

}



void Misc::SpeedBoost(uint64_t localplayercontroller) {

	static bool needfix = false;
	uint64_t localplayer_pawn = Helper::GetPawn(localplayercontroller);
	float* mag = (float*)(localplayer_pawn + C_CitadelPlayerPawn::m_angLockedEyeAngles);
	if (mag == nullptr) return;

	Helper::KeyBindHandler(Config.misc.SpeedBoostKey);

	if (Config.misc.SpeedBoost)
	{
		uint64_t CameraManager = *(uint64_t*)(ClientModuleBase + Offsets.o_CameraManager + 0x28);
		float* ViewAngles = (float*)(CameraManager + 0x44); // RESET to 0x44
		needfix = true;
		mag[0] = 90;
		mag[1] = ViewAngles[1];
		mag[2] = 90;
	}
	else if (needfix)
	{
		needfix = false;
		mag[0] = 16384;
		mag[1] = 16384;
		mag[2] = 16384;
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

/*	if (GetAsyncKeyState(VK_F3)) {
		CCitadelBulletManager* bulletman = (CCitadelBulletManager*)(0x7ffb696eff50);
		uint64_t bullet1 = *(uint64_t*)bulletman->BulletHandler->CurrentBullets;
		float speed = Helper::getBulletSpeed(bullet1);
		std::cout << speed << std::endl;
	}*/

Drawing testdraw;



void testbed() {

	uint64_t hook = Helper::FindFirstEntityWithName("C_Citadel_Projectile_BloodBomb");
	if (!hook)
		return;

	float speed = *(float*)(hook + C_CitadelProjectile::m_flProjectileSpeed);

	std::cout << speed << std::endl;

}


void Misc::DoMisc() {
		SimpleNoRecoil();
		testbed();
		//DoSkyModulation();
}