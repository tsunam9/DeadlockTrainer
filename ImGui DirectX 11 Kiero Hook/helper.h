#pragma once
#include "Windows.h"
#include <string>
#include "offsets.h"
#include <string>
#include <TlHelp32.h>
#include "offsets.h"
#include "client_dll.hpp"
#include <iostream>
#include <vector>
#include "math.h"
#include "Config.h"
#include "mem.h"

#define M_PI 3.14159265358979323846

#define IN_ATTACK (1 << 0)
#define IN_JUMP (1 << 1)
#define IN_DUCK (1 << 2)
#define IN_FORWARD (1 << 3)
#define IN_BACK (1 << 4)
#define IN_USE (1 << 5)
// UNKNOWN (1 << 6)
#define IN_TURNLEFT (1 << 7)
#define IN_TURNRIGHT (1 << 8)
#define IN_MOVELEFT (1 << 9)
#define IN_MOVERIGHT (1 << 10)
#define IN_ZOOM (1 << 11)
// UNKNOWN (1 << 12)
#define IN_RELOAD (1 << 13)
// UNKNOWN (1 << 14-15)
#define IN_SPEED (1 << 16)
#define IN_JOYAUTOSPRINT (1 << 17)
// UNKNOWN (1 << 18-31)
#define IN_ABILITY1  (1ull << 33ull)
#define IN_ABILITY2  (1ull << 34ull)
#define IN_ABILITY3  (1ull << 35ull)
#define IN_ABILITY4  (1ull << 36ull)


