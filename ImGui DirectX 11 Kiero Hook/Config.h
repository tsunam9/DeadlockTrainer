#pragma once

#include <string>
#include "imgui/imgui.h"
#include "fstream"
#include "iostream"
#include "json.hpp"
#include <vector>
#include "cfgvar.h"



struct KeyBind {
    std::string name = "-";
    std::string BindName = "XD";
    int key = 0;           // The key code
    bool waitingForKey = false; // Track if this keybind is waiting for a key press
    int keybindmode = 0; // 0 == always 1 == hold 2 == toggle

    bool* varptr = nullptr;

    KeyBind(bool* VariableToKeybind, std::string nameforbind) {
        varptr = VariableToKeybind;
        BindName = nameforbind;
    }

    KeyBind(const char* varname, int bindkey) {
        name = varname;
        key = bindkey;
    }

    KeyBind() = default; 


};


 


class ConfigSettings
{
public:

    std::vector<std::string> configs;
    int selectedconfig = 0;

    // Nested structure for Aimbot settings
    struct AimbotSettings {
        bool bRageBotMasterSwitch = false;
        bool bAimbot = false;
        KeyBind AimKey;
        KeyBind AimKeyXp;
        KeyBind AimKeyMinions;
        bool MovementFix = false;
		bool AimXp = false;
        bool AimMinions = false;
        int targetSelectionMode = 0; // 0, 1, 2... depending on your mode
        float MaxDistance = 0.0f;
        float fov = 0.0f;
        bool silentaim = false;
        bool magicbullet = false;
        KeyBind magicbulletkey;

        AimbotSettings() :
            AimKey(&bAimbot, std::string("RageBot")),
            AimKeyXp(&AimXp, std::string("Aim Xp")),
            AimKeyMinions(&AimMinions, std::string("Aim Minions")),
            magicbulletkey(&magicbullet, std::string("Magic Bullet"))
        {}



    } aimbot;

    struct LegitBotSettings {

        bool legitbotmasterswitch = false;
        bool bLegitBot = false;
        KeyBind LegitAimKey;
        KeyBind LegitAimKeyXp;
        KeyBind LegitAimKeyMinions;
		bool LegitAimXp = false;
        bool LegitAimMinions = false;
        float fov = 0.0f;
        float smooth = 1.0f;
        int aimdelayinms = 0;
        std::vector<std::string> hitboxes;

        bool pitchcorrection = false;
        float pitchcorrectammount = 1.0f;
        bool yawcorrection = false;
        float yawcorrectammount = 1.0f;

        const char* HitboxNames[3] = { "Head", "Neck", "Pelvis" };
        bool selectedHitboxes[3] = { false, false, false }; // Head, Neck_0, Pelvis;

        LegitBotSettings() :
            LegitAimKey(&bLegitBot, std::string("LegitBot")),
            LegitAimKeyXp(&LegitAimXp, std::string("Aim XP")),
            LegitAimKeyMinions(&LegitAimMinions, std::string("Aim Minions"))
        {}

    }legitbot;

    // Nested structure for ESP settings
    struct EspSettings {
        bool bEsp = false;
        bool boneEsp = false;
        bool boxEsp = false;
        bool HealthText = false;
        bool Tracers = false;
        bool HealthEsp = false;
		bool DistanceEsp = false;
        bool NameEsp = false;
        bool HealthBar = false;
		bool DrawFov = false;
        bool DrawAimbotPrediction = false;
		bool DrawXp = false;
        bool DrawMonsters = false;
        bool DrawMinions = false;
        bool DrawAimbotTarget = false;
        bool ShowKeyBindList = false;
        bool Chams = false;
        bool ModelChams = false;
        bool LocalChams = false;
        bool ModWorld = false;
        bool ModLights = false;
        bool GlowEsp = false;
        bool GlowTeam = false;
    } esp;

    struct MiscSettings {
        bool bNorecoil = false;
        bool modfovandaspect = false;
        float fovmodifier = 1.0f;
        float aspectratio = 1.0f;

    } misc;

	struct ShivSettings {
		bool AutoAimDagger = false;
		bool AutoAimDash = false;
		bool AutoExecute = false;
	} shiv;

    struct VindictaSettings {
        bool AutoAimStake = false;
        bool AutoAimCrow = false;
		bool AutoSnipe = false;
        float AutoUltHealthPercent = 0.5f;
    } vindicta;

    struct BebopSettings {
        bool AimHook = false;
        bool AutoBomb = false;
        bool AutoUppercut = false;
    } bebop;

    struct HazeSettings {
        bool AimDagger = false;
    }haze;

    struct InfernusSettings {
        bool AimCatalyst = false;
    }infernus;

