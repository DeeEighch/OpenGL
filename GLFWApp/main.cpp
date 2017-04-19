#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#include <glfw_app.h>

using namespace grdima;

using namespace std;

struct MyApp : App {
    MyApp() : App() {}

    virtual void onDraw()
    {

    }

    virtual void onMouseMove(int x, int y)
    {
        cout << x << " " << y << endl;
    }

    virtual void onMouseDown(int button, int action)
    {
        if(action == GLFW_PRESS) cout << "mouse pressed" << endl;
        if(action == GLFW_RELEASE) cout << "mouse released" << endl;
    }

    virtual void onKeyDown(int key, int action) override
    {
        cout << (unsigned char)key << endl;
    }
};

int main(int argc, char *argv[])
{
    MyApp app;

    app.start();

    cout << "Googbye!" << endl;

    return 0;
}
