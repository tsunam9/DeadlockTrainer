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

uint64_t Helper::get_entity_list() {

	static uint64_t tf = *(uintptr_t*)(ClientModuleBase + Offsets.o_EntityList); // Assign to the static tf
	return tf;

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
	static uint64_t entity_list = Helper::get_entity_list();
	int max_entities = *(int*)(entity_list + Offsets.o_HighestEntityIndex);
	return max_entities;
}

uint64_t Helper::get_Camera() {


	//camera = pm.read_longlong(client_base + 0x1f450b0 + 0x28)
	uint64_t camera = (ClientModuleBase + Offsets.o_CameraManager + 0x28);
	camera = *(uint64_t*)camera;
	return camera;



}

uint64_t Helper::get_local_player() {
	uint64_t local_player = *(uint64_t*)(ClientModuleBase + Offsets.o_LocalPlayerController);
	return local_player;
}

//DirectX 11 WorldToScreen
bool Helper::WorldToScreen(vec3 pos, vec2& screen) {

	vec2 resolution = Helper::GetResolution();
	uintptr_t ViewMatrix = (ClientModuleBase + Offsets.o_ViewMatrix);
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
	
	static uint64_t entity_list = Helper::get_entity_list();

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
	uint64_t BoneArray = *(uint64_t*)(skel_instance + CSkeletonInstance::m_modelState + Offsets.o_BoneArray);
	vec3 bonepos = *(vec3*)(BoneArray + index * 32);

	return bonepos;
}

