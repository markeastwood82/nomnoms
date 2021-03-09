set(component veg)

#XXX add_library(${component} PUBLIC src/asparagus.cpp)
add_library(${component} INTERFACE)
# Note: a header only lib in this case! CK

# namespaced alias
add_library(${PROJECT_NAME}::${component} ALIAS ${component})

target_include_directories(
  ${component}
  #XXX PUBLIC
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
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

if(COMPONENT_TARGETS_ENABLED)
  # generate and install export file for this component target
  install(
    EXPORT ${PROJECT_NAME}-targets
    FILE ${PROJECT_NAME}-${component}-targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
  )
endif()

# install header files
install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  # TODO: why should this needed? COMPONENT ${component}
  TYPE INCLUDE
  FILES_MATCHING
  PATTERN "*.h"
)
