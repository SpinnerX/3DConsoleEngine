#pragma once
#include <math/Vector.h>
#include <cstdint>
#include <cstring>
#include <algorithm>

/**
 * 
 * 
 * Pixel
 * - R(Red), G(green), B(blue), A(alpha)
 * 
 * 
*/

struct Pixel{
    Pixel() = default;
    Pixel(uint8_t R, uint8_t G, uint8_t B, uint8_t A = 0) : r(R), g(G), b(B), a(A) { }
    Pixel(const Pixel&& pixel) : r(pixel.r), g(pixel.g), b(pixel.b), a(pixel.a) { }



    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
    Vector2f position;
};