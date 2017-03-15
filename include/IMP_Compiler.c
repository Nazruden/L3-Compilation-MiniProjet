#include "IMP_Compilator.h"

int line = 0;
int tmpvar = 0;
int tmpjump = 0;

void IMP_compile_to_C3A(struct STree* stree)
{
    if(stree == 0)
        return;
    if(stree->type == 'I')
    {
        tmpvar = tmpvar + 1;
        printf("l%d : Afc : %d : : _TMP%d\n", line, *(int*)stree->val, tmpvar);
        line = line + 1;
        return;
    }
    if(stree->type == 'V')
    {
        tmpvar = tmpvar + 1;
        printf("l%d : Af : _TMP%d : %s :\n", line, tmpvar, (char*)stree->val);
        line = line + 1;
        return;
    }

    // On arrive ici si le noeud n'est pas une feuille
    int ope = *(int*)stree->val;
    int tmpleft;
    int tmpright;
    switch(ope)
    {
        case Pl:
            IMP_compile_to_C3A(stree->lSon);
            tmpleft = tmpvar;
            IMP_compile_to_C3A(stree->rSon);
            tmpright = tmpvar;
            tmpvar = tmpvar + 1;
            printf("l%d : Pl : _TMP%d : _TMP%d : _TMP%d\n", line, tmpleft, tmpright, tmpvar);
            line = line + 1;
        break;
        case Mo:
            IMP_compile_to_C3A(stree->lSon);
            tmpleft = tmpvar;
            IMP_compile_to_C3A(stree->rSon);
            tmpright = tmpvar;
            tmpvar = tmpvar + 1;
            printf("l%d : Mo : _TMP%d : _TMP%d : _TMP%d\n", line, tmpleft, tmpright, tmpvar);
            line = line + 1;
        break;
        case Mu:
            IMP_compile_to_C3A(stree->lSon);
            tmpleft = tmpvar;
            IMP_compile_to_C3A(stree->rSon);
            tmpright = tmpvar;
            tmpvar = tmpvar + 1;
            printf("l%d : Mu : _TMP%d : _TMP%d : _TMP%d\n", line, tmpleft, tmpright, tmpvar);
            line = line + 1;
        break;
        case Af:
            IMP_compile_to_C3A(stree->rSon);
            printf("l%d : Af : %s : _TMP%d :\n", line, (char*)stree->lSon->val, tmpvar);
            line = line + 1;
        break;
        case Sk:
            printf("l%d : Sk :  :  :\n", line);
            line = line + 1;
        break;
        case Se:
            IMP_compile_to_C3A(stree->lSon);
            IMP_compile_to_C3A(stree->rSon);
        break;
        case If:
            tmpjump = tmpjump + 1;
            tmpleft = tmpjump;
            IMP_compile_to_C3A(stree->lSon);
            printf("l%d : Jz : _TMP%d : : IfFalse%d\n", line, tmpvar, tmpleft);
            line = line + 1;
            IMP_compile_to_C3A(stree->rSon->lSon);
            printf("l%d : Jp : : : IfEnd%d\n", line, tmpleft);
            line = line + 1;
            printf("IfFalse%d : Sk : : : \n", tmpleft);
            line = line + 1;
            IMP_compile_to_C3A(stree->rSon->rSon);
            printf("IfEnd%d : Sk : : : \n", tmpleft);
            line = line + 1;
        break;
        case Wh:
            tmpjump = tmpjump + 1;
            tmpleft = tmpjump;
            printf("IfStart%d : Sk : : : \n", tmpleft);
            line = line + 1;
            IMP_compile_to_C3A(stree->lSon);
            printf("l%d : Jz : _TMP%d : : IfEnd%d\n", line, tmpvar, tmpleft);
            line = line + 1;
            IMP_compile_to_C3A(stree->rSon);
            printf("l%d : Jp : : : IfStart%d\n", line, tmpleft);
            line = line + 1;
            printf("IfEnd%d : Sk : : : \n", tmpleft);
            line = line + 1;
        break;
    }
}
