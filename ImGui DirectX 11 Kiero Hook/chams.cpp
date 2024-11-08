#include "chams.h"

typedef void (__fastcall* fnCreateMaterial)(void*, void*, const char*, void*, unsigned int, unsigned int);
fnCreateMaterial creatematerial = fnCreateMaterial(materialsystembase + (MEM::PatternScanFunc((void*)materialsystembase, "48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 56 48 81 EC ? ? ? ? 48 8B 05")));

#define LODWORD(l) (*((DWORD*)&(l)))  // Cast to DWORD pointer and dereference

CStrongHandle<CMaterial2> Chams::CreateMaterial(const char* szMaterialName, const char szVmatBuffer[])
{
	CKeyValues3* pKeyValues3 = CKeyValues3::CreateMaterialResource();
	pKeyValues3->LoadFromBuffer(szVmatBuffer);

	CStrongHandle<CMaterial2> pCustomMaterial = {};
	creatematerial(nullptr, &pCustomMaterial, szMaterialName, pKeyValues3, 0, 1);

	return pCustomMaterial;
}

struct CustomMaterial_t
{
	CStrongHandle<CMaterial2> pMaterial;
	CStrongHandle<CMaterial2> pMaterialInvisible;
};

static CustomMaterial_t arrMaterials[0x32ull];

uint64_t asdmatsystemasbase = MEM::GetModuleBaseAddress(MEM::GetProcessIdByName("project8.exe"), "materialsystem2.dll");
typedef CMaterial2*** (*f_findmat)(__int64 a1, __int64* a2, __int64 a3);
f_findmat drawfindmattarget = reinterpret_cast<f_findmat>(asdmatsystemasbase + MEM::PatternScanFunc((void*)asdmatsystemasbase, "4c 8b dc 49 89 5b ? 49 89 73 ? 57 48 81 ec ? ? ? ? 33 db"));

typedef void(__fastcall* f_WrappedSetMaterial)(
	unsigned __int64* CMeshDataThisPtr,
	unsigned __int8 FunctionVar,
	unsigned __int8 Value);

static f_WrappedSetMaterial SetMaterialFunction = reinterpret_cast<f_WrappedSetMaterial>(particlesdllbase + 0x3CCaD0);

using fnFindKeyVar = uint64_t(_fastcall*)(const char*, unsigned int, int);
static auto oFindKeyVar = reinterpret_cast<fnFindKeyVar>(particlesdllbase + MEM::PatternScanFunc((void*)particlesdllbase, "48 89 5C 24 ? 57 48 81 EC ? ? ? ? 33 C0 8B DA"));

using fnFindPerameter = uint64_t(_fastcall*)(__int64 materialHandle, const char* parameterName);
static auto Findparam = reinterpret_cast<fnFindPerameter>(asdmatsystemasbase + 0xCB70);


void Chams::DrawChams(CMeshData* matdata, bool islocal, uint64_t entity_pawn) {

	if (!matdata)
		return;


	PlayerData targetchamsdata;
	PlayerData LocalPlayerData;
	Helper::getPawnData(entity_pawn, &targetchamsdata);
	Helper::get_player_data(Helper::get_local_player(), &LocalPlayerData);


	static auto mymatsystem = GetInterface<IMaterialSystem2>("materialsystem2.dll", "VMaterialSystem2_001");

	CMaterial2*** mymat2 = new CMaterial2**;
	const char* str = "materials/dev/primary_white.vmat";
	auto test = (__int64)(str);
	CMaterial2*** mymaterial = drawfindmattarget((__int64)mymatsystem, (__int64*)mymat2, test);



	if (islocal && Config.esp.LocalChams) {
		matdata->colValue.r = Config.colors.LocalChamsCol.x * 255;
		matdata->colValue.g = Config.colors.LocalChamsCol.y * 255;
		matdata->colValue.b = Config.colors.LocalChamsCol.z * 255;
		matdata->colValue.a = Config.colors.LocalChamsCol.w * 255;
		if (Config.esp.ModelChams) {
			matdata->pMaterial = **mymaterial;
			matdata->pMaterial2 = **mymaterial;
		}
		goto LABEL_1;
	}

	if (targetchamsdata.TeamNum == LocalPlayerData.TeamNum)
		return;

	matdata->colValue.r = Config.colors.ChamsCol.x * 255;
	matdata->colValue.g = Config.colors.ChamsCol.y * 255;
	matdata->colValue.b = Config.colors.ChamsCol.z * 255;
	matdata->colValue.a = Config.colors.ChamsCol.w * 255;
	if (Config.esp.ModelChams) {
		matdata->pMaterial = **mymaterial;
		matdata->pMaterial2 = **mymaterial;
	}






	/*	auto ignorez = matdata->pMaterial->FindParam("F_DISABLE_Z_WRITE");
	if (ignorez) {
		std::cout << ignorez << std::endl;
	}*/


	LABEL_1:

	delete mymat2;
	return;

}

/*
	if (Config.aimbot.bAimbot) {



		

		uint32_t* flags = (uint32_t*)((uint32_t)(matdata->pMaterial) + Config.tempvalues.inputint);



		if (*flags & (1 << 15)) {
			std::cout << "FLAGSVALUE : " << *flags << std::endl;
			std::cout << "OFFSET : " << std::hex << Config.tempvalues.inputint << std::endl;
			std::cout << "IGNOREZ : TRUE" << std::endl;
			std::cout << "----------" << std::endl;
		}
		else {
			std::cout << "FLAGSVALUE : " << *flags << std::endl;
			std::cout << "OFFSET : " << std::hex << Config.tempvalues.inputint << std::endl;
			std::cout << "IGNOREZ : FALSE" << std::endl;
			std::cout << "----------" << std::endl;
		}

		*flags |= MaterialVarFlags_t::MATERIAL_VAR_IGNOREZ;
	}
	else {
		std::cout << "MATDATA : " << matdata << "\n";
	}*/
