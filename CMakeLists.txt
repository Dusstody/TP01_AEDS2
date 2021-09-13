cmake_minimum_required(VERSION 3.20)
project(Trabalho_1 C)

set(CMAKE_C_STANDARD 99)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
find_package( Threads )

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

add_executable(Trabalho_1 IndexInverted.c IndexInverted.h treePatricia.h treePatricia.c WordTad.h WordTad.c main.c arquivoManipulate.c arquivoManipulate.h Dicionario.c Dicionario.h view/janelas/JanelaBusca.c view/janelas/JanelaBusca.h view/janelas/JanelaPrincipal.c view/janelas/JanelaPrincipal.h view/App.c view/App.h view/janelas/JanelaIndiceInvertido.c view/janelas/JanelaIndiceInvertido.h view/janelas/JanelaSelecaoPasta.c view/janelas/JanelaSelecaoPasta.h)

target_link_libraries(Trabalho_1 m ${GTK3_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
