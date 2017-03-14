//
// Created by nazruden on 3/12/17.
//
#include "Quadruplet.h"

Quad Quad_create(char *etiq, int op, Arg *arg1, Arg *arg2, char* dest){
    Quad qd;
    qd = malloc(sizeof(struct Quadruplet));
    qd->etiq = etiq;
    qd->op = op;
    qd->arg1 = arg1;
    qd->arg2 = arg2;
    qd->dest = dest;
    qd->next = NULL;
    return qd;
}

Bilquad Bilquad_create(Quad q){
    Bilquad bq = malloc(sizeof Bilquad);
    bq->begin = q; bq->end = q;
    return bq;
}

Bilquad Bilquad_concat(Bilquad b1, Bilquad b2){
    Bilquad b = malloc(sizeof(Bilquad));
    if(b1->end != NULL){
        if(b2->begin != NULL){
            b1->end->next = b2->begin;
            b->begin = b1->begin;
            b->end = b2->end;
            free(b1);
            free(b2);
            return b;
        }
        else {
            return b1;
        }
    }
    else {
        return b2;
    }
}

Quad Quad_search(char* etiq, Quad q){
    Quad qCurrent = q;
    if(qCurrent != NULL){
        if(strcmp(qCurrent->etiq, etiq)==0){
            return qCurrent;
        }
        else {
            return Quad_search(etiq, qCurrent->next);
        }
    }
    else {
        return NULL;
    }
}

Quad Bilquad_search(char* etiq, Bilquad b){
    return Quad_search(etiq, b->begin);
}

