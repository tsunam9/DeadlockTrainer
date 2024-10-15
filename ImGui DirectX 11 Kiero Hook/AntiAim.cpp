#include "AntiAim.h"



void AntiAim::DoAntiAim() {


	uint64_t CameraManager = Helper::get_Camera();
	vec2 ViewAngles = *(vec2*)(CameraManager + 0x44);
	CCitadelUserCmdPB* cmd = Helper::GetCurrentUserCmd();

	// Flip the view angle
	float flippedAngleY = ViewAngles.y + 180.0f;

	// Ensure the angle is within the range of 0 to 360
	if (flippedAngleY >= 360.0f) {
		flippedAngleY -= 360.0f; // Wrap around if necessary
	}
	cmd->pBaseUserCMD->playerViewAngle->viewAngles.x = 89.0f;
	cmd->pBaseUserCMD->playerViewAngle->viewAngles.y = flippedAngleY;

}