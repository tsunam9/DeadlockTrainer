#pragma once
#include "includes.h"


class Drawing
{
	public:
		void DrawBox(float x, float y, float width, float height, ImU32 color);
		void DrawLine(float x1, float y1, float x2, float y2, ImU32 color);
		void DrawCircle(float x, float y, float radius, ImU32 color);
		void DrawFilledCircle(float x, float y, float radius, ImU32 color);
		void DrawText(float x, float y, ImU32 color, const char* text);
		void DrawFilledBox(float x, float y, float width, float height, ImU32 color);
		void DrawQuad(vec2 a, vec2 b, vec2 c, vec2 d, ImU32 color, float thickness = 2.0f);

};

