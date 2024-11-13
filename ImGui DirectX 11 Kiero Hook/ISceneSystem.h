#pragma once
#include <cstdint>
#include "mem.h"

class ISceneSystem
{
public:

	__int64 CreateCHlowHelperSceneObject(uint64_t entitytoapply) {

		return MEM::CallVFunc<__int64, 11, ISceneSystem>(this, MEM::GetClientBase() + 0x1F25080, 0LL, 0LL, entitytoapply + 176); // SETBACK find real address.

	}


};