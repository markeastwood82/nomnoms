foreach(component ${noms_FIND_COMPONENTS})
    include(${CMAKE_CURRENT_LIST_DIR}/noms-${component}-config.cmake)
endforeach()
