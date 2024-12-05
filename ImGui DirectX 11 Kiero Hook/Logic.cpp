#pragma once
#include "includes.h"
Misc Main_MiscObj; // Misc class

bool menuopen = true;

void GodFunction(){
       
	menuopen = cfg::menu_open;

	CreateHooks();

        Esp::DoEsp();
		
		Main_MiscObj.DoMisc();

}