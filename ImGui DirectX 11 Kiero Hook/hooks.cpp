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

unsigned long long createMask(const std::string& bitString) {
	unsigned long long mask = 0;
	for (int i = bitString.length() - 1, shift = 0; i >= 0; --i, ++shift) {
		if (bitString[i] == '1') {
			mask |= 1ULL << shift;  // Use 1ULL to ensure 64-bit shifting
		}
	}
	return mask;
}

//CreateMove Hook
typedef void(__fastcall* f_CreateMove)(__int64* a1, int a2, char a3);
static f_CreateMove CreateMove = nullptr;
static f_CreateMove CreateMoveTarget = reinterpret_cast<f_CreateMove>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "85 D2 0F 85 ? ? ? ? 48 8B C4 44 88 40"));


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
	BebopLogic bebop;
	HazeLogic haze;
	InfernusLogic infernus;
	IvyLogic ivy;
	KelvinLogic kelvin;
	LadyGeistLogic ladygeist;
	MirageLogic mirage;
	ParadoxLogic paradox;
	PocketLogic pocket;
	SevenLogic seven;
	ViscousLogic viscous;
	WardenLogic warden;
	YamatoLogic yamato;

	if (Config.aimbot.bAimbot) {
		switch (LocalPlayer.HeroID) {

		case Shiv:
			shiv.RunScript(cmd);
			break;
		case Vindicta:
			vindicta.RunScript(cmd);
			break;
		case Bebop:
			bebop.RunScript(cmd);
			break;
		case Haze:
			haze.RunScript(cmd);
			break;
		case Infernus:
			infernus.RunScript(cmd);
			break;
		case Ivy:
			ivy.RunScript(cmd);
			break;
		case Kelvin:
			kelvin.RunScript(cmd);
			break;
		case LadyGeist:
			ladygeist.RunScript(cmd);
			break;
		case Mirage:
			mirage.RunScript(cmd);
			break;
		case Paradox:
			paradox.RunScript(cmd);
			break;
		case Pocket:
			pocket.RunScript(cmd);
			break;
		case Seven:
			seven.RunScript(cmd);
			break;
		case Viscous:
			viscous.RunScript(cmd);
			break;
		case Warden:
			warden.RunScript(cmd);
			break;
		case Yamato:
			yamato.RunScript(cmd);
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

	if (Config.MenuOpen) { // prevent anything except movement while menu open

		static std::string bitString ="0000001000000001000000000000000000000000000000000000011000011100";
		unsigned long long mask = createMask(bitString);
		cmd->buttons = cmd->buttons & mask;
		cmd->pBaseUserCMD->CInButtonStatePB->buttons = cmd->pBaseUserCMD->CInButtonStatePB->buttons & mask;
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


using fnUpdateSceneObject = __int64(__fastcall*)(C_AggregateSceneObject* object, __int64 unk);
fnUpdateSceneObject UpdateSceneObjectTarget = reinterpret_cast<fnUpdateSceneObject>(scenesytembase + MEM::PatternScanFunc((void*)scenesytembase, "48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 54 41 56 41 57 48 83 EC ? 4C 8B F9"));
fnUpdateSceneObject ogUpdateSceneObject = nullptr;

__int64 __fastcall hkUpdateSceneObject(C_AggregateSceneObject* object, __int64 unk)
{
	__int64 result = ogUpdateSceneObject(object, unk);

	if (Config.esp.ModWorld)
	{

		for (int i = 0; i < object->m_nCount; i++)
		{
			object->m_pData[i].r = Config.colors.WorldModulationColor.x * 255;
			object->m_pData[i].g = Config.colors.WorldModulationColor.y * 255;
			object->m_pData[i].b = Config.colors.WorldModulationColor.z * 255;
			object->m_pData[i].a = Config.colors.WorldModulationColor.w * 255;

		}
	}

	return result;
}



using fnLightSceneObject = void(__fastcall*)(void* ptr, C_SceneLightObject* object, void* unk);
fnLightSceneObject LightSceneTarget = reinterpret_cast<fnLightSceneObject>(scenesytembase + MEM::PatternScanFunc((void*)scenesytembase, "48 89 54 24 ? 53 41 56 41 57"));
fnLightSceneObject ogLightScene = nullptr;

void __fastcall hkLightSceneObject(void* ptr, C_SceneLightObject * object, void* unk)
{

	ogLightScene(ptr, object, unk);

	if (Config.esp.ModLights) {
		object->r = Config.colors.LightModColor.x;
		object->g = Config.colors.LightModColor.y;
		object->b = Config.colors.LightModColor.z;
	}

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


//CreateMove Hook
typedef float(__fastcall* f_getBulletSpeed)(__int64 a1, __int64 a2);
static f_getBulletSpeed ogGetBulletSpeed = nullptr;
static f_getBulletSpeed GetBulletSpeedTarget = reinterpret_cast<f_getBulletSpeed>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "48 89 5c 24 ? 57 48 81 ec ? ? ? ? 48 8b f9 0f 29 74 24 ? 48 8b 49"));

float hkGetBulletSpeed(__int64 a1, __int64 a2) {

	float speed = ogGetBulletSpeed(a1, a2);
	return speed;

}


typedef __int64(__fastcall* f_createBullet)(__int64 a1, __int64 a2);
static f_createBullet ogCreateBullet = nullptr;
static f_createBullet createBulletTarget = reinterpret_cast<f_createBullet>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "48 89 5c 24 ? 48 89 74 24 ? 57 48 83 ec ? 48 8b fa 48 8b f1 0f b6 92"));

