#include <stdio.h>
#include <GLFW/glfw3.h>

int main()
{
  glfwInit();
  GLFWwindow *window = glfwCreateWindow(1280, 720, "Todo ", NULL, NULL);
  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window))
  {
    glfwPollEvents();
    glfwSwapBuffers(window);
  }
  return 0;
}
