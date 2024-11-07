#include "helper.h"



class CCitadel_BulletHandler
{
public:
	char pad_0000[40]; //0x0000
	void** CurrentBullets; //0x0028
	char pad_0030[2056]; //0x0030
}; //Size: 0x0838

class CCitadelBulletManager
{
public:
	char pad_0000[64]; //0x0000
	CCitadel_BulletHandler* BulletHandler; //0x0040
};

