#pragma once
#include "binds.h"

Binds mainbinds;

auto findCfgVarByName = [&](const std::string& name) -> cfgvar* const
	{
		for (cfgvar* const var : getInsts<cfgvar>())
		{
			if (!var || var->m_name != name) {
				continue;
			}

			return var;
		}

		return nullptr;
	};

void Binds::addbind(const Bind bind) {

	this->bindlist.push_back(bind);

}

void Binds::removebind(Bind* const bind_ptr) {

	if (!bind_ptr) {
		return;
	}

}

void Binds::think() {

	if (!iEngine->IsInGame())
		return;

	for (Bind& deletebind : bindstodelete) {

		auto it = std::find(bindlist.begin(), bindlist.end(), deletebind);

		if (it != bindlist.end()) {
			int index = std::distance(bindlist.begin(), it);
			bindlist.erase(bindlist.begin() + index);
		}
		else {
			std::cout << "Delete bind failed : couldnt find bind " << deletebind.name;
		}

	}
	bindstodelete.clear();

	for (Bind& bind : bindlist) {

		if (bind.type == BindType::TOGGLE) {
			if (GetAsyncKeyState(bind.key) & 1) {
				bool& var_val{ *static_cast<bool*>(bind.configvar->m_data) };
				var_val = !var_val;
			}
		}

		if (bind.type == BindType::HOLD) {

			if (GetAsyncKeyState(bind.key)) {
				bool& var_val{ *static_cast<bool*>(bind.configvar->m_data) };
				var_val = bind.val_on;
			}
			else {
				bool& var_val{ *static_cast<bool*>(bind.configvar->m_data) };
				var_val = bind.val_off;
			}
		}
	}

}

extern bool menuopen;

void Binds::paint() {

	if (!(bindlist.size() > 0)) {
		return;
	}

	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);

	
	if (ImGui::Begin("Binds", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_AlwaysAutoResize )) {

		for (Bind& bind : bindlist) {

			bool& active{ *static_cast<bool*>(bind.configvar->m_data) };

			ImGui::Text(bind.name.c_str());

			if (ImGui::IsItemHovered && ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
				ImGui::OpenPopup(bind.name.c_str());
			}

			ImGui::SameLine();
			
			if (active) {
				ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.f, 1.f, 0.f, 1.f));
				ImGui::Text("true");
				ImGui::PopStyleColor();
			}
			else {
				ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.f, 0.f, 0.f, 1.f));
				ImGui::Text("false");
				ImGui::PopStyleColor();
			}

			if (ImGui::IsItemHovered && ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
				ImGui::OpenPopup(bind.name.c_str());
			}

			if (menuopen) {

				ImGui::SameLine();

				ImGui::Text("Key : %s", KeyNames[bind.key]);

				if (ImGui::IsItemHovered && ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
					ImGui::OpenPopup(bind.name.c_str());
				}

				ImGui::SameLine();

				if (bind.type == TOGGLE) {
					ImGui::Text("Mode : Toggle");
				}
				else if (bind.type == HOLD) {
					ImGui::Text("Mode : Hold");
				}

				if (ImGui::IsItemHovered && ImGui::IsItemClicked(ImGuiMouseButton_Right)) {
					ImGui::OpenPopup(bind.name.c_str());
				}




			}

			if (ImGui::BeginPopupModal(bind.name.c_str(), nullptr, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse)) {

				if (GetAsyncKeyState(VK_ESCAPE)) {
					ImGui::CloseCurrentPopup();
				}

				if (ImGui::Button("Delete")) {
					std::cout << "Deleted\n";

					bindstodelete.push_back(bind);

					ImGui::CloseCurrentPopup();
				}

				ImGui::EndPopup();
			}


		}

	}

	ImGui::End();

	ImGui::PopStyleVar();

	return;
}

void Binds::load(const std::string& path){

	nlohmann::json j{};

	std::ifstream file{ path.data() };

	if (!file.is_open()) {
		return;
	}

	file >> j;

	file.close();

	auto findCfgVarByName = [&](const std::string& name) -> cfgvar* const
		{
			for (cfgvar* const var : getInsts<cfgvar>())
			{
				if (!var || var->m_name != name) {
					continue;
				}

				return var;
			}

			return nullptr;
		};

	if (!j.empty()) {
		bindlist.clear();
	}

	for (const nlohmann::json& b : j)
	{
		Bind bind{};

		bind.name = b["name"].get<std::string>();
		bind.key = b["key"].get<int>();
		bind.type = b["type"].get<int>();
		bind.configvar = findCfgVarByName(b["cfgvarname"].get<std::string>());

		if (!(bind.configvar)) {
			continue;
		}

		bind.val_off = b["val_off"].get<bool>();
		bind.val_on = b["val_on"].get<bool>();


		bindlist.push_back(bind);
	}


}

void Binds::save(const std::string& path){

	nlohmann::json j{};

	for (const Bind& bind : bindlist) {

		nlohmann::json b{};

		b["name"] = bind.name;
		b["key"] = bind.key;
		b["type"] = bind.type;
		b["cfgvarname"] = bind.configvar->m_name;
		b["val_on"] = true;
		b["val_off"] = false;

		j.push_back(b);
	}

	std::ofstream file{ path.data() };
	file << std::setw(4) << j;
	file.close();

}