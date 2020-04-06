cmake_minimum_required(VERSION 3.0)
set(project noms)

project(${project})

add_subdirectory(fruit)
add_subdirectory(veg)

install(
  FILES "${CMAKE_CURRENT_SOURCE_DIR}/${project}-config.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${project})
