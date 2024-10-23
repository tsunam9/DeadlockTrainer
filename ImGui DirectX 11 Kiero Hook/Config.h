#pragma once

#include <string>
#include "imgui/imgui.h"
#include "fstream"
#include "iostream"
#include "json.hpp"
#include <vector>


struct KeyBind {
    std::string name = "Always";
    int key = 0;           // The key code
    bool waitingForKey = false; // Track if this keybind is waiting for a key press
};


class ConfigSettings
{
public:

    std::vector<std::string> configs;
    int selectedconfig = 0;

    // Nested structure for Aimbot settings
    struct AimbotSettings {
        bool bAimbot = false;;
		KeyBind AimKey;
        KeyBind AimKeyXp;
        KeyBind AimKeyMinions;
		bool AimXp = false;
        bool AimMinions = false;
        int targetSelectionMode = 0; // 0, 1, 2... depending on your mode
        float MaxDistance = 0.0f;
        float fov = 0.0f;
        float smooth = 0.0f;
        int aimBone = 0; // Example bone index
        bool silentaim = false;
		bool VisibleCheck = false;
        bool AutoFire = false;
        bool magicbullet = false;
        KeyBind magicbulletkey;

    } aimbot;

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
    } vindicta;

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
        


    } colors;

    struct TempValues {
        bool checkbox = false;
        float slider1 = 0.0f;
        float slider2 = 0.0f;
        float inputfloat = 0.0f;
        int inputint = 0.0f;
    }tempvalues;

    static void LoadConfig(const std::string& filename);
    static void SaveConfig(const std::string& filename);
    void DeleteConfig(const std::string& filename);
    void RefreshConfigs();



    // General settings
    bool MenuOpen = true;
};

extern ConfigSettings Config;



