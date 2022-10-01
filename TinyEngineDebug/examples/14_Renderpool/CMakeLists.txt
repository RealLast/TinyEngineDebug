set (CMAKE_CXX_STANDARD 20)

link_directories(/usr/local/lib /opt/homebrew/lib)
find_package(OpenGL REQUIRED)
add_executable(example 
source/main.cpp
../../TinyEngine.cpp
)

include_directories(/usr/local/include /opt/homebrew/include)
target_link_libraries(example pthread SDL2 SDL2_image SDL2_mixer SDL2_ttf GLEW boost_system boost_filesystem TinyEngine ${OPENGL_LIBRARIES} glfw)
find_package(glfw3 3.4 REQUIRED)
