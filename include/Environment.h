//
// Created by nazruden on 3/12/17.
//

#ifndef PROJET_ENVIRONMENT_H
#define PROJET_ENVIRONMENT_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * TODO : Header des méthodes de gestion de l'Environnement (structure)
 */

/**
 * EnvCell struct with "Environment" alias
 */
typedef struct EnvCell{
    char *Id;
    int val;
    struct EnvCell *next;
} *Environment;

/** FUNCTIONS **/
/**
 * Init function
 * @param e : the Environment to init.
 */
void Env_initEnv(Environment e);

/**
 * Add value function
 * @param e : the Environment where the cell has to be added
 * @param Id : the Id of the cell
 * @param value : the value of the cell
 */
void Env_addValue(Environment *e, char *Id, int value);

/**
 * Environment value getter
 * @param e : the Environment concerned
 * @param Id : the Id of the value to retrieve
 * @return the value attached to specified Id if it exists in e
 */
int Env_getValue(Environment e, char *Id);

/**
 * Research function
 * @param e : the Environment where we will search the cell.
 * @param Id : the Id of the cell we're looking for.
 * @return the cell with specified id if it exists.
 */
Environment Env_searchCell(Environment e, char *Id);

/**
 * Print function
 * @param e : the Environment to print
 */
void Env_printEnv(Environment e);

/** CONSTANTS **/
#define MAXID_LENGTH 16


#endif //PROJET_ENVIRONMENT_H
