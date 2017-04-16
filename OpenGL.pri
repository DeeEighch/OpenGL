LIB_FOLDER = C:/LIBRARIES/OpenGL

GLEW_FOLDER = $${LIB_FOLDER}/glew #For detection OpenGL futures
GLFW_FOLDER = $${LIB_FOLDER}/glfw/glfw-3.2.1.bin.WIN32 # for creation window context

INCLUDEPATH += $${GLEW_FOLDER}/include $${GLFW_FOLDER}/include

LIBS += -L$${GLEW_FOLDER}/lib \
        -L$${GLFW_FOLDER}/lib-mingw \
        -lglew32 \
        -lglfw3 \
        -lopengl32 \
        -lgdi32
