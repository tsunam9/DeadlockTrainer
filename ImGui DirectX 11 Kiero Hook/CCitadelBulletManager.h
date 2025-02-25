#pragma once
#include "helper.h"


class Bullet
{
public:
	char pad_0000[16]; //0x0000
	int32_t TotalShot; //0x0010
	int32_t ThisTypeShot; //0x0014
	char pad_0018[28]; //0x0018
	vec3 InitialPos; //0x0034
	char pad_0040[252]; //0x0040
	float TimeAlive; //0x013C
	char pad_0140[80]; //0x0140
	vec3 vecVelocity; //0x0190
	char pad_019C[16]; //0x019C
	float flatVelocity; //0x01AC
}; //Size: 0x0468

class CCitadel_BulletHandler
{
public:
	char pad_0000[40]; //0x0000
	void* CurrentBullets; //0x0028
	char pad_0030[2056]; //0x0030
}; //Size: 0x0838

class CCitadelBulletManager
{
public:
	char pad_0000[64]; //0x0000
	CCitadel_BulletHandler* BulletHandler; //0x0040
};

