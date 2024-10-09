#pragma once
#include "includes.h"

Aimbot Main_AimbotObj; // Aimbot 
Esp Main_ESPObj; // ESP class
Misc Main_MiscObj; // Misc class

// Define a function pointer for the original function

/*

typedef void(__fastcall* f_CalcAngle)(__int64 pCamera, float a2, float a3, float a4, bool a5);
f_CalcAngle CalcAngle = nullptr;
f_CalcAngle CalcAngleTarget = reinterpret_cast<f_CalcAngle>(Main_HelperObj.Modulebaseaddress + Main_Offsets.o_CalcAngle);

void detourCalcAngle(__int64 pCamera, float a2, float a3, float a4, bool a5) {

    Main_MiscObj.SimpleNoRecoil();

    CalcAngle(pCamera, a2, a3, a4, a5);
}
  FOR WHEN I NEED TO MAKE A HOOK
*/ 

//CreateMove Hook
typedef void(__fastcall* f_CreateMove)(__int64 *a1, int a2, char a3);
f_CreateMove CreateMove = nullptr;
f_CreateMove CreateMoveTarget = reinterpret_cast<f_CreateMove>(ClientModuleBase + Offsets::o_fCreateMove);


void detourCreateMove(__int64* a1, int a2, char a3) {
    CreateMove(a1, a2, a3);
}


void CreateHooks() {

    static bool init = false;
	if (init)
		return;
   
	MH_CreateHook((LPVOID)CreateMoveTarget, &detourCreateMove, reinterpret_cast<LPVOID*>(&CreateMove));
	MH_EnableHook((LPVOID)CreateMoveTarget);



    init = true;

}


void GodFunction(){
        
    CreateHooks();

        if (Config.aimbot.bAimbot) {
            Main_AimbotObj.RunAimbot();
        }
        if (Config.esp.bEsp) {
            Main_ESPObj.DoEsp();
		}
		Main_MiscObj.DoMisc();

        
}