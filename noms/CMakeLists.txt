cmake_minimum_required(VERSION 3.0)
set(project noms)

project(${project})

add_subdirectory(fruit)
add_subdirectory(veg)

configure_file(
  ${project}-config.cmake.in ${project}-config.cmake @ONLY)

install(
  FILES "${CMAKE_BINARY_DIR}/${project}-config.cmake"
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${project})
