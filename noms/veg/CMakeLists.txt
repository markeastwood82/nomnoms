set(component veg)

add_library(${component} SHARED src/asparagus.cpp)

target_include_directories(${component}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

install(TARGETS ${component} EXPORT ${component}-targets
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
  COMPONENT ${component}
)

install(EXPORT ${component}-targets
  FILE "${project}-${component}-targets.cmake"
  NAMESPACE ${project}::
  DESTINATION lib/cmake/${project}
)

# This seems like a kludge, but it does place the file in the correct location
# on my machine (Ubuntu 18.04). Idea taken from Poco
configure_file("${component}-config.cmake.in"
  "${CMAKE_BINARY_DIR}/${project}-${component}-config.cmake"
  @ONLY
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${CMAKE_BINARY_DIR}/${project}-${component}-config-version.cmake"
  VERSION ${version}
  COMPATIBILITY AnyNewerVersion
)

install(
  FILES
    "${CMAKE_BINARY_DIR}/${project}-${component}-config.cmake"
    "${CMAKE_BINARY_DIR}/${project}-${component}-config-version.cmake"
  DESTINATION lib/cmake/${project}
)
