#ifndef PROJET_C3A_COMPILER_H
#define PROJET_C3A_COMPILER_H

#include "Environment.h"
#include "Quadruplet.h"
#include "./../tmp/c3a.tab.h"



/** FUNCTIONS **/

/**
 * C3A_EVAL : Function used to update @e resulting from execution of the C3A command @list
 * @param list : C3A code
 * @param quad : C3A command
 * @param e : current environment
*/
struct Quad* C3A_eval(struct Bilquad* list, struct Quad* quad, Environment* e);

/**
 * C3A_EXECUTE : Function used to run and execute C3A program
 * @param list : C3A code
 * @param e : environment variables
*/
void C3A_execute(struct Bilquad* list, Environment* e);

#endif
