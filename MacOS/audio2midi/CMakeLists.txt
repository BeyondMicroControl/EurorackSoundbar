cmake_minimum_required(VERSION 3.20)
project(audio2midi LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(libremidi CONFIG REQUIRED)
find_package(SndFile CONFIG REQUIRED)
find_package(aubio CONFIG REQUIRED)

add_executable(audio2midi
  src/main.cpp
)

target_include_directories(audio2midi PRIVATE src)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
  target_compile_options(audio2midi PRIVATE -Wall -Wextra -Wpedantic)
endif()

find_package(aubio CONFIG REQUIRED)

# Robust linking for vcpkg on macOS (Debug/Release)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  set(AUBIO_LIB "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/debug/lib/libaubio.a")
else()
  set(AUBIO_LIB "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/lib/libaubio.a")
endif()

target_link_libraries(audio2midi PRIVATE
  libremidi
  SndFile::sndfile
  "${AUBIO_LIB}"
)


