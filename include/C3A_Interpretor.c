//
// Created by nazruden on 3/12/17.
//
#include "C3A_Interpretor.h"

void C3A_Interpretor_execute(Bilquad b, Environment e){
    /* The current quad being executed */
    Quad qCurrent = b.begin;
    do {
        // If there's a "St" instruction
        if(C3A_evalQuadruplet(qCurrent, e, b) == 0){
            return;
        }
        // Looping through next quad
        else {
            qCurrent = qCurrent->next;
        }
    } while(qCurrent != NULL && b.begin != b.end);
}

int C3A_Interpretor_executeQuad(Quad q, Environment e, Bilquad b){

    /* Variables used */
    Quad qNext; // for jumps
    int opRes; // to contain op result

    /* Determining the case depending on the operator of q */
    switch(q->op){
        // Add
        case Pl:
            opRes = Arg_getValue(q->arg1, e) + Arg_getValue(q->arg2, e);
            Environment_setValue(e, q->dest, opRes);
            return 1;
        // Substract
        case Mo:
            opRes = Arg_getValue(q->arg1, e) - Arg_getValue(q->arg2, e);
            Environment_setValue(e, q->dest, opRes);
            return 1;
        // Multiply
        case Mu:
            opRes = Arg_getValue(q->arg1, e) * Arg_getValue(q->arg2, e);
            Environment_setValue(e, q->dest, opRes);
            return 1;
        // Affect
        case Af:
            opRes = Arg_getValue(q->arg2, e);
            Environment_setValue(e, q->dest, opRes);
            return 1;
        case Afc:
            opRes = Arg_getValue(q->arg1, e);
            Environment_setValue(e, q->dest, opRes);
            return 1;
        case Sk:
        case Jp:
            qNext = Bilquad_search(q->dest, b);
            // Checking error : destination not found
            if(qNext != NULL)
            {
                q->next = qNext;
                return 1;
            }
            else {
                printf("Unable to find jump destination '%s'.\n", q->dest);
                exit(1);
            }
        case Jz:
            opRes = Arg_getValue(q->arg1, e);
            if(opRes != 0) {
                return 1;
            }
            else {
                qNext = Bilquad_search(q->dest, b);
                if(qNext != NULL){
                    q->next = qNext;
                    return true;
                }
                else {
                    printf("Unable to find jump destination '%s'.\n", q->dest);
                }
            }
        case St:
            return 0;
        default:
            return 1;

    }
}