TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

LIB_FOLDER = C:/LIBRARIES/OpenGL
GLEW_FOLDER = $${LIB_FOLDER}/glew
GLFW_FOLDER = $${LIB_FOLDER}/glfw/glfw-3.2.1.bin.WIN32

INCLUDEPATH += $${GLEW_FOLDER}/include $${GLFW_FOLDER}/include

LIBS += -L$${GLEW_FOLDER}/lib \
        -L$${GLFW_FOLDER}/lib-mingw \
        -lglew32 \
        -lglfw3 \
        -lopengl32 \
        -lgdi32

#LIBS += -LC:/mingw/bin -LC:/curl
