#include "hooks.h"

static CMaterial2* permamat;
static bool foundmat = false;

struct object_info_t {
	enum e_id : int {
		arm = 38,
		player_t = 104,
		player_ct = 113,
	};
	// todo: id var here (176 offset)
};

uint64_t matsystemasbase = MEM::GetModuleBaseAddress(MEM::GetProcessIdByName("project8.exe"), "materialsystem2.dll");

typedef CMaterial2*** (*f_findmat)(__int64 a1, __int64* a2, __int64 a3);
f_findmat findmat = nullptr;
f_findmat findmattarget = reinterpret_cast<f_findmat>(matsystemasbase + 0x2A640);

static uint64_t scenesytembase = MEM::GetModuleBaseAddress(MEM::GetProcessIdByName("project8.exe"), "scenesystem.dll");
typedef __int64(__fastcall* f_DrawModel)(
	__int64 a1,
	__int64 a2,
	CMeshData* materialdata,
	int a4,
	__int64 a5,
	__int64 a6,
	__int64 a7,
	__int64 a8);
f_DrawModel DrawModel = nullptr;
f_DrawModel DrawModelTarget = reinterpret_cast<f_DrawModel>(scenesytembase + MEM::PatternScanFunc((void*)scenesytembase, "48 8b c4 48 89 50 ? 53"));

void detourdrawmodel(__int64 a1, __int64 a2, CMeshData* material_data, int a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8) {

	//permamat = material_data->pMaterial;

	if (!Config.esp.bEsp) {
		DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);
		return;
	}

	if (!Config.esp.Chams) {
		DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);
		return;
	}

	uint64_t hOwner = material_data->pSceneAnimatableObject->hOwner;
	if (!hOwner) {
		DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);
		return;
	}


	uint64_t ownerobjindex = Helper::CHandle_get_entry_index(hOwner);
	uint64_t ownerobj = Helper::get_base_entity_from_index(ownerobjindex);
	if (!ownerobj)
		return;

	std::string objname = Helper::get_schema_name(ownerobj);

	uint64_t localpawn = Helper::GetPawn(Helper::get_local_player());
	if (!localpawn)
		return;

	if ((!localpawn) || localpawn == 0xCCCCCCCCCCCCCCCC) {
		DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);
		return;
	}

	
		

	if(objname == "C_CitadelPlayerPawn"){

		bool islocal = false;

		if (ownerobj == localpawn) {
			islocal = true;
		}


		Chams::DrawChams(material_data, islocal, ownerobj);

	}

	DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);

}

void printBinary(uint64_t num) {
	// Create a mask to check each bit
	for (int i = 63; i >= 0; --i) {
		// Print the bit at the current position
		std::cout << ((num >> i) & 1);
	}
	std::cout << std::endl; // New line after the binary output
}

//CreateMove Hook
typedef void(__fastcall* f_CreateMove)(__int64* a1, int a2, char a3);
static f_CreateMove CreateMove = nullptr;
static f_CreateMove CreateMoveTarget = reinterpret_cast<f_CreateMove>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "85 D2 0F 85 ? ? ? ? 48 8B C4 44 88 40"));

Drawing drawtest;

void detourCreateMove(__int64* a1, int a2, char a3) {

	CreateMove(a1, a2, a3);
	CCitadelUserCmdPB* cmd = Helper::GetCurrentUserCmd();

	if (!cmd->pBaseUserCMD->playerViewAngle || !cmd->cameraViewAngle)
		return;

	vec3 old_viewangles = cmd->cameraViewAngle->viewAngles;
	vec3 old_playerviewangles = cmd->pBaseUserCMD->playerViewAngle->viewAngles;
	float old_forwardmove = cmd->pBaseUserCMD->forwardMove;
	float old_sidemove = cmd->pBaseUserCMD->sideMove;

	if (!cmd || !cmd->commandNumber) {
		return CreateMove(a1, a2, a3);
	}

	uint64_t localplayercontroller = Helper::get_local_player();
	PlayerData LocalPlayer;
	Helper::get_player_data(localplayercontroller, &LocalPlayer);
	uint64_t playerpawn = Helper::GetPawn(localplayercontroller);

	if (Config.aimbot.bAimbot) {
		Aimbot::RunAimbot(cmd);
	}

	if (Config.antiaim.bAntiAim) {
		AntiAim::DoAntiAim(cmd);
	}


	ShivLogic shiv;
	VindictaLogic vindicta;

	if (Config.aimbot.bAimbot) {
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

	if (Config.aimbot.MovementFix) {
		Helper::CorrectMovement(cmd, old_forwardmove, old_sidemove, old_viewangles);
		Helper::CorrectViewAngles(cmd);
	}
	if (Config.misc.SpeedBoost) {
		Misc::SpeedBoost(localplayercontroller);
	}

	return;
}

class CViewRender
{
public:
	char pad_0000[1256]; //0x0000
	float Fov; //0x04E8
	char pad_04EC[60]; //0x04EC
	float AspectRatio; //0x0528
	char pad_052C[0x70];
	BYTE nSomeFlags;
};
//RenderStart Hook
typedef void(__fastcall* f_render)(CViewRender* pViewRender);
f_render RenderStart = nullptr;
f_render RenderStartTarget = reinterpret_cast<f_render>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "48 8b c4 53 55 56 57 41 55"));

