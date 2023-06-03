add_library(Math "")

target_sources(
  Math
  PRIVATE Vector2.cpp Vector3.cpp Matrix.cpp Ray.cpp Quaternion.cpp
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}/Vector2.hpp
         ${CMAKE_CURRENT_LIST_DIR}/Vector3.hpp
         ${CMAKE_CURRENT_LIST_DIR}/Ray.hpp
         ${CMAKE_CURRENT_LIST_DIR}/Matrix.hpp
         ${CMAKE_CURRENT_LIST_DIR}/Quaternion.hpp)

target_include_directories(Math PUBLIC ${CMAKE_CURRENT_LIST_DIR})
