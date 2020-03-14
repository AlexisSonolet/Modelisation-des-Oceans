cmake_minimum_required(VERSION 3.14)

project(TP2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS"-g -Wall")

set(SRCS
    src/main.cpp
    src/Dvector.cpp
    )

set(HEADERS
    src/Dvector.h
    )
    
add_executable(main ${SRCS} ${HEADERS})

target_compile_features(main PUBLIC cxx_nullptr)