void __fastcall hkRenderStart(CViewRender* pViewRender)
{
	RenderStart(pViewRender);
	pViewRender->Fov *= Config.misc.fovmodifier;
	pViewRender->nSomeFlags |= 2;

}


CMaterial2*** __fastcall hkFindMat(__int64 a1, __int64* a2, __int64 a3)
{
	if (foundmat) {
		return findmat(a1, a2, a3);
	}
	std::cout << "findmat called\n";
	auto result = findmat(a1, a2, a3);
	permamat = **result;
	foundmat = true;
	return result;
}

using fnSetMaterialFunction = void(__fastcall*)(unsigned __int64* a1, int* functionvar, __int64 value, unsigned __int8 a4);

static auto oSetMaterialFunction = reinterpret_cast<fnSetMaterialFunction>(particlesdllbase + MEM::PatternScanFunc((void*)particlesdllbase, "48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 54 41 56 41 57 48 83 EC ? 0F B6 01 45 0F B6 F9 8B 2A 48 8B F9"));
fnSetMaterialFunction SetMaterial = nullptr;

void hkSetMaterial(unsigned __int64* a1,int* a2, __int64 a3, unsigned __int8 a4 ) {

	std::cout << "SetMaterialVar Called \n";
	SetMaterial(a1, a2, a3, a4);
}

using fnPotential = void(__fastcall*)(__int64 a1, __int64 a2, __int64* a3);
static auto PotentialTarget = reinterpret_cast<fnPotential>(matsystemasbase + 0x6EE0);
fnPotential ogPotential = nullptr;

void hkpotential(__int64 a1, __int64 a2, __int64* a3){

	std::cout << "Potential " << std::endl;
	ogPotential(a1, a2, a3);
	
}


using fnGetParams = __int64(__fastcall*)(__int64 firstparam, const char* param);
static auto ParamTarget = reinterpret_cast<fnPotential>(matsystemasbase + 0x6EE0);
fnGetParams ogFindParams = nullptr;

__int64 __fastcall hkFindParam(__int64 firstparam, const char* param) {


	std::cout << "FINDPARAMS CALLED\n";


	return ogFindParams(firstparam, param);
}


using fnUpdateSceneObject = void(__fastcall*)(C_AggregateSceneObject* object, void* unk);
fnUpdateSceneObject UpdateSceneObjectTarget = reinterpret_cast<fnUpdateSceneObject>(scenesytembase + MEM::PatternScanFunc((void*)scenesytembase, "48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 54 41 56 41 57 48 83 EC ? 4C 8B F9"));
fnUpdateSceneObject ogUpdateSceneObject = nullptr;

