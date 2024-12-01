#pragma once
#include "cfgvar.h"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "imgui/imgui.h"

std::vector<cfgvar*> ConfigVarList;

void cfg::save(std::string_view name) {

	std::ofstream file{ name.data() };

	if (!file.is_open()) {
		return;
	}

	nlohmann::json j{};

	for (cfgvar* const var : ConfigVarList) {
		try {
			const size_t type{ var->typehash };

			if (type == typeid(bool).hash_code()) {
				j[var->m_name] = *static_cast<bool*>(var->m_data);
			}
			else if (type == typeid(int).hash_code()) {
				j[var->m_name] = *static_cast<int*>(var->m_data);
			}
			else if (type == typeid(float).hash_code()) {
				j[var->m_name] = *static_cast<float*>(var->m_data);
			}
			else if (type == typeid(std::string).hash_code()) {
				j[var->m_name] = *static_cast<std::string*>(var->m_data);
			}
			else if (type == typeid(ImVec4).hash_code()) {
				const ImVec4 clr{ *static_cast<ImVec4*>(var->m_data) };
				j[var->m_name] = { clr.x, clr.y, clr.z, clr.w };
			}
			else {
				// Assuming you have a similar notification system in the refactored code
				std::cout << "failed to save config var: " << var->m_name << " (unknown type)";
			}


		}
		catch (const std::exception& e) {
			std::cout << "Failed to save config var : " << var->m_name;
		}
	}

	file << std::setw(4) << j;

}