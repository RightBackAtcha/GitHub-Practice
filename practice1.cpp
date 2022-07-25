#include <iostream>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const unsigned int WND_HEIGHT = 720;
const unsigned int WND_WIDTH = 1280;

int main(){
    // GLFW initialization and configuration process
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // GLFW window creation
    GLFWwindow *window = glfwCreateWindow(WND_WIDTH, WND_HEIGHT, "Practice OpenGL", NULL, NULL);
    if(window == NULL){
        std::cout << "Failed to create GLFW window";
        glfwTerminate();
        return -1;
    }

    // Render loop
    while(!glfwWindowShouldClose(window)){
        glClearColor( 0.0f, 1.f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}
