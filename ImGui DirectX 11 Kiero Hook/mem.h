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

	template <typename T = void*>
	static [[nodiscard]] constexpr T GetVFunc(const void* thisptr, std::size_t nIndex) {
		// Retrieve the virtual function pointer from the vtable
		return (*static_cast<T**>(const_cast<void*>(thisptr)))[nIndex];
	}

	template <typename T, std::size_t nIndex, typename CBaseClass, typename... Args>
	static [[nodiscard]] constexpr T CallVFunc(CBaseClass* thisptr, Args&&... args) {
		using VirtualFn_t = T(__thiscall*)(CBaseClass*, Args...);
		// Get the virtual function pointer from the vtable
		VirtualFn_t fn = GetVFunc<VirtualFn_t>(thisptr, nIndex);
		return fn(thisptr, std::forward<Args>(args)...);
	}

};