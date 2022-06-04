add_library(Scene "")

target_sources(Scene
  PRIVATE
    Object.cpp
    Sphere.cpp
    Torus.cpp
    Scene.cpp
    Shape.cpp
    DistanceEstimator.cpp
    CompositeDistanceEstimator.cpp
    CompositeObject.cpp
    SphereDistanceEstimator.cpp
    TorusDistanceEstimator.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Object.hpp
    ${CMAKE_CURRENT_LIST_DIR}/CompositeObject.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Shape.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Sphere.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Torus.hpp
    ${CMAKE_CURRENT_LIST_DIR}/Scene.hpp
    ${CMAKE_CURRENT_LIST_DIR}/CompositeDistanceEstimator.hpp
    ${CMAKE_CURRENT_LIST_DIR}/DistanceEstimator.hpp
    ${CMAKE_CURRENT_LIST_DIR}/TorusDistanceEstimator.hpp
    ${CMAKE_CURRENT_LIST_DIR}/SphereDistanceEstimator.hpp
  )

target_include_directories(Scene
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

target_link_libraries(Scene
    PRIVATE
    Render
    Math)
