#pragma once
#include "includes.h"

Offsets Main_Offsets; // Offsets class; // EntityList class
Helper Main_HelperObj; // Helper class
Aimbot Main_AimbotObj; // Aimbot 
Esp Main_ESPObj; // ESP class
Misc Main_MiscObj; // Misc class

// Define a function pointer for the original function

typedef int64_t(__stdcall* RecoilFunction)(int v1, int v2, int v3);
RecoilFunction Recoil = nullptr; //Original after hook
RecoilFunction recoilTarget = reinterpret_cast<RecoilFunction>(Main_HelperObj.networkSystemBase + Main_Offsets.o_pAimPunchFunction);
int64_t detourRecoil(int v1, int v2, int v3) {
	uint32_t recoilvarptr = Main_MiscObj.NoRecoil(v1, v2, v3); 
	return Recoil(v1, v2, recoilvarptr); // Call the original function
}

void CreateHooks() {
   
    MH_CreateHook(reinterpret_cast<void**>(recoilTarget), &detourRecoil, reinterpret_cast<void**>(&Recoil)); // Pass the address of the function pointer
	MH_EnableHook(reinterpret_cast<void**>(recoilTarget));


}




inline void print_entities()
{
    std::unordered_set<uint64_t> processed_ents;
    int max_ents = Main_HelperObj.get_max_entities();
    std::cout << "[>] MaxEntIndex:" << max_ents << std::endl;

    for (size_t i = 1; i <= static_cast<size_t>(max_ents); ++i)
    {
        uint64_t entity = Main_HelperObj.get_base_entity_from_index(i);

        if (!entity || !processed_ents.insert(entity).second)
            continue;

        std::string EntName = Main_HelperObj.get_schema_name(entity);

        std::cout << "[>] " << i << " | " << EntName << std::endl;

    }
}

void GodFunction(uintptr_t ConfigPtr){
    ConfigSettings MainSettings = *(ConfigSettings*)ConfigPtr;
        
    CreateHooks();

        if (MainSettings.aimbot.bAimbot) {
            Main_AimbotObj.RunAimbot(MainSettings);
        }
        if (MainSettings.esp.bEsp) {
            Main_ESPObj.DoEsp(MainSettings);
		}
		Main_MiscObj.DoMisc(MainSettings);

        
}