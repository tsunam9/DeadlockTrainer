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

	uint64_t FindParam(const char* ParamName)
	{
		using fnFindParam = uint64_t*(_fastcall*)(__int64 CMATthisPtr, uint64_t* Output, __int64 String);

		static auto findparams = reinterpret_cast<fnFindParam>(materialsystembase + 0xCBA0);

		uint64_t output = 0;

		uint64_t* returnvalue = findparams((__int64)this, &output, (__int64)ParamName);

		return output;
	}

	char __fastcall FindParamById(unsigned int id, uint64_t* output) {

		using fnFindParamById = char(__fastcall*)(__m128i* a1, uint64_t* a2, unsigned int a3);
		static auto findparambyid = reinterpret_cast<fnFindParamById>(materialsystembase + 0x75C0);

		char returnvalue = findparambyid(reinterpret_cast<__m128i*>(this), output, id);
		return returnvalue;
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
		auto result = oFindKeyVar(szName, 8LL, 826366246LL);
		return result;
		
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
		using fnSetMaterialShaderType = void(__fastcall*)(__int64 thisptr , int* , BYTE* a3, __int8 a4);
		static auto oSetMaterialShaderType = reinterpret_cast<fnSetMaterialShaderType>(particlesdllbase + MEM::PatternScanFunc((void*)particlesdllbase, "48 89 5c 24 ? 48 89 6c 24 ? 56 57 41 54 41 56 41 57 48 83 ec ? 0f b6 01 45 0f b6 f9 8b 2a 4d 8b e0 4c 8b 72 ? 48 8b d9 c0 e8 ? 24 ? 3c ? 74 ? 41 b0 ? b2 ? e8 ? ? ? ? 0f b6 03 33 ff c0 e8 ? 24 ? 3c ? 75 ? 48 8b 73 ? eb ? 48 8b f7 4c 8d 44 24 ? c7 44 24 ? ? ? ? ? 48 8d 54 24 ? 89 6c 24 ? 48 8b ce 4c 89 74 24 ? e8 ? ? ? ? 83 f8 ? 75 ? 45 33 c9 89 6c 24 ? 4c 8d 44 24 ? 4c 89 74 24 ? 48 8b d3 48 8b ce e8 ? ? ? ? 0f b6 0b c0 e9 ? 80 e1 ? 80 f9 ? 75 ? 48 8b 7b ? 80 7f ? ? 48 8d 57"));

		MaterialKeyVar_t shaderVar(0x162C1777, "shader");
		oSetMaterialShaderType((__int64)this, (int*)&shaderVar.uKey, (BYTE*)szShaderName, 0x1A);	
	}

	void SetMaterialFunction(const char* szFunctionName, int nValue)
	{
		using fnSetMaterialFunction = unsigned __int64*(__fastcall*)(unsigned __int64* a1, int* a2, int a3, unsigned __int8 a4);
		static auto oSetMaterialFunction = reinterpret_cast<fnSetMaterialFunction>(particlesdllbase + MEM::PatternScanFunc((void*)particlesdllbase, "48 89 5c 24 ? 48 89 6c 24 ? 56 57 41 54 41 56 41 57 48 83 ec ? 0f b6 01 45 0f b6 f9 8b 2a 48 8b d9"));

		MaterialKeyVar_t functionVar(szFunctionName, true);
		oSetMaterialFunction((unsigned __int64*)this, (int*)&functionVar.uKey , nValue, 0x14u);
	}

	char pad01[0x18];
	CSceneAnimatableObject* pSceneAnimatableObject; // 0x18
	CMaterial2* pMaterial; // 0x20
	CMaterial2* pMaterial2; // 0x28
	char pad02[0x20];
	Color_t colValue; // 0x40
	char pad03[0x4];
	CObjectInfo* pObjectInfo; // 0x48
};

class IMaterialSystem2
{
public:
	CMaterial2*** FindOrCreateFromResource(CMaterial2*** pOutMaterial, __int64 szMaterialName)
	{
		return MEM::CallVFunc<CMaterial2***, 14U>(this, pOutMaterial, szMaterialName);
	}

	CMaterial2** CreateMaterial(CMaterial2*** pOutMaterial, const char* szMaterialName, CMeshData* pData)
	{
		return MEM::CallVFunc<CMaterial2**, 29U>(this, pOutMaterial, szMaterialName, pData, 0, 1);
	}

	void SetCreateDataByMaterial(const void* pData, CMaterial2*** const pInMaterial)
	{
		return MEM::CallVFunc<void, 37U>(this, pInMaterial, pData);
	}




};

static const char* flat = R"(R"#(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d}
			format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
			{
                shader = "generic.vfx"
                g_tColor = resource:"materials/dev/primary_white_color_tga_4eaba099.vtex"
                g_tNormal = resource:"materials/default/default_normal_tga_7652cb.vtex"
                g_tRoughness = resource:"materials/default/default_normal_tga_794cb9ce.vtex"
                g_tMetalness = resource:"materials/default/default_normal_tga_794cb9ce.vtex"
                g_tAmbientOcclusion = resource:"materials/default/default_normal_tga_b3f4ec4c.vtex"
                F_IGNOREZ = 0
                F_DISABLE_Z_WRITE = 0
                F_DISABLE_Z_BUFFERING = 0
                F_RENDER_BACKFACES = 1
                g_vColorTint = [1.0, 1.0, 1.0, 1.0]
			} )#")";

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

static const char* debugMatBuffer = R"(<!-- kv3 encoding:text:version{e21c7f3c-8a33-41c5-9977-a76d3a32aa0d} format:generic:version{7412167c-06e9-4698-aff2-e63eb59037e7} -->
{
    shader = "environment_layer.vfx"
    
    F_PAINT_VERTEX_COLORS = 1
    F_TRANSLUCENT = 1
    F_DISABLE_Z_BUFFERING = 1
    F_BLEND_MODE = 1
    
    MaterialLayerReferenceShaderId_1 = -1
    g_flDisplacementAmount1 = 0
    g_flDisplacementMidlevel1 = 128
    
    TextureColor1 = resource:"materials/default/default_color_tga_22e6f7.vtex"
    TextureTintMask1 = resource:"materials/default/default_mask_tga_344101f8.vtex"
    
    g_vAlbedoContrastSaturationBrightness1 = [1.0, 1.0, 0.5, 0.0]
    g_vLayerRoughnessContrastBrightness1 = [0.0, 0.0, 0.0, 0.0]
})";



class Chams
{
public:

	static CStrongHandle<CMaterial2> CreateMaterial(const char* szMaterialName, const char szVmatBuffer[]);
	static void DrawChams(CMeshData* matdata, bool islocal, uint64_t entity_pawn, bool ignorez);

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
	char pad_0000[0x120];
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