static const char* KeyNames[] = {
    "OFF",
    "VK_LBUTTON",
    "VK_RBUTTON",
    "VK_CANCEL",
    "VK_MBUTTON",
    "VK_XBUTTON1",
    "VK_XBUTTON2",
    "Unknown",
    "VK_BACK",
    "VK_TAB",
    "Unknown",
    "Unknown",
    "VK_CLEAR",
    "VK_RETURN",
    "Unknown",
    "Unknown",
    "VK_SHIFT",
    "VK_CONTROL",
    "VK_MENU",
    "VK_PAUSE",
    "VK_CAPITAL",
    "VK_KANA",
    "Unknown",
    "VK_JUNJA",
    "VK_FINAL",
    "VK_KANJI",
    "Unknown",
    "VK_ESCAPE",
    "VK_CONVERT",
    "VK_NONCONVERT",
    "VK_ACCEPT",
    "VK_MODECHANGE",
    "VK_SPACE",
    "VK_PRIOR",
    "VK_NEXT",
    "VK_END",
    "VK_HOME",
    "VK_LEFT",
    "VK_UP",
    "VK_RIGHT",
    "VK_DOWN",
    "VK_SELECT",
    "VK_PRINT",
    "VK_EXECUTE",
    "VK_SNAPSHOT",
    "VK_INSERT",
    "VK_DELETE",
    "VK_HELP",
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
    "VK_LWIN",
    "VK_RWIN",
    "VK_APPS",
    "Unknown",
    "VK_SLEEP",
    "VK_NUMPAD0",
    "VK_NUMPAD1",
    "VK_NUMPAD2",
    "VK_NUMPAD3",
    "VK_NUMPAD4",
    "VK_NUMPAD5",
    "VK_NUMPAD6",
    "VK_NUMPAD7",
    "VK_NUMPAD8",
    "VK_NUMPAD9",
    "VK_MULTIPLY",
    "VK_ADD",
    "VK_SEPARATOR",
    "VK_SUBTRACT",
    "VK_DECIMAL",
    "VK_DIVIDE",
    "VK_F1",
    "VK_F2",
    "VK_F3",
    "VK_F4",
    "VK_F5",
    "VK_F6",
    "VK_F7",
    "VK_F8",
    "VK_F9",
    "VK_F10",
    "VK_F11",
    "VK_F12",
    "VK_F13",
    "VK_F14",
    "VK_F15",
    "VK_F16",
    "VK_F17",
    "VK_F18",
    "VK_F19",
    "VK_F20",
    "VK_F21",
    "VK_F22",
    "VK_F23",
    "VK_F24",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_NUMLOCK",
    "VK_SCROLL",
    "VK_OEM_NEC_EQUAL",
    "VK_OEM_FJ_MASSHOU",
    "VK_OEM_FJ_TOUROKU",
    "VK_OEM_FJ_LOYA",
    "VK_OEM_FJ_ROYA",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "Unknown",
    "VK_LSHIFT",
    "VK_RSHIFT",
    "VK_LCONTROL",
    "VK_RCONTROL",
    "VK_LMENU",
    "VK_RMENU"
};
static const int KeyCodes[] = {
    0x0,  //Undefined
    0x01,
    0x02,
    0x03,
    0x04,
    0x05,
    0x06,
    0x07, //Undefined
    0x08,
    0x09,
    0x0A, //Reserved
    0x0B, //Reserved
    0x0C,
    0x0D,
    0x0E, //Undefined
    0x0F, //Undefined
    0x10,
    0x11,
    0x12,
    0x13,
    0x14,
    0x15,
    0x16, //IME On
    0x17,
    0x18,
    0x19,
    0x1A, //IME Off
    0x1B,
    0x1C,
    0x1D,
    0x1E,
    0x1F,
    0x20,
    0x21,
    0x22,
    0x23,
    0x24,
    0x25,
    0x26,
    0x27,
    0x28,
    0x29,
    0x2A,
    0x2B,
    0x2C,
    0x2D,
    0x2E,
    0x2F,
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39,
    0x3A, //Undefined
    0x3B, //Undefined
    0x3C, //Undefined
    0x3D, //Undefined
    0x3E, //Undefined
    0x3F, //Undefined
    0x40, //Undefined
    0x41,
    0x42,
    0x43,
    0x44,
    0x45,
    0x46,
    0x47,
    0x48,
    0x49,
    0x4A,
    0x4B,
    0x4C,
    0x4B,
    0x4E,
    0x4F,
    0x50,
    0x51,
    0x52,
    0x53,
    0x54,
    0x55,
    0x56,
    0x57,
    0x58,
    0x59,
    0x5A,
    0x5B,
    0x5C,
    0x5D,
    0x5E, //Rservered
    0x5F,
    0x60, //Numpad1
    0x61, //Numpad2
    0x62, //Numpad3
    0x63, //Numpad4
    0x64, //Numpad5
    0x65, //Numpad6
    0x66, //Numpad7
    0x67, //Numpad8
    0x68, //Numpad8
    0x69, //Numpad9
    0x6A,
    0x6B,
    0x6C,
    0x6D,
    0x6E,
    0x6F,
    0x70, //F1
    0x71, //F2
    0x72, //F3
    0x73, //F4
    0x74, //F5
    0x75, //F6
    0x76, //F7
    0x77, //F8
    0x78, //F9
    0x79, //F10
    0x7A, //F11
    0x7B, //F12
    0x7C, //F13
    0x7D, //F14
    0x7E, //F15
    0x7F, //F16
    0x80, //F17
    0x81, //F18
    0x82, //F19
    0x83, //F20
    0x84, //F21
    0x85, //F22
    0x86, //F23
    0x87, //F24
    0x88, //Unkown
    0x89, //Unkown
    0x8A, //Unkown
    0x8B, //Unkown
    0x8C, //Unkown
    0x8D, //Unkown
    0x8E, //Unkown
    0x8F, //Unkown
    0x90,
    0x91,
    0x92, //OEM Specific
    0x93, //OEM Specific
    0x94, //OEM Specific
    0x95, //OEM Specific
    0x96, //OEM Specific
    0x97, //Unkown
    0x98, //Unkown
    0x99, //Unkown
    0x9A, //Unkown
    0x9B, //Unkown
    0x9C, //Unkown
    0x9D, //Unkown
    0x9E, //Unkown 
    0x9F, //Unkown
    0xA0,
    0xA1,
    0xA2,
    0xA3,
    0xA4,
    0xA5
};

class vec2 {
public:
    float x, y;

    vec2 operator+(const vec2& other) const {
        vec2 result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        return result;
    }

