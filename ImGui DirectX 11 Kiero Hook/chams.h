#pragma once	
#include "Windows.h"
#include "stdint.h"
#include "helper.h"
#include "mem.h"
#include "gameinterface.h"
#include <emmintrin.h> // Include header for SSE intrinsics

static uint64_t particlesdllbase = MEM::GetModuleBaseAddress(MEM::GetProcessIdByName("project8.exe"), "particles.dll");
static uint64_t hTier0 = MEM::GetModuleBaseAddress(MEM::GetProcessIdByName("project8.exe"), "tier0.dll");
static uint64_t materialsystembase = MEM::GetModuleBaseAddress(MEM::GetProcessIdByName("project8.exe"), "materialsystem2.dll");
static uint64_t meshsystembase = MEM::GetModuleBaseAddress(MEM::GetProcessIdByName("project8.exe"), "meshsystem.dll");

template <typename T = std::uint8_t>
[[nodiscard]] T* GetAbsoluteAddress(T* pRelativeAddress, int nPreOffset = 0x0, int nPostOffset = 0x0)
{
	pRelativeAddress += nPreOffset;
	pRelativeAddress += sizeof(std::int32_t) + *reinterpret_cast<std::int32_t*>(pRelativeAddress);
	pRelativeAddress += nPostOffset;
	return pRelativeAddress;
}

class CUtlBuffer;

typedef void(__fastcall* fnUtlBufferInit)(CUtlBuffer*, int, int, int);
typedef void(__fastcall* fnUtlBufferPutString)(CUtlBuffer*, const char*);
typedef void(__fastcall* fnUtlBufferEnsureCapacity)(CUtlBuffer*, int);

static fnUtlBufferInit utlbufferinit = (fnUtlBufferInit)(MEM::GetExportAddress((void*)hTier0, "??0CUtlBuffer@@QEAA@HHH@Z"));
static fnUtlBufferPutString utlbufferputstring = (fnUtlBufferPutString)(MEM::GetExportAddress((void*)hTier0, "?PutString@CUtlBuffer@@QEAAXPEBD@Z"));
static fnUtlBufferEnsureCapacity utlbufferensurecapacity = (fnUtlBufferEnsureCapacity)(MEM::GetExportAddress((void*)hTier0, "?EnsureCapacity@CUtlBuffer@@QEAAXH@Z"));

class CUtlBuffer
{
public:
	char pad01[0x80];

	CUtlBuffer(int a1, int nSize, int a3)
	{
		utlbufferinit(this, a1, nSize, a3);
	}

	void PutString(const char* szString)
	{
		utlbufferputstring(this, szString);
	}

	void EnsureCapacity(int nSize)
	{
		utlbufferensurecapacity(this, nSize);
	}
};


struct KV3ID_t
{
	const char* szName;
	std::uint64_t unk0;
	std::uint64_t unk1;
	KV3ID_t(const char* name, std::uint64_t unknown0, std::uint64_t unknown1) {
		szName = name;
		unk0 = unknown0;
		unk1 = unknown1;
	}
};

class CKeyValues3
{
public:
	char pad01[0x100];
	std::uint64_t uKey;
	void* pValue;
	char pad02[0x8];

	inline void LoadFromBuffer(const char* szString);
	inline bool LoadKV3(CUtlBuffer* buffer);

	static CKeyValues3* CreateMaterialResource()
	{
		using fnSetTypeKV3 = CKeyValues3 * (_fastcall*)(CKeyValues3*, unsigned int, unsigned int);
		static const fnSetTypeKV3 oSetTypeKV3 = reinterpret_cast<fnSetTypeKV3>(ClientModuleBase + (MEM::PatternScanFunc((void*)ClientModuleBase, "40 53 48 83 ec ? 48 8b d9 49 ba")));

		CKeyValues3* pKeyValue = new CKeyValues3[0x10];
		return oSetTypeKV3(pKeyValue, 1U, 6U);
	}
};

void CKeyValues3::LoadFromBuffer(const char* szString)
{
	CUtlBuffer buffer(0, strlen(szString) + 10, 1);
	buffer.PutString(szString); 
	LoadKV3(&buffer);
}

bool CKeyValues3::LoadKV3(CUtlBuffer* buffer)
{
	using fnLoadKeyValues = bool(__fastcall*)(CKeyValues3*, void*, CUtlBuffer*, KV3ID_t*, void*, void*, void*, void*, const char*);
	static const fnLoadKeyValues oLoadKeyValues = (fnLoadKeyValues)(hTier0 + (MEM::PatternScanFunc((void*)hTier0, "48 89 5c 24 ? 48 89 6c 24 ? 48 89 7c 24 ? 41 54 41 56 41 57 48 83 ec ? 45 33 e4")));

	const char* szName = "";
	KV3ID_t kv3ID = KV3ID_t("generic", 0x41B818518343427E, 0xB5F447C23C0CDF8C);
	return oLoadKeyValues(this, nullptr, buffer, &kv3ID, nullptr, nullptr, nullptr, nullptr, "");
	return false;
}

