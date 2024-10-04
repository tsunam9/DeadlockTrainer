
#include "Misc.h"


EntityList Misc_EntList;
Helper Misc_HelperObj;
Offsets Mist_Offsets;
ConfigSettings Misc_Cfg;

uint32_t Misc::NoRecoil(uint32_t v1, uint32_t v2, uint32_t v3) {
		
	//if (Misc_Cfg.misc.bNorecoil == false) //must fix later 
		return v3;
		
	vec3 NoRecoil = { 0,0,0 };
	return (uint32_t)&NoRecoil;
}


void Misc::DoMisc(ConfigSettings cfg) {
	Misc_Cfg = cfg;
}