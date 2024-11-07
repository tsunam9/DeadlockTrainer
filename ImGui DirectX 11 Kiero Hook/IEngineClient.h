#pragma once
#include "mem.h"

class IEngineClient
{
public:

	bool IsInGame()
	{
		//return MEM::CallVFunc<bool, 35U>(this);
		return MEM::CallVFunc<bool, 35, IEngineClient>(this);
	}

	bool IsConnected()
	{
		return MEM::CallVFunc<bool, 36, IEngineClient>(this);
	}

};