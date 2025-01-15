
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

//a1 : Animatablesceneobjectdesc
//a2 : dx device
// a3 : cmeshdata
// a4 : idk
// a5 : CSceneView
// a6 : CSceneLayer
// a7 : idk
// a8 : idk

class CRenderContextBase;

void detourdrawmodel(__int64 a1, __int64 a2, CMeshData* material_data, int a4, __int64 a5, __int64 a6, __int64 a7, __int64 a8) {

	if (!(iEngine->IsInGame())) {
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

	PlayerData LocalData;
	Helper::get_player_data(Helper::get_local_player(), &LocalData);


	if(objname == "C_CitadelPlayerPawn"){

		bool islocal = false;

		if (ownerobj == localpawn) {
			DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);
			return;
		}

		std::string matname = material_data->pMaterial->GetName();

		if (matname.find("glow") != std::string::npos) {
			return;
		}

		Chams::DrawChams(material_data, islocal, ownerobj, false);

		DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);

		return;
	}
	if (objname == "C_NPC_Trooper") {

		if (!cfg::esp_DrawMinions) {
			DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);
			return;
		}

		NpcData EntInfo;
		Helper::get_npc_data(ownerobj, &EntInfo);

		uint64_t entteamnum = 263168 + LocalData.TeamNum;
		if (EntInfo.m_iteamnum == entteamnum) {  // really awful terribleness because the number just happens to be this for minion teams
			DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);
			return;
		}

		material_data->colValue.a = 255;
		material_data->colValue.r = 255;
		material_data->colValue.g = 0;
		material_data->colValue.b = 0;

		static auto setmat = Chams::CreateMaterial("invisible", szVMatBufferWhiteInvisible);

		material_data->pMaterial = setmat;
		material_data->pMaterial2 = setmat;

		DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);

		return;

	}
	if (objname == "C_NPC_TrooperBoss") {

		if (!cfg::esp_drawTowers) {
			DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);
			return;
		}

		NpcData EntInfo;
		Helper::get_npc_data(ownerobj, &EntInfo);

		uint64_t entteamnum = 262144 + LocalData.TeamNum;
		if (EntInfo.m_iteamnum == entteamnum) {  // really awful terribleness because the number just happens to be this for minion teams
			DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);
			return;
		}

		std::string matname = material_data->pMaterial->GetName();

		material_data->colValue.a = 255;
		material_data->colValue.r = 255;
		material_data->colValue.g = 0;
		material_data->colValue.b = 0;

		static auto setmat = Chams::CreateMaterial("invisible", szVMatBufferWhiteInvisible);

		material_data->pMaterial = setmat;
		material_data->pMaterial2 = setmat;

		DrawModel(a1, a2, material_data, a4, a5, a6, a7, a8);

		return;

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

	Aimbot::RunAimbot(cmd); // always run aimbot 

	Misc::AutoActiveReload(cmd);

	if (cfg::antiaim_bAntiAim) {
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
	WraithLogic wraith;

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
		case Wraith:
			wraith.RunScript(cmd);
			break;
		default:
			break;
		}

	if (cfg::ragebot_masterswitch) {
		Helper::CorrectMovement(cmd, old_forwardmove, old_sidemove, old_viewangles);
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

}

using fnSetMaterialFunction = void(__fastcall*)(unsigned __int64* a1, int* functionvar, __int64 value, unsigned __int8 a4);

static auto oSetMaterialFunction = reinterpret_cast<fnSetMaterialFunction>(particlesdllbase + MEM::PatternScanFunc((void*)particlesdllbase, "48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 54 41 56 41 57 48 83 EC ? 0F B6 01 45 0F B6 F9 8B 2A 48 8B F9"));
fnSetMaterialFunction SetMaterial = nullptr;

void hkSetMaterial(unsigned __int64* a1,int* a2, __int64 a3, unsigned __int8 a4 ) {

	std::cout << "SetMaterialVar Called \n";
	SetMaterial(a1, a2, a3, a4);
}



using fnUpdateSceneObject = __int64(__fastcall*)(C_AggregateSceneObject* object, __int64 unk, char a3);
fnUpdateSceneObject UpdateSceneObjectTarget = reinterpret_cast<fnUpdateSceneObject>(scenesytembase + MEM::PatternScanFunc((void*)scenesytembase, "48 89 6c 24 ? 48 89 74 24 ? 44 88 44 24"));
fnUpdateSceneObject ogUpdateSceneObject = nullptr;

