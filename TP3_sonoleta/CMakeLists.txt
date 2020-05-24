cmake_minimum_required(VERSION 3.10)

project(TP2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS"-g -Wall")

set(SRCS
    src/main.cpp
    src/Dvector.cpp
    src/Height.cpp
    src/WaveModel.cpp
    src/GerstnerWave.cpp
    src/GerstnerWaveModel.cpp
	test/test_height.cpp
	test/test_gerstner.cpp
    )

set(HEADERS
    headers/Dvector.h
    headers/Height.h
    headers/WaveModel.h
    headers/GerstnerWave.h
    headers/GerstnerWaveModel.h
	test/test.h
    )
    
add_executable(main ${SRCS} ${HEADERS})

target_compile_features(main PUBLIC cxx_nullptr)
