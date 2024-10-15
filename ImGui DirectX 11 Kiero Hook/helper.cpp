#pragma once
#include "helper.h"
#include "imgui/imgui.h"
using namespace cs2_dumper::schemas::client_dll;

#define M_PI 3.14159265358979323846


std::string Helper::ReadString(uintptr_t address) {
	std::string str;
	char c;
	do {
		c = *(char*)address;
		str += c;
		address++;
	} while (c != '\0');
	return str;
}

uint64_t Helper::GetModuleBaseAddress(uint64_t procId, const char* modName) {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	MODULEENTRY32 modEntry;
	modEntry.dwSize = sizeof(modEntry);

	do {
		if (!strcmp(modEntry.szModule, modName)) {
			CloseHandle(hSnap);
			return (uint64_t)modEntry.modBaseAddr;
		}
	} while (Module32Next(hSnap, &modEntry));

	CloseHandle(hSnap);
	return 0;
}

uint64_t Helper::GetProcessIdByName(const char* processname) {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 procEntry;
	procEntry.dwSize = sizeof(procEntry);

	do {
		if (!strcmp(procEntry.szExeFile, processname)) {
			CloseHandle(hSnap);
			return procEntry.th32ProcessID;
		}
	} while (Process32Next(hSnap, &procEntry));

	CloseHandle(hSnap);
	return 0;
}

uint64_t Helper::get_entity_list(){
	uintptr_t tf = *(uintptr_t*)(ClientModuleBase + Offsets::o_EntityList);
	return static_cast<uint64_t>(tf);
}

uint64_t Helper::GetClientBase() {
	uint64_t Modulebaseaddress = Helper::GetModuleBaseAddress(Helper::GetProcessIdByName("project8.exe"), "client.dll");
	return Modulebaseaddress;
}

std::string Helper::readstr(uintptr_t address){
	std::string str;
	char c;
	do {
		c = *(char*)address;
		str += c;
		address++;
	} while (c != '\0');
	return str;
}

int Helper::get_max_entities()
{
	uint64_t entity_list = Helper::get_entity_list();
	int max_entities = *(int*)(entity_list + Offsets::o_HighestEntityIndex);
	return max_entities;
}

uint64_t Helper::get_Camera() {


	//camera = pm.read_longlong(client_base + 0x1f450b0 + 0x28)
	uint64_t camera = (ClientModuleBase + Offsets::o_CameraManager + 0x28);
	camera = *(uint64_t*)camera;
	return camera;
}

uint64_t Helper::get_local_player() {
	uint64_t local_player = *(uint64_t*)(ClientModuleBase + Offsets::o_LocalPlayerController);
	return local_player;
}

//DirectX 11 WorldToScreen
bool Helper::WorldToScreen(vec3 pos, vec2& screen) {

	vec2 resolution = Helper::GetResolution();
	uintptr_t ViewMatrix = (ClientModuleBase + Offsets::o_ViewMatrix);
	ViewMatrixObj matrix = *(ViewMatrixObj*)ViewMatrix;
	

	vec4 clipCoords;
	clipCoords.x = pos.x * matrix.matrix[0] + pos.y * matrix.matrix[1] + pos.z * matrix.matrix[2] + matrix.matrix[3];
	clipCoords.y = pos.x * matrix.matrix[4] + pos.y * matrix.matrix[5] + pos.z * matrix.matrix[6] + matrix.matrix[7];
	clipCoords.z = pos.x * matrix.matrix[8] + pos.y * matrix.matrix[9] + pos.z * matrix.matrix[10] + matrix.matrix[11];
	clipCoords.w = pos.x * matrix.matrix[12] + pos.y * matrix.matrix[13] + pos.z * matrix.matrix[14] + matrix.matrix[15];

	if (clipCoords.w < 0.1f)
		return false;

	vec3 NDC;
	NDC.x = clipCoords.x / clipCoords.w;
	NDC.y = clipCoords.y / clipCoords.w;
	NDC.z = clipCoords.z / clipCoords.w;

	screen.x = (resolution.x / 2 * NDC.x) + (NDC.x + resolution.x / 2);
	screen.y = -(resolution.y / 2 * NDC.y) + (NDC.y + resolution.y / 2);

	return true;
}

