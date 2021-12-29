cmake_minimum_required(VERSION 3.0.0)
project(regpegawai VERSION 0.0.2 LANGUAGES C)

include_directories(include)

file(GLOB SOURCES "src/*.c")

add_executable(regpegawai ${SOURCES})

set_property(TARGET regpegawai PROPERTY C_STANDARD 99)

target_link_libraries(regpegawai PRIVATE m)