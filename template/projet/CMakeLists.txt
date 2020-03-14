cmake_minimum_required(VERSION 3.14)

project(nom_du_projet)
add_subdirectory(lib)

set(CMAKE_CXX_STANDARD 14)

# Ajouter les fichiers à compiler
set(SRCS
    main.cpp
    )

    # On crée un exécutable
add_executable(main ${SRCS})
# Bibliothèques
target_link_libraries(main fichier)

target_compile_features(main PUBLIC cxx_nullptr)
