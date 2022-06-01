project(c++_terminal_trash_render)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

add_subdirectory(Math)
add_subdirectory(Render)
add_subdirectory(Scene)
add_subdirectory(Window)

target_link_libraries(${CMAKE_PROJECT_NAME} 
    PRIVATE
    Math
    Scene
    Render
    Window)

target_link_libraries(${CMAKE_PROJECT_NAME} 
    m
    ncurses
    stdc++)
