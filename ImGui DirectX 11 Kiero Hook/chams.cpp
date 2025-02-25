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

#include <mutex>

static std::mutex printMutex; // Declare a mutex

static void printBinary(uint64_t num) {
	std::lock_guard<std::mutex> lock(printMutex); // Acquire the mutex lock

	// Create a mask to check each bit
	for (int i = 63; i >= 0; --i) {
		// Print the bit at the current position
		std::cout << ((num >> i) & 1);
	}
	std::cout << std::endl; // New line after the binary output
}

CMaterial2* create_material(const std::string_view material_name) {
	std::array< byte*, 0x200 > buffer{ };

	static auto mymatsystem = GetInterface<IMaterialSystem2>("materialsystem2.dll", "VMaterialSystem2_001");

	const struct set_material_data_t {
		explicit constexpr set_material_data_t(void* data) : m_data(data) {}


		[[nodiscard]] auto get_data() const noexcept { return this->m_data; }
	private:
		void* m_data{ };
	} material(buffer.data() + 0x50);

	CMaterial2** material_prototype;

	const char* str = "materials/dev/primary_white.vmat";

	mymatsystem->FindOrCreateFromResource(&material_prototype, (__int64)str);
	mymatsystem->SetCreateDataByMaterial(material.get_data(), &material_prototype);


	CMaterial2** custom_material;
	mymatsystem->CreateMaterial(&custom_material, material_name, material.get_data());

	return *custom_material;

}

void Chams::HandleMaterial(CMeshData* matdata, uint64_t entity_pawn, CMaterial2* material) {

	if (!matdata)
		return;

	PlayerData targetchamsdata;
	PlayerData LocalPlayerData;
	Helper::getPawnData(entity_pawn, &targetchamsdata);
	Helper::get_player_data(Helper::get_local_player(), &LocalPlayerData);

	static auto setmat = Chams::CreateMaterial("invisible", szVMatBufferWhiteInvisible);

	if (targetchamsdata.TeamNum == LocalPlayerData.TeamNum && cfg::esp_tChams) {
		material = setmat;
	}
	else if (cfg::esp_eChams) {
		material = setmat;
	}

}

void Chams::HandleColor(CMeshData* matdata, uint64_t entity_pawn, int localteamnum, int numMeshes) {

	if (!matdata)
		return;

	PlayerData targetchamsdata;
	Helper::getPawnData(entity_pawn, &targetchamsdata);

	for (int i = 0; i < numMeshes; i++) {

		auto& currentMesh = matdata[i];

		if (targetchamsdata.TeamNum == localteamnum && cfg::esp_tChams) {
			currentMesh.colValue.r = cfg::colors_tChamsCol.x * 255;
			currentMesh.colValue.g = cfg::colors_tChamsCol.y * 255;
			currentMesh.colValue.b = cfg::colors_tChamsCol.z * 255;
			currentMesh.colValue.a = cfg::colors_tChamsCol.w * 255;
		}
		else if (cfg::esp_eChams) {
			currentMesh.colValue.r = cfg::colors_eChamsCol.x * 255;
			currentMesh.colValue.g = cfg::colors_eChamsCol.y * 255;
			currentMesh.colValue.b = cfg::colors_eChamsCol.z * 255;
			currentMesh.colValue.a = cfg::colors_eChamsCol.w * 255;
		}


	}

}

