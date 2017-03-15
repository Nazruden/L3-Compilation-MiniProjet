//
// Created by nazruden on 3/12/17.
//

#ifndef PROJET_IMP_INTERPRETOR_H
#define PROJET_IMP_INTERPRETOR_H

#include <string.h>
#include <stdio.h>
#include "Environment.h"
#include "Syntax_Tree.h"
#include "../tmp/imp.tab.h"

/**
 * C3A_INTERPRETOR_SIMULATE : Function used to create an "IMP leaf"
 * @param type : node type
 * @param val : node value
 * @return struct STree
 */
struct STree* IMP_Interpretor_init_leaf(int type, void* val);

/**
 * IMP_INTERPRETOR_EXECUTE : Function used to run an IMP program
 * @param sTr : program to run
 * @param e : current environment
 * @return
 */
int IMP_Interpretor_execute(struct STree* sTr, Environment *e);




#endif //PROJET_IMP_INTERPRETOR_H
