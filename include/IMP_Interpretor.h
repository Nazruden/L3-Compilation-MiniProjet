#ifndef PROJET_IMP_INTERPRETOR_H
#define PROJET_IMP_INTERPRETOR_H

/* INCLUDES */

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
 * IMP_INTERPRETOR_LAUNCH : Function used to interpret an IMP program
 * Recursively used because we work on a tree structure
 * @param t : the Abstract Syntax Tree to interpret
 * @param e : the Environment where the tree has to be interpreted
 * @return values needed if a leaf is interpreted
 */
int IMP_Interpretor_launch(STree t, Environment e);


#endif //PROJET_IMP_INTERPRETOR_H
