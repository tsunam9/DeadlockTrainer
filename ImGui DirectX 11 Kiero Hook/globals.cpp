// Globals.cpp
#include "Globals.h" 



void globals::SortEnts() { // ONLY CALL IN AIMBOT

        this->entlist.updating->clear();
        int max_ents = Helper::get_max_entities();
        if (!(max_ents >= 0))
            return;
        for (size_t i = 1; i <= static_cast<size_t>(max_ents); ++i) {
            uint64_t entity = Helper::get_base_entity_from_index(i);

            if (!entity)
                continue;

            std::string EntName = Helper::get_schema_name(entity);

            if (EntName == "CCitadelPlayerController" && !*(bool*)(entity + CBasePlayerController::m_bIsLocalPlayerController))
                this->entlist.updating->push_back(entity);
            if (EntName == "CItemXP" && Config.esp.DrawXp)
                this->entlist.updating->push_back(entity);
            if (EntName == "C_NPC_TrooperNeutral")
                this->entlist.updating->push_back(entity);
            if (EntName == "C_NPC_Trooper")
                this->entlist.updating->push_back(entity);
        }
        this->entlist.SwapBuffers();
}

void globals::SortEntsEsp() { // ONLY CALL IN DOESP

    this->espEntList.updating->clear();
    int max_ents = Helper::get_max_entities();

    if (max_ents < 1)
        return;

    for (size_t i = 1; i <= static_cast<size_t>(max_ents); ++i) {
        uint64_t entity = Helper::get_base_entity_from_index(i);

        if (!entity)
            continue;

        std::string EntName = Helper::get_schema_name(entity);

        if (EntName == "CCitadelPlayerController" && !*(bool*)(entity + CBasePlayerController::m_bIsLocalPlayerController))
            this->espEntList.updating->push_back(entity);
        if (EntName == "CItemXP" && Config.esp.DrawXp)
            this->espEntList.updating->push_back(entity);
        if (EntName == "C_NPC_TrooperNeutral")
            this->espEntList.updating->push_back(entity);
        if (EntName == "C_NPC_Trooper")
            this->espEntList.updating->push_back(entity);
    }
    this->espEntList.SwapBuffers();
}