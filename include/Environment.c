//
// Created by nazruden on 3/12/17.
//
#include "Environment.h"

/**
 * TODO : Implémentation des méthodes de gestion de la structure d'Environnement
 */

void Env_initEnv(Environment e){
    e->Id = NULL;
    e->next = NULL;
    e->val = NULL;
}

Environment Env_allocCell(){
    return ((Environment)malloc(sizeof(struct EnvCell)));
}

void Env_addValue(Environment *e, char *Id, int value){
    Environment newCell = Env_allocCell();
    strcpy(newCell->Id,Id);
    newCell->val = value;
    newCell->next = *e;
    *e = newCell;
}

int Env_getValue(Environment e, char *Id){
    return Env_searchCell(e, Id)->val;
}

Environment Env_searchCell(Environment e, char *Id){
    if(e != NULL){
        if(strcmp(e->Id,Id)==0){
            return e;
        }
        else
            return Env_searchCell(e->next,Id);
    }
    else
        return NULL;
}

void Env_printEnv(Environment e){
    if(e == NULL){
        printf(" -- Fin d'environnement\n");
    }
    else {
        printf("(%s:%d)", e->Id, e->val);
        Env_printEnv(e->next);
    }
}
