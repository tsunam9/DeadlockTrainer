#include "AntiAim.h"
#include <random>

int generateRandomNumber(int min, int max) {
	static std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}

void AntiAim::DoAntiAim(CCitadelUserCmdPB* cmd) {

	if (Config.misc.SpeedBoost && Helper::KeyBindHandler(Config.misc.SpeedBoostKey.key)) {
		return;
	}

	uint64_t CameraManager = Helper::get_Camera();
	vec2 ViewAngles = *(vec2*)(CameraManager + 0x44);

	if (Config.antiaim.AAtype == 0) { // spin
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.x = 89.0f;

		float yangle = cmd->pBaseUserCMD->playerViewAngle->viewAngles.y;
		yangle += 180.0f;
		if (yangle >= 360.0f) {
			yangle -= 360.0f; // Wrap around if necessary
		}
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.y = yangle;
		return;
	}
	else if (Config.antiaim.AAtype == 1) { // jitter
		// Flip the view angle
		float flippedAngleY = ViewAngles.y + 180.0f;

		// Ensure the angle is within the range of 0 to 360
		if (flippedAngleY >= 360.0f) {
			flippedAngleY -= 360.0f; // Wrap around if necessary
		}
		if (!cmd->pBaseUserCMD->playerViewAngle) {
			return;
		}
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.x = 89.0f;
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.y = flippedAngleY + generateRandomNumber(Config.antiaim.lowerjitter, Config.antiaim.upperjitter);
		return;
	}
	else if (Config.antiaim.AAtype == 2) { // 180 Treehouse
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.x = 89.0f;
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.y = 0.0f;
		return;
	}


}