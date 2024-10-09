#pragma once
#include "helper.h"
using namespace cs2_dumper::schemas::client_dll;

Offsets HelperOffsets;



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
	uintptr_t tf = *(uintptr_t*)(ClientModuleBase + HelperOffsets.o_EntityList);
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
	int max_entities = *(int*)(entity_list + HelperOffsets.o_HighestEntityIndex);
	return max_entities;
}

uint64_t Helper::get_Camera() {


	//camera = pm.read_longlong(client_base + 0x1f450b0 + 0x28)
	uint64_t camera = (ClientModuleBase + HelperOffsets.o_CameraManager + 0x28);
	camera = *(uint64_t*)camera;
	return camera;
}

uint64_t Helper::get_local_player() {
	uint64_t local_player = *(uint64_t*)(ClientModuleBase + HelperOffsets.o_LocalPlayerController);
	return local_player;
}

//DirectX 11 WorldToScreen
bool Helper::WorldToScreen(vec3 pos, vec2& screen, float matrix[16]) {

	vec2 resolution = Helper::GetResolution();

	vec4 clipCoords;
	clipCoords.x = pos.x * matrix[0] + pos.y * matrix[1] + pos.z * matrix[2] + matrix[3];
	clipCoords.y = pos.x * matrix[4] + pos.y * matrix[5] + pos.z * matrix[6] + matrix[7];
	clipCoords.z = pos.x * matrix[8] + pos.y * matrix[9] + pos.z * matrix[10] + matrix[11];
	clipCoords.w = pos.x * matrix[12] + pos.y * matrix[13] + pos.z * matrix[14] + matrix[15];

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
	uint64_t BoneArray = *(uint64_t*)(skel_instance + CSkeletonInstance::m_modelState + HelperOffsets.o_BoneArray);
	vec3 bonepos = *(vec3*)(BoneArray + index * 32);

	return bonepos;
}

float Helper::GetGameTime() {

	uint64_t local_player = *(uint64_t*)(ClientModuleBase + HelperOffsets.o_LocalPlayerController);
	float gametime = *(float*)(local_player + C_BaseEntity::m_flSimulationTime);
	return gametime;
}

int Helper::get_index(uintptr_t target_entity, const std::string bone_name) {
																							
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
	ReturnObj.Health = *(uint32_t*)(PlayerDataGlobal + PlayerDataGlobal_t::m_iHealth);
	ReturnObj.MaxHealth = *(uint32_t*)(PlayerDataGlobal + PlayerDataGlobal_t::m_iHealthMax);
	ReturnObj.HeroID = *(int*)(PlayerDataGlobal + PlayerDataGlobal_t::m_nHeroID);
	ReturnObj.TeamNum = *(int*)(Pawn + C_BaseEntity::m_iTeamNum);
	ReturnObj.isalive = *(bool*)(PlayerDataGlobal + PlayerDataGlobal_t::m_bAlive);
	

	return ReturnObj;
}

xpData Helper::get_xp_data(uint64_t entity) {

	xpData xpdataobj;

	if (!entity)
		return xpdataobj;

	uintptr_t GameSceneNode = *(uintptr_t*)(entity + C_BaseEntity::m_pGameSceneNode);
	xpdataobj.m_vecOrigin = *(vec3*)(GameSceneNode + CGameSceneNode::m_vecAbsOrigin);
	xpdataobj.bDormant = *(bool*)(GameSceneNode + CGameSceneNode::m_bDormant);
	xpdataobj.blaunchtime = *(float*)(entity + CItemXP::m_timeLaunch);

	return xpdataobj;

}

vec2 Helper::GetResolution() {

	vec2 resolution;

	uint64_t resolutionptr = ClientModuleBase + HelperOffsets.o_Resolution;
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
	const uintptr_t entity_identity = *(uintptr_t*)(entity + HelperOffsets																															.o_entityInfo);
	if (!entity_identity)
		return "";

	const uintptr_t entity_class_info = *(uint64_t*)(entity_identity + 0x8);
	const uintptr_t schema_class_info_data = *(uint64_t*)(entity_class_info + 0x28);
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
	int boneindex = Helper::get_index(Pawn, bonechoice);
	BonePos = Helper::GetBoneVectorFromIndex(Pawn, boneindex);

	return BonePos;
}

float Helper::DegreesToRadians(float degrees) {
	return degrees * (M_PI / 180.0f);
}

CCitadelUserCmdPB* Helper::GetUserCmdArray()
{
	using fnGetUserCmd = CCitadelUserCmdPB * (__fastcall*)(__int64*);
	static auto oGetUserCmd = reinterpret_cast<fnGetUserCmd>(ClientModuleBase + Offsets::o_fGetUserCmdArray);

	return oGetUserCmd(reinterpret_cast<__int64*>(Helper::get_local_player));
}

CCitadelUserCmdPB* Helper::GetUserCmdByIndex(int index)
{
	auto _array = Helper::GetUserCmdArray();
	auto current_cmd = (uintptr_t)_array + 0x88 * index;
	return (CCitadelUserCmdPB*)current_cmd;

}

CCitadelUserCmdPB* Helper::GetCurrentUserCmd()
{
	CCitadelUserCmdPB* cmdarray = Helper::GetUserCmdArray();
	uint64_t sequence = *(uint64_t*)(uint64_t)(cmdarray + 0x5290);
	if (sequence != 0) {
		std::cout << "SEQUENCE: " << sequence << "\n";
	}
	auto current_index = sequence % 150u; // evil terrible 
	auto current_cmd = Helper::GetUserCmdByIndex(current_index);

	return (CCitadelUserCmdPB*)current_cmd;

}


bool Helper::KeyBindHandler(int key) {

	if (key == 0) {
		return true;
	}

	if (GetAsyncKeyState(key) & 0x8000)
		return true;
	return false;
}

