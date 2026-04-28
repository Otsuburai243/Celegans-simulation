/*=========================================================================
Define the mathematical model used in the simulation.
Derive the rate of change of the cell’s membrane potential.
dV/dt = (-Iion + Igap + Ichem + Istim)/Cm
Iion  = Rgb*((v - Va) + Vc / (1.0 + exp((v - Va) / Vd)) - Ve)
Igap  = Ngap*Ggap*(v - v)
Ichem = Nche*Gche*((Epola - v) / (1 + exp(-(v - Vshift) / Vrange)))
=========================================================================*/



#ifndef CANSER_FUNCTION_EQUATION_H
#define CANSER_FUNCTION_EQUATION_H

#include <stdio.h>
#include <math.h>
#include "canser_parameters.h"
#include "canser_stimulation.h"


/*----- function of the equation -----*/
Variable f(double arg_t, Variable arg_v, Parameter arg_param){

  int i, j;
    Variable ret;
    double Ichem,Igap,Iion,IstimL,IstimR;

    Ichem = 0.0;
    Igap  = 0.0;
    Iion  = 0.0;
    IstimL=Istim(arg_t);
    IstimR=Istim(arg_t);

    /*if(arg_t>=14 && arg_t<=25){
        IstimL=0.0;
    }else if(arg_t>=5 && arg_t<=14){
        IstimR=0.0;
    }*/

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
	        Ichem += arg_param.Nche[i][j]*Gche*((arg_param.Epola[i][j] - arg_v.v[i]) / (1 + exp(-(arg_v.v[j] - Vshift) / Vrange)));
	        Igap  += arg_param.Ngap[i][j]*Ggap*(arg_v.v[j] - arg_v.v[i]);       
        }

        Iion   = arg_param.Rgb[i]*((arg_v.v[i] - arg_param.Va[i]) + arg_param.Vc[i] / (1.0 + exp((arg_v.v[i] - arg_param.Va[i]) / arg_param.Vd[i])) - arg_param.Ve[i]);

	    if(i==16){
	        ret.v[i] = DT*(-Iion+Ichem+Igap+IstimL)/arg_param.Cm[i];  //AWCL stimulation
        //}else if(i==17){
        //    ret.v[i] = DT*(-Iion+Ichem+Igap+IstimR)/arg_param.Cm[i];  //AWCR stimulation
        }else if(i==8 || i==9){
            ret.v[i] = DT*(-Iion+Ichem+Igap+Istim(arg_t)/2)/arg_param.Cm[i];
        }else{
            ret.v[i] = DT*(-Iion+Ichem+Igap)/arg_param.Cm[i];
        }
    }
   
    return ret; 
}

#endif