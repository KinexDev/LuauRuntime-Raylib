#include "lualib.h"
#include "iostream"
#include "raylib.h"

#define LUAU_API extern "C" __declspec(dllexport)

LUAU_API int Luau_InitWindow(lua_State* L)
{
	int width = (int)lua_tonumber(L, 1);
	int height = (int)lua_tonumber(L, 2);
	const char* title = lua_tostring(L, 3);

	InitWindow(width, height, title);
	return 0;
}

LUAU_API int Luau_SetTargetFPS(lua_State* L)
{
	int fps = (int)lua_tonumber(L, 1);
	SetTargetFPS(fps);
	return 0;
}

LUAU_API int Luau_WindowShouldClose(lua_State* L)
{
	lua_pushboolean(L, WindowShouldClose());
	return 1;
}


LUAU_API int Luau_BeginDrawing(lua_State* L)
{
	BeginDrawing();
	return 1;
}

LUAU_API int Luau_ClearBackground(lua_State* L)
{
	unsigned char r = (int)lua_tonumber(L, 1);
	unsigned char g = (int)lua_tonumber(L, 2);
	unsigned char b = (int)lua_tonumber(L, 3);

	ClearBackground(Color{ r, g, b, 255 });
	return 1;
}

LUAU_API int Luau_DrawText(lua_State* L)
{
	const char* text = lua_tostring(L, 1);
	int x = (int)lua_tonumber(L, 2);
	int y = (int)lua_tonumber(L, 3);
	int size = (int)lua_tonumber(L, 4);

	// color stuff
	unsigned char r = (int)lua_tonumber(L, 1);
	unsigned char g = (int)lua_tonumber(L, 2);
	unsigned char b = (int)lua_tonumber(L, 3);

	DrawText(text, x, y, size, Color{ r, g, b, 255 });
	return 0;
}

LUAU_API int Luau_EndDrawing(lua_State* L)
{
	EndDrawing();
	return 1;
}

LUAU_API int Luau_CloseWindow(lua_State* L)
{
	CloseWindow();
	return 1;
}