    struct IvySettings {
        bool AimBomb = false;
    }ivy;

    struct KelvinSettings {
        bool AimGrenade = false;
        bool LockBeam = false;
    }kelvin;

    struct LadyGeistSettings {
        bool AimBomb = false;
        bool AimMalice = false;

    }ladygeist;

    struct MirageSettings {
        bool AimTornado = false;
        bool AimScarabs = false;
    }mirage;

    struct ParadoxSettings {
        bool AimGrenade = false;
        bool AimSwap = false;
    }paradox;

    struct PocketSettings {
        bool AimBarrage = false;
        bool AimCloak = false;
    }pocket;

    struct SevenSettings {
        bool AimLightingBall = false;
        bool AutoStaticCharge = false;
    }seven;

    struct ViscousSettings {
        bool AimGooGrenade = false;
    }viscous;

    struct WardenSettings {
        bool AimLightingGrenade = false;
    }warden;

    struct WraithSettings {
        bool AimCards = false;
    }wraith;

    struct YamatoSettings {
        bool AimPowerSlash = false;
        bool AimCrimsonSlash = false;
    }yamato;

	struct AntiAimSettings {
		bool bAntiAim = false;
        int AAtype = 0;

        float SpinYawChange = 1.0f;
        float SpinPitchChange = 1.0f;

        float lowerjitter = -90.0f;
        float upperjitter = 90.0f;
	} antiaim;

    struct Colors {
       
        ImVec4 boxespcol = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
        ImVec4 skeletoncol = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 namecoloresp = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 healthtextcolesp = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 tracerscol = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 distancecolesp = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 drawfovcol = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 drawxpcol = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 drawmonsterscol = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 aimbotTargetcol = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 ChamsCol = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 LocalChamsCol = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 WorldModulationColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 LightModColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 GlowCol = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 GlowTeamCol = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 MenuColor = ImVec4(1.00f, 0.00f, 0.53f, 1.0f);
        


    } colors;

    struct TempValues {
        bool checkbox = false;
        float slider1 = 0.0f;
        float slider2 = 0.0f;
        float inputfloat = 0.0f;
        int inputint = 0;

        float tempx;
        float tempy; 
        float tempz;

    }tempvalues;

    static void LoadConfig(const std::string& filename);
    static void SaveConfig(const std::string& filename);
    void DeleteConfig(const std::string& filename);
    void RefreshConfigs();



    // General settings
    const char* menukeyname = "VK_INSERT";
    KeyBind MenuKey = KeyBind(menukeyname, VK_INSERT);

    bool MenuOpen = true;
};

extern ConfigSettings Config;

// Aimbot Settings
MAKE_CFGVAR(ragebot_masterswitch, false);
MAKE_CFGVAR(ragebot_bAimbot, false);
MAKE_CFGVAR(ragebot_movementfix, false);
MAKE_CFGVAR(ragebot_AimXp, false);
MAKE_CFGVAR(ragebot_AimMinions, false);
MAKE_CFGVAR(ragebot_TargetSelectMode, 0);
MAKE_CFGVAR(ragebot_maxdistance, 3000.f);
MAKE_CFGVAR(ragebot_aimfov, 180.f);
MAKE_CFGVAR(ragebot_silentaim, false);
MAKE_CFGVAR(ragebot_magicbullet, false);

// LegitBot Settings
MAKE_CFGVAR(legitbot_masterswitch, false);
MAKE_CFGVAR(legitbot_bLegitBot, false);
MAKE_CFGVAR(legitbot_LegitAimXp, false);
MAKE_CFGVAR(legitbot_LegitAimMinions, false);
MAKE_CFGVAR(legitbot_fov, 0.0f);
MAKE_CFGVAR(legitbot_smooth, 1.0f);
MAKE_CFGVAR(legitbot_aimdelayinms, 0);
MAKE_CFGVAR(legitbot_pitchcorrection, false);
MAKE_CFGVAR(legitbot_pitchcorrectammount, 1.0f);
MAKE_CFGVAR(legitbot_yawcorrection, false);
MAKE_CFGVAR(legitbot_yawcorrectammount, 1.0f);

