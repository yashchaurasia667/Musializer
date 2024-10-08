#include <stdio.h>
#include <GLFW/glfw3.h>

void error_callback(int error, const char *description)
{
  fprint(stderr, "Error; %s\n", description);
}

int main()
{
  GLFWwindow *window;
  glfwSetErrorCallback(error_callback);

  if (!glfwInit())
  {
    printf("Failed to initialize GLFW\n");
    return -1;
  }

  window = glfwCreateWindow(1280, 720, "Todo", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  while (!glfwWindowShouldClose(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}