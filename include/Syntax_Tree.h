#ifndef PROJET_SYNTAX_TREE_H
#define PROJET_SYNTAX_TREE_H
#include <stdlib.h>
#include <string.h>

/**
 * SYNTAX_TREE : Structure used to recreate an Abstract Syntax Tree. Here used to translate IMP instructions and manipulate them through a tree structure
 * @var type : the type of the node (Integer / Variable)
 * @var val : value of the node, made void pointer to accept different types
 * @var lSon : left son of the tree / node
 * @var rSon : right son of the tree / node
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
