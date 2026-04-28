/*=========================================================================
A fourth-order Runge–Kutta method with four stages was used for the
numerical calculations.
=========================================================================*/
#ifndef CANSER_RUNGE_KUTTA_H
#define CANSER_RUNGE_KUTTA_H


#include <stdio.h>
#include <math.h>
#include "canser_parameters.h"
#include "canser_function_equation.h"
#include "canser_weighted_add.h"

Variable Runge_Kutta(double arg_t, Variable arg_v, Parameter arg_param)
{
    Variable v_divp, vk[4]; // variables of Runge-Kutta method
    Variable ret;

    vk[0] = f(arg_t, arg_v, arg_param); // 1st stage

    v_divp = weighted_add(arg_v, 0.5, vk[0]);                // dividing point 1 of v
    vk[1] = f(arg_t + 0.5 * DT, v_divp, arg_param);          // 2nd stage

    v_divp = weighted_add(arg_v, 0.5, vk[1]);                // dividing point 2 of v
    vk[2] = f(arg_t + 0.5 * DT, v_divp, arg_param);          // 3rd stage

    v_divp = weighted_add(arg_v, 1.0, vk[2]);                // dividing point 3 of v
    vk[3] = f(arg_t + DT, v_divp, arg_param);                // 4th stage

    ret = weighted_add(arg_v, 1.0 / 6.0, vk[0]);
    ret = weighted_add(  ret, 1.0 / 3.0, vk[1]);
    ret = weighted_add(  ret, 1.0 / 3.0, vk[2]);
    ret = weighted_add(  ret, 1.0 / 6.0, vk[3]);

    return ret;
}

#endif