uint64_t Helper::get_base_entity_from_index(int index)
{
	
	uint64_t entity_list = Helper::get_entity_list();

	uint64_t entity_base = entity_list + 8LL * ((index & 0x7FFF) >> 9) + 16;
	uint64_t entity = *(uint64_t*)(entity_base);
	if (!entity)
		return 0;

	entity += 120LL * (index & 0x1FF);
	entity = *(uint64_t*)(entity);
	return entity;
}

uint64_t* Helper::get_base_entityptr_from_index(int index)
{

	uint64_t entity_list = Helper::get_entity_list();

	uint64_t entity_base = entity_list + 8LL * ((index & 0x7FFF) >> 9) + 16;
	uint64_t entity = *(uint64_t*)(entity_base);
	if (!entity)
		return 0;

	entity += 120LL * (index & 0x1FF);
	return (uint64_t*)entity;
}

vec3 Helper::GetBoneVectorFromIndex(uintptr_t target_entity, int index) {

	if(index == -1)
		return vec3{0,0,0};
	uint64_t skel_instance = *(uint64_t*)(target_entity + C_BaseEntity::m_pGameSceneNode);
	uint64_t BoneArray = *(uint64_t*)(skel_instance + CSkeletonInstance::m_modelState + Offsets::o_BoneArray);
	vec3 bonepos = *(vec3*)(BoneArray + index * 32);

	return bonepos;
}

float Helper::GetGameTime() {

	uint64_t local_player = *(uint64_t*)(ClientModuleBase + Offsets::o_LocalPlayerController);
	float gametime = *(float*)(local_player + C_BaseEntity::m_flSimulationTime);
	return gametime;
}

int Helper::get_bone_index(uintptr_t target_entity, const std::string bone_name) { // entity = pawn
																							
	if(!target_entity)
		return -1;
	uint64_t skel_instance = *(uint64_t*)(target_entity + C_BaseEntity::m_pGameSceneNode);
	if(!skel_instance)
		return -1;
	const auto model_ptr = *(uint64_t*)(skel_instance + CSkeletonInstance::m_modelState + CModelState::m_hModel);
	if(!model_ptr)
		return -1;
	const uint64_t model = *(uint64_t*)(model_ptr);
	if(!model)
		return -1;

	const __int32 names_count = *(__int32*)(model + 0x178);
	auto names = *(const char**)(model + 0x168);
	if (names_count <= 0)
		return -1;

	for (int i = 0; i < names_count; ++i)
	{
		const uint64_t bone_name_address = *(uint64_t*)(names + i * sizeof(uint64_t));
		const std::string current_bone_name = (char*)(bone_name_address);

		if (current_bone_name.compare(bone_name) == 0)
		{
			return i;
		}
	}

	return -1;
}

PlayerData Helper::get_player_data(uint64_t entity) {


	
	PlayerData ReturnObj;

	if(!entity)
		return ReturnObj;

	uint64_t PawnHandle = *(uint64_t*)(entity + CBasePlayerController::m_hPawn);
	uint64_t Index = Helper::CHandle_get_entry_index(PawnHandle);
	uint64_t Pawn = Helper::get_base_entity_from_index(Index);
	if (!Pawn)
		return ReturnObj;
	uint64_t GameSceneNode = *(uint64_t*)(Pawn + C_BaseEntity::m_pGameSceneNode);
	uint64_t PlayerDataGlobal = entity + CCitadelPlayerController::m_PlayerDataGlobal;
	ReturnObj.m_vecOrigin = *(vec3*)(GameSceneNode + CGameSceneNode::m_vecAbsOrigin);
	ReturnObj.m_vecVelocity= *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);
	ReturnObj.Health = *(uint32_t*)(PlayerDataGlobal + PlayerDataGlobal_t::m_iHealth);
	ReturnObj.MaxHealth = *(uint32_t*)(PlayerDataGlobal + PlayerDataGlobal_t::m_iHealthMax);
	ReturnObj.HeroID = *(int*)(PlayerDataGlobal + PlayerDataGlobal_t::m_nHeroID);
	ReturnObj.TeamNum = *(int*)(Pawn + C_BaseEntity::m_iTeamNum);
	ReturnObj.isalive = *(bool*)(PlayerDataGlobal + PlayerDataGlobal_t::m_bAlive);
	ReturnObj.weaponservices = *(uint64_t*)(Pawn + C_BasePlayerPawn::m_pWeaponServices);
	

	return ReturnObj;
}

