//
// Created by nazruden on 3/12/17.
//
#include "Argument.h"

Arg* Arg_create(char type, void* value){
    /* Checking type of argument to create */
    // If it is an integer
    if(type == 'I'){
        int* tmp = malloc(sizeof(int));
        memcpy(tmp, value, sizeof(int));
        value = tmp;
    }
    // If it is a variable
    else if(type == 'V'){
        size_t len = strlen((char*)value) + 1;
        char* tmp = malloc((strlen((char*)value) + 1) * sizeof(char));
        memcpy(tmp, value, len*sizeof(char));
        value = tmp;
    }
    // Otherwise nothing to create
    else {
        return NULL;
    }
    Arg* newArg = malloc(sizeof(struct Argument));
    newArg->type = type;
    newArg->value = value;
    return newArg;
}

int Arg_getValue(struct Argument* arg, Environment e){
    /* GETTING A VARIABLE */
    if(arg->type == 'V'){
        int value = Environment_getValue(e, (char*)arg->value);
        if(value != NULL) {
            return value;
        }
        else {
            printf("Undefined argument value '%s'.\n", (char*)arg->value);
            exit(1);
        }
    }
    /* GETTING AN INTEGER */
    else if(arg->type == 'I'){
        return *(int*)arg->value;
    }
}