// ESP Settings
MAKE_CFGVAR(esp_bEsp, false);
MAKE_CFGVAR(esp_boneEsp, false);
MAKE_CFGVAR(esp_boxEsp, false);
MAKE_CFGVAR(esp_HealthText, false);
MAKE_CFGVAR(esp_Tracers, false);
MAKE_CFGVAR(esp_HealthEsp, false);
MAKE_CFGVAR(esp_DistanceEsp, false);
MAKE_CFGVAR(esp_NameEsp, false);
MAKE_CFGVAR(esp_HealthBar, false);
MAKE_CFGVAR(esp_DrawFov, false);
MAKE_CFGVAR(esp_DrawAimbotPrediction, false);
MAKE_CFGVAR(esp_DrawXp, false);
MAKE_CFGVAR(esp_DrawMonsters, false);
MAKE_CFGVAR(esp_DrawMinions, false);
MAKE_CFGVAR(esp_DrawAimbotTarget, false);
MAKE_CFGVAR(esp_ShowKeyBindList, false);
MAKE_CFGVAR(esp_Chams, false);
MAKE_CFGVAR(esp_ModelChams, false);
MAKE_CFGVAR(esp_LocalChams, false);
MAKE_CFGVAR(esp_ModWorld, false);
MAKE_CFGVAR(esp_ModLights, false);
MAKE_CFGVAR(esp_GlowEsp, false);
MAKE_CFGVAR(esp_GlowTeam, false);

// Misc Settings
MAKE_CFGVAR(misc_bNorecoil, false);
MAKE_CFGVAR(misc_modfovandaspect, false);
MAKE_CFGVAR(misc_fovmodifier, 1.0f);
MAKE_CFGVAR(misc_aspectratio, 1.0f);

// Shiv Settings
MAKE_CFGVAR(shiv_AutoAimDagger, false);
MAKE_CFGVAR(shiv_AutoAimDash, false);
MAKE_CFGVAR(shiv_AutoExecute, false);

// Vindicta Settings
MAKE_CFGVAR(vindicta_AutoAimStake, false);
MAKE_CFGVAR(vindicta_AutoAimCrow, false);
MAKE_CFGVAR(vindicta_AutoSnipe, false);
MAKE_CFGVAR(vindicta_AutoUltHealthPercent, 0.5f);

// Bebop Settings
MAKE_CFGVAR(bebop_AimHook, false);
MAKE_CFGVAR(bebop_AutoBomb, false);
MAKE_CFGVAR(bebop_AutoUppercut, false);

// Haze Settings
MAKE_CFGVAR(haze_AimDagger, false);

// Infernus Settings
MAKE_CFGVAR(infernus_AimCatalyst, false);

// Ivy Settings
MAKE_CFGVAR(ivy_AimBomb, false);

// Kelvin Settings
MAKE_CFGVAR(kelvin_AimGrenade, false);
MAKE_CFGVAR(kelvin_LockBeam, false);

// LadyGeist Settings
MAKE_CFGVAR(ladygeist_AimBomb, false);
MAKE_CFGVAR(ladygeist_AimMalice, false);

// Mirage Settings
MAKE_CFGVAR(mirage_AimTornado, false);
MAKE_CFGVAR(mirage_AimScarabs, false);

// Paradox Settings
MAKE_CFGVAR(paradox_AimGrenade, false);
MAKE_CFGVAR(paradox_AimSwap, false);

// Pocket Settings
MAKE_CFGVAR(pocket_AimBarrage, false);
MAKE_CFGVAR(pocket_AimCloak, false);

// Seven Settings
MAKE_CFGVAR(seven_AimLightingBall, false);
MAKE_CFGVAR(seven_AutoStaticCharge, false);

// Viscous Settings
MAKE_CFGVAR(viscous_AimGooGrenade, false);

// Warden Settings
MAKE_CFGVAR(warden_AimLightingGrenade, false);

// Wraith Settings
MAKE_CFGVAR(wraith_AimCards, false);

// Yamato Settings
MAKE_CFGVAR(yamato_AimPowerSlash, false);
MAKE_CFGVAR(yamato_AimCrimsonSlash, false);

// AntiAim Settings
MAKE_CFGVAR(antiaim_bAntiAim, false);
MAKE_CFGVAR(antiaim_AAtype, 0);
MAKE_CFGVAR(antiaim_SpinYawChange, 1.0f);
MAKE_CFGVAR(antiaim_SpinPitchChange, 1.0f);
MAKE_CFGVAR(antiaim_lowerjitter, -90.0f);
MAKE_CFGVAR(antiaim_upperjitter, 90.0f);

//Color Settings
MAKE_CFGVAR(colors_boxespcol, ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
MAKE_CFGVAR(colors_skeletoncol, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_namecoloresp, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_healthtextcolesp, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_tracerscol, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_distancecolesp, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_drawfovcol, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_drawxpcol, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_drawmonsterscol, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_aimbotTargetcol, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_ChamsCol, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_LocalChamsCol, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_WorldModulationColor, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_LightModColor, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_GlowCol, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_GlowTeamCol, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
MAKE_CFGVAR(colors_MenuColor, ImVec4(1.00f, 0.00f, 0.53f, 1.0f));


