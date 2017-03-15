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

    // Integer case
    if(type == 'I'){
        // Copying val to store it in value void pointer
        int* value = malloc(sizeof(int));
        memcpy(value, val, sizeof(int));
        // Affecting value to leaf
        leaf->val = value;
    }
    // Variable case
    else if(type == 'V'){
        // Getting string length to allocate memory properly for the value void pointer
        size_t valLength = strlen((char*)val);
        // Copying val to store it in value void pointer
        char* value = malloc(valLength*sizeof(char));
        memcpy(value, val, valLength*sizeof(char));
        // Affecting value to leaf
        leaf->val = value;
    }

    /* Affecting other leaf members */
    leaf->type = type;
    // No sons cause it's a leaf
    leaf->rSon = NULL;
    leaf->lSon = NULL;

    // Returning the leaf/vertex created
    return leaf;
}