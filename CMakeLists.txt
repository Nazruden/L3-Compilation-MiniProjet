cmake_minimum_required(VERSION 3.6)
project(Projet)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        include/Quadruplet.h include/Quadruplet.c include/C3A_Interpretor.h include/C3A_Interpretor.c include/IMP_Interpretor.h include/IMP_Interpretor.c include/Environment.h include/Environment.c include/Argument.h include/Argument.c include/Syntax_Tree.h include/Syntax_Tree.c)

add_executable(Projet ${SOURCE_FILES})