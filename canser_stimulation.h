/*===========================================================================
In the main function, the simulation conditions are configured, including 
the simulation time, the criteria for outputting results, and checks for 
duplicate random numbers.
===========================================================================*/
#ifndef CANSER_STIMULATION_H
#define CANSER_STIMULATION_H

#include <stdio.h>
#include <math.h>
#include "canser_parameters.h"


/*-----stimulation-----*/
double Istim(double arg_t){
    double Istim, t;
    t=0;
    Istim=0;
    if(arg_t>=5.0 && arg_t<=14.0){
        t=arg_t-5.0;
        Istim = R_stim*(exp(-t / t1_stim) - exp(-t / t2_stim)) / (pow(t2_stim / t1_stim, t2_stim / (t1_stim - t2_stim)) - pow(t2_stim / t1_stim, t1_stim / (t1_stim - t2_stim)));
    /*}else if(arg_t>=15.0 && arg_t<=25.0){
        t=arg_t-15.0;  
        Istim = R_stim*(exp(-t / t1_stim) - exp(-t / t2_stim)) / (pow(t2_stim / t1_stim, t2_stim / (t1_stim - t2_stim)) - pow(t2_stim / t1_stim, t1_stim / (t1_stim - t2_stim)));
    }else if(arg_t>=30.0 && arg_t<=39.0){
        t=arg_t-30.0;  
        Istim = -R_stim*(exp(-t / t1_stim) - exp(-t / t2_stim)) / (pow(t2_stim / t1_stim, t2_stim / (t1_stim - t2_stim)) - pow(t2_stim / t1_stim, t1_stim / (t1_stim - t2_stim)));
    }else if(arg_t>=40.0 && arg_t<=49.0){
        t=arg_t-40.0;  
        Istim = R_stim/2*(exp(-t / t1_stim) - exp(-t / t2_stim)) / (pow(t2_stim / t1_stim, t2_stim / (t1_stim - t2_stim)) - pow(t2_stim / t1_stim, t1_stim / (t1_stim - t2_stim)));
    */
    }else{
    Istim = 0.0;
  }
    return Istim;
}


#endif

