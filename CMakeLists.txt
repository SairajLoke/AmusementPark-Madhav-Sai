###-----------------CMake Setup----------------------
cmake_minimum_required(VERSION 3.16)
add_compile_options(-Werror)  
#setting warnings to error, production grade
#not to be present in final shipping code but good for dev
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


###-----------------Project Specifics----------------------
project(cs352 VERSION 0.1.0)
add_executable(${PROJECT_NAME} 
    main.cpp 
)
# install()

set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SGI_IMG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sgi_images)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sgi_images
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
# List all the source files recursively
file(GLOB_RECURSE SOURCES ${SOURCES_DIR}/*.cpp)
file(GLOB_RECURSE HEADERS ${SOURCES_DIR}/*.h)

# #project libs (ones created by us)
# we create a lib out of those cpp and hpp 
# and then link it to execs using target_link_libraries
#builds static lib by default (.a in build folder)
# can be seen using the ldd cscs cmd
add_library(${PROJECT_NAME}_lib
    # include_libs.h 
    libs.h
    
    ${SOURCES}
    ${HEADERS}
    bmpLoader.h 
    bmpLoader.cpp
)


#how is this diff than above? check it out
# target_include_directories(${PROJECT_NAME}
#     PUBLIC src/
# )

#external dependencies
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
# find_package(GTest) planning to use afterwards

#how to put both interface and private link libs tog4ether?
target_link_libraries(${PROJECT_NAME} 
    OpenGL::GL 
    GLUT::GLUT 
    GLU

    ${PROJECT_NAME}_lib

)
#running make req sudo ig because of path of OpenGL and glut libs
#-l add automatically ( these are the same libs used in compile cmd with-l prefix)
#Interface as we dont have anything to build

