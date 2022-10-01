set (CMAKE_CXX_STANDARD 20)

link_directories(/usr/local/lib /opt/homebrew/lib)
find_package(OpenGL REQUIRED)


add_executable(example 
main.cpp

)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set(CMAKE_BUILD_TYPE Debug)

add_definitions(-DTINYENGINE_COMPATIBILITY)

find_package(glfw3 3.4 REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(example PUBLIC ${OPENGL_INCLUDE_DIR} /opt/homebrew/include ${CMAKE_CURRENT_LIST_DIR}/srcs/include ${CMAKE_CURRENT_LIST_DIR}/srcs)

if (APPLE)
    target_link_libraries(example "-framework Cocoa")
    target_link_libraries(example "-framework OpenGL")
    target_link_libraries(example "-framework IOKit")
endif (APPLE)
target_link_libraries(example glfw ${OPENGL_gl_LIBRARY})

include_directories(/usr/local/include /opt/homebrew/include)
target_link_libraries(example pthread SDL2 SDL2_image SDL2_mixer SDL2_ttf GLEW boost_system boost_filesystem  ${OPENGL_LIBRARIES} TinyEngine)
