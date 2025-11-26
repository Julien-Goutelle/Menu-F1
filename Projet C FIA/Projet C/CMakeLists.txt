cmake_minimum_required(VERSION 4.0)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c
        main.c
        Menus.c
        Menus.h
        Pilote.c
        Pilote.h
        cmake-build-debug/classement.c
        main.h
        grandprix.c
        grandprix.h
        Ecurie.c
        Ecurie.h
        ResultatCourse.c
        ResultatCourse.h)
