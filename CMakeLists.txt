cmake_minimum_required(VERSION 3.12)
project(INSEL_PARSER)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG")

add_executable(INSEL_PARSER main.cpp utility.cpp graph.cpp)

target_link_libraries(INSEL_PARSER -fsanitize=address)