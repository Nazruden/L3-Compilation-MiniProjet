//
// Created by nazruden on 3/12/17.
//

#ifndef PROJET_QUADRUPLET_H
#define PROJET_QUADRUPLET_H

#include "Environment.h"
#include "Argument.h"

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
} Bilquad;

/** FUNCTIONS **/
Quad Quad_create(char *etiq, int op, Arg *arg1, Arg *arg2, char* dest);

Bilquad Bilquad_create(Quad q);

Bilquad Bilquad_concat(Bilquad b1, Bilquad b2);

Quad Quad_search(char *etiq, Quad q);

Quad Bilquad_search(char *etiq, Bilquad b);

#endif //PROJET_QUADRUPLET_H
