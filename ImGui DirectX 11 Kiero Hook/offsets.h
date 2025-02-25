#pragma once
#include "Windows.h"
#include "mem.h"
#include "helper.h"

class offsets {

public:

	uint64_t o_LocalPlayerController;
	uint64_t o_ViewMatrix;
	uint64_t o_EntityList;
	uint64_t o_CameraManager;
	uint64_t o_crosshairposfromcameramanager = 0xAC;
	uint64_t o_HighestEntityIndex = 0x2100;
	uint64_t o_entityInfo = 0x10;
	uint64_t o_BoneArray = 0x80;
	uint64_t o_Resolution;
	uint64_t o_fApplyRecoil;
	uint64_t o_fCreateMove;
	uint64_t o_fGetUserCmdArray;
	uint64_t o_fGetUserCmd;
	uint64_t o_fGetCUserCmdBase;
	uint64_t o_oUserCmdArray;
	uint64_t o_fRenderStart;
	uint64_t o_fEntityUnderCrosshair;
	uint64_t o_dwGlobalVars;
	uint64_t o_ftraceShape;
	uint64_t o_fConstructFilter;
	uint64_t o_oGameTraceManager;
	uint64_t o_fGetCommandIndex;

	offsets();

};

extern offsets Offsets;



/*

const extern class Offsets {

	public:


		static const uint64_t o_LocalPlayerController = 0x2180308;
		static const uint64_t o_ViewMatrix = 0x2192200;
		static const uint64_t o_EntityList = 0x1fc9660;
		static const uint64_t o_CameraManager = 0x1fec070;
		static const uint64_t o_crosshairposfromcameramanager = 0xAC;
		static const uint64_t o_HighestEntityIndex = 0x1520;
		static const uint64_t o_entityInfo = 0x10;
		static const uint64_t o_BoneArray = 0x80;
		static const uint64_t o_Resolution = 0x2192070;
		static const uint64_t o_fApplyRecoil = 0x379f5c;
		static const uint64_t o_fCreateMove = 0xcdcc90;
		static const uint64_t o_fGetUserCmdArray = 0xb04620;
		static const uint64_t o_fGetUserCmd = 0xb04590;
		static const uint64_t o_fGetCUserCmdBase = 0xb04850;
		static const uint64_t o_oUserCmdArray = 0x1e36b48;
		static const uint64_t o_fRenderStart = 0x364bc6;
		static const uint64_t o_fEntityUnderCrosshair = 0xc647a0;
		static const uint64_t o_dwGlobalVars = 0x1e5d4a8;
		static const uint64_t o_ftraceShape = 0xbb8f30;
		static const uint64_t o_fConstructFilter = 0x2b6e80;
		static const uint64_t o_oGameTraceManager = 0x1e41648;
		static const uint64_t o_fGetCommandIndex = 0x1155460;

};

*/