__int64 khCreateBullet(__int64 a1, __int64 a2) {

	auto result = ogCreateBullet(a1, a2);

	if (*(BYTE*)(a2 + 196)) {
		auto BulletArray = *(uint64_t*)(a1 + 40);
		auto LocalBulletsInAir = *(int*)(a1 + 32);
		Bullet* latestbullet = *(Bullet**)(BulletArray + 8ull * (LocalBulletsInAir - 1));
		globals::instance().BulletVelocity = latestbullet->flatVelocity;
	}
	return result;
}

typedef __int64(__fastcall* f_levelinit)(__int64 a1, __int64 a2);
static f_levelinit ogLevelInit = nullptr;
static f_levelinit LevelInitTarget = reinterpret_cast<f_levelinit>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "48 89 5c 24 ? 56 48 83 ec ? 48 8b 0d ? ? ? ? 48 8b f2"));

__int64 hkLevelInit(__int64 a1, __int64 a2) {
	uint64_t globalsoffset = MEM::PatternScanOffset((void*)ClientModuleBase, "48 8B 05 ? ? ? ? 44 3B 40", 3, 7);
	globals::instance().Globals = *(CGlobalVarsBase**)(ClientModuleBase + globalsoffset);
	return ogLevelInit(a1, a2);
}

typedef __int64(__fastcall* f_levelshutdown)();
static f_levelshutdown oglevelshutdown = nullptr;
static f_levelshutdown levelshutdowntarget = reinterpret_cast<f_levelshutdown>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "48 83 ec ? 48 8b 0d ? ? ? ? 48 8d 15 ? ? ? ? 45 33 c9 45 33 c0 48 8b 01 ff 50 ? 48 85 c0 74 ? 48 8b 0d ? ? ? ? 48 8b d0 4c 8b 01 41 ff 50"));

__int64 hkLevelShutdown(){
	globals::instance().Globals = nullptr;
	return oglevelshutdown();
}

typedef __int64(__fastcall* f_MouseInputEnabled)();
static f_MouseInputEnabled ogMouseInputEnabled = nullptr;
static f_MouseInputEnabled MouseInputEnabledTarget = reinterpret_cast<f_MouseInputEnabled>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "48 83 ec ? e8 ? ? ? ? 84 c0 0f 85")); // CCitadelInput 

bool __fastcall hkMouseInputEnabled()
{
	return Config.MenuOpen ? false : ogMouseInputEnabled();
}




uint64_t engine = MEM::GetModuleBaseAddress(MEM::GetProcessIdByName("project8.exe"), "engine2.dll");
typedef __int64(__fastcall* f_ConsoleCmd)(__int64 a1, unsigned int a2, const char* a3, char a4);
static f_ConsoleCmd ogConsoleCmd = nullptr;
static f_ConsoleCmd ConsoleCmdTarget = reinterpret_cast<f_ConsoleCmd>(engine + 0x6D700); // CCitadelInput 

bool __fastcall hkConsoleCmd(__int64 a1, unsigned int a2, const char* a3, char a4)
{
	return ogConsoleCmd(a1, a2, a3, a4);
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

	MH_CreateHook((LPVOID)UpdateSceneObjectTarget, &hkUpdateSceneObject, reinterpret_cast<LPVOID*>(&ogUpdateSceneObject));
	MH_EnableHook((LPVOID)UpdateSceneObjectTarget);
	std::cout << "[+] UpdateSceneObject Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)LightSceneTarget, &hkLightSceneObject, reinterpret_cast<LPVOID*>(&ogLightScene));
	MH_EnableHook((LPVOID)LightSceneTarget);
	std::cout << "[+] LightScene Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)createBulletTarget, &khCreateBullet, reinterpret_cast<LPVOID*>(&ogCreateBullet));
	MH_EnableHook((LPVOID)createBulletTarget);
	std::cout << "[+] CreateBullet Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)LevelInitTarget, &hkLevelInit, reinterpret_cast<LPVOID*>(&ogLevelInit));
	MH_EnableHook((LPVOID)LevelInitTarget);
	std::cout << "[+] LevelInit Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)levelshutdowntarget, &hkLevelShutdown, reinterpret_cast<LPVOID*>(&oglevelshutdown));
	MH_EnableHook((LPVOID)levelshutdowntarget);
	std::cout << "[+] LevelShutdown Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)MouseInputEnabledTarget, &hkMouseInputEnabled, reinterpret_cast<LPVOID*>(&ogMouseInputEnabled));
	MH_EnableHook((LPVOID)MouseInputEnabledTarget);
	std::cout << "[+] MouseInputEnabled Hook Initialized!" << std::endl;

	//MH_CreateHook((LPVOID)ConsoleCmdTarget, &hkConsoleCmd, reinterpret_cast<LPVOID*>(&ogConsoleCmd));
	//MH_EnableHook((LPVOID)ConsoleCmdTarget);
	//std::cout << "[+] ConsoleCmd Hook Initialized!" << std::endl;


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