cmake_minimum_required(VERSION 3.0)

#set_source_files_properties(templates/ComplexVector.txx PROPERTIES LANGUAGE CXX)

project(TP2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS"-pg -Wall")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -std=c++11")

set(SRCS
    src/main.cpp
    src/WaveModel.cpp
    src/GerstnerWaveModel.cpp
    src/GerstnerWave.cpp
    src/PhilipsWaveModel.cpp
    src/PhilipsWave.cpp
    src/FastFourier.cpp
    src/Ocean.cpp
	test/test_fft.cpp
	test/test_get_height.cpp
    )

set(HEADERS
	headers/ComplexVector.h
    headers/WaveModel.h
    headers/GerstnerWaveModel.h
    headers/GerstnerWave.h
    headers/PhilipsWaveModel.h
    headers/PhilipsWave.h
    headers/FastFourier.h
    headers/Ocean.h
	test/test.h
    )

add_executable(main ${SRCS} ${HEADERS})
target_compile_features(main PUBLIC cxx_nullptr)
