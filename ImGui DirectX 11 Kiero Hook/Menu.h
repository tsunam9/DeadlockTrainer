#pragma once
#include "includes.h"
#include "fstream"
#include "iostream"
#include "json.hpp"
#include <vector>

class Menu {
public:
	static void DrawMenu(FILE* fp);

	static void DrawConfigs();
};