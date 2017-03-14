//
// Created by nazruden on 3/12/17.
//

#ifndef PROJET_QUADRUPLET_H
#define PROJET_QUADRUPLET_H

#include "Environment.h"
#include "Argument.h"

/**
 * QUADRUPLET : Structure used to define instructions like
 */
typedef struct Quadruplet{
    char *etiq;
    int op;
    Arg *arg1;
    Arg *arg2;
    char *dest;
    struct Quadruplet *next;
} *Quad;

typedef struct {
    Quad begin;
    Quad end;
} *Bilquad;

/** FUNCTIONS **/
/**
 * QUAD_CREATE : Function used to create a Quadruplet
 * @param etiq
 * @param op
 * @param arg1
 * @param arg2
 * @param dest
 * @return
 */
Quad Quad_create(char *etiq, int op, Arg *arg1, Arg *arg2, char* dest);

/**
 * BILQUAD_CREATE : Function used to create a Bilquad
 * @param q
 * @return
 */
Bilquad Bilquad_create(Quad q);

Bilquad Bilquad_concat(Bilquad b1, Bilquad b2);

Quad Quad_search(char *etiq, Quad q);

Quad Bilquad_search(char *etiq, Bilquad b);

#endif //PROJET_QUADRUPLET_H
