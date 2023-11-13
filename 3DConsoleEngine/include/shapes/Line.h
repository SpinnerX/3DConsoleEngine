#pragma once
#include <math/Vector.h>

/**
 * 
 * 
 * Line
 * - Intersection()
 * - normalizing
 * 
 * 
*/

struct Line{
    Line() = default;
    Line(const Vector2f& other_1, const Vector2f& other_2) : p1(other_1), p2(other_2) { }
    

    Vector2f p1;
    Vector2f p2;
};