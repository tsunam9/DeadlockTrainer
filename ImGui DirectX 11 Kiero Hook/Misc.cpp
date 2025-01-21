
#include "Misc.h"
#include "CCitadelBulletManager.h"


void InitializeOriginalBytes(char(&original_bytes)[5]) {
	std::memcpy(original_bytes, reinterpret_cast<void*>(ClientModuleBase + Offsets.o_fApplyRecoil), sizeof(original_bytes));
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

		testbed();
		//DoSkyModulation();
}