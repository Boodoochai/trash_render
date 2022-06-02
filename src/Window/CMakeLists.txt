add_library(Window "")

target_sources(Window
  PRIVATE
  Window.cpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/Window.hpp
  )

target_include_directories(Window
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

target_link_libraries(Window PRIVATE Math)
