#include "IMP_Interpretor.h"


struct STree* Ast_IMP_init_leaf(int type, void* value)
{
    if(type == 'I')
    {
        int* tmp = malloc(sizeof(int));
        memcpy(tmp, value, sizeof(int));
        value=tmp;
    }
    else if(type == 'V')
    {
        int len = strlen((char*)value) + 1;
        char* tmp = malloc(len*sizeof(char));
        memcpy(tmp, value, len*sizeof(char));
        value = tmp;
    }
    return STree_createLeaf(type, value);
}


int IMP_Interpretor_execute(struct STree* sTr, Environment *e)
{
    // Si AST est nul, on retourne 0 sans l'executer
    if(sTr == 0)
    {
        return 0;
    }
    if(sTr->type == 'V')
    {
            char* key = (char*)sTr->val;
  /*
            if(Env_key_exists(e, key) == false)
            {
                printf("Impossible d'utiliser une variable non déclarée.\n");
                exit(1);
            }
  */
            return Environment_get_value(e, key);
    }
    else if(sTr->type == 'I')
    {
            return *(int*)sTr->val;
    }
    // On arrive ici si le noeud n'est pas une feuille
    int ope = *(int*)sTr->val;
    //printf("Running ope %d\n", ope);
    int tmp, tmp1, tmp2;
    char* key;
    switch(ope)
    {
        case Sk:
            return 1;
        case Se:
            IMP_Interpretor_execute(sTr->lSon, e);
            IMP_Interpretor_execute(sTr->rSon, e);
            return 1;
        case Af:
            key = (char*)sTr->lSon->value;
            tmp = IMP_Interpretor_execute(sTr->rSon, e);
            Environment_set_value(e, key, tmp);
            //printf("%s <- %d\n", key, tmp);
            return 1;
        case If:
            tmp = IMP_Interpretor_execute(sTr->lSon, e);
            if(tmp)
            {
                return IMP_Interpretor_execute(sTr->rSon->lSon, e);
            }
            else
            {
                return IMP_Interpretor_execute(sTr->rSon->rSon, e);
            }
            return 1;
        case Wh:
            tmp = IMP_Interpretor_execute(sTr->lSon, e);
            //printf("While\n");
            while(tmp)
            {
                IMP_Interpretor_execute(sTr->rSon, e);
                tmp = IMP_Interpretor_execute(sTr->lSon, e);
            }
            return 1;
        case Pl:
            tmp1 = IMP_Interpretor_execute(sTr->lSon, e);
            tmp2 = IMP_Interpretor_execute(sTr->rSon, e);
            tmp =  tmp1 + tmp2 ;
            //printf("%d = %d + %d\n", tmp, tmp1, tmp2);
            return tmp;
        case Mo:
            return IMP_Interpretor_execute(sTr->lSon, e) - IMP_Interpretor_execute(sTr->rSon, e);
        case Mu:
            return IMP_Interpretor_execute(sTr->lSon, e) * IMP_Interpretor_execute(sTr->rSon, e);
        default:
            printf("Instruction non reconnue\n");
        break;
    }
}
