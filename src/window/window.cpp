#include "window.h"

GLWindow::GLWindow()
{
}

GLWindow::~GLWindow()
{
  glfwTerminate();
}

GLFWwindow *GLWindow::create(const char *title, unsigned int width, unsigned int height)
{
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // for macos only, we need to set GLFW_OPENGL_FORWARD_COMPAT
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  window = glfwCreateWindow(width, height, title, NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return nullptr;
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return nullptr;
  }

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

  return window;
}

// Properties
bool GLWindow::shouldClose() const
{
  return glfwWindowShouldClose(window);
}

void GLWindow::pollEvents() const
{
  glfwPollEvents();
}

void GLWindow::swapBuffers() const
{
  glfwSwapBuffers(window);
}

// Setters
void GLWindow::setViewPort(unsigned int width, unsigned int height)
{
  glViewport(0, 0, width, height);
}

void GLWindow::setMouseAccelleration(bool enabled)
{
  if (enabled)
  {
    glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GL_TRUE);
  }
  else
  {
    glfwSetInputMode(window, GLFW_RAW_MOUSE_MOTION, GL_FALSE);
  }
}

void GLWindow::setFramebufferSizeCallback(void (*callback)(GLFWwindow *, int, int))
{
  glfwSetFramebufferSizeCallback(window, callback);
}

void GLWindow::setMouseMoveCallback(void (*callback)(GLFWwindow *, double, double))
{
  glfwSetCursorPosCallback(window, callback);
}

void GLWindow::setScrollCallback(void (*callback)(GLFWwindow *, double, double))
{
  glfwSetScrollCallback(window, callback);
}

// Getters
double GLWindow::getTime()
{
  return glfwGetTime();
}

GLFWwindow *GLWindow::getWindow()
{
  return window;
}