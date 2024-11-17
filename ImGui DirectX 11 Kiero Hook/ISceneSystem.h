#pragma once
#include <cstdint>
#include "mem.h"

class ISceneSystem
{
public:

	__int64 CreateCHlowHelperSceneObject(uint64_t entitytoapply) {

		static const uint64_t helperobjdescoffset = MEM::PatternScanOffset((void*)MEM::GetClientBase(), "48 8d 15 ? ? ? ? 45 33 c9 45 33 c0 48 8b 01 4c 8b 50", 3, 7);

		return MEM::CallVFunc<__int64, 11, ISceneSystem>(this, MEM::GetClientBase() + helperobjdescoffset, 0LL, 0LL, entitytoapply + 176); // SETBACK find real address.

	}


};