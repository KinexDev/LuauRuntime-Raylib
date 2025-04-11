#include "LuauRaylib.h"
#include <iostream>

LUAU_API int Luau_InitWindow(lua_State* L)
{
    Vector2 size = LuauC_GetVector2(L, 1);
    const char* title = lua_tostring(L, 2);

    InitWindow(size.x, size.y, title);
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
    Color color = LuauC_GetColor(L, 1);
    ClearBackground(color);
    return 1;
}

LUAU_API int Luau_DrawText(lua_State* L)
{
    const char* text = lua_tostring(L, 1);
    int size = (int)lua_tonumber(L, 2);
    Vector2 position = LuauC_GetVector2(L, 3);
    Color color = LuauC_GetColor(L, 4);
    DrawText(text, position.x, position.y, size, color);
    return 0;
}

Color LuauC_GetColor(lua_State* L, int idx)
{
    if (!lua_istable(L, idx)) {
        lua_pushstring(L, "Expected a table for color!");
        lua_error(L);
    }

    unsigned char r = 0, g = 0, b = 0, a = 255;

    lua_getfield(L, idx, "r");
    if (lua_isnumber(L, -1)) r = (unsigned char)lua_tonumber(L, -1);
    lua_pop(L, 1);

    lua_getfield(L, idx, "g");
    if (lua_isnumber(L, -1)) g = (unsigned char)lua_tonumber(L, -1);
    lua_pop(L, 1);

    lua_getfield(L, idx, "b");
    if (lua_isnumber(L, -1)) b = (unsigned char)lua_tonumber(L, -1);
    lua_pop(L, 1);

    lua_getfield(L, idx, "a");
    if (lua_isnumber(L, -1)) a = (unsigned char)lua_tonumber(L, -1);
    lua_pop(L, 1);

    return Color{ r, g, b, a };
}

Vector2 LuauC_GetVector2(lua_State* L, int idx)
{
    if (!lua_istable(L, idx)) {
        lua_pushstring(L, "Expected a table for color!");
        lua_error(L);
    }

    float x = 0, y = 0;

    lua_getfield(L, idx, "x");
    if (lua_isnumber(L, -1)) x = (float)lua_tonumber(L, -1);
    lua_pop(L, 1);

    lua_getfield(L, idx, "y");
    if (lua_isnumber(L, -1)) y = (float)lua_tonumber(L, -1);
    lua_pop(L, 1);

    return Vector2{ x, y };
}

LUAU_API int Luau_DrawRectangle(lua_State* L)
{
    Vector2 position = LuauC_GetVector2(L, 1);
    Vector2 size = LuauC_GetVector2(L, 2);
    Color color = LuauC_GetColor(L, 3);

    DrawRectangle(position.x, position.y, size.x, size.y, color);
    return 0;
}

LUAU_API int Luau_DrawLine(lua_State* L)
{
    Vector2 pos1 = LuauC_GetVector2(L, 1);
    Vector2 pos2 = LuauC_GetVector2(L, 2);
    Color color = LuauC_GetColor(L, 3);
    DrawLine(pos1.x, pos1.y, pos2.x, pos2.y, color);
    return 0;
}

LUAU_API int Luau_IsKeyDown(lua_State* L)
{
    int key = (int)lua_tonumber(L, 1);
    lua_pushboolean(L, IsKeyDown(key));
    return 1;
}

LUAU_API int Luau_IsKeyPressed(lua_State* L)
{
    int key = (int)lua_tonumber(L, 1);
    lua_pushboolean(L, IsKeyPressed(key));
    return 1;
}

LUAU_API int Luau_IsKeyReleased(lua_State* L)
{
    int key = (int)lua_tonumber(L, 1);

    lua_pushboolean(L, IsKeyReleased(key));
    return 1;
}

LUAU_API int Luau_GetMouseX(lua_State* L)
{
    lua_pushnumber(L, GetMouseX());
    return 1;
}

LUAU_API int Luau_GetMouseY(lua_State* L)
{
    lua_pushnumber(L, GetMouseY());
    return 1;
}

LUAU_API int Luau_IsMouseButtonDown(lua_State* L)
{
    int button = (int)lua_tonumber(L, 1);
    lua_pushboolean(L, IsMouseButtonDown(button));
    return 1;
}

LUAU_API int Luau_IsMouseButtonPressed(lua_State* L)
{
    int button = (int)lua_tonumber(L, 1);
    lua_pushboolean(L, IsMouseButtonPressed(button));
    return 1;
}

LUAU_API int Luau_IsMouseButtonReleased(lua_State* L)
{
    int button = (int)lua_tonumber(L, 1);
    lua_pushboolean(L, IsMouseButtonReleased(button));
    return 1;
}

LUAU_API int Luau_GetScreenHeight(lua_State* L)
{
    lua_pushinteger(L, GetScreenHeight());
    return 1;
}

