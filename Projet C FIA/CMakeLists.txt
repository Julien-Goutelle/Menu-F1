cmake_minimum_required(VERSION 4.0)
project(Projet_C_VF C)

set(CMAKE_C_STANDARD 11)

include_directories("Projet C")

add_executable(Projet_C_VF
        "Projet C/cmake-build-debug/classement.c"
        "Projet C/Ecurie.c"
        "Projet C/Ecurie.h"
        "Projet C/grandprix.c"
        "Projet C/grandprix.h"
        "Projet C/main.c"
        "Projet C/main.h"
        "Projet C/Menus.c"
        "Projet C/Menus.h"
        "Projet C/Pilote.c"
        "Projet C/Pilote.h"
        "Projet C/ResultatCourse.c"
        "Projet C/ResultatCourse.h")