uint64_t Helper::FindFirstEntityWithName(std::string name) {


	int max_ents = Helper::get_max_entities();
	if (!(max_ents >= 0))
		return 0;
	for (size_t i = 1; i <= static_cast<size_t>(max_ents); ++i) {
		uint64_t entity = Helper::get_base_entity_from_index(i);

		if (!entity)
			continue;

		std::string EntName = Helper::get_schema_name(entity);

		auto found = EntName.find("Projectile");
		if (found != std::string::npos) {
			return entity;
		}

	}
	return 0;

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

 bool Helper::get_player_data(uint64_t entity, PlayerData* outputPlrData){


	 if (!entity)
		 return false;

	uint64_t PawnHandle = *(uint64_t*)(entity + CBasePlayerController::m_hPawn);
	uint64_t Index = Helper::CHandle_get_entry_index(PawnHandle);
	uint64_t Pawn = Helper::get_base_entity_from_index(Index);
	if (!Pawn)
		return outputPlrData;
	uint64_t GameSceneNode = *(uint64_t*)(Pawn + C_BaseEntity::m_pGameSceneNode);
	uint64_t PlayerDataGlobal = entity + CCitadelPlayerController::m_PlayerDataGlobal;
	outputPlrData->m_vecOrigin = *(vec3*)(GameSceneNode + CGameSceneNode::m_vecAbsOrigin);
	outputPlrData->m_vecVelocity= *(vec3*)(Pawn + C_BaseEntity::m_vecVelocity);
	outputPlrData->Health = *(uint32_t*)(PlayerDataGlobal + PlayerDataGlobal_t::m_iHealth);
	outputPlrData->MaxHealth = *(uint32_t*)(PlayerDataGlobal + PlayerDataGlobal_t::m_iHealthMax);
	outputPlrData->HeroID = *(int*)(PlayerDataGlobal + PlayerDataGlobal_t::m_nHeroID);
	outputPlrData->kills = *(int*)(PlayerDataGlobal + PlayerDataGlobal_t::m_iPlayerKills);
	outputPlrData->TeamNum = *(int*)(Pawn + C_BaseEntity::m_iTeamNum);
	outputPlrData->isalive = *(bool*)(PlayerDataGlobal + PlayerDataGlobal_t::m_bAlive);
	outputPlrData->dormant = *(bool*)(GameSceneNode + CGameSceneNode::m_bDormant);
	outputPlrData->weaponservices = *(uint64_t*)(Pawn + C_BasePlayerPawn::m_pWeaponServices);
	

	return true;
}

  bool Helper::getPawnData(uint64_t entity_pawn, PlayerData* outputPlrData){


	 if (!entity_pawn)
		 return false;


	 uint64_t GameSceneNode = *(uint64_t*)(entity_pawn + C_BaseEntity::m_pGameSceneNode);
	 outputPlrData->m_vecOrigin = *(vec3*)(GameSceneNode + CGameSceneNode::m_vecAbsOrigin);
	 outputPlrData->m_vecVelocity = *(vec3*)(entity_pawn + C_BaseEntity::m_vecVelocity);
	 outputPlrData->TeamNum = *(int*)(entity_pawn + C_BaseEntity::m_iTeamNum);
	 outputPlrData->dormant = *(bool*)(GameSceneNode + CGameSceneNode::m_bDormant);
	 outputPlrData->weaponservices = *(uint64_t*)(entity_pawn + C_BasePlayerPawn::m_pWeaponServices);


	 return true;
 }

bool Helper::get_xp_data(uint64_t entity, xpData* xpdataobj) {


	if (!entity)
		return false;

	uintptr_t GameSceneNode = *(uintptr_t*)(entity + C_BaseEntity::m_pGameSceneNode);
	xpdataobj->m_vecOrigin = *(vec3*)(GameSceneNode + CGameSceneNode::m_vecAbsOrigin);
	xpdataobj->m_bDormant = *(bool*)(GameSceneNode + CGameSceneNode::m_bDormant);
	xpdataobj->m_flLaunchtime = *(float*)(entity + CItemXP::m_timeLaunch);
	xpdataobj->CreationTime = *(float*)(entity + C_BaseEntity::m_flCreateTime);


	return true;

}

bool Helper::get_npc_data(uint64_t entity, NpcData* npcdata) {



	if (!entity)
		return false;



	uintptr_t GameSceneNode = *(uintptr_t*)(entity + C_BaseEntity::m_pGameSceneNode);

	npcdata->m_bMinion = *(bool*)(entity + C_AI_CitadelNPC::m_bMinion);
	npcdata->m_iHealth = *(int*)(entity + C_BaseEntity::m_iHealth);
	npcdata->m_iMaxHealth = *(int*)(entity + C_BaseEntity::m_iMaxHealth);
	npcdata->m_ilifestate = *(int*)(entity + C_BaseEntity::m_lifeState);
	npcdata->m_iteamnum = *(int*)(entity + C_BaseEntity::m_iTeamNum);
	npcdata->m_bDormant = *(bool*)(GameSceneNode + CGameSceneNode::m_bDormant);
	npcdata->m_vecOrigin = *(vec3*)(GameSceneNode + CGameSceneNode::m_vecAbsOrigin);
	npcdata->m_szClassname = (char*)(GameSceneNode + CGameSceneNode::m_name);

	return true;

}

vec2 Helper::GetResolution() {

	vec2 resolution;

	uint64_t resolutionptr = ClientModuleBase + Offsets.o_Resolution;
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



std::string Helper::get_schema_name(const uint64_t entity)
{
	uintptr_t entity_identity = *(uintptr_t*)(entity + CEntityInstance::m_pEntity);
	if (!entity_identity)
		return "";

	const uintptr_t entity_class_info = *(uint64_t*)(entity_identity + 0x8);
	if (!entity_class_info)
		return "";

	const uintptr_t schema_class_info_data = *(uint64_t*)(entity_class_info + 0x30);
	if (!schema_class_info_data)
		return "";

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


vec3 Helper::GetBonePosition(uintptr_t entity_controller, const char* BoneName) {

	vec3 BonePos = { 0, 0, 0 };

	if (!entity_controller)
		return BonePos;


	uintptr_t entity_pawn = Helper::GetPawn(entity_controller);
	std::string bonechoice = BoneName;
	int boneindex = Helper::get_bone_index(entity_pawn, bonechoice);
	BonePos = Helper::GetBoneVectorFromIndex(entity_pawn, boneindex);

	return BonePos;
}

std::vector<BoneConnection> Helper::GetBoneConnections(uintptr_t playerpawn, int heroid) {

	
	std::vector <BoneConnection> connections;

	uint64_t pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(*(uint64_t*)(playerpawn + CCitadelPlayerController::m_hHeroPawn)));


	if (heroid == Dynamo) {
		connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "head"), Helper::get_bone_index(pawn, "neck_0")));
		connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "neck_0"), Helper::get_bone_index(pawn, "pelvis")));
		connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "pelvis"), Helper::get_bone_index(pawn, "leg_lower_L")));
		connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "pelvis"), Helper::get_bone_index(pawn, "leg_lower_R")));
		connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "leg_lower_R"), Helper::get_bone_index(pawn, "ankle_R")));
		connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "leg_lower_L"), Helper::get_bone_index(pawn, "ankle_L")));
		connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "neck_0"), Helper::get_bone_index(pawn, "arm_lower_R")));
		connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "neck_0"), Helper::get_bone_index(pawn, "arm_lower_L")));
		connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "arm_lower_R"), Helper::get_bone_index(pawn, "hand_R")));
		connections.push_back(BoneConnection(Helper::get_bone_index(pawn, "arm_lower_L"), Helper::get_bone_index(pawn, "hand_L")));
	}
	else {
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
	}

	return connections;

 }

