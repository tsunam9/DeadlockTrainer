#pragma once
#include "includes.h"

class ConfigSettings
{
public:
    // Nested structure for Aimbot settings
    struct AimbotSettings {
        bool bAimbot = false;;
        int AimKey = 0; // Default value
		int AimKeyXp = 0; // Default value
		bool AimXp = false;
        int targetSelectionMode = 0; // 0, 1, 2... depending on your mode
        float MaxDistance = 0.0f;
        float fov = 0.0f;
        float smooth = 0.0f;
        int aimBone = 0; // Example bone index
        bool silentaim = false;

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
    } misc;

    // General settings
    bool MenuOpen = true;
};

extern ConfigSettings Config;


