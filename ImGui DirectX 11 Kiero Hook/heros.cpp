#pragma once
#include "heros.h"


void Hero::OnTick() {

}


void Hero::RunScript(CCitadelUserCmdPB* cmd) {

	if (!(Config.aimbot.bRageBotMasterSwitch) && !(Config.legitbot.legitbotmasterswitch)) {
		return;
	}

	this->cmd = cmd;
	this->LocalPlayer = Helper::get_local_player();
	Helper::get_player_data(this->LocalPlayer, this->localplayerdata);

	this->abilitiesarray = Helper::GetAbilities(Helper::GetPawn(this->LocalPlayer));

	
	if (cmd->buttons & IN_ABILITY1) {
		this->InputCasting1 = true;
	}
	if (cmd->buttons & IN_ABILITY2) {

		this->InputCasting2 = true;
	}
	if (cmd->buttons & IN_ABILITY3) {
		this->InputCasting3 = true;
	}
	if (cmd->buttons & IN_ABILITY4) {
		this->InputCasting4 = true;
	}

	if (!this->LocalPlayer)
		return;
	if (!this->abilitiesarray.size())
		return;

	OnTick();

}