__int64 __fastcall hkUpdateSceneObject(C_AggregateSceneObject* object, __int64 unk, char a3)
{
	__int64 result = ogUpdateSceneObject(object, unk, a3);

	if (cfg::esp_ModWorld)
	{

		for (int i = 0; i < object->m_nCount; i++)
		{
			object->m_pData[i].r = cfg::colors_WorldModulationColor.x * 255;
			object->m_pData[i].g = cfg::colors_WorldModulationColor.y * 255;
			object->m_pData[i].b = cfg::colors_WorldModulationColor.z * 255;
			object->m_pData[i].a = cfg::colors_WorldModulationColor.w * 255;

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
	if (cfg::esp_ModLights) {
		object->r = cfg::colors_LightModColor.x;
		object->g = cfg::colors_LightModColor.y;
		object->b = cfg::colors_LightModColor.z;
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
	return cfg::menu_open ? false : ogMouseInputEnabled();
}




uint64_t engine = MEM::GetModuleBaseAddress(MEM::GetProcessIdByName("project8.exe"), "engine2.dll");
typedef __int64(__fastcall* f_ConsoleCmd)(__int64 a1, unsigned int a2, const char* a3, char a4);
static f_ConsoleCmd ogConsoleCmd = nullptr;
static f_ConsoleCmd ConsoleCmdTarget = reinterpret_cast<f_ConsoleCmd>(engine + 0x6D700); // CCitadelInput 

bool __fastcall hkConsoleCmd(__int64 a1, unsigned int a2, const char* a3, char a4)
{
	return ogConsoleCmd(a1, a2, a3, a4);
}

typedef __int64(__fastcall* f_applyglow)(__int64 CGlowProperty, CSceneAnimatableObject* glowobject);
static f_applyglow ogApplyGlow = nullptr;
static f_applyglow applyglowtarget = reinterpret_cast<f_applyglow>(MEM::GetClientBase() + 0xD395D0); // ApplyGlow 



__int64 __fastcall hkApplyGlow(__int64 CGlowProperty, CSceneAnimatableObject* glowobject)
{

	uint64_t hOwner = glowobject->hOwner;
	if(!Helper::CHandle_is_valid(hOwner))
		return ogApplyGlow(CGlowProperty, glowobject);

	int ownerindex = Helper::CHandle_get_entry_index(hOwner);
	uint64_t ownerobj = Helper::get_base_entity_from_index(ownerindex);
	auto entname = Helper::get_schema_name(ownerobj);


	if (entname == "C_CitadelPlayerPawn") {

		*(uint32_t*)(CGlowProperty + 0x50) = 1;

		PlayerData data;
		PlayerData localdata;
		uint64_t localpawn = Helper::GetPawn(Helper::get_local_player());

		Helper::get_player_data(Helper::get_local_player(), &localdata);
		Helper::getPawnData(ownerobj, &data);

		uint64_t glowhelper = *(uint64_t*)(CGlowProperty + 0x28);

		if (!glowhelper) {
			uint64_t NewGlowHelper = iSceneSystem002->CreateCHlowHelperSceneObject((uint64_t)glowobject);
			*(uint64_t*)(CGlowProperty + 0x28) = NewGlowHelper;
		}

		if (ownerobj == localpawn)
			return ogApplyGlow(CGlowProperty, glowobject);


		if (data.TeamNum == localdata.TeamNum)
			return ogApplyGlow(CGlowProperty, glowobject);

		//std::cout << std::hex << CGlowProperty << std::endl;
		*(uint32_t*)(CGlowProperty + 0x5C) = data.TeamNum;
		*(uint32_t*)(CGlowProperty + 0x30) = 3;
		*(uint64_t*)(ownerobj + C_BaseEntity::m_iTeamNum) = localdata.TeamNum;
		*(uint32_t*)(CGlowProperty + CGlowProperty::m_glowColorOverride) = 0xFFFFFF00;

	}

	return ogApplyGlow(CGlowProperty, glowobject);

}

using fn_AddGlowObject = void(__fastcall*)(__int64 GlowManager, __int64 GlowPropertyToAdd);
static auto fnAddGlowObject = reinterpret_cast<fn_AddGlowObject>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "48 85 d2 0f 84 ? ? ? ? 55 41 56 48 83 ec ? 48 89 7c 24 ? 45 33 c0 4c 89 7c 24 ? 48 8b ea 4c 63 79 ? 4c 8b f1 45 85 ff 7e ? 49 8b 46 ? 41 8b c8 48 39 28 74 ? 41 ff c0 48 ff c1 48 83 c0 ? 49 3b cf 7c ? eb ? 41 83 f8 ? 0f 85 ? ? ? ? 45 3b 7e ? 0f 85 ? ? ? ? 41 f7 46 ? ? ? ? ? 0f 85 ? ? ? ? 41 8b 4e ? 48 89 5c 24 ? 48 89 74 24 ? 81 f9 ? ? ? ? 7e ? ba ? ? ? ? ff 15 ? ? ? ? 41 8b 4e ? 41 b9 ? ? ? ? 41 8b 56 ? 81 e2 ? ? ? ? 8d 71 ? 44 8b c6 ff 15 ? ? ? ? 8b d8 3b c6 7d ? 85 c0 75 ? 83 fe ? 7f ? 8d 58 ? eb ? 8d 04 33 99 2b c2 d1 f8 8b d8 3b c6 7c ? 4d 63 4e ? 49 8b 4e ? 49 c1 e1 ? 41 f7 46 ? ? ? ? ? 4c 63 c3 0f 94 c2 49 c1 e0 ? ff 15 ? ? ? ? 48 8b 74 24 ? 49 89 46 ? 41 8b 46 ? a9 ? ? ? ? 74 ? 25 ? ? ? ? 41 89 46 ? 41 89 5e ? 48 8b 5c 24 ? 41 ff 46 ? 49 8b 46 ? 4a 89 2c f8 48 8b 7c 24 ? 4c 8b 7c 24 ? 48 83 c4 ? 41 5e 5d c3 cc cc cc cc cc cc cc cc cc cc 48 89 5c 24"));


typedef void(__fastcall* f_doglow)(__int64 a1);
static f_doglow ogdoglow = nullptr;
static f_doglow doglowtarget = reinterpret_cast<f_doglow>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "41 57 48 83 ec ? 83 79 ? ? 4c 8b f9")); // actual doglow

