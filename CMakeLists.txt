cmake_minimum_required(VERSION 3.20)

project(Projeto_de_Algoritimo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(Projeto_de_Algoritimo

        # main
        main.cpp

        # algoritmos
        src/algoritmos/insertion_sort.cpp
        src/algoritmos/bubble_sort.cpp
        src/algoritmos/selection_sort.cpp
        # src/algoritmos/shell_sort.cpp

        # utils
        src/utils/arquivos.cpp
        src/utils/gerador.cpp
        src/utils/menu.cpp
        src/utils/tempo.cpp
        src/utils/executar.cpp
)

# .hpp's
target_include_directories(Projeto_de_Algoritimo PRIVATE
        include
)