float Helper::DegreesToRadians(float degrees) {
	return degrees * (M_PI / 180.0f);
}


using fmGetUCmd = CCitadelUserCmdPB * (__fastcall*)(__int64 a1, int a2);
static auto oGetUserCmd = reinterpret_cast<fmGetUCmd>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "40 53 48 83 ec ? 8b da 85 d2 78"));

using GetCommandIndex = __int64(__fastcall*)(__int64 a1, __int64 a2);
static auto oGetCommandIndex = reinterpret_cast<GetCommandIndex>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "40 53 48 83 ec ? 4c 8b 41 ? 48 8b da 48 8b 0d"));

using GetCUserCMDBASE = __int64(__fastcall*)(__int64 a1, int a2);
static auto oGetCUserCmdBASE = reinterpret_cast<GetCUserCMDBASE>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "48 89 4c 24 ? 41 54 41 57"));

using getcmdupdated = __int64(__fastcall*)(__int64 a1);
static auto ogetcmdupdated = reinterpret_cast<getcmdupdated>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "48 83 ec ? e8 ? ? ? ? 8b 80"));

typedef float(__fastcall* f_getBulletSpeed)(__int64 a1, __int64 a2);
static f_getBulletSpeed getBulletSpeedFunction = reinterpret_cast<f_getBulletSpeed>(MEM::GetClientBase() + MEM::PatternScanFunc((void*)MEM::GetClientBase(), "48 89 5c 24 ? 57 48 81 ec ? ? ? ? 48 8b f9 0f 29 74 24 ? 48 8b 49"));


			

CCitadelUserCmdPB* Helper::GetCurrentUserCmd()
{

	auto localplayer = Helper::get_local_player();

	if (localplayer) {
		auto var = ogetcmdupdated(localplayer);
		auto cmd = oGetUserCmd(localplayer, var);
		return cmd;
	}
	return nullptr;

}


/*
	static uint64_t offset = ClientModuleBase + MEM::PatternScanOffset((void*)ClientModuleBase, "48 8b 0d ? ? ? ? e8 ? ? ? ? 48 8b cf 4c 8b e8", 3, 7);

	const char* v132;
	__int64 v4 = GetLocalPlayerController(0LL);
	__int64 v5 = v4;
	if (!v4)
		return nullptr;
	oGetCommandIndex(v4, (__int64)&v132);
	__int64 v6 = (unsigned int)((uint32_t)v132 - 1);
	if ((uint32_t)v132 == -1)
		v6 = 0xFFFFFFFFLL;
	__int64 *v7 = (__int64*)oGetCUserCmdBASE(offset, v6);

	unsigned int v8 = *(uint32_t*)(*v7 + 21136);
	CCitadelUserCmdPB* v9 = oGetUserCmd(v5, v8);

	return v9;
*/

