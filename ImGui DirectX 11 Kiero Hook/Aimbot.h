#pragma once
#include "includes.h"
#include "Config.h"
#include "Globals.h"


class Aimbot {

public:
	static vec2 GetAimAngles(vec3 Target);
	static void RageAimAt(uint64_t entity);
	static void RageAimAtXp(uintptr_t entity);
	static void RageAimAtMinions(uintptr_t entity);
	static void ShootMagicBullet(uint64_t entity);
	static void RunAimbot(CCitadelUserCmdPB* usercmd);
	static vec3 PredictPosition(vec3 Target, vec3 Velocity, float bulletspeed);
	static uint64_t RageGetAimbotTarget(uint32_t group);
	static uint64_t GetCurrentAimbotTarget();
	static bool IsAimbotting();
	static bool IsRageBotting();
	static bool IsLegitBotting();
	static void AimAbility(uintptr_t entity, int aimpos, uintptr_t ability, float projectilespeed, bool projectile);

	static bool LegitGetAimbotTarget(uint32_t group, int& closestbone, uint64_t& aimtarget);
	static void LegitAimAt(uint64_t entity, std::string bone);



};