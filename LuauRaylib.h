#pragma once

#include "lualib.h"
#include "raylib.h"

#define LUAU_API extern "C" __declspec(dllexport)

LUAU_API int Luau_InitWindow(lua_State* L);
LUAU_API int Luau_SetTargetFPS(lua_State* L);
LUAU_API int Luau_WindowShouldClose(lua_State* L);
LUAU_API int Luau_BeginDrawing(lua_State* L);
LUAU_API int Luau_ClearBackground(lua_State* L);
LUAU_API int Luau_DrawText(lua_State* L);
LUAU_API int Luau_DrawRectangle(lua_State* L);
LUAU_API int Luau_DrawLine(lua_State* L);
LUAU_API int Luau_IsKeyDown(lua_State* L);
LUAU_API int Luau_IsKeyPressed(lua_State* L);
LUAU_API int Luau_IsKeyReleased(lua_State* L);
LUAU_API int Luau_GetMouseX(lua_State* L);
LUAU_API int Luau_GetMouseY(lua_State* L);
LUAU_API int Luau_IsMouseButtonDown(lua_State* L);
LUAU_API int Luau_IsMouseButtonPressed(lua_State* L);
LUAU_API int Luau_IsMouseButtonReleased(lua_State* L);
LUAU_API int Luau_GetScreenHeight(lua_State* L);
LUAU_API int Luau_GetScreenWidth(lua_State* L);
LUAU_API int Luau_GetFrameTime(lua_State* L);
LUAU_API int Luau_GetTime(lua_State* L);
LUAU_API int Luau_GetFPS(lua_State* L);
LUAU_API int Luau_EndDrawing(lua_State* L);
LUAU_API int Luau_CloseWindow(lua_State* L);
Color LuauC_GetColor(lua_State* L, int idx);
Vector2 LuauC_GetVector2(lua_State* L, int idx);