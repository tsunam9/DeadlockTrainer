#include "mem.h"


/*
     * @brief Scan for a given byte pattern on a module
     *
     * @Param module    Base of the module to search
     * @Param signature IDA-style byte array pattern
     *
     * @Returns Address of the first occurence
     */

uint64_t MEM::GetProcessIdByName(const char* processname) {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    PROCESSENTRY32 procEntry;
    procEntry.dwSize = sizeof(procEntry);

    do {
        if (!strcmp(procEntry.szExeFile, processname)) {
            CloseHandle(hSnap);
            return procEntry.th32ProcessID;
        }
    } while (Process32Next(hSnap, &procEntry));

    CloseHandle(hSnap);
    return 0;
}

uint64_t MEM::GetModuleBaseAddress(uint64_t procId, const char* modName) {
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
    MODULEENTRY32 modEntry;
    modEntry.dwSize = sizeof(modEntry);

    do {
        if (!strcmp(modEntry.szModule, modName)) {
            CloseHandle(hSnap);
            return (uint64_t)modEntry.modBaseAddr;
        }
    } while (Module32Next(hSnap, &modEntry));

    CloseHandle(hSnap);
    return 0;
}

uint64_t MEM::GetClientBase() {
    static uint64_t Modulebaseaddress = GetModuleBaseAddress(GetProcessIdByName("project8.exe"), "client.dll");
    return Modulebaseaddress;
}

 uint64_t ClientModuleBase = MEM::GetClientBase();

std::uint8_t* MEM::PatternScan(void* module, const char* signature)
{
    static auto pattern_to_byte = [](const char* pattern) {
        auto bytes = std::vector<int>{};
        auto start = const_cast<char*>(pattern);
        auto end = const_cast<char*>(pattern) + strlen(pattern);

        for (auto current = start; current < end; ++current) {
            if (*current == '?') {
                ++current;
                if (*current == '?')
                    ++current;
                bytes.push_back(-1);
            }
            else {
                bytes.push_back(strtoul(current, &current, 16));
            }
        }
        return bytes;
        };

    auto dosHeader = (PIMAGE_DOS_HEADER)module;
    auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)module + dosHeader->e_lfanew);

    auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
    auto patternBytes = pattern_to_byte(signature);
    auto scanBytes = reinterpret_cast<std::uint8_t*>(module);

    auto s = patternBytes.size();
    auto d = patternBytes.data();

    for (auto i = 0ul; i < sizeOfImage - s; ++i) {
        bool found = true;
        for (auto j = 0ul; j < s; ++j) {
            if (scanBytes[i + j] != d[j] && d[j] != -1) {
                found = false;
                break;
            }
        }
        if (found) {
            return &scanBytes[i];
        }
    }
    return nullptr;
}

uint64_t MEM::PatternScanFunc(void* module, const char* signature)
{
	uint8_t* sig = PatternScan(module, signature);
    return (uint64_t)sig - (uint64_t)module;

}

uint64_t MEM::PatternScanOffset(void* module, const char* signature, int offset, int extra)
{
    uint64_t patternAddress = reinterpret_cast<uint64_t>(PatternScan(module, signature));
    int32_t of;
	of = *(int32_t*)(patternAddress + offset);
    uintptr_t result = patternAddress + of + extra;
    return result - (uint64_t)module;

}

void* MEM::GetExportAddress(const void* hModuleBase, const char* szProcedureName)
{
	const auto pBaseAddress = static_cast<const std::uint8_t*>(hModuleBase);

	const auto pIDH = static_cast<const IMAGE_DOS_HEADER*>(hModuleBase);
	if (pIDH->e_magic != IMAGE_DOS_SIGNATURE)
		return nullptr;

	const auto pINH = reinterpret_cast<const IMAGE_NT_HEADERS64*>(pBaseAddress + pIDH->e_lfanew);
	if (pINH->Signature != IMAGE_NT_SIGNATURE)
		return nullptr;

	const IMAGE_OPTIONAL_HEADER64* pIOH = &pINH->OptionalHeader;
	const std::uintptr_t nExportDirectorySize = pIOH->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;
	const std::uintptr_t uExportDirectoryAddress = pIOH->DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;

	if (nExportDirectorySize == 0U || uExportDirectoryAddress == 0U)
	{
		std::cout << "[+] Module Has No Exports\n";
		return nullptr;
	}

	const auto pIED = reinterpret_cast<const IMAGE_EXPORT_DIRECTORY*>(pBaseAddress + uExportDirectoryAddress);
	const auto pNamesRVA = reinterpret_cast<const std::uint32_t*>(pBaseAddress + pIED->AddressOfNames);
	const auto pNameOrdinalsRVA = reinterpret_cast<const std::uint16_t*>(pBaseAddress + pIED->AddressOfNameOrdinals);
	const auto pFunctionsRVA = reinterpret_cast<const std::uint32_t*>(pBaseAddress + pIED->AddressOfFunctions);

	// Perform binary search to find the export by name
	std::size_t nRight = pIED->NumberOfNames, nLeft = 0U;
	while (nRight != nLeft)
	{
		// Avoid INT_MAX/2 overflow
		const std::size_t uMiddle = nLeft + ((nRight - nLeft) >> 1U);
        const int iResult = strcmp(szProcedureName, reinterpret_cast<const char*>(pBaseAddress + pNamesRVA[uMiddle]));

		if (iResult == 0)
		{
			const std::uint32_t uFunctionRVA = pFunctionsRVA[pNameOrdinalsRVA[uMiddle]];

			// Check if it's a forwarded export
			if (uFunctionRVA >= uExportDirectoryAddress && uFunctionRVA - uExportDirectoryAddress < nExportDirectorySize)
			{
				// Forwarded exports are not supported
				break;
			}

			return const_cast<std::uint8_t*>(pBaseAddress) + uFunctionRVA;
		}

		if (iResult > 0)
			nLeft = uMiddle + 1;
		else
			nRight = uMiddle;
	}

    std::cout << "[+] Export Not Found\n";

	// Export not found
	return nullptr;
}









