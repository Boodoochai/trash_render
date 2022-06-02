add_library(Objects "")

target_sources(Objects
  PRIVATE
    Object.cpp
    Sphere.cpp
    Torus.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Object.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Sphere.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Torus.hpp
  )

target_include_directories(Objects
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

target_link_libraries(Objects
    PRIVATE
    Math)
