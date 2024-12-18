cmake_minimum_required(VERSION 3.20)

project(img_convert LANGUAGES CXX)

set(CXX_STANDARD 20)

set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(SOURCES
  # sources
  src/main.cpp
  src/cms.cpp
  src/converter.cpp
)

set(WEBP_PATH ${INCLUDE_DIR}/libwebp-1.4.0-windows-x64)

set(INCLUDE_DIRS
  ${WEBP_PATH}/include
  ${INCLUDE_DIR}/stb
)

message("Include directories:" ${INCLUDE_DIRS})

# create exe

add_executable(img_convert ${SOURCES})

target_include_directories(img_convert PUBLIC ${INCLUDE_DIRS})

target_link_libraries(img_convert
  ${WEBP_PATH}/libwebp.lib
  ${WEBP_PATH}/libwebpdemux.lib
  ${WEBP_PATH}/libwebpmux.lib
)