    vec2 operator-(const vec2& other) const {
        vec2 result;
        result.x = this->x - other.x;
        result.y = this->y - other.y;
        return result;
    }

    float length() const {
        return std::sqrt(x * x + y * y);
    }

    vec2 normalized() const {
        float len = length();
        if (len == 0) return { 0, 0 }; // Avoid division by zero
        return { x / len, y / len };
    }

    vec2 clamp() const {
        vec2 delta = *this;

        if (delta.x > 180) delta.x -= 360;
        if (delta.x < -180) delta.x += 360;
        if (delta.y > 180) delta.y -= 360;
        if (delta.y < -180) delta.y += 360;

        return delta;
    }

    vec2 operator/(float scalar) const {
        return { x / scalar, y / scalar };
    }

    vec2 operator*(float scalar) const {
        return { x * scalar, y * scalar };
    }
};

class vec3 {
public:
    float x = 0, y = 0, z = 0;

    vec3 operator+(const vec3& other) const {
        vec3 result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        result.z = this->z + other.z;
        return result;
    }

    vec3 operator-(const vec3& other) const {
        vec3 result;
        result.x = this->x - other.x;
        result.y = this->y - other.y;
        result.z = this->z - other.z;
        return result;
    }

    // Calculate the length of the vector
    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // Normalize the vector (make its length 1)
    vec3 normalized() const {
        float len = length();
        if (len == 0) return { 0, 0, 0 }; // Avoid division by zero
        return { x / len, y / len, z / len };
    }

    // Overload the division operator for scalar division
    vec3 operator/(float scalar) const {
        return { x / scalar, y / scalar, z / scalar };
    }

    // Overload the multiplication operator for scalar multiplication
    vec3 operator*(float scalar) const {
        return { x * scalar, y * scalar, z * scalar };
    }


};

class vec4 {
public:
    float x = 0, y = 0, z = 0, w = 0;

    vec4 operator+(const vec4& other) const {
        vec4 result;
        result.x = this->x + other.x;
        result.y = this->y + other.y;
        result.z = this->z + other.z;
        result.w = this->w + other.w;
        return result;
    }

    vec4 operator-(const vec4& other) const {
        vec4 result;
        result.x = this->x - other.x;
        result.y = this->y - other.y;
        result.z = this->z - other.z;
        result.w = this->w - other.w;
        return result;
    }
};

struct ViewMatrixObj {

    public:
	float matrix[16];

};

struct Bone {

    vec3 Position;
	std::string name;
};

struct PlayerData {
    

	vec3 m_vecOrigin;
    vec3 m_vecVelocity;
	uint32_t Health;
	uint32_t MaxHealth;
    bool isalive;
    bool dormant;
    int HeroID;
    int TeamNum;
    uint64_t weaponservices;
    uint64_t itemservices;
    uint64_t autoaimservices;
    uint64_t movementservices;


};

struct  xpData {

    vec3 m_vecOrigin;
    bool m_bDormant;
    float m_flLaunchtime;
    float CreationTime;
};

struct  NpcData {

    bool m_bMinion;
    int m_iHealth;
	int m_iMaxHealth;
    int m_ilifestate;
    int m_iteamnum;
    bool m_bDormant;
	vec3 m_vecOrigin;
    char* m_szClassname;



};

enum HeroIDs {
    Infernus = 1,
    Seven,
    Vindicta,
    LadyGeist,
    Abrams = 6,
    Wraith,
    McGinnis,
    Paradox = 10,
    Dynamo,
    Kelvin,
    Haze,
    Holliday,
    Bebop,
    GreyTalon = 17,
    MoAndKrill,
    Shiv,
    Ivy,
    Warden = 25,
    Yamato = 27,
    Lash = 31,
    Viscous = 35,
    Wrecker = 48,
    Pocket = 50,
    Mirage = 52
};

class CMsgQAngle {
public:
	char pad1[0x18];
	vec3 viewAngles;
};

class CMsgVector {
public:
    char pad01[0x18];
	vec3 m_vecOrigin;
};
 
class CInButtonStatePB {
public:
	char pad[0x18];
	uint32_t buttons;
 
};
 
class CBaseUserCMD {
public:
 
