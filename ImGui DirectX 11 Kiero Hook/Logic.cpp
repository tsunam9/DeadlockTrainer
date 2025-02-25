#pragma once
#include "includes.h"
Misc Main_MiscObj; // Misc class

bool menuopen = true;

static bool init = false;

void GodFunction(){

	if (!init) {

		static const std::string path = "C:/DeadlockTrainer/";

		if (!(std::filesystem::exists(path))) {
			std::filesystem::create_directories(path);
		}

		if (!(std::filesystem::exists(path + "/binds"))) {
			std::filesystem::create_directories(path + "/binds");
		}
		init = true;
	}
       
	menuopen = cfg::menu_open;

	CreateHooks();

        Esp::DoEsp();
		
		Main_MiscObj.DoMisc();

}