struct ResourceBinding_t
{
	void* pData;
};

template <typename T>
class CStrongHandle
{
public:
	operator T* () const
	{
		if (pBinding == nullptr)
			return nullptr;

		return static_cast<T*>(pBinding->pData);
	}

	T* operator->() const
	{
		if (pBinding == nullptr)
			return nullptr;

		return static_cast<T*>(pBinding->pData);
	}

	const ResourceBinding_t* pBinding;
};

enum MaterialVarFlags_t
{
	MATERIAL_VAR_DEBUG = (1 << 0),
	MATERIAL_VAR_NO_DEBUG_OVERRIDE = (1 << 1),
	MATERIAL_VAR_NO_DRAW = (1 << 2),
	MATERIAL_VAR_USE_IN_FILLRATE_MODE = (1 << 3),
	MATERIAL_VAR_VERTEXCOLOR = (1 << 4),
	MATERIAL_VAR_VERTEXALPHA = (1 << 5),
	MATERIAL_VAR_SELFILLUM = (1 << 6),
	MATERIAL_VAR_ADDITIVE = (1 << 7),
	MATERIAL_VAR_ALPHATEST = (1 << 8),
	MATERIAL_VAR_ZNEARER = (1 << 10),
	MATERIAL_VAR_MODEL = (1 << 11),
	MATERIAL_VAR_FLAT = (1 << 12),
	MATERIAL_VAR_NOCULL = (1 << 13),
	MATERIAL_VAR_NOFOG = (1 << 14),
	MATERIAL_VAR_IGNOREZ = (1 << 15),
	MATERIAL_VAR_DECAL = (1 << 16),
	MATERIAL_VAR_ENVMAPSPHERE = (1 << 17), // OBSOLETE
	MATERIAL_VAR_ENVMAPCAMERASPACE = (1 << 19), // OBSOLETE
	MATERIAL_VAR_BASEALPHAENVMAPMASK = (1 << 20),
	MATERIAL_VAR_TRANSLUCENT = (1 << 21),
	MATERIAL_VAR_NORMALMAPALPHAENVMAPMASK = (1 << 22),
	MATERIAL_VAR_NEEDS_SOFTWARE_SKINNING = (1 << 23), // OBSOLETE
	MATERIAL_VAR_OPAQUETEXTURE = (1 << 24),
	MATERIAL_VAR_ENVMAPMODE = (1 << 25), // OBSOLETE
	MATERIAL_VAR_SUPPRESS_DECALS = (1 << 26),
	MATERIAL_VAR_HALFLAMBERT = (1 << 27),
	MATERIAL_VAR_WIREFRAME = (1 << 28),
	MATERIAL_VAR_ALLOWALPHATOCOVERAGE = (1 << 29),
	MATERIAL_VAR_ALPHA_MODIFIED_BY_PROXY = (1 << 30),
	MATERIAL_VAR_VERTEXFOG = (1 << 31),
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


struct CMaterial2
{
	virtual const char* GetName() = 0;
	virtual const char* GetShareName() = 0;

	bool IsLoaded() {
		return MEM::CallVFunc<bool, 4>(this);
	}

	__int64 GetAttributes()
	{
		return MEM::CallVFunc<__int64, 24>(this);
	}

	__int64 GetVertexShaderInputSignature()
	{
		return MEM::CallVFunc<__int64, 18>(this);
	}

};


struct MaterialKeyVar_t
{
	uint64_t uKey;
	const char* szName;

	MaterialKeyVar_t(uint64_t uKey, const char* szName) :
		uKey(uKey), szName(szName) { }

	MaterialKeyVar_t(const char* szName, bool bShouldFindKey = false) :
		szName(szName)
	{
		uKey = bShouldFindKey ? FindKey(szName) : 0x0;
	}

