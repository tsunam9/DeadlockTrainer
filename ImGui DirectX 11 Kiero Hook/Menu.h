#pragma once
#include "includes.h"
#include "fstream"
#include "iostream"
#include "json.hpp"
#include <vector>
#include "binds.h"
#include "cfgvar.h"

extern char quickiterationmaterial[20408];
extern bool replacedmaterial;
extern bool firstreplacedmaterial;

enum WidgetType {
	checkbox,
	sliderint,
	sliderfloat
};

struct widgetinfo_checkbox {

	std::string label;
	bool* var;

};

struct storedcfgvar {

	cfgvar* var;
	int WidgetType;
	void* widgetinfo;
};

class Menu {
public:	

	void DrawRageBotTab();
	void DrawLegitBotTab();
	void DrawHeroesTab();
	void DrawEspTab();
	void DrawConfigTab(FILE* fp);

	std::vector<storedcfgvar> menu_storedvars;

	void DrawBackround();
	void DrawNewMenu(FILE* fp, ID3D11Device* dx11Device);
	void DrawConfigs();

	void checkbox(const char* label, bool* v);

	

};