set(component fruit)

include(GNUInstallDirs)

add_library(${component} STATIC src/apple.cpp)

target_include_directories(
  ${component} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(
  TARGETS ${component}
  EXPORT ${project}-${component}-config
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include
  DESTINATION ${CMAKE_INSTALL_PREFIX})

install(
  EXPORT ${project}-${component}-config
  NAMESPACE ${project}::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${project})
