LIB_FOLDER = C:/LIBRARIES/OpenGL

GLEW_FOLDER = $${LIB_FOLDER}/glew/msys_build/2.0.0 #For detection OpenGL futures
GLFW_FOLDER = $${LIB_FOLDER}/glfw/glfw-3.2.1.bin.WIN32 # for creation window context

INCLUDEPATH += $${GLEW_FOLDER}/include $${GLFW_FOLDER}/include

LIBS += -L$${GLEW_FOLDER}/lib \
        -L$${GLFW_FOLDER}/lib-mingw \
        -lglfw3 \
        -lglew32.dll \
        -lgdi32\
        -lglu32 \
        -luser32\
        -lkernel32 \
        -lopengl32

DEFINES += GLEW_STATIC
QMAKE_CXXFLAGS += --static
