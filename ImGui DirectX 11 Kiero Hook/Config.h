#pragma once

#include <string>
#include "imgui/imgui.h"
#include "fstream"
#include "iostream"
#include "json.hpp"
#include <vector>



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
        bool SpeedBoost = false;
        KeyBind SpeedBoostKey;
        float fovmodifier = 1.0f;
        float aspectratio = 1.0f;

        MiscSettings() :
            SpeedBoostKey(&SpeedBoost, std::string("Speed Boost"))
        {}

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
        


    } colors;

    struct TempValues {
        bool checkbox = false;
        float slider1 = 0.0f;
        float slider2 = 0.0f;
        float inputfloat = 0.0f;
        int inputint = 0x20;

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



