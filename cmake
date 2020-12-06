make_minimum_required(VERSION 3.17)
project(Assignment4)
set(CMAKE_CXX_STANDARD 14)

find_package (Threads)

aux_source_dictionary(. DIR_SRCS)

add_executable(Assignment ${DIR_SRCS})
target_line_libraries (myapp ${CMAKE_THREAD_LIBS_INIT})
