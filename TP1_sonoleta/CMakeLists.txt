# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet
project(Dvector)

# Crée des variables avec les fichiers à compiler
set(SRCS
    main.cpp
    src/Dvector.cpp
	test/test_string.cpp
	test/test_construct.cpp
	test/test_copy.cpp
	test/test_random.cpp
    )
    
set(HEADERS
    src/Dvector.h
	test.h
    )

# Notre exécutable
add_executable(main ${SRCS} ${HEADERS})

# Cette ligne doit être placée après les add_executable/add_library
target_compile_features(main PUBLIC cxx_nullptr)