xpData Helper::get_xp_data(uint64_t entity) {

	xpData xpdataobj;

	if (!entity)
		return xpdataobj;

	uintptr_t GameSceneNode = *(uintptr_t*)(entity + C_BaseEntity::m_pGameSceneNode);
	xpdataobj.m_vecOrigin = *(vec3*)(GameSceneNode + CGameSceneNode::m_vecAbsOrigin);
	xpdataobj.m_bDormant = *(bool*)(GameSceneNode + CGameSceneNode::m_bDormant);
	xpdataobj.m_flLaunchtime = *(float*)(entity + CItemXP::m_timeLaunch);
	xpdataobj.CreationTime = *(float*)(entity + C_BaseEntity::m_flCreateTime);


	return xpdataobj;

}

NpcData Helper::get_npc_data(uint64_t entity) {


	NpcData DataObj;

	if (!entity)
		return DataObj;

	uintptr_t GameSceneNode = *(uintptr_t*)(entity + C_BaseEntity::m_pGameSceneNode);

	DataObj.m_bMinion = *(bool*)(entity + C_AI_CitadelNPC::m_bMinion);
	DataObj.m_iHealth = *(int*)(entity + C_BaseEntity::m_iHealth);
	DataObj.m_iMaxHealth = *(int*)(entity + C_BaseEntity::m_iMaxHealth);
	DataObj.m_ilifestate = *(int*)(entity + C_BaseEntity::m_lifeState);
	DataObj.m_iteamnum = *(int*)(entity + C_BaseEntity::m_iTeamNum);
	DataObj.m_bDormant = *(bool*)(GameSceneNode + CGameSceneNode::m_bDormant);
	DataObj.m_vecOrigin = *(vec3*)(GameSceneNode + CGameSceneNode::m_vecAbsOrigin);
	DataObj.m_szClassname = (char*)(GameSceneNode + CGameSceneNode::m_name);

	return DataObj;

}

vec2 Helper::GetResolution() {

	vec2 resolution;

	uint64_t resolutionptr = ClientModuleBase + Offsets::o_Resolution;
	uint64_t resclassobj = *(uint64_t*)resolutionptr;
	uint64_t resolutionaddress = resclassobj + 0x484;

	resolution.x = *(int*)(resolutionaddress);
	resolution.y = *(int*)(resolutionaddress + 0x8);
	return resolution;
}


std::string Helper::GetHeroNameByID(int id) {
	switch (id) {
	case Infernus: return "Infernus";
	case Seven: return "Seven";
	case Vindicta: return "Vindicta";
	case LadyGeist: return "LadyGeist";
	case Abrams: return "Abrams";
	case Wraith: return "Wraith";
	case McGinnis: return "McGinnis";
	case Paradox: return "Paradox";
	case Dynamo: return "Dynamo";
	case Kelvin: return "Kelvin";
	case Haze: return "Haze";
	case Holliday: return "Holliday";
	case Bebop: return "Bebop";
	case GreyTalon: return "Grey Talon";
	case MoAndKrill: return "Mo and Krill";
	case Shiv: return "Shiv";
	case Ivy: return "Ivy";
	case Warden: return "Warden";
	case Yamato: return "Yamato";
	case Lash: return "Lash";
	case Viscous: return "Viscous";
	case Wrecker: return "Wrecker";
	case Pocket: return "Pocket";
	case Mirage: return "Mirage";
	default: return "Unknown Hero"; // Handle invalid IDs
	}
}



