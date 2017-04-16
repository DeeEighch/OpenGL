#include <stdlib.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if(!glfwInit()){
        exit(EXIT_FAILURE);
    }

    int width = 1024;
    int height = 768;

    GLFWwindow * window;

    window = glfwCreateWindow(width, height, "GLFW", NULL, NULL);

    if(!window){
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

    cout << "Hello glfw window!" << endl;



    return 0;
}
