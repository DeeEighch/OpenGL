#ifndef GLFW_APP_H
#define GLFW_APP_H

#include "glfw_window.h"

namespace grdima {

struct App{

    Window mWindow;
    Window& window() { return mWindow; }

    App (int width = 640, int height = 480, const char* name = WINDOW_NAME) {

        /*---------------------------------------------------------------------------------
         *  Initialize GLFW
         *---------------------------------------------------------------------------------*/
        if ( !glfwInit() ) exit(EXIT_FAILURE);

        cout << "GLFW initialized!" << endl;

        mWindow.create(this, width, height, name); //<-- Create window, passing this application to it

        cout << "GLFW window created!" << endl;

        /*---------------------------------------------------------------------------------
         *  Initialize GLEW
         *---------------------------------------------------------------------------------*/
        glewExperimental = true;
        GLenum glewError = glewInit();

        if (glewError != GLEW_OK){
            cout << "GLEW init error" << endl
                 << glewGetErrorString(glewError) << endl;
        }

        //Check for specific functionality
        if(GLEW_APPLE_vertex_array_object){
            cout << "genVertexArrayAPPLE supported" << endl;
        } else if(GLEW_ARB_vertex_array_object){
            cout << "genVertexArrays supported" << endl;
        }

        /*---------------------------------------------------------------------------------
         *  Some Good Defaults to Start with: enable Alpha Blending and Depth Testing
         * --------------------------------------------------------------------------------*/
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glLineWidth(3); //<-- Thincken lines so we can see 'em clearly
    }

    /*---------------------------------------------------------------------------------
     *  start the Draw Loop
     * --------------------------------------------------------------------------------*/

    void start(){
        cout << "Starting application" << endl;

        while ( !mWindow.shouldClose() ) {
            mWindow.setViewport();

            glClearColor(.2, .2, .2, 1);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            onDraw();

            mWindow.swapBuffers(); //<--SWAP BUFFERS
            glfwPollEvents();      //<--LISTEN FOR WINDOW EVENTS
        }
    }

    /*---------------------------------------------------------------------------------
     *  Properly terminate GLFW when app closes
     * --------------------------------------------------------------------------------*/
    ~App(){
        glfwTerminate();
    }

    virtual void onDraw() {}

    virtual void onMouseMove(int x, int y){}

    virtual void onMouseDown(int button, int action) {}

    virtual void onKeyDown(int key, int action) {}

};

}
#endif // GLFW_APP_H
