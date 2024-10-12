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

#define M_PI 3.14159265358979323846

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
	char pad2[0x10];
	float forwardMove;
	float sideMove;
 
};
 
class CCitadelUserCmdPB {
public:
	char pad[0x8];
	DWORD commandNumber;
	char pad1[0x1C];
	CBaseUserCMD* pBaseUserCMD;
	char pad2[0x8];
	CMsgQAngle* cameraViewAngle;
	char pad3[0x18];
	uint32_t buttons;
};

struct BoneConnection
{
    int bone1;
    int bone2;

    BoneConnection(int b1, int b2) : bone1(b1), bone2(b2) {}
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
	static std::string get_schema_name(const uintptr_t& entity);
    static uint64_t CHandle_get_entry_index(uint64_t handle);
    static bool CHandle_is_valid(uint64_t handle);
    static uint64_t get_Camera();
    static uint64_t get_local_player();
    static PlayerData get_player_data(uint64_t entity);
    static uint64_t get_localplr_weapon();

    //Bone Stuff
    static int get_bone_index(uintptr_t target_entity, const std::string bone_name);
    static vec3 GetBoneVectorFromIndex(uintptr_t target_entity, int index);
    static vec3 GetBonePosition(uintptr_t entity, const char* BoneName);
    static std::vector<BoneConnection> GetBoneConnections(uintptr_t playerpawn);

    static std::string ReadString(uintptr_t address);
    static bool WorldToScreen(vec3 pos, vec2& screen);
    static float GetDistance(vec3 src, vec3 dst);
    static std::string GetHeroNameByID(int id);
    static float DegreesToRadians(float degrees);
    static xpData get_xp_data(uint64_t entity);
    static vec2 GetResolution();
    static float GetGameTime();
    static CCitadelUserCmdPB* GetUserCmdArray();
    static CCitadelUserCmdPB* GetUserCmdByIndex(int index);
    static CCitadelUserCmdPB* GetCurrentUserCmd();
    static bool KeyBindHandler(int key);
	static NpcData get_npc_data(uint64_t entity);


};

static const uint64_t ClientModuleBase = Helper::GetClientBase();
