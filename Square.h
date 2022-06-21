#pragma once

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "Shape.h"

class Square : public Shape
{
public:

    static unsigned int vertexArray;
    static unsigned int vertexBuffer;
    static unsigned int indexBuffer;

    Square();

    void draw();

private:
    float vertices[16] = {
    1.0f, 1.0f, 0.0f, 1.0f,
    -1.0f, 1.0f, 0.0f, 0.0f,
    -1.0f, -1.0f, 0.0f, -1.0f,
    1.0f, -1.0f, 1.0f, 1.0f
    };

    unsigned int indexArr[6] = {
        0, 1, 2, 0, 2, 3
    };

    glm::vec4 color = glm::vec4(1.0, 1.0, 1.0, 1.0);

    glm::mat4x4 transformationMat4x4 = glm::mat4x4(1.0f);
    
};

