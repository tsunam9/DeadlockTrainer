#pragma once
#include "cfgvar.h"

void cfg::save(std::string_view name) {

	std::ofstream file{ name.data() };

	if (!file.is_open()) {
		return;
	}

	nlohmann::json j{};

	for (cfgvar* const var : getInsts<cfgvar>()) {
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
				std::cout << "failed to save config var: " << var->m_name << " (unknown type)";
			}


		}
		catch (const std::exception& e) {
			std::cout << "Failed to save config var : " << var->m_name;
		}
	}

	file << std::setw(4) << j; 

}

void cfg::load(std::string_view name)
{
	std::ifstream file{ name.data() };

	if (!file.is_open()) {
		return;
	}

	nlohmann::json j{};

	file >> j;

	for (cfgvar* const var : getInsts<cfgvar>())
	{
		try
		{
			if (j.contains(var->m_name))
			{
				const size_t type{ var->typehash };

				if (type == typeid(bool).hash_code()) {
					*static_cast<bool*>(var->m_data) = j[var->m_name];
				}

				else if (type == typeid(int).hash_code()) {
					*static_cast<int*>(var->m_data) = j[var->m_name];
				}

				else if (type == typeid(float).hash_code()) {
					*static_cast<float*>(var->m_data) = j[var->m_name];
				}

				else if (type == typeid(std::string).hash_code()) {
					*static_cast<std::string*>(var->m_data) = j[var->m_name];
				}

				else if (type == typeid(ImVec4).hash_code()) {
					*static_cast<ImVec4*>(var->m_data) = ImVec4{ j[var->m_name][0], j[var->m_name][1], j[var->m_name][2], j[var->m_name][3] };
				}

				else {
					std::cout << (std::format("failed to load config var: {} (unknown type)", var->m_name));
				}
			}
			else {
				std::cout << (std::format("failed to load config var: {} (not found)", var->m_name));
			}
		}

		catch (const std::exception& e) {
			std::cout << (std::format("failed to load config var: {} ({})", var->m_name, e.what()));
		}
	}
}