#pragma once
#include "Windows.h"
#include <cstdint>

class CGlobalVarsBase
{
public:
    float flRealTime; //0x0000 
    std::uint32_t iFrameCount; //0x0004 
    float flFrameTime; //0x0008 
    float flAbsFrameTime; //0x000C 
    std::uint32_t iMaxClients; //0x0010
private:
    [[maybe_unused]] float flUnkn1; //0x0014
    [[maybe_unused]] char pad_0x0018[0x1C]; //0x0018
public:
    float flCurtime; //0x0034 
    float flAbsCurTime; //0x0038 
    float flSomeFraction; //0x003C
private:
    [[maybe_unused]] char pad_0x0040[0x8]; //0x0040
public:
    std::uint32_t iTickCount; //0x0048
private:
    [[maybe_unused]] char pad_0x004C[0x14]; //0x004C
public:
    void* pNetChannel; //0x0060
private:
    [[maybe_unused]] char pad_0x0068[0x118]; //0x0068
public:
    char* szCurrentMap; //0x0180 
    char* szCurrentMapGame; //0x0188
private:
    [[maybe_unused]] char pad_0x0190[0x298]; //0x0190
};