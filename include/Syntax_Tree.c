//
// Created by nazruden on 3/14/17.
//
#include "Syntax_Tree.h"

STree STree_create(int type, int op, STree lSon, STree rSon){
    // Allocating the tree/node memory
    STree tree = malloc(sizeof(STree));

    /* Init tree/node members */
    tree->type = type;
    tree->lSon = lSon;
    tree->rSon = rSon;

    /* Convert operator into a void */
    int* voidConv = malloc(sizeof(int));
    *voidConv = op;
    tree->val = voidConv;

    // Returning the tree/node created
    return tree;
}

STree STree_createLeaf(int type, void* val){
    // Allocating the leaf memory
    STree leaf = malloc(sizeof(STree));

    /* Init leaf/vertex members */
    leaf->type = type;
    leaf->rSon = NULL;
    leaf->lSon = NULL;
    leaf->val = val;

    // Returning the leaf/vertex created
    return leaf;
}