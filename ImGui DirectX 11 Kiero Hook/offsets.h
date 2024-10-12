#pragma once
#include "Windows.h"


const extern class Offsets {

	public:
		static const uint64_t o_LocalPlayerController = 0x217b0b8;
		static const uint64_t o_ViewMatrix = 0x218cfb0;
		static const uint64_t o_EntityList = 0x1fc4420;
		static const uint64_t o_CameraManager = 0x1fe6e20;
		static const uint64_t o_crosshairposfromcameramanager = 0xAC;
		static const uint64_t o_HighestEntityIndex = 0x1520;
		static const uint64_t o_entityInfo = 0x10;
		static const uint64_t o_BoneArray = 0x80;
		static const uint64_t o_Resolution = 0x218ce20;
		static const uint64_t o_fApplyRecoil = 0x379a5c;
		static const uint64_t o_fCreateMove = 0xcdc050;
		static const uint64_t o_fGetUserCmdArray = 0xb039e0;
		static const uint64_t o_fRenderStart = 0x363ee6;
		static const uint64_t o_dwGlobalVars = 0x1e58418;

};