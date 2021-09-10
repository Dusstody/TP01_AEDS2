cmake_minimum_required(VERSION 3.20)
project(Trabalho_1 C)

set(CMAKE_C_STANDARD 99)

add_executable(Trabalho_1 IndexInverted.c IndexInverted.h treePatricia.h treePatricia.c WordTad.h WordTad.c main.c arquivoManipulate.c arquivoManipulate.h Dicionario.c Dicionario.h)

target_link_libraries(Trabalho_1 m)
