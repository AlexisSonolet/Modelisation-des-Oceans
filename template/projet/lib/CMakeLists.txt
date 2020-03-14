cmake_minimum_required(VERSION 3.14)

project(lib)

set(CMAKE_CXX_STANDARD 14)

set(SRCS
    fichier.cpp
    )
    
set(HEADERS
    fichier.h
    )

# On ajoute la librairie
add_library(fichier ${SRCS} ${HEADERS})