	char pad1[0x38];
	CInButtonStatePB* CInButtonStatePB;
	CMsgQAngle* playerViewAngle;
	char pad2[0x8];
	float forwardMove;
	float sideMove;
 
};
 
class CCitadelUserCmdPB {
public:
	char pad[0x8];
	DWORD commandNumber;
	char pad1[0x1C];
	CBaseUserCMD* pBaseUserCMD;
    CMsgVector* origin;
	CMsgQAngle* cameraViewAngle;
	char pad3[0x18];
	uint64_t buttons;
};

struct BoneConnection
{
    int bone1;
    int bone2;

    BoneConnection(int b1, int b2) : bone1(b1), bone2(b2) {}
};

struct Ray_t
{
public:
    vec3 m_vecStart;
    vec3 m_vecEnd;
    vec3 m_vecMins;
    vec3 m_vecMaxs;
    char pad[0x4];
    std::uint8_t UnkType;
};

static_assert(sizeof(Ray_t) == 0x38);

struct SurfaceData_t
{
public:
    char pad[0x8];
    float m_flPenetrationModifier;
    float m_flDamageModifier;
    char pad2[0x4];
    int m_iMaterial;
};

static_assert(sizeof(SurfaceData_t) == 0x18);

struct TraceHitboxData_t
{
public:
    char pad[0x38];
    int m_nHitGroup;
    char pad2[0x4];
    int m_nHitboxId;
};

static_assert(sizeof(TraceHitboxData_t) == 0x44);


struct GameTrace_t
{
public:
    GameTrace_t() = default;


    void* m_pSurface;
    uint64_t m_pHitEntity;
    TraceHitboxData_t* m_pHitboxData;
    // MEM_PAD(0x38);
    char pad[0x38];
    std::uint32_t m_uContents;
    // MEM_PAD(0x24);
    char pad2[0x24];
    vec3 m_vecStartPos;
    vec3 m_vecEndPos;
    vec3 m_vecNormal;
    vec3 m_vecPosition;
    // MEM_PAD(0x4);
    char pad3[0x4];
    float m_flFraction;
    // MEM_PAD(0x6);
    char pad4[0x6];
    bool m_bAllSolid;
    // MEM_PAD(0x4D)
    char pad5[0x4D];
}; // Size: 0x108

static_assert(sizeof(GameTrace_t) == 0x108);

struct TraceFilter_t
{
public:
    char pad[0x8];
    std::int64_t m_uTraceMask;
    int64_t m_v1[2];
	int32_t m_arrSkipHandles[4];
	int16_t m_arrCollisions[2];

    std::int16_t m_v2;
    std::uint8_t m_v3;
    std::uint8_t m_v4;
    std::uint8_t m_v5;
    TraceFilter_t() = default;
    TraceFilter_t(uint32_t uMask, uint64_t pSkip1, uint8_t nLayer, uint16_t unkNum);
};

static_assert(sizeof(TraceFilter_t) == 0x40);

class CGlobalVarsBase
{
public:
    float flRealTime; //0x0000 
    std::uint32_t iFrameCount; //0x0004 
    float flFrameTime; //0x0008 
    float flAbsFrameTime; //0x000C 
    std::uint32_t iMaxClients; //0x0010
private:
    [[maybe_unused]] float flUnkn1; //0x0014
    [[maybe_unused]] char pad_0x0018[0x1C]; //0x0018
public:
    float flCurtime; //0x0034 
    float flAbsCurTime; //0x0038 
    float flSomeFraction; //0x003C
private:
    [[maybe_unused]] char pad_0x0040[0x8]; //0x0040
public:
    std::uint32_t iTickCount; //0x0048
private:
    [[maybe_unused]] char pad_0x004C[0x14]; //0x004C
public:
    void* pNetChannel; //0x0060
private:
    [[maybe_unused]] char pad_0x0068[0x118]; //0x0068
public:
    char* szCurrentMap; //0x0180 
    char* szCurrentMapGame; //0x0188
private:
    [[maybe_unused]] char pad_0x0190[0x298]; //0x0190
};

class Helper {

public:
   
