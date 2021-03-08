cmake_minimum_required(VERSION 3.14...3.20)

project(
  munch
  VERSION 1.0.0
  LANGUAGES CXX
)

find_package(noms 1 REQUIRED COMPONENTS fruit veg)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC noms::fruit noms::veg)

enable_testing()
add_test(NAME munchTest COMMAND munch)

# MAYBE:
# install(${PROJECT_NAME} ...)
