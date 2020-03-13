# Nous voulons un cmake "récent" pour utiliser les dernières fonctionnalités
cmake_minimum_required(VERSION 3.0)

# Notre projet
project(Dvector)

# Crée des variables avec les fichiers à compiler
set(SRCS
    main.cpp
    src/Dvector.cpp
    )
    
set(HEADERS
    src/Dvector.h
    )

# Notre exécutable
add_executable(main ${SRCS} ${HEADERS})

# Cette ligne doit être placée après les add_executable/add_library
target_compile_features(main PUBLIC cxx_nullptr)