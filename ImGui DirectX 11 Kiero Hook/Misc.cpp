
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

/*	if (GetAsyncKeyState(VK_F3)) {
		CCitadelBulletManager* bulletman = (CCitadelBulletManager*)(0x7ffb696eff50);
		uint64_t bullet1 = *(uint64_t*)bulletman->BulletHandler->CurrentBullets;
		float speed = Helper::getBulletSpeed(bullet1);
		std::cout << speed << std::endl;
	}*/

Drawing testdraw;



void testbed() {

	if (!(iEngine->IsInGame()))
		return;

	
	auto pawn = Helper::GetPawn(Helper::get_local_player());

	auto cameraservices = *(uint64_t*)(pawn + C_BasePlayerPawn::m_pCameraServices);

	vec3 democamera = *(vec3*)(cameraservices + CPlayer_CameraServices::m_angDemoViewAngles);

	std::cout << "X: " << democamera.x << " Y: " << democamera.y << "\n";


}


void Misc::DoMisc() {
		SimpleNoRecoil();
		//testbed();
		//DoSkyModulation();
}