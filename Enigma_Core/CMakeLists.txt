# CMakeList.txt : projet CMake pour Enigma_Console, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("Enigma_Core")

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Enigma_Core "main.cpp" "main.hpp" "Enigma.hpp" "Enigma.cpp")

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