std::string Helper::get_schema_name(const uintptr_t& entity)
{
	uintptr_t entity_identity = *(uintptr_t*)(entity + CEntityInstance::m_pEntity);
	if (!entity_identity)
		return "";

	const uintptr_t entity_class_info = *(uint64_t*)(entity_identity + 0x8);
	const uintptr_t schema_class_info_data = *(uint64_t*)(entity_class_info + 0x30);
	const uintptr_t class_name = *(uintptr_t*)(schema_class_info_data + 0x8);

	std::string class_name_str = reinterpret_cast<const char*>(class_name);

	return class_name_str;
}

float Helper::GetDistance(vec3 point1, vec3 point2) {

	float distanceSquared = (point1.x - point2.x) * (point1.x - point2.x) +
		(point1.y - point2.y) * (point1.y - point2.y) +
		(point1.z - point2.z) * (point1.z - point2.z);
	float distance = sqrt(distanceSquared);

	return distance;
}

uint64_t Helper::CHandle_get_entry_index(uint64_t handle)
{
	return handle & 0x7FFF;
}

bool Helper::CHandle_is_valid(uint64_t handle)
{
	return handle > 0 && handle != 0xFFFFFFFF;
}

vec3 Helper::GetBonePosition(uintptr_t entity, const char* BoneName) {

	vec3 BonePos = { 0, 0, 0 };

	//Get PlayerPawn
	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	std::string bonechoice = BoneName;
	int boneindex = Helper::get_bone_index(Pawn, bonechoice);
	BonePos = Helper::GetBoneVectorFromIndex(Pawn, boneindex);

	return BonePos;
}

std::vector<BoneConnection> Helper::GetBoneConnections(uintptr_t playerpawn) {

	
	std::vector <BoneConnection> connections;


		
		uint64_t pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(*(uint64_t*)(playerpawn + CCitadelPlayerController::m_hHeroPawn)));

			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "head"), Helper::get_bone_index(pawn, "neck_0")));
			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "neck_0"), Helper::get_bone_index(pawn, "spine_3")));
			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "spine_3"), Helper::get_bone_index(pawn, "pelvis")));
			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "pelvis"), Helper::get_bone_index(pawn, "leg_lower_L")));
			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "pelvis"), Helper::get_bone_index(pawn, "leg_lower_R")));
			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "leg_lower_R"), Helper::get_bone_index(pawn, "ankle_R")));
			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "leg_lower_L"), Helper::get_bone_index(pawn, "ankle_L")));
			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "spine_3"), Helper::get_bone_index(pawn, "arm_lower_R")));
			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "spine_3"), Helper::get_bone_index(pawn, "arm_lower_L")));
			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "arm_lower_R"), Helper::get_bone_index(pawn, "hand_R")));
			connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "arm_lower_L"), Helper::get_bone_index(pawn, "hand_L")));

	return connections;

 }

float Helper::DegreesToRadians(float degrees) {
	return degrees * (M_PI / 180.0f);
}



