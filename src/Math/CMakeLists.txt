add_library(Math "")

target_sources(Math
  PRIVATE
    Vector2.cpp
    Vector3.cpp
    Matrix.cpp
    Ray.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Vector2.h
    ${CMAKE_CURRENT_LIST_DIR}/Vector3.h
    ${CMAKE_CURRENT_LIST_DIR}/Ray.h
    ${CMAKE_CURRENT_LIST_DIR}/Matrix.h
  )

target_include_directories(Math
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )
