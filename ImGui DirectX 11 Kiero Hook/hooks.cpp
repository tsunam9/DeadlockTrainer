#include "hooks.h"
#include "mem.h"



//CreateMove Hook
typedef void(__fastcall* f_CreateMove)(__int64* a1, int a2, char a3);
f_CreateMove CreateMove = nullptr;
f_CreateMove CreateMoveTarget = reinterpret_cast<f_CreateMove>(ClientModuleBase + MEM::PatternScanFunc((void*)ClientModuleBase, "85 D2 0F 85 ? ? ? ? 48 8B C4 44 88 40"));


struct object_info_t {
	enum e_id : int {
		arm = 38,
		player_t = 104,
		player_ct = 113,
	};
	// todo: id var here (176 offset)
};

struct Color_t {
	uint8_t r, g, b, a;
};

class CSceneAnimatableObject
{
public:
	char pad[0xB8];
	uint64_t hOwner;
};

struct material_data_t {
	char pad01[0x18];
	CSceneAnimatableObject* pSceneAnimatableObject; // 0x18
	void* pMaterial; // 0x20
	char pad02[0x18];
	Color_t Color;
	char pad03[0x8];
	void* pObjectInfo; // 0x48
};

uint64_t scenesytembase = Helper::GetModuleBaseAddress(Helper::GetProcessIdByName("project8.exe"), "scenesystem.dll");
typedef __int64(__fastcall* f_DrawModel)(
	__int64 a1,
	__int64 a2,
	__int64* a3,
	int a4,
	__int64 a5,
	__int64 a6,
	__int64 a7,
	__int64 a8);
f_DrawModel DrawModel = nullptr;
f_DrawModel DrawModelTarget = reinterpret_cast<f_DrawModel>(scenesytembase + 0x49540);

void detourdrawmodel(__int64 a1, __int64 a2, __int64* a3, int a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8) {




	material_data_t* material_data = (material_data_t*)a3;
	static void* permamat = material_data->pMaterial;

	uint64_t hOwner = material_data->pSceneAnimatableObject->hOwner;
	if (!hOwner) {
		DrawModel(a1, a2, a3, a4, a5, a6, a7, a8);
		return;
	}
	uint64_t ownerobjindex = Helper::CHandle_get_entry_index(hOwner);
	uint64_t ownerobj = Helper::get_base_entity_from_index(ownerobjindex);

	uint64_t localpawn = Helper::GetPawn(Helper::get_local_player());

	if (ownerobj == localpawn) {
		DrawModel(a1, a2, a3, a4, a5, a6, a7, a8);
		return;
	}

	std::string objname = Helper::get_schema_name(ownerobj);

	if(objname == "C_CitadelPlayerPawn"){
		std::cout << "Player Found!" << std::endl;
		material_data->pMaterial = permamat;
		material_data->Color.r = 255;
		material_data->Color.g = 255;
		material_data->Color.b = 255;
		material_data->Color.a = 255;
	}


	DrawModel(a1, a2, a3, a4, a5, a6, a7, a8);

}

void printBinary(uint64_t num) {
	// Create a mask to check each bit
	for (int i = 63; i >= 0; --i) {
		// Print the bit at the current position
		std::cout << ((num >> i) & 1);
	}
	std::cout << std::endl; // New line after the binary output
}


void detourCreateMove(__int64* a1, int a2, char a3) {

	CreateMove(a1, a2, a3);
	CCitadelUserCmdPB* cmd = Helper::GetCurrentUserCmd(); 
	if (!cmd) return;
	uint64_t CameraManager = Helper::get_Camera();
	vec2 ViewAngles = *(vec2*)(CameraManager + 0x44);
	PlayerData LocalPlayer = Helper::get_player_data(Helper::get_local_player());
	uint64_t playerpawn = Helper::GetPawn(Helper::get_local_player());
	auto abilities = Helper::GetAbilities(playerpawn);


	if (Config.aimbot.bAimbot) {
		Aimbot::RunAimbot(cmd);
	}

	if (Config.antiaim.bAntiAim) {
		AntiAim::DoAntiAim(cmd);
	}

	ShivLogic shiv;
	VindictaLogic vindicta;

	switch (LocalPlayer.HeroID) {

		case Shiv:
			shiv.RunScript(cmd);
			break;
		case Vindicta:
			vindicta.RunScript(cmd);
			break;
		default:
			break;
	}



}



void CreateHooks() {

	static bool init = false;
	if (init)
		return;

	MH_CreateHook((LPVOID)CreateMoveTarget, &detourCreateMove, reinterpret_cast<LPVOID*>(&CreateMove));
	MH_EnableHook((LPVOID)CreateMoveTarget);

	//MH_CreateHook((LPVOID)DrawModelTarget, &detourdrawmodel, reinterpret_cast<LPVOID*>(&DrawModel));
	//MH_EnableHook((LPVOID)DrawModelTarget);


	init = true;
}