cmake_minimum_required(VERSION 3.0)

project(munch)

find_package(noms REQUIRED CONFIG COMPONENTS veg fruit)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/main.cpp)

target_link_libraries(
  ${PROJECT_NAME} PUBLIC noms::veg noms::fruit)
