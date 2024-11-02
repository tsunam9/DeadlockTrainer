#pragma once
#include "includes.h"
#include "fstream"
#include "iostream"
#include "json.hpp"
#include <vector>

class Menu {
public:	

	static void DrawAimbotTab();
	static void DrawAntiAimTab();
	static void DrawHeroesTab();
	static void DrawEspTab();
	static void DrawConfigTab(FILE* fp);


	static void DrawMenu(FILE* fp);
	static void DrawNewMenu(FILE* fp, ID3D11Device* dx11Device);
	static void DrawConfigs();
};