#pragma once

#include <string>


struct KeyBind {
    std::string name = "Not Set";
    int key = 0;           // The key code
    bool waitingForKey = false; // Track if this keybind is waiting for a key press
};


class ConfigSettings
{
public:
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
    } esp;

    struct MiscSettings {
        bool bNorecoil = false;
        float XRange = 0.0f;
		float YRange = 0.0f;
		float Yrange2 = 0.0f;
		float Xrange2 = 0.0f;
    } misc;

	struct AntiAimSettings {
		bool bAntiAim = false;
	} antiaim;

    // General settings
    bool MenuOpen = true;
};

extern ConfigSettings Config;


