#include "IMP_Interpretor.h"

int IMP_Interpretor_launch(STree t, Environment e){
    /** We first need to check the validity of the tree and
     *  determine if we're on a leaf of the tree or not to
     *  define the workflow
     */
    if(t != NULL){
        /** Leaf cases : Integers / Variables **/
        // Integer : returning the value directly
        if(t->type == 'I'){
            return *(int*)t->val;
        }
        // Variable : retrieving value through the Environment
        else if(t->type == 'V'){
            // Obtaining value with its Id
            char *Id = (char*)t->val;
            int tmp = Environment_getValue(e, Id);
            // Value found
            if(tmp != NULL){
                return tmp;
            }
            // Managing not found error
            else {
                printf("Unable to find value of the variable node '%s' in tree.\n", Id);
                exit(1);
            }
        }

        /** Not-leaf cases **/
        /* VARIABLES USED */
        // Getting the node operator
        int op = *(int*)t->val;
        // Id for affectation
        char *Id;
        // Temporary operation members
        int mem1, mem2, mem3;

        /* SWITCH ON OPERATOR */
        switch(op){
            // Affect
            case Af:
                // Getting id to set in Environment e
                Id = (char*)t->lSon->val;
                // Retrieving value of the right son
                mem1 = IMP_Interpretor_launch(t->rSon, e);
                // Setting value in Environment e
                Environment_setValue(e, Id, mem1);

                return 1;
            // Skip
            case Sk:
                // Nothing to do, just returning
                return 1;
            // Separator
            case Se:
                // Just interpreting the two sons of t
                IMP_Interpretor_launch(t->lSon, e);
                IMP_Interpretor_launch(t->rSon, e);

                return 1;
            // If
            case If:
                // Getting result of left son expression and interpreting the right expression in consequence
                if(IMP_Interpretor_launch(t->lSon, e)){
                    return IMP_Interpretor_launch(t->rSon->lSon, e);
                }
                else {
                    return IMP_Interpretor_launch(t->rSon->rSon, e);
                }
            // While
            case Wh:
                mem1 = IMP_Interpretor_launch(t->lSon, e);
                // While the interpreted expression is ok
                while(mem1){
                    IMP_Interpretor_launch(t->rSon, e);
                    // Looping on the same expression
                    mem1 = IMP_Interpretor_launch(t->lSon, e);
                }
                return 1;
            // Add
            case Pl:
                // Getting values and returning result
                return IMP_Interpretor_launch(t->lSon, e) + IMP_Interpretor_launch(t->rSon, e);
            // Substract
            case Mo:
                // Getting values and returning result
                return IMP_Interpretor_launch(t->lSon, e) - IMP_Interpretor_launch(t->rSon, e);
            // Multiply
            case Mu:
                // Getting values and returning result
                return IMP_Interpretor_launch(t->lSon, e) * IMP_Interpretor_launch(t->rSon, e);
            default:
            break;
        }
    }
    else {
        return 0;
    }
}
