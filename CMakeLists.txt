cmake_minimum_required(VERSION 3.26)

project(cpp_test)

#set(CMAKE_CXX_COMPILER g++-13)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -Wconversion -pedantic -O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-Wall -Wextra -pedantic -Wconversion -Werror -O3")

add_subdirectory(src)
include_directories(./include)

add_executable(main src/main.cpp)

add_custom_command(
	TARGET main POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json
	COMMENT "Transferring compile_commands.json"
)
