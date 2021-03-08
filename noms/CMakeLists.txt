cmake_minimum_required(VERSION 3.14...3.20)

project(
  noms
  VERSION 1.0.0
  LANGUAGES CXX
)

add_subdirectory(fruit)
add_subdirectory(veg)

### Note: does not work noms-targets.cmake! CK
# configure_file(${PROJECT_NAME}-config.cmake
#   "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-config.cmake"
#   @ONLY
# )

include(CMakePackageConfigHelpers)

# generate the version file for the config file
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
  VERSION ${version}
  COMPATIBILITY SameMajorVersion
)

# create config file
option(COMPONET_TARGETS_ENABLED "enable individual config targets" NO)
configure_package_config_file(
  config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
  INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
)

# generate the export targets for the build tree. Note: This needs to be done after the all
# install(TARGETS ...) commands!
export(
  EXPORT ${PROJECT_NAME}-targets
  FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-targets.cmake
  NAMESPACE ${PROJECT_NAME}::
)

# install cmake project config files
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-targets.cmake
  DESTINATION lib/cmake/${PROJECT_NAME}
)
