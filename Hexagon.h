#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Hexagon : public Shape
{
public:

    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Hexagon();
    void draw();

private:
    float xp = 0, yp = 0, r = 1, n = 8, x = 0, y = 0;
    float a = 0.5f;

    float vertices[18] = {

    };


    unsigned int indexArr[24] = {
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 5,
        0, 5, 6,
        0, 6, 7,
        0, 7, 8,
        0, 8, 1
    };
};