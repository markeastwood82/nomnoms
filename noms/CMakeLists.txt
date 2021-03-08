cmake_minimum_required(VERSION 3.14...3.20)

project(noms VERSION 1.0.0 LANGUAGES CXX)

add_subdirectory(fruit)
add_subdirectory(veg)

# UPDATE: implement advice from Tsyvarev

configure_file(${PROJECT_NAME}-config.cmake
  "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
  @ONLY
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake"
  VERSION ${version}
  COMPATIBILITY AnyNewerVersion
)

install(
  FILES
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
  DESTINATION lib/cmake/${PROJECT_NAME}
)
