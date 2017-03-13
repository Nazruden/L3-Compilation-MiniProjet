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

Quad Quad_create(char *etiq, int op, Arg *arg1, Arg *arg2, char* dest);
Bilquad Bilquad_creaate()

#endif //PROJET_QUADRUPLET_H
