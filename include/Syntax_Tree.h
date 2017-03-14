//
// Created by nazruden on 3/14/17.
//

#ifndef PROJET_SYNTAX_TREE_H
#define PROJET_SYNTAX_TREE_H
#include <stdlib.h>

/**
 * TODO
 */
typedef struct Syntax_Tree {
    int type;
    void *val;
    struct Syntax_Tree *lSon;
    struct Syntax_Tree *rSon;
} *STree;

/**
 * STREE_CREATE : Function used to create a typical tree/node without value
 * @param type
 * @param op
 * @param lSon
 * @param rSon
 * @return
 */
STree STree_create(int type, int op, STree lSon, STree rSon);

/**
 * STREE_CREATELEAF : Function used to create a valuated node (leaf/vertex)
 * @param type
 * @param val
 * @return
 */
STree STree_createLeaf(int type, void* val);

#endif //PROJET_SYNTAX_TREE_H
