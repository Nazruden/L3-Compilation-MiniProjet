#ifndef PROJET_C3A_COMPILER_H
#define PROJET_C3A_COMPILER_H

#include "Environment.h"
#include "Quadruplet.h"
#include "./../tmp/c3a.tab.h"


/** FUNCTIONS **/
/**
 * IMP_COMPILE_TO_C3A : Function used to count Y86 instructions needed to compile from C3A code
 * @param list : C3A code
 * @return : nb instructions
 */
int C3A_count_instructions(struct Bilquad* list);

/**
* C3A_INIT_VARIABLES : Function used to init Y86 memory for C3A variables
* @param list : C3A code
* @param memory_end : first free variable's memory emplacement
* @return : Environment
**/
Environment* C3A_init_variables(struct Bilquad* list, int* memory_end);

/**
* C3A_COMPILE_IN_Y86 : Function used to compile a C3A program in Y86 program
* @param list : C3A code
**/
void C3A_compile_in_Y86(struct Bilquad* list);

/**
* C3A_Y86_TRANSLATER : Function used to translate C3A code in Y86 instructions
* @param q : C3A code
* @param memory_begin : beginning of the variable's memory used
* @param vOffset: environment composed by variables associated to its memory location
**/
void C3A_Y86_translater(struct Quad* q, int memory_begin, Environment* vOffset);

#endif //PROJET_C3A_COMPILER_H