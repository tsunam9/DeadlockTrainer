#include "chams.h"

typedef void (__fastcall* fnCreateMaterial)(void*, void*, const char*, void*, unsigned int, unsigned int);
static uint64_t materialsystembase = Helper::GetModuleBaseAddress(Helper::GetProcessIdByName("project8.exe"), "materialsystem2.dll");
fnCreateMaterial creatematerial = fnCreateMaterial(materialsystembase + (MEM::PatternScanFunc((void*)materialsystembase, "48 89 5C 24 ? 48 89 6C 24 ? 56 57 41 56 48 81 EC ? ? ? ? 48 8B 05")));


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


void Chams::DrawChams(material_data_t* matdata) {

	if (!matdata)
		return;

	void* material = Chams::CreateMaterial("materials/debug/debugempty.vmat_c", texturedchams);


	matdata->pMaterial = material;



}
