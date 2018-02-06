cmake_minimum_required(VERSION 3.8)
project(TDA_Cola)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Documento.h Impresora.h Documento.cpp Impresora.cpp)
add_executable(TDA_Cola ${SOURCE_FILES})