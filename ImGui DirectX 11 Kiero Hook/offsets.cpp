#include "offsets.h"

offsets::offsets() {

	static int timescalled = 0;

	if (timescalled > 0) {
		std::cout << "EMERGENCY" << std::endl;
	}

	timescalled++;

	static void* clientdll = (void*)MEM::GetClientBase();

	o_LocalPlayerController = MEM::PatternScanOffset(clientdll, "48 8B 0D ? ? ? ? 48 85 C9 74 65 83 FF FF", 3, 7);
	o_ViewMatrix = MEM::PatternScanOffset(clientdll, "48 8D ? ? ? ? ? 48 C1 E0 06 48 03 C1 C3", 3, 7);
	o_EntityList = MEM::PatternScanOffset(clientdll, "48 8B 0D ? ? ? ? 8B C5 48 C1 E8", 3, 7);
	o_CameraManager = MEM::PatternScanOffset(clientdll, "48 8D 3D ? ? ? ? 8B D9", 3, 7);
	o_Resolution = MEM::PatternScanOffset(clientdll, "48 8B 0D ? ? ? ? 48 8B 01 FF 50 ? E8 ? ? ? ? 40 0F B6 CE", 3, 7);
	o_fApplyRecoil = MEM::PatternScanFunc(clientdll, "f2 41 0f 11 07 8b 40 ? eb");
	o_fCreateMove = MEM::PatternScanFunc(clientdll, "85 D2 0F 85 ? ? ? ? 48 8B C4 44 88 40");
	o_fGetUserCmdArray = MEM::PatternScanFunc(clientdll, "41 54 41 57 48 83 EC ? 48 8D 54 24");
	o_fRenderStart = MEM::PatternScanFunc(clientdll, "48 8b 05 ? ? ? ? 48 8d 0d ? ? ? ? 48 8b da");
	o_fEntityUnderCrosshair = MEM::PatternScanFunc(clientdll, "48 89 5c 24 ? 57 48 81 ec ? ? ? ? 33 ff 8b cf");
	o_dwGlobalVars = MEM::PatternScanOffset(clientdll, "48 8B 05 ? ? ? ? 44 3B 40", 3, 7);
	o_fConstructFilter = MEM::PatternScanFunc(clientdll, "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC 20 0F B6 41 37 33 F6 24 C9 C6 41 36 03");
	o_oGameTraceManager = MEM::PatternScanOffset(clientdll, "48 8b 0d ? ? ? ? 48 8b 09 48 8b 11 ff 92", 3, 7);
	o_fGetCommandIndex = MEM::PatternScanFunc(clientdll, "40 53 48 83 ec ? 4c 8b 41 ? 48 8b da 48 8b 0d");
	o_fGetCUserCmdBase = MEM::PatternScanFunc(clientdll, "48 89 4c 24 ? 41 54 41 57");
	o_fGetUserCmd = MEM::PatternScanFunc(clientdll, "40 53 48 83 ec ? 8b da 85 d2 78");
	o_oUserCmdArray = MEM::PatternScanOffset(clientdll, "48 8b 0d ? ? ? ? e8 ? ? ? ? 48 8b cf 4c 8b e8", 3, 7);
	o_ftraceShape = MEM::PatternScanFunc(clientdll, "48 89 5c 24 ? 48 89 4c 24 ? 55 56 41 55");
};


