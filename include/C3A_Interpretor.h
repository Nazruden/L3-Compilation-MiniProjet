//
// Created by nazruden on 3/12/17.
//

#ifndef PROJET_C3A_INTERPRETOR_H
#define PROJET_C3A_INTERPRETOR_H

#include "Environment.h"
#include "Quadruplet.h"
#include "../tmp/c3a.tab.h"

/**
 * C3A_INTERPRETOR_SIMULATE : Function used to simulate execution of a C3A app
 * @param b
 * @param e
 */
void C3A_Interpretor_simulate(Bilquad b, Environment e);

/**
 * C3A_EVALQUADRUPLET : Function used to simulate the execution of a C3A Quadruplet
 * @param q
 * @param e
 * @param b
 * @return
 */
int C3A_evalQuadruplet(Quad q, Environment e, Bilquad b);

#endif //PROJET_C3A_INTERPRETOR_H
