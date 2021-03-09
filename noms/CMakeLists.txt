cmake_minimum_required(VERSION 3.14...3.20)

project(
  noms
  VERSION 1.0.0
  LANGUAGES CXX
)

option(COMPONENT_TARGETS_ENABLED "enable individual config targets" YES)

add_subdirectory(fruit)
add_subdirectory(veg)

# generate and install export file
# Note: This needs to be done after the all install(TARGETS ...) commands!
install(
  EXPORT ${PROJECT_NAME}-targets
  FILE ${PROJECT_NAME}-targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION lib/cmake/${PROJECT_NAME}
)

include(CMakePackageConfigHelpers)

# generate the version file for the config file
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

# create config file
configure_package_config_file(
  config.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
  INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
  NO_CHECK_REQUIRED_COMPONENTS_MACRO
)

# generate the export targets for the build tree.
# Note: The file created by this command is specific to the build
# tree and should never be installed!
export(
  EXPORT ${PROJECT_NAME}-targets
  FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-targets.cmake
  NAMESPACE ${PROJECT_NAME}::
)

# install cmake project config files
install(
  FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}-config-version.cmake
  DESTINATION lib/cmake/${PROJECT_NAME}
)
