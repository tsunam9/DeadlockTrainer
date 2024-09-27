#pragma once
#include "helper.h"
#include "PlayerClasses.h"



class Aimbot {

public:
	void AimAtPlayer(uintptr_t entity, bool orb);
	void AimAt(vec3 Target);
	void RunAimbot();

};