void __fastcall hkDoGlow(__int64 a1) {

	if ((!cfg::esp_eGlowEsp && !cfg::esp_tGlowEsp ) || !cfg::esp_bEsp)
		return;


	std::vector<uint64_t> Controllers;
	std::vector<uint32_t> teamnums;

	PlayerData localdata;
	Helper::get_player_data(Helper::get_local_player(), &localdata);

	int max_ents = Helper::get_max_entities();
	if (!(max_ents >= 0))
		return;
	for (size_t i = 1; i <= static_cast<size_t>(max_ents); ++i) {
		uint64_t entity = Helper::get_base_entity_from_index(i);

		if (!entity)
			continue;

		std::string EntName = Helper::get_schema_name(entity);

		if (EntName == "CCitadelPlayerController" && !*(bool*)(entity + CBasePlayerController::m_bIsLocalPlayerController)) {
			PlayerData entdata;
			Helper::get_player_data(entity, &entdata);

			if (entdata.TeamNum != localdata.TeamNum) {
				teamnums.push_back(entdata.TeamNum);
				Controllers.push_back(entity);
			}
			else if (cfg::esp_tGlowEsp) {
				teamnums.push_back(entdata.TeamNum);
				Controllers.push_back(entity);
			}
		}
	}

	for (int i = 0; i < Controllers.size(); i++) {

		uint64_t pawn = Helper::GetPawn(Controllers[i]);

		if (!pawn)
			continue;

		uint64_t glowProperty = pawn + C_BaseModelEntity::m_Glow; 


		uint64_t glowhelper = *(uint64_t*)(glowProperty + 0x28);

		if (!glowhelper) {
			if (teamnums[i] == localdata.TeamNum) {
				if (!(cfg::colors_tGlowCol.w == 0.f)) {
					*(uint64_t*)(glowProperty + 0x28) = iSceneSystem002->CreateCHlowHelperSceneObject((uint64_t)pawn);
				}
			}
			else {
				if (!(cfg::colors_eGlowCol.w == 0.f)) {
					*(uint64_t*)(glowProperty + 0x28) = iSceneSystem002->CreateCHlowHelperSceneObject((uint64_t)pawn);
				}
			}
		}

		*(uint32_t*)(glowProperty + CGlowProperty::m_bGlowing) = 1; 
		*(uint32_t*)(glowProperty + CGlowProperty::m_iGlowType) = 3;


		if (teamnums[i] != localdata.TeamNum) {
			*(uint8_t*)(glowProperty + CGlowProperty::m_glowColorOverride) = cfg::colors_eGlowCol.x* 255;     // Red
			*(uint8_t*)(glowProperty + CGlowProperty::m_glowColorOverride + 1) = cfg::colors_eGlowCol.y * 255; // Green
			*(uint8_t*)(glowProperty + CGlowProperty::m_glowColorOverride + 2) = cfg::colors_eGlowCol.z * 255; // Blue
			*(uint8_t*)(glowProperty + CGlowProperty::m_glowColorOverride + 3) = cfg::colors_eGlowCol.w * 255; // Alpha
		}
		else {
			*(uint8_t*)(glowProperty + CGlowProperty::m_glowColorOverride) = cfg::colors_tGlowCol.x * 255;     // Red
			*(uint8_t*)(glowProperty + CGlowProperty::m_glowColorOverride + 1) = cfg::colors_tGlowCol.y * 255;  // Green
			*(uint8_t*)(glowProperty + CGlowProperty::m_glowColorOverride + 2) = cfg::colors_tGlowCol.z * 255;  // Blue
			*(uint8_t*)(glowProperty + CGlowProperty::m_glowColorOverride + 3) = cfg::colors_tGlowCol.w * 255;  // Alpha
		}


		

		fnAddGlowObject(a1, glowProperty);

	}

	ogdoglow(a1);

}

