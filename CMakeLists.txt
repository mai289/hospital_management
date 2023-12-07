cmake_minimum_required(VERSION 3.0)

project(hospital_management C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2 -g -Wall")

include_directories("${PROJECT_SOURCE_DIR}/include")

aux_source_directory(. ROOT_SOURCE)

add_subdirectory(src)

add_executable(main ${ROOT_SOURCE} ${SRC_FILE})