LUAU_API int Luau_GetScreenWidth(lua_State* L)
{
    lua_pushinteger(L, GetScreenWidth());
    return 1;
}

LUAU_API int Luau_GetFrameTime(lua_State* L)
{
    lua_pushnumber(L, GetFrameTime());
    return 1;
}

LUAU_API int Luau_GetTime(lua_State* L)
{
    lua_pushnumber(L, GetTime());
    return 1;
}

LUAU_API int Luau_GetFPS(lua_State* L)
{
    lua_pushnumber(L, GetFPS());
    return 1;
}

LUAU_API int Luau_EndDrawing(lua_State* L)
{
    EndDrawing();
    return 0;
}

LUAU_API int Luau_CloseWindow(lua_State* L)
{
    CloseWindow();
    return 0;
}

LUAU_API int Luau_InitAudioDevice(lua_State* L)
{
    InitAudioDevice();
    return 0;
}

LUAU_API int Luau_CloseAudioDevice(lua_State* L)
{
    CloseAudioDevice();
    return 0;
}

LUAU_API int Luau_LoadTexture(lua_State* L)
{
    const char* path = lua_tostring(L, 1);
    Texture2D* tex = new Texture2D(LoadTexture(path));
    lua_pushlightuserdata(L, tex);
    return 1;
}

LUAU_API int Luau_UnloadTexture(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
        return 0;
    Texture2D* tex = (Texture2D*)lua_tolightuserdata(L, 1);
    if (tex)
    {
        UnloadTexture(*tex);
        delete tex;
    }
    return 0;
}

LUAU_API int Luau_DrawTexture(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
        return 0;

    Texture2D* tex = (Texture2D*)lua_tolightuserdata(L, 1);
    Vector2 position = LuauC_GetVector2(L, 2);
    Color color = LuauC_GetColor(L, 3);

    if (tex)
    {
        DrawTexture(*tex, position.x, position.y, color);
    }
    return 0;
}

LUAU_API int Luau_LoadSound(lua_State* L)
{
    const char* path = lua_tostring(L, 1);
    Sound* sound = new Sound(LoadSound(path));
    lua_pushlightuserdata(L, sound);
    return 1;
}

LUAU_API int Luau_PlaySound(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
        return 0;

    Sound* sound = (Sound*)lua_tolightuserdata(L, 1);
    if (sound)
    {
        if (IsSoundValid(*sound))
        {
            PlaySound(*sound);
        }
    }
    return 0;
}


LUAU_API int Luau_StopSound(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
        return 0;
    Sound* tex = (Sound*)lua_tolightuserdata(L, 1);
    if (tex)
    {
        StopSound(*tex);
    }
    return 0;
}

LUAU_API int Luau_PauseSound(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
        return 0;
    Sound* tex = (Sound*)lua_tolightuserdata(L, 1);
    if (tex)
    {
        PauseSound(*tex);
    }
    return 0;
}

LUAU_API int Luau_ResumeSound(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
        return 0;
    Sound* tex = (Sound*)lua_tolightuserdata(L, 1);
    if (tex)
    {
        ResumeSound(*tex);
    }
    return 0;
}

LUAU_API int Luau_UnloadSound(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
        return 0;
    Sound* tex = (Sound*)lua_tolightuserdata(L, 1);
    if (tex)
    {
        UnloadSound(*tex);
        delete tex;
    }
    return 0;
}

LUAU_API int Luau_SetSoundPitch(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
        return 0;

    Sound* sound = (Sound*)lua_tolightuserdata(L, 1);
    float pitch = lua_tonumber(L, 2);

    if (sound)
    {
        SetSoundPitch(*sound, pitch);
    }
    return 0;
}

LUAU_API int Luau_SetSoundVolume(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
        return 0;

    Sound* sound = (Sound*)lua_tolightuserdata(L, 1);
    float volume = lua_tonumber(L, 2);

    if (sound)
    {
        SetSoundVolume(*sound, volume);
    }
    return 0;
}

LUAU_API int Luau_SetSoundPan(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
        return 0;

    Sound* sound = (Sound*)lua_tolightuserdata(L, 1);
    float pan = lua_tonumber(L, 2);

    if (sound)
    {
        SetSoundPan(*sound, pan);
    }

    return 0;
}

LUAU_API int Luau_IsSoundPlaying(lua_State* L)
{
    if (!lua_islightuserdata(L, 1))
    {
        lua_pushboolean(L, 0);
        return 1;
    }

    Sound* sound = (Sound*)lua_tolightuserdata(L, 1);
    float pan = lua_tonumber(L, 2);

    if (sound)
    {
        lua_pushboolean(L, IsSoundPlaying(*sound));
    }
    else
    {
        lua_pushboolean(L, 0);
    }

    return 1;
}