void __fastcall hkUpdateSceneObject(C_AggregateSceneObject* object, void* unk)
{
	ogUpdateSceneObject(object, unk);
	return;


	__try {
		// First validate object pointer
		if (!object || (uintptr_t)object < 0x10000) {
			return;
		}

		// Read count first and validate before anything else
		int count = 0;
		__try {
			count = object->m_nCount;
			// Validate count is reasonable (assuming no object should have more than 1000 elements)
			if (count <= 0 || count > 1000) {
				return;
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return;  // Exit if we can't even read the count
		}

		// Now check data pointer
		void* dataPtr = nullptr;
		__try {
			dataPtr = object->m_Pdata;
			if (!dataPtr || (uintptr_t)dataPtr < 0x10000) {
				return;
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
			return;  // Exit if we can't read the data pointer
		}

		// Call original function
		ogUpdateSceneObject(object, unk);

		// Validate again after original function
		if (object->m_nCount != count || object->m_Pdata != dataPtr) {
			return;  // Data changed during update, abort
		}

		// Now try to modify only objects with count == 1 first
		// This helps us identify if the issue is with multi-element objects
		if (count == 1) {
			__try {
				// Test read access first
				volatile BYTE testRead = object->m_Pdata[0].r;

				// If read succeeded, try write
				object->m_Pdata[0].r = 255;
				object->m_Pdata[0].g = 255;
				object->m_Pdata[0].b = 255;
			}
			__except (EXCEPTION_EXECUTE_HANDLER) {
				// Silent fail - we've validated what we can
				return;
			}
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {
		return;
	}
}


using fnLightSceneObject = void(__fastcall*)(void* ptr, C_SceneLightObject* object, void* unk);
fnLightSceneObject LightSceneTarget = reinterpret_cast<fnLightSceneObject>(scenesytembase + MEM::PatternScanFunc((void*)scenesytembase, "48 89 54 24 ? 53 41 56 41 57"));
fnLightSceneObject ogLightScene = nullptr;

void __fastcall hkLightSceneObject(void* ptr, C_SceneLightObject * object, void* unk)
{

	ogLightScene(ptr, object, unk);

		object->r = 0.0f;
		object->g = 0.0f;
		object->b = 0.0f;


}

enum ModelType_t : int
{
	MODEL_SUN,
	MODEL_CLOUDS,
	MODEL_EFFECTS,
	MODEL_OTHER,
};


using fnDrawSceneObject = void(__fastcall*)(void* ptr, void* a2, CBaseSceneData* scene_data, int count, int a5, void* a6, void* a7, void* a8);
fnDrawSceneObject DrawSceneObjectTarget = reinterpret_cast<fnDrawSceneObject>(scenesytembase + MEM::PatternScanFunc((void*)scenesytembase, "48 89 54 24 ? 53 41 56 41 57"));
fnDrawSceneObject ogDrawSceneObject = nullptr;


void hkDrawSceneObject(void* ptr, void* a2, CBaseSceneData* scene_data, int count, int a5, void* a6, void* a7, void* a8)
{

	ogDrawSceneObject(ptr, a2, scene_data, count, a5, a6, a7, a8);
	return;

		for (int i = 0; i < count; ++i)
		{
			auto scene_ptr = &scene_data[i];
			if (scene_ptr)
			{
				scene_ptr->r = 0;
				scene_ptr->g = 0;
				scene_ptr->b = 0;
				scene_ptr->a = 0;
			}
		}


	ogDrawSceneObject(ptr, a2, scene_data, count, a5, a6, a7, a8);
}



void CreateHooks() {

	static bool init = false;
	if (init)
		return;


	MH_CreateHook((LPVOID)CreateMoveTarget, &detourCreateMove, reinterpret_cast<LPVOID*>(&CreateMove));
	MH_EnableHook((LPVOID)CreateMoveTarget);
	std::cout << "[+] CreateMove Hook Initialized!" << std::endl;
	MH_CreateHook((LPVOID)RenderStartTarget, &hkRenderStart, reinterpret_cast<LPVOID*>(&RenderStart));
	MH_EnableHook((LPVOID)RenderStartTarget);
	std::cout << "[+] RenderStart Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)DrawModelTarget, &detourdrawmodel, reinterpret_cast<LPVOID*>(&DrawModel));
	MH_EnableHook((LPVOID)DrawModelTarget);
	std::cout << "[+] DrawModel Hook Initialized!" << std::endl;

	//MH_CreateHook((LPVOID)UpdateSceneObjectTarget, &hkUpdateSceneObject, reinterpret_cast<LPVOID*>(&ogUpdateSceneObject));
	//MH_EnableHook((LPVOID)UpdateSceneObjectTarget);
	//std::cout << "[+] UpdateSceneObject Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)LightSceneTarget, &hkLightSceneObject, reinterpret_cast<LPVOID*>(&ogLightScene));
	MH_EnableHook((LPVOID)LightSceneTarget);
	std::cout << "[+] LightScene Hook Initialized!" << std::endl;

	//MH_CreateHook((LPVOID)DrawSceneObjectTarget, &hkDrawSceneObject, reinterpret_cast<LPVOID*>(&ogDrawSceneObject));
	//MH_EnableHook((LPVOID)DrawSceneObjectTarget);
	//std::cout << "[+] DrawSceneObject Hook Initialized!" << std::endl;

	//MH_CreateHook((LPVOID)ParamTarget, &hkFindParam, reinterpret_cast<LPVOID*>(&ogFindParams));
	//MH_EnableHook((LPVOID)ParamTarget);
	//std::cout << "[+] FindParams Hook Initialized!" << std::endl;


	//MH_CreateHook((LPVOID)findmattarget, &hkFindMat, reinterpret_cast<LPVOID*>(&findmat));
    //MH_EnableHook((LPVOID)findmattarget);
	//std::cout << "[+] Findmat Hook Initialized!" << std::endl;

	//MH_CreateHook((LPVOID)oSetMaterialFunction, &hkSetMaterial, reinterpret_cast<LPVOID*>(&SetMaterial));
	//MH_EnableHook((LPVOID)oSetMaterialFunction);
	//std::cout << "[+] SetMat Hook Initialized!" << std::endl;




	init = true;
}