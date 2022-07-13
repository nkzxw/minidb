cmake_minimum_required(VERSION 3.10)
project(MiniDB)
set(CMAKE_CXX_STANDARD 14)
include_directories(
    ${CMAKE_SOURCE_DIR}/deps/cereal-1.3.2/include
    ${CMAKE_SOURCE_DIR}/deps/NanoLog
)
aux_source_directory(src source_list)
aux_source_directory(deps/NanoLog NanoLog_list)
add_executable(minidb ${source_list} ${NanoLog_list})
target_link_libraries(minidb readline stdc++fs pthread)
