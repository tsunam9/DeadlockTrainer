#include "Drawing.h"



void Drawing::DrawBox(float x, float y, float width, float height, ImU32 color) {
	ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); // Use the background draw list for ESP

	// Draw the border first
	ImU32 borderColor = IM_COL32(0, 0, 0, 75); // Black color for the border
	draw_list->AddRect(ImVec2(x, y), ImVec2(x + width, y + height), borderColor, 0.0f, 0.0f, 1.0f);
	draw_list->AddRect(ImVec2(x + 1.0f, y + 1.0f),
		ImVec2(x + width - 1.0f, y + height - 1.0f),
		color);
}

void Drawing::DrawLine(float x1, float y1, float x2, float y2, ImU32 color, float thickness) {
	ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); // Use the background draw list for ESP
	draw_list->AddLine(ImVec2(x1, y1), ImVec2(x2, y2), color, thickness);
}

void Drawing::DrawCircle(float x, float y, float radius, ImU32 color) {
	ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); // Use the background draw list for ESP
	draw_list->AddCircle(ImVec2(x, y), radius, color, 128, 1.0f);
}

void Drawing::DrawQuad(vec2 a, vec2 b, vec2 c, vec2 d, ImU32 color, float thickness){
	ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); // Use the background draw list for ESP
	draw_list->AddQuad(ImVec2(a.x, a.y), ImVec2(b.x, b.y), ImVec2(c.x, c.y), ImVec2(d.x, d.y), color, thickness);
}

void Drawing::DrawFilledCircle(float x, float y, float radius, ImU32 color) {
	ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); // Use the background draw list for ESP
	draw_list->AddCircleFilled(ImVec2(x, y), radius, color, 128);
}

void Drawing::DrawText(float x, float y, ImU32 color, const char* text) {

	ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); // Use the background draw list for ESP

	


	// Calculate text size
	ImVec2 textSize = ImGui::CalcTextSize(text);

	// Adjust x position to center the text
	x -= textSize.x * 0.5f;

	draw_list->AddText(ImVec2(x, y), color, text);
}

void Drawing::ncDrawText(float x, float y, ImU32 color, const char* text) {

	ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); // Use the background draw list for ESP
	draw_list->AddText(ImVec2(x, y), color, text);
}

void Drawing::DrawFilledBox(float x, float y, float width, float height, ImU32 color) {
	ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); // Use the background draw list for ESP
	draw_list->AddRectFilled(ImVec2(x, y), ImVec2(x + width, y + height), color);
}

void Drawing::DrawTriangleFilled(vec2 a, vec2 b, vec2 c, ImU32 color) {
	ImDrawList* draw_list = ImGui::GetBackgroundDrawList(); // Use the background draw list for ESP
	draw_list->AddTriangleFilled(ImVec2(a.x, a.y), ImVec2(b.x, b.y), ImVec2(c.x, c.y), color);
 }