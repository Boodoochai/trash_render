add_library(Render "")

target_sources(
  Render
  PRIVATE Camera.cpp Render.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Camera.hpp
         ${CMAKE_CURRENT_LIST_DIR}/Render.hpp)

target_include_directories(Render PUBLIC ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(Render PRIVATE Math Scene Window)
