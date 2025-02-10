#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window/window.h"

int SCR_WIDTH = 1024, SCR_HEIGHT = 720;

int main()
{
    GLWindow window = GLWindow();
    window.create("xc0n prototype", SCR_WIDTH, SCR_HEIGHT);
    window.setViewPort(SCR_WIDTH, SCR_HEIGHT);
    window.setMouseAccelleration(false);
    while (!window.shouldClose())
    {
    }

    glfwTerminate();
    return 0;
}