// Globals.cpp
#include "Globals.h" 

IEngineClient* iEngine = GetInterface<IEngineClient>("Engine2.dll", "Source2EngineToClient001");
IEngineCVar* VEngineCvar = GetInterface<IEngineCVar>("tier0.dll", "VEngineCvar007");
ISceneSystem* iSceneSystem002 = GetInterface<ISceneSystem>("scenesystem.dll", "SceneSystem_002");
ISource2Client* source2client = GetInterface<ISource2Client>("client.dll", "Source2Client002");



bool unloadRequested = false; 

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
            if (EntName == "CItemXP" && (cfg::ragebot_AimXp|| cfg::legitbot_LegitAimXp))
                this->entlist.updating->push_back(entity);
            if (EntName == "C_NPC_Trooper" && (cfg::ragebot_AimMinions || cfg::legitbot_LegitAimMinions))
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
        if (EntName == "CItemXP" && cfg::esp_DrawXp)
            this->espEntList.updating->push_back(entity);
        if (EntName == "C_NPC_TrooperNeutral")
            this->espEntList.updating->push_back(entity);
        if (EntName == "C_NPC_Trooper")
            this->espEntList.updating->push_back(entity);
    }

    this->espEntList.SwapBuffers();
}

