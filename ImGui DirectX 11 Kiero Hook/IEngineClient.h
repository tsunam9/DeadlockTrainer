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

	void ClientCmd_Unrestricted(const char* szCmd) {
		//return :CallMethod<void>(this, 45, 0, szCmd, 0x7FFEF001);
		return MEM::CallVFunc<void, 45U, IEngineClient>(this, 0, *szCmd, false);
	}


};