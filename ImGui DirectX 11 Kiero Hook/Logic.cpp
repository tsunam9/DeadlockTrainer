#pragma once
#include "includes.h"

Aimbot Main_AimbotObj; // Aimbot 
Esp Main_ESPObj; // ESP class
Misc Main_MiscObj; // Misc class


void GodFunction(){
       

	CreateHooks();

        Main_ESPObj.DoEsp();
		
		Main_MiscObj.DoMisc();

}