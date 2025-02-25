#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include "kiero/kiero.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include <iostream>
#include "offsets.h"
#include <unordered_set>
#include <string>
#include "PlayerClasses.h"
#include "Aimbot.h"
#include "Logic.h"
#include "Config.h"
#include "helper.h"
#include "ESP.h"
#include "Drawing.h"
#include "Misc.h"
#include "kiero/minhook/include/MinHook.h"
#include "client_dll.hpp"
#include "hooks.h"

using namespace cs2_dumper::schemas::client_dll;


typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef HRESULT(__stdcall* ResizeBuffers)(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);
using create_swap_chain_fn = HRESULT(WINAPI*)(IDXGIFactory*, IUnknown*, DXGI_SWAP_CHAIN_DESC*, IDXGISwapChain**);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;