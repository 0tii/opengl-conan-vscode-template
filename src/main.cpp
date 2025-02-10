#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window/GLWindow.h"

int SCR_WIDTH = 1024, SCR_HEIGHT = 720;

int main()
{
    GLWindow window = GLWindow();
    window.create("GL template", SCR_WIDTH, SCR_HEIGHT);
    window.setViewPort(SCR_WIDTH, SCR_HEIGHT);

    for (size_t i = 0; i < 10; i++)
    {
        std::cout << i << std::endl;
    }

    glfwTerminate();
    return 0;
}