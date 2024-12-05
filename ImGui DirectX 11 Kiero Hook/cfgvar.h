#pragma once
#include <string>
#include <typeinfo>
#include <vector>
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "imgui/imgui.h"
#include "insttracker.cpp"

//basically lifted tf2 cheat seowned but its a good system so im gonna use it

class cfgvar;


class cfgvar final : public InstTracker<cfgvar> 
{

	public:

	std::string m_name;
	void* m_data;
	size_t typehash;

	cfgvar(std::string_view name, void* const ptr, const size_t type_hash) : InstTracker(this)
	{
		m_name = name;
		m_data = ptr;
		typehash = type_hash;
		
	}

};


#define MAKE_CFGVAR(name, val) \
namespace cfg { inline auto name{ val }; } \
namespace make_cfgvar { inline cfgvar name{ #name, &cfg::name, typeid(cfg::name).hash_code() }; }

namespace cfg
{
	void save(std::string_view name);
	void load(std::string_view name);
	bool remove(std::string_view name);
}