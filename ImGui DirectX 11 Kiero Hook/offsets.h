#pragma once
#include "Windows.h"


const extern class Offsets {

	public:
		static const uint64_t o_LocalPlayerController = 0x217c108;
		static const uint64_t o_ViewMatrix = 0x218e000;
		static const uint64_t o_EntityList = 0x1fc5460;
		static const uint64_t o_CameraManager = 0x1fe7e70;
		static const uint64_t o_crosshairposfromcameramanager = 0xAC;
		static const uint64_t o_HighestEntityIndex = 0x1520;
		static const uint64_t o_entityInfo = 0x10;
		static const uint64_t o_BoneArray = 0x80;
		static const uint64_t o_Resolution = 0x218de70;
		static const uint64_t o_fApplyRecoil = 0x379b2c;
		static const uint64_t o_fCreateMove = 0xcdc3c0;
		static const uint64_t o_fGetUserCmdArray = 0xb03d50;
		static const uint64_t o_fGetUserCmd = 0xB03CC0;
		static const uint64_t o_fGetCUserCmdBase = 0xB03F80;
		static const uint64_t o_oUserCmdArray = 0x1E32B08;
		static const uint64_t o_fRenderStart = 0x364796;
		static const uint64_t o_fEntityUnderCrosshair = 0xc63ed0;
		static const uint64_t o_dwGlobalVars = 0x1e59468;
		static const uint64_t o_ftraceShape = 0xBB8660;
		static const uint64_t o_fConstructFilter = 0x2b6a50;
		static const uint64_t o_oGameTraceManager = 0x1e3d608;
		static const uint64_t o_fGetCommandIndex = 0x11529A0;

};