// Add a static variable to track the currently active keybind waiting for a key
static KeyBind* activeKeybind = nullptr;
std::vector<KeyBind> KeyBinds;

void Helper::HotKey(KeyBind& keybind) {
	// Use PushID with a unique identifier for each keybind
	ImGui::PushID(&keybind); // Use the address of keybind as a unique ID

	if (!keybind.waitingForKey) {
		if (ImGui::Button(keybind.name.c_str())) {
			// Set the active keybind if none is waiting
			if (activeKeybind == nullptr) {
				activeKeybind = &keybind; // Set this keybind as active
				keybind.waitingForKey = true;
			}
		}
	}
	else {
		ImGui::Button("...");
		for (auto& Key : KeyCodes) {
			if (GetAsyncKeyState(Key) & 0x8000) { // Ensure the key is pressed down
				if (Key == VK_ESCAPE) {
					keybind.key = 0;
					keybind.name = "Always";
					keybind.waitingForKey = false;
					activeKeybind = nullptr; // Reset active keybind
					break;
				}

				// Check if the key is already bound to another keybind
				if (activeKeybind != nullptr && activeKeybind != &keybind && activeKeybind->key == Key) {
					// Optionally handle the conflict here (e.g., notify the user)
					// You could reset the conflicting keybind or ignore the new key.	
					break;
				}

				// Set the key and update the name
				keybind.key = Key;
				keybind.name = KeyNames[Key];
				keybind.waitingForKey = false;
				activeKeybind = nullptr; // Reset active keybind
				break;
			}
		}
	}

	// Pop the ID to restore the previous state
	ImGui::PopID();
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


		// Use std::string::find to check if the name starts with the target string
		if (EntName.find("CCitadel_Ability_PrimaryWeapon") == 0)
			return entity;
	}
	return 0;
}

uint64_t Helper::GetPawnHandle(uint64_t entity) {

	uint64_t PawnHandle = *(uint64_t*)(entity + CCitadelPlayerController::m_hHeroPawn);
	return PawnHandle;

}



uint64_t Helper::GetPawn(uint64_t entity_controller) {

	if (!entity_controller)
		return 0;

	uint64_t PawnHandle = *(uint64_t*)(entity_controller + CCitadelPlayerController::m_hHeroPawn);
	uint64_t Pawn = Helper::get_base_entity_from_index(Helper::CHandle_get_entry_index(PawnHandle));
	return Pawn;

}

bool __fastcall Helper::traceshape(void* dis, Ray_t* pRay, vec3* vecStart, vec3* vecEnd, TraceFilter_t* pFilter, GameTrace_t* pGameTrace) {


	typedef bool(__fastcall* traceshape_fn)(void*, Ray_t*, vec3*, vec3*, TraceFilter_t*, GameTrace_t*);
	traceshape_fn traceshape = (traceshape_fn)(ClientModuleBase + Offsets.o_ftraceShape);
	bool result = traceshape(dis, pRay, vecStart, vecEnd, pFilter, pGameTrace);
	return result;
}

static void __fastcall ConstructFilter(void* thisptr, void* pSkip1, void* uMask, void* nlayer, void* unkNum) {


	typedef void(__fastcall* ConfstructFilter_fn)(void*, void*, void*, void*, void*);
	ConfstructFilter_fn filterconstruct = (ConfstructFilter_fn)(ClientModuleBase + Offsets.o_fConstructFilter);
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

	uint64_t tracemanagerptr = ClientModuleBase + Offsets.o_oGameTraceManager;
	uint64_t tracemanagerlr1 = *(uint64_t*)tracemanagerptr;

	return tracemanagerlr1;
}

