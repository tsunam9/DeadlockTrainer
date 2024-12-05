#include "AntiAim.h"
#include <random>

int generateRandomNumber(int min, int max) {
	static std::random_device rd;
	static std::mt19937 generator(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}

void AntiAim::DoAntiAim(CCitadelUserCmdPB* cmd) {

	uint64_t CameraManager = Helper::get_Camera();
	vec2 ViewAngles = *(vec2*)(CameraManager + 0x44);

	if (cfg::antiaim_AAtype == 0) {
		static float yawAngle = 89.0f;
		static float yawDirection = -1.0f;
		static float spinAngle = 0.0f;

		// Yaw spin (up and down)
		yawAngle += cfg::antiaim_SpinPitchChange * yawDirection;
		if (yawAngle > 89.0f) {
			yawAngle = 89.0f;
			yawDirection = -1.0f;
		}
		else if (yawAngle < -89.0f) {
			yawAngle = -89.0f;
			yawDirection = 1.0f;
		}
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.x = yawAngle;

		// Spin around (left and right)
		spinAngle += cfg::antiaim_SpinYawChange;
		if (spinAngle > 360.0f) {
			spinAngle = fmod(spinAngle, 360.0f);
		}
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.y = spinAngle;
	}

	else if (cfg::antiaim_AAtype == 1) { // jitter
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
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.y = flippedAngleY + generateRandomNumber(cfg::antiaim_lowerjitter, cfg::antiaim_upperjitter);
		return;
	}
	else if (cfg::antiaim_AAtype == 2) { // 180 Treehouse
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.x = 89.0f;
		cmd->pBaseUserCMD->playerViewAngle->viewAngles.y = 0.0f;
		return;
	}


}