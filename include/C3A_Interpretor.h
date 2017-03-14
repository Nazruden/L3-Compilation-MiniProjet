//
// Created by nazruden on 3/12/17.
//

#ifndef PROJET_C3A_INTERPRETOR_H
#define PROJET_C3A_INTERPRETOR_H

#include "Environment.h"
#include "Quadruplet.h"
#include "../tmp/c3a.tab.h"

void C3A_interpret(Bilquad b, Environment e);

int C3A_evalQuadruplet(Quad q, Environment e, Bilquad b);

#endif //PROJET_C3A_INTERPRETOR_H