	uint64_t FindKey(const char* szName)
	{
		using fnFindKeyVar = uint64_t(_fastcall*)(const char*, unsigned int, int);
		static auto oFindKeyVar = reinterpret_cast<fnFindKeyVar>(particlesdllbase + MEM::PatternScanFunc((void*)particlesdllbase, "48 89 5C 24 ? 57 48 81 EC ? ? ? ? 33 C0 8B DA"));

		// idk those enum flags, just saw it called like that soooo yea
		return oFindKeyVar(szName, 0x12, 0x31415926);
		
	}
};

class CObjectInfo
{
	char pad01[0xB0];
	int nId;
};

class CMeshInstance_IMP {
public:
	__int64 SetMaterialOverrides(uint64_t thisptr, CStrongHandle<CMaterial2> material, int nummaterials) {
		using fnSetMatOverrides = __int64(__fastcall*)(uint64_t thisptr, CStrongHandle<CMaterial2> material, int nummaterials);
		static auto OverrideMaterials = reinterpret_cast<fnSetMatOverrides>(meshsystembase + MEM::PatternScanFunc((void*)meshsystembase, "40 55 41 56 41 57 48 83 ec ? 48 8d 6c 24 ? 48 8b 41 ? 48 89 5d"));

	return OverrideMaterials(thisptr, material, nummaterials);

	}
};

class CMeshData
{
public:

	CMeshInstance_IMP* pMeshInstance;
	char pad01[0x10];
	CSceneAnimatableObject* pSceneAnimatableObject; // 0x18
	CMaterial2* pMaterial; // 0x20
	CMaterial2* pMaterial2; // 0x28
	char pad02[0x20];
	Color_t colValue; // 0x50 
	char pad03[0x10];
};

class IMaterialSystem2
{
public:



	CMaterial2*** FindOrCreateFromResource(CMaterial2*** pOutMaterial, __int64 materialnameptr)
	{
		return MEM::CallVFunc<CMaterial2***, 14U>(this, (__int64*)pOutMaterial, (__int64)materialnameptr);
	}

	CMaterial2** CreateMaterial(CMaterial2*** pOutMaterial, const std::string_view new_material_name, void* pData)
	{
		return MEM::CallVFunc<CMaterial2**, 29U>(this, pOutMaterial, new_material_name.data(), pData, 0, 1);
	}

	void SetCreateDataByMaterial(const void* pData, CMaterial2*** const pInMaterial)
	{
		return MEM::CallVFunc<void, 37U>(this, pInMaterial, pData);
	}

};

static constexpr char szVMatBufferWhiteInvisible[] =
R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "pbr.vfx"
	
	F_SELF_ILLUM = 1
	g_flSelfIllumScale1 = 0.05	

	g_tAmbientOcclusion = resource:"materials/default/default_ao_tga_559f1ac6.vtex"
	g_tColor = resource:"materials/dev/primary_white_color_tga_e79cd79d.vtex"
	g_tNormalRoughness = resource:"materials/default/default_normal_tga_7be61377.vtex"
	g_tSelfIllumMask = resource:"materials/dev/primary_white_color_tga_e3f40130.vtex"
	g_tTintMask = resource:"materials/default/default_mask_tga_344101f8.vtex"

})";



class Chams
{
public:

	static CStrongHandle<CMaterial2> CreateMaterial(const char* szMaterialName, const char szVmatBuffer[]);
	static void HandleMaterial(CMeshData* matdata, uint64_t entity_pawn, CMaterial2* material);
	static void HandleColor(CMeshData* matdata, uint64_t entity_pawn,int localteamnum, int numMeshes);

};

class CSceneObject
{
public:
    char pad_0000[184]; //0x0000
    uint8_t r; //0x00B8
    uint8_t g; //0x00B9
    uint8_t b; //0x00BA
    uint8_t a; //0x00BB
    char pad_00BC[196]; //0x00BC
}; //Size: 0x0180

class CBaseSceneData
{
public:
    char pad_0000[0x18]; //0x0000
    CSceneObject* sceneObject; //0x0018
    CMaterial2* material; //0x0020
    CMaterial2* material2; //0x0028
    char pad_0030[0x20]; //0x0030
    uint8_t r; //0x0040
    uint8_t g; //0x0041
    uint8_t b; //0x0042
    uint8_t a; //0x0043
    char pad_0044[36]; //0x0044
}; //Size: 0x0068

class C_AggregateSceneObjectData
{
public:
	char pad_0000[56]; //0x0000
	uint8_t r; //0x0038
	uint8_t g; //0x0039
	uint8_t b; //0x003A
	uint8_t a; //0x003B
	char pad0001[0x8];
}; 


class C_AggregateSceneObject
{
private:
	char pad_0000[0x130];
public:
	int m_nCount; // 0x120
private:
	char pad_0120[0x4];
public:
	C_AggregateSceneObjectData* m_pData; // 0x128
};

class C_SceneLightObject
{
public:
    char pad_0000[0xE4]; // 0x0
    float r; // 0xE4
    float g; // 0xE4
    float b; // 0xE4
};
