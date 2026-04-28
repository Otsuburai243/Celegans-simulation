#ifndef CANSER_WEIGHTED_ADD_H
#define CANSER_WEIGHTED_ADD_H

#include <stdio.h>
#include "canser_parameters.h"


/* ----- addition of variables with weights ----- */
Variable weighted_add(Variable arg_v0, double arg_w, Variable arg_v1){
    int i;
    Variable ret;

    for (i = 0; i < N; i++){
        ret.v[i] = arg_v0.v[i] + arg_w * arg_v1.v[i];
    }

    return ret;
}

#endif