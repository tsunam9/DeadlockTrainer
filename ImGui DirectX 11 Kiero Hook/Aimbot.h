#pragma once
#include "includes.h"
#include "Config.h"


class Aimbot {

public:
	static vec2 GetAimAngles(vec3 Target);
	static void AimAt(uintptr_t entity, const char* bone);
	static void AimAtXp(uintptr_t entity);
	static void AimAtMinions(uintptr_t entity);
	static void RunAimbot(CCitadelUserCmdPB* usercmd);
	static vec3 PredictPosition(vec3 Target, vec3 Velocity, float bulletspeed);
	static uint64_t GetAimbotTarget(std::string group);
	static void AimAbility(uintptr_t entity, int aimpos, uintptr_t ability);


};