CCitadelUserCmdPB* Helper::GetCurrentUserCmd()
{

	using fmGetUCmd = CCitadelUserCmdPB * (__fastcall*)(__int64 a1, int a2);
	static auto oGetUserCmd = reinterpret_cast<fmGetUCmd>(ClientModuleBase + Offsets::o_fGetUserCmd);

	using GetCommandIndex = __int64(__fastcall*)(__int64 a1, __int64 a2);
	static auto oGetCommandIndex = reinterpret_cast<GetCommandIndex>(ClientModuleBase + Offsets::o_fGetCommandIndex);

	using GetCUserCMDBASE = __int64(__fastcall*)(__int64 a1, int a2);
	static auto oGetCUserCmdBASE = reinterpret_cast<GetCUserCMDBASE>(ClientModuleBase + Offsets::o_fGetCUserCmdBase);



	uint64_t v132 = 0;
	uint64_t LocalPlayerController = Helper::get_local_player();
	uint64_t v5 = LocalPlayerController;
	oGetCommandIndex(LocalPlayerController, (uint64_t)&v132);
	uint64_t v6 = (unsigned int)((uint32_t)v132 - 1);
	if ((uint32_t)v132 == -1)
		v6 = 0xFFFFFFFFLL;
	uint64_t v7 = *(uint64_t*)oGetCUserCmdBASE((ClientModuleBase + Offsets::o_oUserCmdArray), v6);
	uint64_t v8 = *(uint32_t*)(v7 + 21136);
	uint64_t v9 = (uint64_t)oGetUserCmd(v5, v8);

	return (CCitadelUserCmdPB*)v9;

}

void Helper::HotKey(KeyBind &keybind){


	if (!keybind.waitingForKey) {
		if (ImGui::Button(keybind.name.c_str())) {
			keybind.waitingForKey = true;
		}
	}
	else {
		ImGui::Button("...");
		for (auto& Key : KeyCodes) {
			if (GetAsyncKeyState(Key)) {
				Sleep(20);
				if (Key == VK_ESCAPE) {
					keybind.key = 0;
					keybind.name = "None";
					keybind.waitingForKey = false;
					break;
				}
				keybind.key = Key;
				keybind.name = KeyNames[Key];
				keybind.waitingForKey = false;
				break;
			}
		}
	}
}



bool Helper::KeyBindHandler(int key) {

	if (key == 0) {
		return true;
	}

	if (GetAsyncKeyState(key) & 0x8000)
		return true;
	return false;
}


uint64_t Helper::get_localplr_weapon() {

	int max_ents = Helper::get_max_entities();

	for (size_t i = 1; i <= static_cast<size_t>(max_ents); ++i)
	{
		uint64_t entity = Helper::get_base_entity_from_index(i);

		if (!entity)
			continue;

		std::string EntName = Helper::get_schema_name(entity);

		if (EntName == "CCitadel_Ability_PrimaryWeapon_Empty")
			return entity;

	}
	return -1;
}

uint64_t Helper::GetPawnHandle(uint64_t entity) {

	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	return PawnHandle;

}



uint64_t Helper::GetPawn(uint64_t entity) {

	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	return Pawn;

}

bool __fastcall Helper::traceshape(void* dis, Ray_t* pRay, vec3* vecStart, vec3* vecEnd, TraceFilter_t* pFilter, GameTrace_t* pGameTrace) {

	typedef bool(__fastcall* traceshape_fn)(void*, Ray_t*, vec3*, vec3*, TraceFilter_t*, GameTrace_t*);
	traceshape_fn traceshape = (traceshape_fn)(ClientModuleBase + Offsets::o_ftraceShape);
	bool result = traceshape(dis, pRay, vecStart, vecEnd, pFilter, pGameTrace);
	return result;
}

static void __fastcall ConstructFilter(void* thisptr, void* pSkip1, void* uMask, void* nlayer, void* unkNum) {

	typedef void(__fastcall* ConfstructFilter_fn)(void*, void*, void*, void*, void*);
	ConfstructFilter_fn filterconstruct = (ConfstructFilter_fn)(ClientModuleBase + Offsets::o_fConstructFilter);
	filterconstruct(thisptr, pSkip1, uMask, nlayer, unkNum);
	return;

}

uint32_t GetOwnerHandle(uint64_t ent)
{
	if (!ent)
		return -1;

	std::uint32_t Result = -1;
	Result = *(uint64_t*)(ent + C_BaseEntity::m_hOwnerEntity);
	return Result;
}

