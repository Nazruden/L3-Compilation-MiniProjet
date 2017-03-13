//
// Created by nazruden on 3/12/17.
//

#ifndef PROJET_ARGUMENT_H
#define PROJET_ARGUMENT_H

/** INCLUDES **/
#include "Environment.h"

/**
 * Structure Argument pour les quadruplets
 */
typedef struct Argument{
 char type;
 void *value;
} Arg;


Arg* Arg_create(char type, void* value);

int Arg_getValue(struct Argument* arg, Environment e);




#endif //PROJET_ARGUMENT_H
