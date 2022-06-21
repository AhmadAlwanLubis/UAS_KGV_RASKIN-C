#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

#include "util.h"
#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "Square.h"
#include "Triangle.h"
#include "Triangle2.h"
#include "Bendera.h"
#include "Hexagon.h"

int main(void)
{

    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Raskin-C", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();

    Square s1;
    s1.setTranslation(0.0f, -1.0f, 1.0f);
    s1.setScale(1.0f, 2.0f, 0.0f);
    s1.setColor(glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));

    Square s2;
    s2.setTranslation(0.0f, -1.0f, 1.0f);
    s2.setScale(1.0f, 0.3f, 1.0f);
    s2.setColor(glm::vec4(1.0f, 0.5f, 0.0f, 0.0f));

    Square s3;
    s3.setTranslation(0.0f, -1.0f, 1.0f);
    s3.setScale(0.2f, 0.2f, 1.0f);
    s3.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));

    Square s4;
    s4.setTranslation(0.0f, -0.5f, 1.0f);
    s4.setScale(-0.1f, 1.0f, 0.0f);
    s4.setColor(glm::vec4(1.0f, 1.0f, 1.0f, 0.0f));

    Triangle t1;
    t1.setTranslation(-0.3f, -0.9f, 0.0f);
    t1.setScale(0.1f, 0.1f, 1.0f);
    t1.setColor(glm::vec4(1.0f, 1.0f, 0.0f, 0.0f));
    
    Triangle2 t2;
    t2.setTranslation(0.3f, -0.9f, 0.0f);
    t2.setScale(0.1f, 0.1f, 1.0f);
    t2.setColor(glm::vec4(1.0f, 1.0f, 0.0f, 0.0f));

    Bendera b1;
    b1.setTranslation(0.2f, 0.4f, 0.0f);
    b1.setScale(0.2f, -0.1f, 0.5f);
    b1.setColor(glm::vec4(1.0f, 0.0f, 0.0f, 0.0f));

    Hexagon bl1;
    bl1.setTranslation(0.9f, 0.9f, 0.0f);
    bl1.setScale(0.2f, 0.2f, 1.0f);
    bl1.setColor(glm::vec4(1.0f, 1.0f, 0.0f, 0.0f));

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    string vertexString = readFile("vertex.vert");
    string fragmentString = readFile("fragment.frag");

    const char* vertexChar = vertexString.c_str();
    const char* fragmentChar = fragmentString.c_str();

    glShaderSource(vertexShader, 1, &vertexChar, NULL);
    glShaderSource(fragmentShader, 1, &fragmentChar, NULL);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);


    unsigned int program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    GLint uColor = glGetUniformLocation(program, "uColor");
    GLint uMat4x4 = glGetUniformLocation(program, "transformationMat4x4");

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(program);

        glUniform4fv(uColor, 1, &s1.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s1.getTransformationMat4x4()[0][0]);
        s1.draw();

        glUniform4fv(uColor, 1, &s2.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s2.getTransformationMat4x4()[0][0]);
        s2.draw();

        glUniform4fv(uColor, 1, &s3.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s3.getTransformationMat4x4()[0][0]);
        s3.draw();

        glUniform4fv(uColor, 1, &s4.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &s4.getTransformationMat4x4()[0][0]);
        s4.draw();
        
        glUniform4fv(uColor, 1, &t1.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &t1.getTransformationMat4x4()[0][0]);
        t1.draw();

        glUniform4fv(uColor, 1, &t2.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &t2.getTransformationMat4x4()[0][0]);
        t2.draw();

        glUniform4fv(uColor, 1, &b1.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &b1.getTransformationMat4x4()[0][0]);
        b1.draw();

        glUniform4fv(uColor, 1, &bl1.getColor()[0]);
        glUniformMatrix4fv(uMat4x4, 1, GL_FALSE, &bl1.getTransformationMat4x4()[0][0]);
        bl1.draw();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}