uint64_t GetEntityHandleRebuilt(uintptr_t a1) //aka CCSPlayerPawn* a1 
{
	uintptr_t v1; // rax
	unsigned int v2; // r8d
	int v3; // edx
	int v4; // eax

	if (!a1)
		return 0xFFFFFFFF;
	v1 = *(uint64_t*)(a1 + 16);
	if (!v1)
		return 0xFFFFFFFF;
	v2 = *(uint32_t*)(v1 + 16);
	v3 = 0x7FFF;
	v4 = ((v2 >> 15) - (*(uint32_t*)(v1 + 48) & 1)) << 15;
	if (v2 != -1)
		v3 = v2 & 0x7FFF;
	return v3 | (unsigned int)v4;
}

int16_t GetCollisionMask(uint64_t ent)
{
	if (!ent)
		return -1;
	uint64_t collisionproperty = *(uint64_t*)(ent + C_BaseEntity::m_pCollision);
	UINT8 collisionmask = (UINT8)(collisionproperty + CCollisionProperty::m_CollisionGroup);
	return (int16_t)collisionmask;
}


TraceFilter_t::TraceFilter_t(uint32_t uMask, uint64_t pSkip1, uint8_t nLayer, uint16_t unkNum) {
	reinterpret_cast<void(*)(TraceFilter_t*, uint64_t, uint32_t mask, uint8_t layer, uint16_t num7)>
		(ConstructFilter)(this, pSkip1, uMask, nLayer, unkNum);
	return;
}

uint64_t Helper::gettracemanager(){

	uint64_t tracemanagerptr = ClientModuleBase + Offsets::o_oGameTraceManager;
	uint64_t tracemanagerlr1 = *(uint64_t*)tracemanagerptr;

	return tracemanagerlr1;
}

bool Helper::CheckLocationVisible(vec3 LocalPlayerPos, vec3 LocationCheck) {

	CGameTraceManager* tracemanager = (CGameTraceManager*)Helper::gettracemanager();

	uint64_t localplayerpawn = Helper::GetPawn(Helper::get_local_player());
	TraceFilter_t filter(0x1C3003, localplayerpawn, 4, 7);
	Ray_t ray = {};
	GameTrace_t trace = {};

	tracemanager->TraceShape(&ray, LocalPlayerPos, LocationCheck, &filter, &trace);
	if (trace.m_flFraction < 0.97)
		return false;
	return true;
		
}

void Helper::CorrectMovement(vec2 OldAngles, CCitadelUserCmdPB* pCmd, float& fOldForward, float& fOldSidemove) {

	// side/forward move correction
	float deltaView;
	float f1;
	float f2;


		f1 = OldAngles.y;
		f2 = pCmd->cameraViewAngle->viewAngles.y;


	if (f2 < f1)
		deltaView = abs(f2 - f1);
	else
		deltaView = 360.0f - abs(f1 - f2);


	// Replace DEG2RAD with inline conversion (PI / 180)
	float radDeltaView = deltaView * (M_PI / 180.0f);
	float radDeltaViewPlus90 = (deltaView + 90.0f) * (M_PI / 180.0f);

	float forwardmove = cos(radDeltaView) * fOldForward + cos(radDeltaViewPlus90) * fOldSidemove;
	float sidemove = sin(radDeltaView) * fOldForward + sin(radDeltaViewPlus90) * fOldSidemove;

	if (forwardmove > 1.0f)
		forwardmove = 1.0f;
	if (forwardmove < -1.0f)
		forwardmove = -1.0f;
	if (sidemove > 1.0f)
		sidemove = 1.0f;
	if (sidemove < -1.0f)
		sidemove = -1.0f;


	pCmd->pBaseUserCMD->forwardMove = forwardmove;
	pCmd->pBaseUserCMD->sideMove = sidemove;
}

void Helper::CorrectViewAngles(vec2 OldAngles, CCitadelUserCmdPB* pCmd) {

	pCmd->pBaseUserCMD->playerViewAngle->viewAngles.x = OldAngles.x;
	pCmd->pBaseUserCMD->playerViewAngle->viewAngles.y = OldAngles.y;

}



