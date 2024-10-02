#pragma once
#include "includes.h"
#include "Config.h"



class Aimbot {

public:
	vec2 GetAimAngles(vec3 Target);
	void AimAt(uintptr_t entity, const char* bone);
	void RunAimbot(ConfigSettings cfg);

};