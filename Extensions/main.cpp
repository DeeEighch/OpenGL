#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if(!glfwInit()){
        exit(EXIT_FAILURE);
    }

    cout << "GLFW initialized!" << endl;

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

    //GLEW must be initialized, if OpenGL context exists

    //glewExperimental = true; //This flag helps prevent errors with modern OpenGL
    GLenum glewError = glewInit(); //Initialize GLEW
    if(glewError != GLEW_OK){
        cout << "GLEW initialization error" << endl
             << glewGetErrorString(glewError) << endl;
    }

    if(!GLEW_VERSION_2_1){
        cout << "OpenGL 2.1 or above not supported" << endl;
        return false;
    }

    //Get OpenGL Version String and GLSL Version string
    const GLubyte * p = glGetString(GL_VERSION);
    cout << "Graphics Driver: " << p << endl;

    const GLubyte * q = glGetString(GL_SHADING_LANGUAGE_VERSION);
    cout << "GLSL Version: " << q << endl;

    //Check for specific functionality
    if(GLEW_ARB_vertex_array_object){
        cout << "genVertexArrays supported" << endl;
    }
    if(GLEW_APPLE_vertex_array_object){
        cout << "genVertexArrayAPPLE supported" << endl;
    }


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
