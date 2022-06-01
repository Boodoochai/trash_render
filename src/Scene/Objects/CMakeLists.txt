add_library(Objects "")

target_sources(Objects
  PRIVATE
    Object.cpp
    Sphere.cpp
    Torus.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Object.h
    ${CMAKE_CURRENT_LIST_DIR}/Sphere.h
    ${CMAKE_CURRENT_LIST_DIR}/Torus.h
  )

target_include_directories(Objects
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

target_link_libraries(Objects
    PRIVATE
    Math)