	static uint64_t GetModuleBaseAddress(uint64_t procId, const char* modName);
    static uint64_t GetClientBase();
	static uint64_t GetProcessIdByName(const char* processname);
	static uint64_t get_entity_list();
	static std::string readstr(uintptr_t address);
	static int get_max_entities();
	static uint64_t get_base_entity_from_index(int index);
	static uint64_t* get_base_entityptr_from_index(int index);
	static std::string get_schema_name(const uint64_t entity);
    static uint64_t CHandle_get_entry_index(uint64_t handle);
    static bool CHandle_is_valid(uint64_t handle);
    static uint64_t get_Camera();
    static uint64_t get_local_player();
    static bool get_player_data(uint64_t entity, PlayerData* outputPlrData);
    static bool getPawnData(uint64_t entity_pawn, PlayerData* outputPlrData);
    static uint64_t get_localplr_weapon();
    static uint64_t gettracemanager();
    static bool CheckLocationVisible(vec3 LocalPlayerPos, vec3 LocationCheck);

    //Bone Stuff
    static int get_bone_index(uintptr_t target_entity, const std::string bone_name);
    static vec3 GetBoneVectorFromIndex(uintptr_t target_entity, int index);
    static vec3 GetBonePosition(uintptr_t entity_controller, const char* BoneName);
    static std::vector<BoneConnection> GetBoneConnections(uintptr_t playerpawn, int heroid);

    static std::string ReadString(uintptr_t address);
    static bool WorldToScreen(vec3 pos, vec2& screen);
    static float GetDistance(vec3 src, vec3 dst);
    static std::string GetHeroNameByID(int id);
    static float DegreesToRadians(float degrees);
    static bool get_xp_data(uint64_t entity, xpData* xpdata);
    static vec2 GetResolution();
    static float GetGameTime();
    static CGlobalVarsBase* GetGlobals();
    static CCitadelUserCmdPB* GetCurrentUserCmd();
    static CCitadelUserCmdPB* ExperimentalGetUserCmd();
    static bool KeyBindHandler(int key);
	static bool get_npc_data(uint64_t entity, NpcData* npcdata);
    static bool __fastcall traceshape(void* dis, Ray_t* pRay, vec3* vecStart, vec3* vecEnd, TraceFilter_t* pFilter, GameTrace_t* pGameTrace);
    static void __fastcall ConstructFilter(__int64 a1, __int64 a2, __int64 a3, char a4, __int16 a5);
    static uint64_t GetPawnHandle(uint64_t entity);
    static uint64_t GetPawn(uint64_t entity_controller);
	static void CorrectMovement(CCitadelUserCmdPB* pCmd, float &fOldForward, float &fOldSidemove, vec3 oldangles);
    static void CorrectViewAngles(CCitadelUserCmdPB* pCmd);
    static void HotKey(KeyBind& keybind);
	static std::vector<uintptr_t> GetAbilities(uint64_t entity_pawn);
	static bool IsAbilityCasting(uintptr_t ability);



};

template <typename T = void*>
[[nodiscard]] constexpr T GetVFunc(const void* thisptr, std::size_t nIndex) {
    // Retrieve the virtual function pointer from the vtable
    return (*static_cast<T**>(const_cast<void*>(thisptr)))[nIndex];
}

template <typename T, std::size_t nIndex, typename CBaseClass, typename... Args>
[[nodiscard]] constexpr T CallVFunc(CBaseClass* thisptr, Args&&... args) {
    using VirtualFn_t = T(__thiscall*)(CBaseClass*, Args...);
    // Get the virtual function pointer from the vtable
    VirtualFn_t fn = GetVFunc<VirtualFn_t>(thisptr, nIndex);
    return fn(thisptr, std::forward<Args>(args)...);
}

static const uint64_t ClientModuleBase = Helper::GetClientBase();

class CGameTraceManager
{
public:
    bool TraceShape(Ray_t* pRay, vec3 vecStart, vec3 vecEnd, TraceFilter_t* pFilter, GameTrace_t* pGameTrace)
    {
        return Helper::traceshape(this, pRay, &vecStart, &vecEnd, pFilter, pGameTrace);
    }
};
