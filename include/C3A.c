#include "C3A.h"

void C3A_execute(struct Bilquad* list, Environment* e)
{
    struct Quad* current = list->begin;
    struct Quad* next;
    do
    {
        current = C3A_eval(current, env, list);
        if( current == 0)
            return;
    }
    while(list->begin != list->end && current != 0);

}

struct Quad* C3A_update(struct Bilquad* list, struct Quad* quad, Environment* e)
{
    int tmp;
    struct Quad* next;
    //printf("Eval node %p %s | %p %p\n",quad,  quad->address, list->begin, list->begin->address);
    switch(quad->op)
    {
        case Pl:
            tmp = Value_get(quad->arg1, env) + Value_get(quad->arg2, env);
            //printf("%s <- %d\n", quad->dest, tmp);
            Environment_set_value(env, quad->dest, tmp);
            return quad->qNext;
        case Mo:
            tmp = Value_get(quad->arg1, env) - Value_get(quad->arg2, env);
            //printf("%s <- %d\n", quad->dest, tmp);

            Environment_set_value(env, quad->dest, tmp);
            return quad->qNext;
        case Mu:
            tmp = Value_get(quad->arg1, env) * Value_get(quad->arg2, env);
            //printf("%s <- %d\n", quad->dest, tmp);

            Environment_set_value(env, quad->dest, tmp);
            return quad->qNext;
        case Af:
            tmp = Value_get(quad->arg2, env);
            //printf("%s <- %d\n", quad->dest, tmp);

            Environment_set_value(env, quad->dest, tmp);
            return quad->qNext;
        case Afc:
            tmp = Value_get(quad->arg1, env);
            //printf("%s <- %d\n", quad->dest, tmp);

            Environment_set_value(env, quad->dest, tmp);
            return quad->qNext;
        case Jp:
            //printf("Jp %s\n", quad->address);
            next = Bilquad_search(list, quad->dest);
            //printf("next: %p\n", next);
            if(next == 0)
            {
                printf("L'adresse '%s' est introuvable.\n", quad->dest);
                exit(1);
            }
            return next;
        case Jz:
            tmp = Value_get(quad->arg1, env);
            if(tmp != 0)
            {
                return quad->qNext;
            }
            next = Bilquad_search(list, quad->dest);
            if(next == 0)
            {
                printf("L'adresse '%s' est introuvable.\n", quad->dest);
                exit(1);
            }
            return next;
        case St:
            return 0;
        case Sk:
            return quad->qNext;
        default:
            return 0;
    }
}
