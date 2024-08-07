# 将cpp文件分别编译为同名二进制并放入bin文件夹内
#[[框注释]]
cmake_minimum_required(VERSION 3.18.0)
project(cpp_learn)
# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(HOME ${PROJECT_SOURCE_DIR})
set(EXECUTABLE_OUTPUT_PATH ${HOME}/bin)
set(PROJECT_BINARY_DIR ${HOME}/build)
set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -std=c++23 -stdlib=libstdc++ -Wall -Wextra -Wpedantic -Werror"
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

find_package(Boost REQUIRED COMPONENTS)

if(Boost_FOUND)
  message("Boost found")
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARY_DIRS})
endif()

message(${CMAKE_CXX_FLAGS})
include_directories(${HOME}/include)

file(GLOB SRC RELATIVE ${PROJECT_SOURCE_DIR}/src ${PROJECT_SOURCE_DIR}/src/*.cpp)

foreach(_src_cpp ${SRC})
  string(REGEX MATCH [A-Za-z0-9\-\_]+.cpp _src_target ${_src_cpp}) # extract

  # filename
  string(LENGTH ${_src_target} _src_len)
  math(EXPR _src_len "${_src_len}-4")
  string(SUBSTRING ${_src_target} 0 ${_src_len} _src_target) # extract filename
                                                             # without extension
  message("${_src_cpp} -> ${_src_target}")
  add_executable(${_src_target} ${PROJECT_SOURCE_DIR}/src/${_src_cpp}) # add target
endforeach(_src_cpp ${SRC})

file(GLOB children ${PROJECT_SOURCE_DIR}/src/*)
# 过滤出所有的子目录
set(DIRLIST "")
foreach(child ${children})
  if(IS_DIRECTORY ${child})
    list(APPEND DIRLIST ${child})
  endif()
endforeach()

# 输出所有子目录
foreach(dir ${DIRLIST})
  string(REGEX MATCH /[A-Za-z0-9\-\_]+$ dir_name ${dir})
  string(SUBSTRING ${dir_name} 1 -1 dir_name)
  file(GLOB subsrc ${dir}/*.cpp)
  file(
    GLOB subsrc_rela
    RELATIVE ${dir}
    ${dir}/*.cpp)
  message("ADD PROJ \"${dir_name}\" from: ${subsrc_rela}")
  add_executable(${dir_name} ${subsrc})
endforeach()
