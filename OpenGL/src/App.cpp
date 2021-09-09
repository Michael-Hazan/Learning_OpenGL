#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

extern struct Reso {
    int x;
    int y;
    Reso(int X, int Y) {
        x = X;
        y = Y;
    }
};


void ProcessInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);


}

int main(void)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    GLFWwindow* window;
    Reso* ScrRes;

    ScrRes = new Reso(800, 600);

    window = glfwCreateWindow(ScrRes->x, ScrRes->y, 
                                          "Hello There", NULL, NULL);

    glfwMakeContextCurrent(window);
    if (window == NULL)
    {
        std::cout << "Failed To Create Window" << std::endl;
        glfwTerminate();
        return -1;
    }
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, ScrRes->x, ScrRes->y);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    while (!glfwWindowShouldClose(window))
    {
        ProcessInput(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    

    glfwTerminate();
    return 0;
}

