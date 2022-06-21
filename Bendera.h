#pragma once
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Bendera : public Shape
{

public:
    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Bendera();

    void draw();


private:

    float vertices[16] = {
       1.0f, 1.0f, 1.0f, 0.0f,
        -1.0f, 1.0f, 0.0f, 0.0f,
    -1.0f, -1.0f, 0.0f, 1.0f,
    1.0f, -1.0f, 1.0f, 1.0f
    };
    

    unsigned int indexArr[6] = {
        0, 1, 2, 2, 1, 3
    };

};
