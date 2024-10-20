#pragma once
#include "heros.h" x1`

void Hero::OnAbility1() {
	// do something
}
void Hero::OnAbility2() {
	// do something
}
void Hero::OnAbility3() {
	// do something
}
void Hero::OnAbility4() {
	// do something
}

void Hero::OnTick() {
	// do something
}


void Hero::RunScript(CCitadelUserCmdPB* cmd) {

	this->cmd = cmd;
	this->LocalPlayer = Helper::get_local_player();
	this->localplayerdata = Helper::get_player_data(this->LocalPlayer);
	this->abilitiesarray = Helper::GetAbilities(Helper::GetPawn(this->LocalPlayer));

	if (cmd->buttons & IN_ABILITY1) {
		OnAbility1();
	}
	if (cmd->buttons & IN_ABILITY2) {
		OnAbility2();
	}
	if (cmd->buttons & IN_ABILITY3) {
		OnAbility3();
	}
	if (cmd->buttons & IN_ABILITY4) {
		OnAbility4();
	}

	if (!this->LocalPlayer)
		return;
	if (!this->abilitiesarray.size())
		return;

	OnTick();
}