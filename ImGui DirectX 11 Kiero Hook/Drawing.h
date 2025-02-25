#pragma once
#include "includes.h"


class Drawing
{
	public:
		static void DrawBox(float x, float y, float width, float height, ImU32 color);
		static void DrawLine(float x1, float y1, float x2, float y2, ImU32 color, float thickness = 1.0f);
		static void DrawCircle(float x, float y, float radius, ImU32 color);
		static void DrawFilledCircle(float x, float y, float radius, ImU32 color);
		static void DrawText(float x, float y, ImU32 color, const char* text);
		static void ncDrawText(float x, float y, ImU32 color, const char* text);
		static void DrawFilledBox(float x, float y, float width, float height, ImU32 color);
		static void DrawQuad(vec2 a, vec2 b, vec2 c, vec2 d, ImU32 color, float thickness = 2.0f);
		static void DrawTriangleFilled(vec2 a, vec2 b, vec2 c, ImU32 color);

};

