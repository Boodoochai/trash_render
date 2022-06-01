add_library(Scene "")

add_subdirectory(Objects)

target_sources(Scene
  PRIVATE
  Scene.cpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/Scene.h
  )

target_include_directories(Scene
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

target_link_libraries(Scene 
    PRIVATE 
    Objects
    Render)
