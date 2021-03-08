set(component fruit)

add_library(${component} src/apple.cpp)

# namespaced alias
add_library(${PROJECT_NAME}::${component} ALIAS ${component})

target_include_directories(
  ${component} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                      $<INSTALL_INTERFACE:include>
)

install(
  TARGETS ${component}
  EXPORT ${PROJECT_NAME}-targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES
  DESTINATION include
)

if(COMPONET_TARGETS_ENABLED)
  # generate and install export file
  install(
    EXPORT ${PROJECT_NAME}-targets
    FILE ${PROJECT_NAME}-${component}-targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
  )
endif()

if(NO)
  # When COMPONENT is specified at the bottom tyring to install munch results
  # in an error in which noms::fruit references nonexistent
  # path usr/local/COMPONENT in INTERFACE_INCLUDE_DIRECTORIES (in Ubuntu).
  # On windows, it was referencing nonexistent lib/fruit.lib
  # Now that I have done this, on Linux at least that seems to be resolved.
  # It appears to be important that INCLUDES DESTINATION is the last parameter!
  # This does reflect the parameter order in the documentation for the install
  # function
  install(
    TARGETS ${component}
    EXPORT ${component}-targets
    COMPONENT ${component}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES
    DESTINATION include
  )

  install(
    EXPORT ${component}-targets
    FILE "${PROJECT_NAME}-${component}-targets.cmake"
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
    COMPONENT ${component}
  )

  # This seems like a kludge, but it does place the file in the correct location
  # on my machine (Ubuntu 18.04). Idea taken from Poco
  configure_file(
    "${component}-config.cmake.in"
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-${component}-config.cmake" @ONLY
  )

  include(CMakePackageConfigHelpers)
  write_basic_package_version_file(
    "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-${component}-config-version.cmake"
    VERSION ${version}
    COMPATIBILITY SameMajorVersion
  )

  install(
    FILES
      "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-${component}-config.cmake"
      "${CMAKE_BINARY_DIR}/${PROJECT_NAME}-${component}-config-version.cmake"
    DESTINATION lib/cmake/${PROJECT_NAME}
    COMPONENT ${component}
  )
endif()

# install header files
install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
  COMPONENT ${component}
  DESTINATION ${CMAKE_INSTALL_PREFIX}
  FILES_MATCHING
  PATTERN "*.h"
)
