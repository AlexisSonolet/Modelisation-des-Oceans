cmake_minimum_required(VERSION 3.10)

project(TP2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS"-g -Wall")

set(SRCS
    src/main.cpp
    src/Dvector.cpp
	test/test_access.cpp
    test/test_affect.cpp
	test/test_self_operators.cpp
	test/test_flux.cpp
	test/test_operators.cpp
	test/test_resize_equal.cpp
	test/test_time.cpp
	)

set(HEADERS
    src/Dvector.h
	test/test.h
    )
    
add_executable(main ${SRCS} ${HEADERS})

target_compile_features(main PUBLIC cxx_nullptr)
