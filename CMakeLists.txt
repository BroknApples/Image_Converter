cmake_minimum_required(VERSION 3.20)

project(img_convert LANGUAGES CXX)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(SOURCES
  # sources
  src/main.cpp
  src/cms.cpp
  src/converter.cpp
)

set(INCLUDE_DIRS
  ${INCLUDE_DIR}/libwebp-1.4.0-windows-x64/include
  ${INCLUDE_DIR}/stb
)

message("Include directories:" ${INCLUDE_DIRS})

add_executable(img_convert ${SOURCES})
target_include_directories(img_convert PUBLIC ${INCLUDE_DIRS})