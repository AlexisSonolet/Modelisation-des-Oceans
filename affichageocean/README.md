# AffichageOcean

Ce projet contient quelques fichiers permettant d'afficher votre modélisation d'océan
avec glfw et opengl. Vous pouvez vous inspirer du script cmake et l'adapter à votre cas.
Le projet devrait compiler sans problème sur windows/linux et même mac (no warranty) une fois glfw installée.

## Installation de glfw:

Allez faire un tour ici:
https://www.glfw.org/docs/3.3/compile_guide.html

## Compilation du projet

Comme d'habitude:
>cd build
>cmake ..
>make

A modifier suivant votre installation personnelle, votre IDE, etc...

## Lancement de l'exécutable

L'exécutable nécessite 2 choses:

La librairie dynamique:

	-glfw3.dll sur windows, placée dans le même répertoire que l'exécutable (ici: build/)
	-glfw3.so ou autre sur linux, placée automatiquement à l'installation de la lib dans un répertoire connu du système (pas besoin de s'en préoccuper donc)
	-aucune idée de comment ça marche sur mac

Les shaders:

	-Ils sont dans le répertoire "shaders/"
	L'exécutable ne pourra les localiser que si le répertoire "shaders/" est dans votre répertoire courant.
	En clair:
	
	Si vous êtes dans le répertoire du projet avec votre console vous aurez:
	>ls
	>CMakeLists.txt  README.md  build  shaders  src
	>build\Ocean3D.exe
	Localisera bien les shaders à l'exécution
	
	
## Remarques:

Le programme nécessite opengl 3.3 (peut-être moins)
Si votre PC est une antiquité (un dinosaure quoi), il est possible qu'il ne supporte pas cette version.

Quelques dépendances externes ont été incorporées pour faciliter l'installation:

-glad: permet de charger les fonctions opengl

-linmath: fournit quelques classes utiles comme vec3, vec4, mat4, etc...
