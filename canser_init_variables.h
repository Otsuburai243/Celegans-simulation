/*=========================================================================
Initialize the cell’s membrane potential and membrane capacitance.
=========================================================================*/
#ifndef CANSER_INIT_VARIABLES_H
#define CANSER_INIT_VARIABLES_H

#include <stdio.h>
#include <math.h>
#include "canser_parameters.h"

// ----- initialization of variables -----
void init_variables(Variable *arg_v){

    int i;

    for (i = 0; i < N; i++){
        arg_v->v[i] = -60;
        arg_v->Ca[i] = 0.0;
        arg_v->fluorescence[i] = 0.0;
    }

    return;
}

#endif 