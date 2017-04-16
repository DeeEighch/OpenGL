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

    GLFWwindow * window; //Create Window (use glfwGetPrimaryMonitor() for fullscreen)
    window = glfwCreateWindow(width, height, "GLFW", NULL, NULL);

    if(!window){ //Check Validity
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window); //Make Window Current Context

    cout << "GLFW window initialized!" << endl;

    while (!glfwWindowShouldClose(window)) {
        glViewport(0, 0, width, height); //set Viewport in pixels
        glClearColor(1, 0, 0, 1);   //Clear window contents
        glClear(GL_COLOR_BUFFER_BIT);

        //drawing

        glfwSwapBuffers(window); //<--SWAP BUFFERS
        glfwPollEvents(); //<--LISTEN FOR WINDOW EVENTS

    }
    //destroy window and terminate glfw
    glfwDestroyWindow(window);
    glfwTerminate();
    cout << "Googbye!" << endl;

    return 0;
}
