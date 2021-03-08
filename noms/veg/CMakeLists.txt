set(component veg)

#XXX add_library(${component} PUBLIC src/asparagus.cpp)
add_library(${component} INTERFACE)

# namespaced alias
add_library(${PROJECT_NAME}::${component} ALIAS ${component})

target_include_directories(${component}
  INTERFACE #XXX PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# When COMPONENT is specified at the bottom tyring to install munch results
# in an error in which noms::veg references nonexistent
# path usr/local/COMPONENT in INTERFACE_INCLUDE_DIRECTORIES (in Ubuntu).
# On windows, it was referencing nonexistent lib/fruit.lib
# Now that I have done this, on Linux at least that seems to be resolved.
# It appears to be important that INCLUDES DESTINATION is the last parameter!
# This does reflect the parameter order in the documentation for the install
# function
install(TARGETS ${component} EXPORT ${component}-targets
  COMPONENT ${component}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

install(EXPORT ${component}-targets
  FILE "${PROJECT_NAME}-${component}-targets.cmake"
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION lib/cmake/${PROJECT_NAME}
  COMPONENT ${component}
)

# This seems like a kludge, but it does place the file in the correct location
# on my machine (Ubuntu 18.04). Idea taken from Poco
configure_file("${component}-config.cmake.in"
  "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-${component}-config.cmake"
  @ONLY
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-${component}-config-version.cmake"
  VERSION ${version}
  COMPATIBILITY AnyNewerVersion
)

install(
  FILES
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-${component}-config.cmake"
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-${component}-config-version.cmake"
  DESTINATION lib/cmake/${PROJECT_NAME}
  COMPONENT ${component}
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
  COMPONENT ${component}
  DESTINATION ${CMAKE_INSTALL_PREFIX}
  FILES_MATCHING
  PATTERN "*.h"
)
