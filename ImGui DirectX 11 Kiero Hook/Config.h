#pragma once

class ConfigSettings
{
public:
    // Nested structure for Aimbot settings
    struct AimbotSettings {
        bool bAimbot = false;
        int AimKey = 0; // Default value
        int targetSelectionMode = 0; // 0, 1, 2... depending on your mode
        float MaxDistance = 0.0f;
        float fov = 0.0f;
        int aimBone = 0; // Example bone index

    } aimbot;

    // Nested structure for ESP settings
    struct EspSettings {
        bool bEsp = false;
        bool boxEsp = false;
        bool HealthText = false;
        bool Tracers = false;
        bool HealthEsp = false;
		bool DistanceEsp = false;
        bool NameEsp = false;
        bool HealthBar = false;
		bool DrawFov = false;
    } esp;

    // General settings
    bool MenuOpen = true;
};


