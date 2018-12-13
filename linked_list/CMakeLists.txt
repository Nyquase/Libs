cmake_minimum_required(VERSION 3.4)
project(linked_list)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wextra -Wall")

set(SRCS
        linked_list_access.c
        linked_list_destroy.c
        linked_list_add.c
        linked_list_remove.c
        )

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_library(${PROJECT_NAME} SHARED ${SRCS})
add_executable(example example.c)

target_link_libraries(example ${PROJECT_NAME})
