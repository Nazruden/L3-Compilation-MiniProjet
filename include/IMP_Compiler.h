#ifndef PROJET_IMP_COMPILER_H
#define PROJET_IMP_COMPILER_H

#include <stdio.h>

#include "Quadruplet.h"
#include "Syntax_Tree.h"

/** FUNCTION **/
/**
 * IMP_COMPILE_TO_C3A : Function used to compile IMP code to C3A code
 * @param prog_imp : IMP code
 */
void IMP_compile_to_C3A(struct STree* prog_imp);

#endif
