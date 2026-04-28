/*=========================================================================
Initialize the cell’s membrane potential and membrane capacitance.
=========================================================================*/
#ifndef CANSER_OUTPUT_H
#define CANSER_OUTPUT_H

#include <stdio.h>
#include <math.h>
#include "canser_parameters.h"

// ----- output the results -----
void output(FILE *arg_fp, double arg_t, Variable arg_v, double Istim, Parameter arg_param){

    int i,j;
    double IstimL,IstimR;
    double Ichem[N],Igap[N];
    IstimL=Istim;
    IstimR=Istim;

    /*if(arg_t>=5 && arg_t<=14){
        IstimR=0.0;
    }else if(arg_t>=15 && arg_t<=25){
        IstimL=0.0;
    }*/

    
    fprintf( arg_fp, "%f  %.15e %.15e %.15e %.15e %.15e %.15e %.15e", arg_t, arg_v.v[AVAL], arg_v.v[AVAR], arg_v.v[AVBL], arg_v.v[AVBR],IstimL,IstimR,Istim/2);
    fprintf( arg_fp, "\n");
    

    return;

}

#endif