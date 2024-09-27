#pragma once
#include "includes.h"

Offsets OffsetsMain; // Offsets class; // EntityList class
Helper Main_HelperObj; // Helper class
Aimbot Main_AimbotObj; // Aimbot 
Esp Main_ESPObj; // ESP class

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
        

        if (MainSettings.bAimbot && GetAsyncKeyState(VK_RBUTTON)) {
            Main_AimbotObj.RunAimbot();
        }
        if (MainSettings.bEsp) {
            Main_ESPObj.DoEsp(MainSettings);
		}
        
}