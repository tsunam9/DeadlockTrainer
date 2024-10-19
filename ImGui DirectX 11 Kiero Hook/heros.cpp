#include "heros.h"

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
	OnTick();
}