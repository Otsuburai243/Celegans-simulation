/*=============================================================================================
Output the simulation results (the membrane potential of each cell over time) to a text file
==============================================================================================*/
#ifndef CANSER_OUTPUT_ALL_H
#define CANSER_OUTPUT_ALL_H

#include <stdio.h>
#include <math.h>
#include "canser_parameters.h"

// ----- output the results -----
void output_all(FILE *arg_fp[], double arg_t, Variable arg_v, double Istim, Parameter arg_param){

    int i,j;
    double IstimL,IstimR;
    double Ichem[N],Igap[N];
    IstimL=Istim;
    IstimR=Istim;

    /*if(arg_t>=5.0 && arg_t<=14.0){
        IstimR=0.0;
    }else if(arg_t>=15.0 && arg_t<=25.0){
        IstimL=0.0;
    }*/

    
    fprintf( arg_fp[0], "%f  %.15e %.15e %.15e", arg_t, IstimL, IstimR, Istim/2); //刺激は左右で同じ
    for( i = 0; i < N; i++ ) {
        fprintf( arg_fp[0], "  %.15e",  arg_v.v[i]);
    }
    fprintf( arg_fp[0], "\n");

    for(j = 0; j < N; j++){
        Ichem[j] = 0.0;
        Igap[j]  = 0.0;
    }


    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
	        Ichem[j] = arg_param.Nche[i][j]*Gche*((arg_param.Epola[i][j] - arg_v.v[i]) / (1 + exp(-(arg_v.v[j] - Vshift) / Vrange)));
	        Igap[j]  = arg_param.Ngap[i][j]*Ggap*(arg_v.v[j] - arg_v.v[i]);       
        }

        if(i==AIAL){
            fprintf(arg_fp[1] ,"%.15e %.15e %.15e %.15e %.15e \n",arg_t, Igap[AIAR],Ichem[AIZL],Ichem[ASHL],Ichem[AWCL]);
        }else if(i==AIAR){
            fprintf(arg_fp[2] ,"%.15e %.15e %.15e %.15e %.15e %.15e \n",arg_t, Igap[AIAL],Ichem[AIZR],Ichem[ASHR],Ichem[AWCL],Ichem[AWCR]);
        }else if(i==AIBL){
            fprintf(arg_fp[3] ,"%.15e %.15e %.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIAL],Ichem[AIZL],Ichem[AIZR],Ichem[ASHL],Ichem[AWCL]);
        }else if(i==AIBR){
            fprintf(arg_fp[4] ,"%.15e %.15e %.15e %.15e %.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIAR],Ichem[AIZL],Ichem[AIZR],Ichem[ASHR],Ichem[AWBL],Ichem[AWCL],Ichem[AWCR]);
        }else if(i==AIYL){
            fprintf(arg_fp[5] ,"%.15e %.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIBL],Igap[AIYR],Ichem[AWCL],Ichem[AWCR]);
        }else if(i==AIYR){
            fprintf(arg_fp[6] ,"%.15e %.15e %.15e \n",arg_t, Igap[AIYL],Ichem[AWCR]);
        }else if(i==AIZL){
            fprintf(arg_fp[7] ,"%.15e %.15e %.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIAL],Ichem[AIYL],Igap[AIZR],Igap[ASHL],Ichem[AWBL]);
        }else if(i==AIZR){
            fprintf(arg_fp[8] ,"%.15e %.15e %.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIAR],Ichem[AIYR],Igap[AIZL],Igap[ASHR],Ichem[AWBR]);
        }else if(i==ASHL){
            fprintf(arg_fp[9] ,"%.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIAL],Igap[AIZL],Igap[ASHR]);
        }else if(i==ASHR){
            fprintf(arg_fp[10] ,"%.15e %.15e %.15e %.15e \n",arg_t, Igap[AIZR],Igap[ASHL],Ichem[AWBR]);
        }else if(i==AVAL){
            fprintf(arg_fp[11] ,"%.15e %.15e %.15e %.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIBL],Ichem[AVAR],Igap[AVAR],Ichem[AVBL],Ichem[AVBR],Ichem[AWCL]);
        }else if(i==AVAR){
            fprintf(arg_fp[12] ,"%.15e %.15e %.15e %.15e %.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIBR],Ichem[ASHL],Ichem[ASHR],Ichem[AVAL],Igap[AVAL],Ichem[AVBL],Ichem[AVBR]);
        }else if(i==AVBL){
            fprintf(arg_fp[13] ,"%.15e %.15e %.15e %.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIBL],Ichem[ASHL],Ichem[AVAR],Ichem[AVBR],Igap[AVBR],Ichem[AWBL]);
        }else if(i==AVBR){
            fprintf(arg_fp[14] ,"%.15e %.15e %.15e %.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIBR],Ichem[ASHR],Ichem[AVAL],Ichem[AVBL],Igap[AVBL],Ichem[AWBR]);
        }else if(i==AWBL){
            fprintf(arg_fp[15] ,"%.15e %.15e \n",arg_t, Igap[AWBR]);
        }else if(i==AWBR){
            fprintf(arg_fp[16] ,"%.15e %.15e \n",arg_t, Igap[AWBL]);
        }else if(i==AWCL){
            fprintf(arg_fp[17] ,"%.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIAR],Ichem[AIYL],Ichem[AWCR]);
        }else if(i==AWCR){
            fprintf(arg_fp[18] ,"%.15e %.15e %.15e %.15e %.15e \n",arg_t, Ichem[AIAL],Ichem[AIAR],Ichem[AIYL],Ichem[AWCL]);
        }
    }

    return;

}

#endif