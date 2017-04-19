#ifndef GLFW_WINDOW_H
#define GLFW_WINDOW_H

#include "gl_lib.h"
#include <iostream>

using namespace std;

namespace grdima {
struct Interface {
    static void * app;

    template<class APPLICATION>
    static void OnKeyDown(GLFWwindow* window, int key, int scancode, int action, int mods){
        ((APPLICATION*)(app))->onKeyDown(key, action);
    }

    template<class APPLICATION>
    static void OnMouseMove(GLFWwindow* window, double x, double y){
        ((APPLICATION*)(app))->onMouseMove(x, y);
    }

    template<class APPLICATION>
    static void OnMouseDown(GLFWwindow* window, int button, int action, int mods){
        ((APPLICATION*)(app))->onMouseDown(button, action);
    }
};

void * Interface::app;

/*---------------------------------------------------------------------------------
 *  A GLFW window wrapper
 *---------------------------------------------------------------------------------*/

struct Window{

    GLFWwindow * window;
    Interface interface;

    int mWidth, mHeight;

    int width(){ return mWidth; }
    int heignt() { return mHeight;}
    float ratio() { return (float)mWidth/mHeight;}

    Window(){}

    //Create a window Context
    template<class APPLICATION>
    void create(APPLICATION * app, int width, int height, const char * name = "Window"){
        interface.app = app;

        mWidth = width; mHeight = height;

        window = glfwCreateWindow(width, height, name, NULL, NULL);

        if(!window){
            glfwTerminate();
            exit(EXIT_FAILURE);
        }

        glfwMakeContextCurrent(window);
        glfwSwapInterval(1); //<--force interval (not guaranted to work with all graphics drivers)

        //register callbacks for keyboard and mouse
        glfwSetKeyCallback(window, Interface::OnKeyDown<APPLICATION>);
        glfwSetCursorPosCallback(window, Interface::OnMouseMove<APPLICATION>);
        glfwSetMouseButtonCallback(window, Interface::OnMouseDown<APPLICATION>);

    }

    //Get current framebuffer SIze and Set the Viewport to it
    void setViewport(){
        glfwGetFramebufferSize(window, &mWidth, &mHeight);
        glViewport(0, 0, mWidth, mHeight);
    }

    //Check whether window should close
    bool shouldClose(){
        return glfwWindowShouldClose(window);
    }

    //Swap front and back buffers
    void swapBuffers(){
        glfwSwapBuffers(window);
    }

    //Destroy the window
    void destroy(){
        glfwDestroyWindow(window);
    }

    ~Window(){
        destroy();
    }

};


}


#endif // GLFW_WINDOW_H
