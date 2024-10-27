#pragma once	
#include "Windows.h"
#include "stdint.h"
#include "helper.h"
#include "mem.h"

static uint64_t particlesdllbase = Helper::GetModuleBaseAddress(Helper::GetProcessIdByName("project8.exe"), "particles.dll");
static uint64_t hTier0 = Helper::GetModuleBaseAddress(Helper::GetProcessIdByName("project8.exe"), "tier0.dll");

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
		static const fnSetTypeKV3 oSetTypeKV3 = reinterpret_cast<fnSetTypeKV3>(ClientModuleBase + (MEM::PatternScanFunc((void*)ClientModuleBase, "40 53 48 83 EC 20 48 8B 01 48 8B D9 44")));

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
	static const fnLoadKeyValues oLoadKeyValues = (fnLoadKeyValues)(hTier0 + (MEM::PatternScanFunc((void*)hTier0, "48 89 5c 24 ? 48 89 6c 24 ? 57 41 56 41 57 48 83 ec ? 4d 8b f9")));

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

class CMaterial2
{
public:
	virtual const char* GetName() = 0;
	virtual const char* GetShareName() = 0;
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
		static auto oFindKeyVar = reinterpret_cast<fnFindKeyVar>(MEM::PatternScanFunc((void*)particlesdllbase, "48 89 5C 24 ? 57 48 81 EC ? ? ? ? 33 C0 8B DA"));

		// idk those enum flags, just saw it called like that soooo yea
		return oFindKeyVar(szName, 0x12, 0x31415926);
	}
};

class CObjectInfo
{
	char pad01[0xB0];
	int nId;
};

class CMeshData
{
public:
	void SetShaderType(const char* szShaderName)
	{
		// @ida: #STR: shader, spritecard.vfx
		using fnSetMaterialShaderType = void(__fastcall*)(void*, MaterialKeyVar_t, const char*, int);
		static auto oSetMaterialShaderType = reinterpret_cast<fnSetMaterialShaderType>(MEM::PatternScanFunc((void*)particlesdllbase, "48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 54 41 56 41 57 48 83 EC ? 0F B6 01 45 0F B6 F9 8B 2A 4D 8B E0 4C 8B 72 ? 48 8B F9 C0 E8 ? 24 ? 3C ? 74 ? 41 B0 ? B2 ? E8 ? ? ? ? 0F B6 07 33 DB C0 E8 ? 24 ? 3C ? 75 ? 48 8B 77 ? EB ? 48 8B F3 4C 8D 44 24 ? C7 44 24 ? ? ? ? ? 48 8D 54 24 ? 89 6C 24 ? 48 8B CE 4C 89 74 24 ? E8 ? ? ? ? 8B D0 83 F8 ? 75 ? 45 33 C9 89 6C 24 ? 4C 8D 44 24 ? 4C 89 74 24 ? 48 8B D7 48 8B CE E8 ? ? ? ? 8B D0 0F B6 0F C0 E9 ? 80 E1 ? 80 F9 ? 75 ? 48 8B 4F ? EB ? 48 8B CB 8B 41 ? 85 C0 74 ? 48 8D 59 ? 83 F8 ? 76 ? 48 8B 1B 48 63 C2 4D 85 E4"));

#ifdef CS_PARANOID
		CS_ASSERT(oSetMaterialShaderType != nullptr);
#endif

		MaterialKeyVar_t shaderVar(0x162C1777, "shader");
		oSetMaterialShaderType(this, shaderVar, szShaderName, 0x18);
	}

	void SetMaterialFunction(const char* szFunctionName, int nValue)
	{
		using fnSetMaterialFunction = void(__fastcall*)(void*, MaterialKeyVar_t, int, int);
		static auto oSetMaterialFunction = reinterpret_cast<fnSetMaterialFunction>(MEM::PatternScanFunc((void*)particlesdllbase, "48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 54 41 56 41 57 48 83 EC ? 0F B6 01 45 0F B6 F9 8B 2A 48 8B F9"));

		MaterialKeyVar_t functionVar(szFunctionName, true);
		oSetMaterialFunction(this, functionVar, nValue, 0x18);
	}

	char pad01[0x18];
	CSceneAnimatableObject* pSceneAnimatableObject; // 0x18
	CMaterial2* pMaterial; // 0x20
	char pad02[0x18];
	Color_t colValue; // 0x40
	char pad03[0x4];
	CObjectInfo* pObjectInfo; // 0x48
};

class IMaterialSystem2
{
public:
	CMaterial2*** FindOrCreateFromResource(CMaterial2*** pOutMaterial, const char* szMaterialName)
	{
		return CallVFunc<CMaterial2***, 14U>(this, pOutMaterial, szMaterialName);
	}

	CMaterial2** CreateMaterial(CMaterial2*** pOutMaterial, const char* szMaterialName, CMeshData* pData)
	{
		return CallVFunc<CMaterial2**, 29U>(this, pOutMaterial, szMaterialName, pData, 0, 0, 0, 0, 0, 1);
	}

	void SetCreateDataByMaterial(const void* pData, CMaterial2*** const pInMaterial)
	{
		return CallVFunc<void, 37U>(this, pInMaterial, pData);
	}
};

static const char* flat = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
	shader = "toossls_2d_generic.vfx"
	
	g_tColorTexture = resource:"materials/default/default_color_tga_22e6f7.vtex_c"
})";

static const char* texturedchams = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
    shader = "environment_layer.vfx"
    IS_LEGACY = 1
    F_IGNOREZ = 1
    F_DISABLE_Z_WRITE = 1
    F_DISABLE_Z_BUFFERING = 1
    F_PAINT_VERTEX_COLORS = 1
    F_TRANSLUCENT = 1
    F_BLEND_MODE = 1
    
    
    MaterialLayerReferenceShaderId_1 = -1
    g_flDisplacementAmount1 =     0
    g_flDisplacementMidlevel1 =     128
    TextureColor1 =                      resource:"materials/default/default_color_tga_22e6f7.vtex_c"
    TextureTintMask1 =                  resource:"materials/default/default_mask_tga_344101f8.vtex_c"
    TextureNormal1 =                  resource:"materials/flat/flat_generic_03_normal_png_aab68adb.vtex_c"
    TextureRoughness1 =                  resource:"materials/particle/abilities/archer/archer_charged_shot_vmat_g_tnormalroughness_d52512a9.vtex_c"
    TextureAmbientOcclusion1 =          resource:"materials/default/default_ao_tga_303cc73a.vtex_c"
    TextureMetalness1 =                  resource:"materials/default/default_metal_tga_c7502e1.vtex_c"
    TextureDisplacement1 =              resource:"materials/concrete/concrete_trim_01_vmat_g_ttintmaskdisplacement_86a014fe.vtex_c"
    
    g_tColor1 = resource:"materials/default/default_color_tga_fcc21737.vtex_c"
    g_tNormalRoughness1 =   resource:"materials/particle/abilities/archer/archer_charged_shot_vmat_g_tnormalroughness_d52512a9.vtex_c"
    g_tPacked1 =    resource:"materials/default/default_ao_tga_303cc73a.vtex_c"
    
 
})";

class Chams
{
public:

	static CStrongHandle<CMaterial2> CreateMaterial(const char* szMaterialName, const char szVmatBuffer[]);
	static void DrawChams(material_data_t* matdata);

};