bool Helper::CheckLocationVisible(vec3 LocalPlayerPos, vec3 LocationCheck) {
	
	float tracefraction = 0.97f;

	if (Helper::GetDistance(LocalPlayerPos, LocationCheck) < 300.0f) {
		tracefraction = 0.8f;
	}

	CGameTraceManager* tracemanager = (CGameTraceManager*)Helper::gettracemanager();

	uint64_t localplayerpawn = Helper::GetPawn(Helper::get_local_player());
	TraceFilter_t filter(0x1C3003, localplayerpawn, 4, 7);
	Ray_t ray = {};
	GameTrace_t trace = {};

	tracemanager->TraceShape(&ray, LocalPlayerPos, LocationCheck, &filter, &trace);
	if (trace.m_flFraction < tracefraction)
		return false;
	return true;
		
}

void Helper::CorrectMovement(CCitadelUserCmdPB* pCmd, float& fOldForward, float& fOldSidemove,vec3 oldangles) {


	float deltaView;
	float f1;
	float f2;


	f1 = oldangles.y;
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

	
	uint64_t pbase = (uint64_t)pCmd->pBaseUserCMD;
	if (forwardmove >= 0) {
		pCmd->buttons |= IN_FORWARD;
		pCmd->pBaseUserCMD->CInButtonStatePB->buttons |= IN_FORWARD;
		*(uint64_t*)(pbase + 16) |= 0x20u;
	}
	else {
		pCmd->buttons |= IN_BACK;
		pCmd->pBaseUserCMD->CInButtonStatePB->buttons |= IN_BACK;
		*(uint64_t*)(pbase + 16) |= 0x20u;
	}

	if (sidemove >= 0) {
		pCmd->buttons |= IN_MOVELEFT;
		pCmd->pBaseUserCMD->CInButtonStatePB->buttons |= IN_MOVELEFT;
		*(uint64_t*)(pbase + 16) |= 0x40u;
	}
	else {
		pCmd->buttons |= IN_MOVERIGHT;
		pCmd->pBaseUserCMD->CInButtonStatePB->buttons |= IN_MOVERIGHT;
		*(uint64_t*)(pbase + 16) |= 0x40u;
	}

	pCmd->pBaseUserCMD->forwardMove = forwardmove;
	pCmd->pBaseUserCMD->sideMove = sidemove;
}

void Helper::CorrectViewAngles( CCitadelUserCmdPB* pCmd) {

	auto camera = Helper::get_Camera();
	vec2 OldAngles = *(vec2*)(camera + 0x44);

	if (!pCmd->pBaseUserCMD->playerViewAngle)
		return;
	pCmd->pBaseUserCMD->playerViewAngle->viewAngles.x = OldAngles.x;
	pCmd->pBaseUserCMD->playerViewAngle->viewAngles.y = OldAngles.y;

}

std::vector<uintptr_t> Helper::GetAbilities(uint64_t entity_pawn) {

	std::vector<uintptr_t> abilities;

	if (!entity_pawn)
		return abilities;

	uint64_t weaponcomponent = (uint64_t)(entity_pawn + C_CitadelPlayerPawn::m_CCitadelAbilityComponent);
	if (!weaponcomponent)
		return abilities;
	uint64_t vecAbilities = *(uint64_t*)(weaponcomponent + CCitadelAbilityComponent::m_vecAbilities + 0x8);
	if (!vecAbilities)
		return abilities;

	for (int i = 10; i < 16; i++) {
		auto abilityHandle = *(uint32_t*)(vecAbilities + (0x4 * i));
		if (abilityHandle == 0) continue;

		int index = Helper::CHandle_get_entry_index(abilityHandle);
		uintptr_t ability = Helper::get_base_entity_from_index(index);
		abilities.push_back(ability);
		if (!ability) continue;

	}
	return abilities;

}

bool Helper::IsAbilityCasting(uintptr_t ability) {

	float completetime = *(float*)(ability + C_CitadelBaseAbility::m_bInCastDelay);
	float gametime = globals::instance().Globals->flAbsCurTime;
	
	if (completetime > gametime)
		return true;
	return false;

}

float Helper::getBulletSpeed(uint64_t BulletHandler) {
	return getBulletSpeedFunction(BulletHandler, BulletHandler + 16);
}


