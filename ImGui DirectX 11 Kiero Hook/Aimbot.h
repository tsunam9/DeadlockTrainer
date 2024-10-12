#pragma once
#include "includes.h"
#include "Config.h"



class Aimbot {

public:
	static vec2 GetAimAngles(vec3 Target);
	void AimAt(uintptr_t entity, const char* bone, float smooth_factor);
	void AimAtXp(uintptr_t entity, float smooth_factor);
	void RunAimbot();
	vec3 PredictPosition(vec3 Target, vec3 Velocity, float bulletspeed);

};