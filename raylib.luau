--!strict
local raylib: lib = lib.load("raylib-luau.dll")
local utils = require("raylib-utils")

return {
    InitWindow = raylib:extern("Luau_InitWindow") :: (windowSize: utils.vec2,
        title: string) -> (),
    SetTargetFPS = raylib:extern("Luau_SetTargetFPS") :: (fps: number) -> (),
    WindowShouldClose = raylib:extern("Luau_WindowShouldClose") :: () -> boolean,
    BeginDrawing = raylib:extern("Luau_BeginDrawing") :: () -> (),
    ClearBackground = raylib:extern("Luau_ClearBackground") :: (color: utils.color) -> (),
    DrawText = raylib:extern("Luau_DrawText") :: (text: string, fontSize: number,
        pos: utils.vec2,
        color: utils.color) -> (),
    EndDrawing = raylib:extern("Luau_EndDrawing") :: () -> (),
    CloseWindow = raylib:extern("Luau_CloseWindow") :: () -> (),
    DrawRectangle = raylib:extern("Luau_DrawRectangle") :: (pos: utils.vec2, size: utils.vec2, 
        color: utils.color) -> (),
    DrawLine = raylib:extern("Luau_DrawLine") :: (pos1: utils.vec2, pos2: utils.vec2, 
        color: utils.color) -> (),
    IsKeyDown = raylib:extern("Luau_IsKeyDown") :: (key: number) -> boolean,
    IsKeyPressed = raylib:extern("Luau_IsKeyPressed") :: (key: number) -> boolean,
    IsKeyReleased = raylib:extern("Luau_IsKeyReleased") :: (key: number) -> boolean,
    GetMouseX = raylib:extern("Luau_GetMouseX") :: () -> number,
    GetMouseY = raylib:extern("Luau_GetMouseY") :: () -> number,
    IsMouseButtonDown = raylib:extern("Luau_IsMouseButtonDown") :: (button: number) -> boolean,
    IsMouseButtonPressed = raylib:extern("Luau_IsMouseButtonPressed") :: (button: number) -> boolean,
    IsMouseButtonReleased = raylib:extern("Luau_IsMouseButtonReleased") :: (button: number) -> boolean,
    GetScreenWidth = raylib:extern("Luau_GetScreenWidth") :: () -> number,
    GetScreenHeight = raylib:extern("Luau_GetScreenHeight") :: () -> number,
    GetFrameTime = raylib:extern("Luau_GetFrameTime") :: () -> number,
    GetTime = raylib:extern("Luau_GetTime") :: () -> number,
    GetFPS = raylib:extern("Luau_GetFPS") :: () -> number,
}