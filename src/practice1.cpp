#include <iostream>
#include <vector>
#include <glad.h>
#include <glfw3.h>

const unsigned int WIND_WIDTH = 1600;
const unsigned int WIND_HEIGHT = 900;

int main(){

    // glwf initialization and configuration process
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    // glfw window creation
    GLFWwindow *window = glfwCreateWindow(WIND_WIDTH, WIND_HEIGHT, "Practice", NULL, NULL);
    if(window == NULL){
        std::cout << "Failed to create GLFW window.\n";
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
}
