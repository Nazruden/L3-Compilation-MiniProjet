#include "Environment.h"

/**
 * TODO : Implémentation des méthodes de gestion de la structure d'Environnement
 */

void Environment_initEnv(Environment e){
    e->Id = NULL;
    e->next = NULL;
    e->val = NULL;
}

Environment Environment_allocCell(){
    return ((Environment)malloc(sizeof(struct EnvCell)));
}

void Environment_addValue(Environment *e, char *Id, int value){
    Environment newCell = Environment_allocCell();
    strcpy(newCell->Id,Id);
    newCell->val = value;
    newCell->next = *e;
    *e = newCell;
}

int Environment_getValue(Environment e, char *Id){
    Environment cell = Environment_searchCell(e, Id);
    if(cell != NULL){
        return cell->val;
    }
    else {
        return NULL;
    }
}

Environment Environment_searchCell(Environment e, char *Id){
    if(e != NULL){
        if(strcmp(e->Id,Id)==0){
            return e;
        }
        else
            return Environment_searchCell(e->next, Id);
    }
    else
        return NULL;
}

void Environment_printEnv(Environment e){
    if(e == NULL){
        printf(" -- Fin d'environnement\n");
    }
    else {
        printf("(%s:%d)", e->Id, e->val);
        Environment_printEnv(e->next);
    }
}
