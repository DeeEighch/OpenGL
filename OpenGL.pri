LIB_FOLDER = $$PWD/libraries

GLEW_FOLDER = $${LIB_FOLDER}/glew/msys_build_2_0_0 #For detection OpenGL futures
GLFW_FOLDER = $${LIB_FOLDER}/glfw/glfw-3.2.1.bin.WIN32 # for creation window context

INCLUDEPATH += $${GLEW_FOLDER}/include $${GLFW_FOLDER}/include $${PWD}/include

LIBS += -L$${GLEW_FOLDER}/lib \
        -L$${GLFW_FOLDER}/lib \
        -lglfw3 \
        -lglew32 \
        -lgdi32\
        -lglu32 \
        -luser32\
        -lkernel32 \
        -lopengl32

DEFINES += GLEW_STATIC \
           WINDOW_NAME=\"\\\"$$TARGET\\\"\"
#QMAKE_CXXFLAGS += --static
