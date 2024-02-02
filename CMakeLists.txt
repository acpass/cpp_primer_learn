#将cpp文件分别编译为同名二进制并放入bin文件夹内
#[[框注释]]
cmake_minimum_required(VERSION 3.22.0)
project(cpp_learn)
set(CMAKE_CXX_STANDARD 17)
set(HOME ${PROJECT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
set(PROJECT_BINARY_DIR ${HOME}/build)
set(CMAKE_INCLUDE_PATH ${HOME}/include)

file(GLOB SRC ${PROJECT_SOURCE_DIR}/*.cpp)

foreach(_src_cpp ${SRC})
  string(REGEX MATCH [A-Za-z0-9\-\_]*.cpp _src_target ${_src_cpp})  # extract filename
  string(LENGTH ${_src_target} _src_len)
  math(EXPR _src_len "${_src_len}-4")
  string(SUBSTRING ${_src_target} 0 ${_src_len} _src_target)  #extract filename without extension
  message("${_src_cpp} -> ${_src_target}")
  add_executable(${_src_target} ${_src_cpp})  #add target
endforeach(_src_cpp ${SRC})
