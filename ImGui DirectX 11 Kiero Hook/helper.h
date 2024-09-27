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

class ViewMatrixObj {

    public:
	float matrix[16];

};

class Bone {
public:
    vec3 Position;
	std::string name;
};

class PlayerData {
public:

	vec3 m_vecOrigin;
	uint64_t Health;
	uint64_t MaxHealth;
    bool isalive;
    int HeroID;
    int TeamNum;


};

class Helper {

public:

	uint64_t GetModuleBaseAddress(uint64_t procId, const char* modName);
	uint64_t Modulebaseaddress = GetModuleBaseAddress(GetProcessIdByName("project8.exe"), "client.dll");
	uint64_t GetProcessIdByName(const char* processname);
	uint64_t get_entity_list();
	std::string readstr(uintptr_t address);
	int get_max_entities();
	uint64_t get_base_entity_from_index(int index);
	uint64_t* get_base_entityptr_from_index(int index);
	std::string get_schema_name(const uintptr_t& entity);
	uint64_t CHandle_get_entry_index(uint64_t handle);
	bool CHandle_is_valid(uint64_t handle);
	uint64_t get_Camera();
	uint64_t get_local_player();
	PlayerData get_player_data(uint64_t entity);
    int get_index(uintptr_t target_entity, const std::string bone_name);
    vec3 GetBoneVectorFromIndex(uintptr_t target_entity, int index);
    std::string ReadString(uintptr_t address);
    bool WorldToScreen(vec3 pos, vec2& screen, float matrix[16]);

};