typedef __int64(__fastcall* applyglowcaller)(__int64 a1, __int64 a2, __int64 a3, int a4);
static applyglowcaller ogapplycaller = nullptr;
static applyglowcaller applycallertarget = reinterpret_cast<applyglowcaller>(MEM::GetClientBase() + 0x62D2C0); // calls applyglow

__int64 __fastcall hkApplyGlowCaller(__int64 a1, __int64 a2, __int64 a3, int a4) {

	return ogapplycaller(a1, a2, a3, a4);

}

typedef __int64(__fastcall* verifyGlowObject)(__int64 a1, int a2, float a3);
static verifyGlowObject ogverifyglowobject = nullptr;
static verifyGlowObject verifyglowobjecttarget = reinterpret_cast<verifyGlowObject>(MEM::GetClientBase() + 0xD80EC0); // calls applyglow

__int64 __fastcall hkVerifyGlowObject(__int64 a1, int a2, float a3) {

	uint32_t oldMode = *(uint32_t*)(a1 + 0x30);

	__int64 result = ogverifyglowobject(a1, a2, a3);

	if (*(uint32_t*)(a1 + 0x30) != oldMode) {
		*(uint32_t*)(a1 + 0x30) = oldMode;
	}

	return result;
}





void CreateHooks() {

	static bool init = false;
	if (init)
		return;

	MH_CreateHook((LPVOID)CreateMoveTarget, &detourCreateMove, reinterpret_cast<LPVOID*>(&CreateMove));
	MH_EnableHook((LPVOID)CreateMoveTarget);
	//std::cout << "[+] CreateMove Hook Initialized!" << std::endl;
	MH_CreateHook((LPVOID)RenderStartTarget, &hkRenderStart, reinterpret_cast<LPVOID*>(&RenderStart));
	MH_EnableHook((LPVOID)RenderStartTarget);
	//std::cout << "[+] RenderStart Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)DrawModelTarget, &detourdrawmodel, reinterpret_cast<LPVOID*>(&DrawModel));
	MH_EnableHook((LPVOID)DrawModelTarget);
	//std::cout << "[+] DrawModel Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)UpdateSceneObjectTarget, &hkUpdateSceneObject, reinterpret_cast<LPVOID*>(&ogUpdateSceneObject));
	MH_EnableHook((LPVOID)UpdateSceneObjectTarget);

	MH_CreateHook((LPVOID)LightSceneTarget, &hkLightSceneObject, reinterpret_cast<LPVOID*>(&ogLightScene));
	MH_EnableHook((LPVOID)LightSceneTarget);
	//std::cout << "[+] LightScene Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)createBulletTarget, &khCreateBullet, reinterpret_cast<LPVOID*>(&ogCreateBullet));
	MH_EnableHook((LPVOID)createBulletTarget);
	//std::cout << "[+] CreateBullet Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)LevelInitTarget, &hkLevelInit, reinterpret_cast<LPVOID*>(&ogLevelInit));
	MH_EnableHook((LPVOID)LevelInitTarget);
	//std::cout << "[+] LevelInit Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)levelshutdowntarget, &hkLevelShutdown, reinterpret_cast<LPVOID*>(&oglevelshutdown));
	MH_EnableHook((LPVOID)levelshutdowntarget);
	//std::cout << "[+] LevelShutdown Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)MouseInputEnabledTarget, &hkMouseInputEnabled, reinterpret_cast<LPVOID*>(&ogMouseInputEnabled));
	MH_EnableHook((LPVOID)MouseInputEnabledTarget);
	//std::cout << "[+] MouseInputEnabled Hook Initialized!" << std::endl;

	MH_CreateHook((LPVOID)doglowtarget, &hkDoGlow, reinterpret_cast<LPVOID*>(&ogdoglow));
	MH_EnableHook((LPVOID)doglowtarget);
	//std::cout << "[+] DoGlow Hook Initialized!" << std::endl;


	// Set the new window procedure




	init = true;
}

