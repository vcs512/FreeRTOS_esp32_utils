# This file was automatically generated for projects
# without default 'CMakeLists.txt' file.

FILE(GLOB_RECURSE app_sources ${CMAKE_SOURCE_DIR}/src/*.*)
FILE(GLOB_RECURSE app_includes ${CMAKE_SOURCE_DIR}/include/*.*)
FILE(GLOB_RECURSE app_libs ${CMAKE_SOURCE_DIR}/lib/*.*)

idf_component_register(SRCS ${app_sources} ${app_includes} ${app_libs})