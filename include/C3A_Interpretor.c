#include "C3A_Interpretor.h"

void C3A_Interpretor_simulate(Bilquad b, Environment e){
    /* The current quad being executed */
    Quad qCurrent = b->begin;
    while(qCurrent != NULL && b->begin != b->end){
        qCurrent = C3A_Interpretor_executeQuad(qCurrent, e, b);
    }
}

Quad C3A_Interpretor_executeQuad(Quad q, Environment e, Bilquad b){

    /* Variables used */
    Quad qNext; // for jumps
    int opRes; // to contain op result

    /* Determining the case depending on the operator of q */
    switch(q->op){
        // Add
        case Pl:
            opRes = Arg_getValue(q->arg1, e) + Arg_getValue(q->arg2, e);
            Environment_setValue(e, q->dest, opRes);
            return q->qNext;
        // Substract
        case Mo:
            opRes = Arg_getValue(q->arg1, e) - Arg_getValue(q->arg2, e);
            Environment_setValue(e, q->dest, opRes);
            return q->qNext;
        // Multiply
        case Mu:
            opRes = Arg_getValue(q->arg1, e) * Arg_getValue(q->arg2, e);
            Environment_setValue(e, q->dest, opRes);
            return q->qNext;
        // Affect
        case Af:
            opRes = Arg_getValue(q->arg2, e);
            Environment_setValue(e, q->dest, opRes);
            return q->qNext;
        case Afc:
            opRes = Arg_getValue(q->arg1, e);
            Environment_setValue(e, q->dest, opRes);
            return q->qNext;
        case Sk:
            return q->qNext;
        case Jp:
            qNext = Bilquad_search(q->dest, b);
            // Checking error : destination not found
            if(qNext != NULL)
            {
                return qNext;
            }
            else {
                printf("Unable to find jump destination '%s'.\n", q->dest);
                exit(1);
            }
        case Jz:
            opRes = Arg_getValue(q->arg1, e);
            // Arg1 must be empty for Jz to make a jump
            if(opRes != 0) {
                return q->qNext;
            }
            else {
                qNext = Bilquad_search(q->dest, b);
                // Checking if the specified quad was found
                if(qNext != NULL){
                    return qNext;
                }
                // If not, exiting with error
                else {
                    printf("Unable to find jump destination '%s'.\n", q->dest);
                }
            }
        case St:
            return NULL;
        default:
            return NULL;
    }
}