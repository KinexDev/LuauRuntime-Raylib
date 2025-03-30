-- between 0-255
export type color = {
    r: number,
    g: number,
    b: number,
    a: number?
}

local color = {
    new = function(r: number, g: number, b: number, a: number?): color
        return { r = r, g = g, b = b, a = a }
    end
}

local vec2 = {}

local vec2_mt = {}

vec2_mt.__index = vec2

vec2_mt.__add = function(a: vec2, b: vec2): vec2
	return vec2.new(a.x + b.x, a.y + b.y)
end

vec2_mt.__sub = function(a: vec2, b: vec2): vec2
	return vec2.new(a.x - b.x, a.y - b.y)
end

vec2_mt.__mul = function(a: vec2, b: number): vec2
	return vec2.new(a.x * b, a.y * b)
end

vec2_mt.__div = function(a: vec2, b: number): vec2
	return vec2.new(a.x / b, a.y / b)
end

vec2_mt.__tostring = function(a: vec2): string
	return "(" .. a.x .. ", " .. a.y .. ")"
end

function vec2.new(x: number, y: number) : vec2
	local b: { x: number, y: number} = { x = x, y = y }
	return setmetatable(b, vec2_mt) :: vec2
end

export type vec2 = typeof(setmetatable({} :: { x: number, y: number}, vec2_mt))

local keys = {
    A = 65,
    B = 66,
    C = 67,
    D = 68,
    E = 69,
    F = 70,
    G = 71,
    H = 72,
    I = 73,
    J = 74,
    K = 75,
    L = 76,
    M = 77,
    N = 78,
    O = 79,
    P = 80,
    Q = 81,
    R = 82,
    S = 83,
    T = 84,
    U = 85,
    V = 86,
    W = 87,
    X = 88,
    Y = 89,
    Z = 90,
    Key0 = 48,
    Key1 = 49,
    Key2 = 50,
    Key3 = 51,
    Key4 = 52,
    Key5 = 53,
    Key6 = 54,
    Key7 = 55,
    Key8 = 56,
    Key9 = 57,
    Space = 32,
    Enter = 257,
    Tab = 258,
    Backspace = 259,
    Escape = 256,
    LeftShift = 340,
    RightShift = 344,
    LeftControl = 341,
    RightControl = 345,
    LeftAlt = 342,
    RightAlt = 346,
    Up = 265,
    Down = 264,
    Left = 263,
    Right = 262
}

local mouseButtons = {
    left = 0,
    right = 1,
    middle = 2
}

return {
    color = color,
    vec2 = vec2,
    keys = keys,
    mouseButtons = mouseButtons
}