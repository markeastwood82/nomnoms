cmake_minimum_required(VERSION 3.0)
set(project noms)
set(version 1.0.0)

project(${project})

add_subdirectory(fruit)
add_subdirectory(veg)

# UPDATE: implement advice from Tsyvarev

configure_file(${project}-config.cmake
  "${CMAKE_BINARY_DIR}/${project}-config.cmake"
  @ONLY
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_BINARY_DIR}/${project}-config-version.cmake"
  VERSION ${version}
  COMPATIBILITY AnyNewerVersion
)

install(
  FILES
    "${CMAKE_BINARY_DIR}/${project}-config.cmake"
  DESTINATION lib/cmake/${project}
)
