#pragma once
#include <Windows.h>
#include "TlHelp32.h"
#include <iostream>
#include <vector>
#include <string>
#include <Psapi.h>
#include <sstream>
#include <stdexcept>


class MEM {
public:


	static  uint64_t GetProcessIdByName(const char* processname);
	static  uint64_t GetModuleBaseAddress(uint64_t procId, const char* modName);
	static  uint64_t GetClientBase();


	static std::uint8_t* PatternScan(void* module, const char* signature);
	static std::uint64_t PatternScanFunc(void* module, const char* signature);
	static std::uint64_t PatternScanOffset(void* module, const char* signature, int offset, int extra);
	static void* GetExportAddress(const void* hModuleBase, const char* szProcedureName);

};