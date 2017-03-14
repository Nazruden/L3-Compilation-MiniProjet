//
// Created by nazruden on 3/12/17.
//

#ifndef PROJET_ARGUMENT_H
#define PROJET_ARGUMENT_H

/** INCLUDES **/
#include "Environment.h"

/**
 * ARGUMENT : Structure - Used for Quadruplets arguments (variables/integers)
 * @var type : the argument type (variable/integer)
 * @var value : void pointer on value defined (made void to accept both types)
 */
typedef struct Argument{
 char type;
 void *value;
} Arg;

/**
 * ARG_CREATE : Function - Used to create an Argument
 * @param type
 * @param value
 * @return
 */
Arg* Arg_create(char type, void* value);

/**
 * ARG_GETVALUE : Function - Used to retrieve the value of an Argument in an Environment e
 * @param arg : the argument we're working on
 * @param e : the environment where arg value has to be retrieved
 * @return arg value if found
 */
int Arg_getValue(struct Argument* arg, Environment e);




#endif //PROJET_ARGUMENT_H
