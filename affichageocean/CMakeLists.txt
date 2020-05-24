cmake_minimum_required(VERSION 3.13)

#set(CMAKE_VERBOSE_MAKEFILE on) #Affichage des commandes exécutées à la compilation

project(AffichageOcean3D)

if(WIN32)
	set(DCMAKE_SH="CMAKE_SH-NOTFOUND")  # Trick pour compiler sur mon pc
										# car sh.exe est dans le path à cause de l'installation
										# de git bash
endif()

# Les options de compilation
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall -Werror -std=gnu11")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror -std=gnu++11")

if(WIN32)
	#Définit le répertoire d'installation de glfw pour windows	(sur ma machine, à adapter suivant votre situation)
	#pas besoin d'indiquer où chercher sur linux normalement
	set(glfw3_DIR "C:/Program Files (x86)/GLFW/lib/cmake/glfw3")
endif()


find_package(glfw3 REQUIRED) # Cherche GLFW, échoue si la lib n'a pas pu être localisée sur le pc
		
set(LIBS ${LIBS} glfw)
		
# Les fichiers nécessaires à l'affichage graphique
SET(RENDER src/rendering_glfw/main.cpp src/rendering_glfw/glad.c src/rendering_glfw/Window.cpp src/rendering_glfw/openglObjects.cpp src/rendering_glfw/OceanRenderer.cpp)

# Un fichier d'exemple de classe océan
set(COMMON src/Ocean.cpp)

# Le programme de visualisation 3D
add_executable(Ocean3D ${RENDER} ${COMMON})
target_link_libraries(Ocean3D ${LIBS}) # Les libs à linker



# La commande que j'utilise pour générer les makefiles:
# >cmake .. -G "MinGW Makefiles"
# puis:
# >mingw32-make all
# lancé par eclipse dans le répertoire build ou manuellement

