foreach(component ${noms_FIND_COMPONENT})
    include(${CMAKE_CURRENT_LIST_DIR}/${component}-config.cmake)
endforeach()