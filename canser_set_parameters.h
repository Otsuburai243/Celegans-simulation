/*===========================================================================
Initialize each simulation variable. Specify the connectivity between cells. 
Additionally, assume the sign for some connections based on their properties.
===========================================================================*/
#ifndef CANSER_SET_PARAMETERS_H
#define CANSER_SET_PARAMETERS_H

#include <stdio.h>
#include "canser_parameters.h"


// ----- set the parameters -----
void set_parameters(Parameter *arg_param, int arg_bit[ ]){

    int i, j;

    for (i = 0; i < N; i++){
        arg_param->Cm[i] = 0.01;      //mF
        arg_param->FFmax[16] = 6.0;
        arg_param->FFmax[17] = 6.0;

        if(i==AVAL || i==AVAR || i==AVBL || i==AVBR){
            arg_param->Rgb[i] = 0.4;
            arg_param-> Va[i] = -30.5;
            arg_param-> Vc[i] = 2.0;
            arg_param-> Vd[i] = 5.0;
            arg_param-> Ve[i] = 1.0;
        }else{
            arg_param->Rgb[i] = 1.9;
            arg_param->Va[i] = -25.0;
            arg_param->Vc[i] = 112.4;
            arg_param->Vd[i] = 25.0;
            arg_param->Ve[i] = 56.2;
        }

        for(j = 0; j<N; j++){
            arg_param-> Nche[i][j] = 0.0;
            arg_param-> Ngap[i][j] = 0.0;
            arg_param->Epola[i][j] = E_unknown;
        }
    }

/*
    arg_param->Epola[AIAL][AIZL] = E_inhibitory;
    arg_param->Epola[AIAL][ASHL] = E_inhibitory;
    arg_param->Epola[AIAR][AIZR] = E_inhibitory;
    arg_param->Epola[AIAR][ASHR] = E_inhibitory;
    arg_param->Epola[AIBL][AIAL] = E_inhibitory;
    arg_param->Epola[AIBR][AIAR] = E_inhibitory;
    arg_param->Epola[AIZL][AIAL] = E_inhibitory;
    arg_param->Epola[AIZR][AIAR] = E_inhibitory;

*/
/*    [to][from] ----->[i][j]    */
    //arg_param->Epola[AIZL][AIAL] = E_excitory;
    //arg_param->Epola[AIZR][AIAR] = E_excitory;
    arg_param->Epola[ASHL][AIAL] = E_excitory;
    arg_param->Epola[AVAR][AVAL] = E_excitory;
    arg_param->Epola[AVAL][AVAR] = E_excitory;
    arg_param->Epola[AVBR][AVBL] = E_excitory;
    arg_param->Epola[AVBL][AVBR] = E_excitory;
    arg_param->Epola[AVBR][AVAL] = E_inhibitory;
    arg_param->Epola[AVBL][AVAR] = E_inhibitory;
    arg_param->Epola[AVAL][AVBL] = E_inhibitory;
    arg_param->Epola[AVAR][AVBL] = E_inhibitory;
    arg_param->Epola[AVAL][AVBR] = E_inhibitory;
    arg_param->Epola[AVAR][AVBR] = E_inhibitory;
    //arg_param->Epola[AIBR][AWBL] = E_excitory;
    //arg_param->Epola[ASHR][AWBR] = E_excitory;
    

/*   [to][from] ---> [i][j]   */
/*-----AIAL-----*/
    arg_param->Ngap[AIAL][AIAR] = 1.0;
    arg_param->Nche[AIAL][AIZL] = 3.0;
    arg_param->Nche[AIAL][ASHL] = 7.0;
    arg_param->Nche[AIAL][AWCL] = 2.0;
/*-----AIAIR----*/
    arg_param->Ngap[AIAR][AIAL] = 1.0;
    arg_param->Nche[AIAR][AIZR] = 1.0;
    arg_param->Nche[AIAR][ASHR] = 10.0;
    arg_param->Nche[AIAR][AWCL] = 4.0;
    arg_param->Nche[AIAR][AWCR] = 2.0;
/*-----AIBL-----*/
    arg_param->Nche[AIBL][AIAL] = 10.0;
    arg_param->Nche[AIBL][AIZL] = 4.0;
    arg_param->Nche[AIBL][AIZR] = 8.0;
    arg_param->Nche[AIBL][ASHL] = 5.0;
    arg_param->Nche[AIBL][AWCL] = 2.0;
/*-----AIBR-----*/
    arg_param->Nche[AIBR][AIAR] = 14.0;
    arg_param->Nche[AIBR][AIZL] = 8.0;
    arg_param->Nche[AIBR][AIZR] = 1.0;
    arg_param->Nche[AIBR][ASHR] = 3.0;
    //arg_param->Nche[AIBR][AWBL] = 1.0;
    arg_param->Nche[AIBR][AWCL] = 1.0;
    arg_param->Nche[AIBR][AWCR] = 4.0;
/*-----AIYL-----*/
    arg_param->Nche[AIYL][AIBL] = 1.0;
    arg_param->Ngap[AIYL][AIYR] = 1.0;
    arg_param->Nche[AIYL][AWCL] = 10.0;
    arg_param->Nche[AIYL][AWCR] = 4.0;
/*-----AIYR-----*/
    arg_param->Ngap[AIYR][AIYL] = 1.0;
    arg_param->Nche[AIYR][AWCR] = 9.0;
/*-----AIZL-----*/
    arg_param->Nche[AIZL][AIAL] = 1.0;
    arg_param->Nche[AIZL][AIYL] = 13.0;
    arg_param->Ngap[AIZL][AIZR] = 2.0;
    arg_param->Ngap[AIZL][ASHL] = 1.0;
    //arg_param->Nche[AIZL][AWBL] = 9.0;
/*-----AIZR-----*/
    arg_param->Nche[AIZR][AIAR] = 1.0;
    arg_param->Nche[AIZR][AIYR] = 8.0;
    arg_param->Ngap[AIZR][AIZL] = 2.0;
    arg_param->Ngap[AIZR][ASHR] = 1.0;
    //arg_param->Nche[AIZR][AWBR] = 4.0;
/*-----ASHL-----*/
    arg_param->Nche[ASHL][AIAL] = 1.0;
    arg_param->Ngap[ASHL][AIZL] = 1.0;
    arg_param->Ngap[ASHL][ASHR] = 1.0;
/*-----ASHR-----*/
    arg_param->Ngap[ASHR][AIZR] = 1.0;
    arg_param->Ngap[ASHR][ASHL] = 1.0;
    //arg_param->Nche[ASHR][AWBR] = 2.0;
/*-----AVAL-----*/
    arg_param->Nche[AVAL][AIBL] = 2.0;
    arg_param->Nche[AVAL][AVAR] = 1.0;
    arg_param->Ngap[AVAL][AVAR] = 5.0;
    arg_param->Nche[AVAL][AVBL] = 7.0;
    arg_param->Nche[AVAL][AVBR] = 6.0;
    arg_param->Nche[AVAL][AWCL] = 1.0;
/*-----AVAR-----*/
    arg_param->Nche[AVAR][AIBR] = 1.0;
    arg_param->Nche[AVAR][ASHL] = 2.0;
    arg_param->Nche[AVAR][ASHR] = 5.0;
    arg_param->Nche[AVAR][AVAL] = 2.0;
    arg_param->Ngap[AVAR][AVAL] = 5.0;
    arg_param->Nche[AVAR][AVBL] = 7.0;
    arg_param->Nche[AVAR][AVBR] = 7.0;
/*-----AVBL-----*/
    arg_param->Nche[AVBL][AIBL] = 5.0;
    arg_param->Nche[AVBL][AVAR] = 1.0;
    arg_param->Nche[AVBL][AVBR] = 1.0;
    arg_param->Ngap[AVBL][AVBR] = 3.0;
    //arg_param->Nche[AVBL][AWBL] = 1.0;
/*-----AVBR-----*/
    arg_param->Nche[AVBR][AIBR] = 3.0;
    arg_param->Nche[AVBR][ASHL] = 6.0;
    arg_param->Nche[AVBR][ASHR] = 3.0;
    arg_param->Nche[AVBR][AVAL] = 1.0;
    arg_param->Nche[AVBR][AVBL] = 1.0;
    arg_param->Ngap[AVBR][AVBL] = 3.0;
    //arg_param->Nche[AVBR][AWBR] = 2.0;
/*-----AWBL-----*/
    //arg_param->Ngap[AWBL][AWBR] = 1.0;
/*-----AWBR-----*/
    //arg_param->Ngap[AWBR][AWBL] = 1.0;
/*-----AWCL-----*/
    arg_param->Nche[AWCL][AIAR] = 1.0;
    arg_param->Nche[AWCL][AIYL] = 1.0;
    arg_param->Nche[AWCL][AWCR] = 5.0;
/*-----AWCR-----*/
    arg_param->Nche[AWCR][AIAL] = 1.0;
    arg_param->Nche[AWCR][AIAR] = 3.0;
    arg_param->Nche[AWCR][AIYL] = 1.0;
    arg_param->Nche[AWCR][AWCL] = 1.0;


/*---------------------------------------------------------------------------------------------------*/


    //Exploration of polarity
    //[to][from]--->[i][j]
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if((arg_param->Nche[i][j]!=0 || arg_param->Ngap[i][j]!=0) && arg_param->Epola[i][j]==E_unknown){
                if(i==AIAL && j==AIZL){//0
                    if(arg_bit[0] == 0){
                        arg_param->Epola[AIAL][AIZL] = E_excitory;
                        arg_param->Epola[AIAR][AIZR] = E_excitory;
                    }else if(arg_bit[0] == 1){
                        arg_param->Epola[AIAL][AIZL] = E_inhibitory;
                        arg_param->Epola[AIAR][AIZR] = E_inhibitory;
                    }
                }else if(i==AIAL && j==ASHL){//1
                    if(arg_bit[1] == 0){
                        arg_param->Epola[AIAL][ASHL] = E_excitory;
                        arg_param->Epola[AIAR][ASHR] = E_excitory;
                    }else if(arg_bit[1] == 1){
                        arg_param->Epola[AIAL][ASHL] = E_inhibitory;
                        arg_param->Epola[AIAR][ASHR] = E_inhibitory;
                    }
                }else if(i==AIAL && j==AWCL){//2
                    if(arg_bit[2] == 0){
                        arg_param->Epola[AIAL][AWCL] = E_excitory;
                        arg_param->Epola[AIAR][AWCL] = E_excitory;
                        arg_param->Epola[AIAR][AWCR] = E_excitory;
                    }else if(arg_bit[2] == 1){
                        arg_param->Epola[AIAL][AWCL] = E_inhibitory;
                        arg_param->Epola[AIAR][AWCL] = E_inhibitory;
                        arg_param->Epola[AIAR][AWCR] = E_inhibitory;
                    }   
                }else if(i==AIBL && j==AIAL){//3
                    if(arg_bit[3] == 0){
                        arg_param->Epola[AIBL][AIAL] = E_excitory;
                        arg_param->Epola[AIBR][AIAR] = E_excitory;
                    }else if(arg_bit[3] == 1){
                        arg_param->Epola[AIBL][AIAL] = E_inhibitory;
                        arg_param->Epola[AIBR][AIAR] = E_inhibitory;
                    }
                }else if(i==AIBL && j==AIZL){//4
                    if(arg_bit[4] == 0){
                        arg_param->Epola[AIBL][AIZL] = E_excitory;
                        arg_param->Epola[AIBR][AIZL] = E_excitory;
                        arg_param->Epola[AIBL][AIZR] = E_excitory;
                        arg_param->Epola[AIBR][AIZR] = E_excitory;
                    }else if(arg_bit[4] == 1){
                        arg_param->Epola[AIBL][AIZL] = E_inhibitory;
                        arg_param->Epola[AIBR][AIZL] = E_inhibitory;
                        arg_param->Epola[AIBL][AIZR] = E_inhibitory;
                        arg_param->Epola[AIBR][AIZR] = E_inhibitory;
                    }
                }else if(i==AIBL && j==AWCL){//5
                    if(arg_bit[5] == 0){
                        arg_param->Epola[AIBL][AWCL] = E_excitory;
                        arg_param->Epola[AIBR][AWCL] = E_excitory;
                        arg_param->Epola[AIBR][AWCR] = E_excitory;
                    }else if(arg_bit[6] == 1){
                        arg_param->Epola[AIBL][AWCL] = E_inhibitory;
                        arg_param->Epola[AIBR][AWCL] = E_inhibitory;
                        arg_param->Epola[AIBR][AWCR] = E_inhibitory;
                    }
                }else if(i==AIBR && j==ASHL){//6
                    if(arg_bit[7] == 0){
                        arg_param->Epola[AIBR][ASHL] = E_excitory;
                        arg_param->Epola[AIBR][ASHR] = E_excitory;
                    }else if(arg_bit[7] == 1){
                        arg_param->Epola[AIBR][ASHL] = E_inhibitory;
                        arg_param->Epola[AIBR][ASHR] = E_inhibitory;
                    }
                }else if(i==AIYL && j==AIBL){//7
                    if(arg_bit[7] == 0){
                        arg_param->Epola[AIYL][AIBL] = E_excitory;
                    }else if(arg_bit[7] == 1){
                        arg_param->Epola[AIYL][AIBL] = E_inhibitory;
                    }
                }else if(i==AIYL && j==AWCL){//8
                    if(arg_bit[8] == 0){
                        arg_param->Epola[AIYL][AWCL] = E_excitory;
                        arg_param->Epola[AIYL][AWCR] = E_excitory;
                        arg_param->Epola[AIYR][AWCR] = E_excitory;
                    }else if(arg_bit[8] == 1){
                        arg_param->Epola[AIYL][AWCL] = E_inhibitory;
                        arg_param->Epola[AIYL][AWCR] = E_inhibitory;
                        arg_param->Epola[AIYR][AWCR] = E_inhibitory;
                    }
                }else if(i==AIZL && j==AIAL){//9
                    if(arg_bit[9] == 0){
                        arg_param->Epola[AIZL][AIAL] = E_excitory;
                        arg_param->Epola[AIZR][AIAR] = E_excitory;
                    }else if(arg_bit[9] == 1){
                        arg_param->Epola[AIZL][AIAL] = E_inhibitory;
                        arg_param->Epola[AIZR][AIAR] = E_inhibitory;
                    }
                }else if(i==AIZL && j==AIYL){//10
                    if(arg_bit[10] == 0){
                        arg_param->Epola[AIZL][AIYL] = E_excitory;
                        arg_param->Epola[AIZR][AIYR] = E_excitory;
                    }else if(arg_bit[10] == 1){
                        arg_param->Epola[AIZL][AIYL] = E_inhibitory;
                        arg_param->Epola[AIZR][AIYR] = E_inhibitory;
                    }
                /*}else if(i==AIZL && j==AWBL){//14
                    if(arg_bit[14] == 0){
                        arg_param->Epola[AIZL][AWBL] = E_excitory;
                        arg_param->Epola[AIZR][AWBR] = E_excitory;
                    }else if(arg_bit[14] == 1){
                        arg_param->Epola[AIZL][AWBL] = E_inhibitory;
                        arg_param->Epola[AIZR][AWBR] = E_inhibitory;
                    }*/
                }else if(i==ASHL && j==AIAL){//11
                    if(arg_bit[11] == 0){
                        arg_param->Epola[ASHL][AIAL] = E_excitory;
                    }else if(arg_bit[11] == 1){
                        arg_param->Epola[ASHL][AIAL] = E_inhibitory;
                    }
                }else if(i==AVAL && j==AIBL){//12
                    if(arg_bit[12] == 0){
                        arg_param->Epola[AVAL][AIBL] = E_excitory;
                        arg_param->Epola[AVAR][AIBR] = E_excitory;
                    }else if(arg_bit[12] == 1){
                        arg_param->Epola[AVAL][AIBL] = E_inhibitory;
                        arg_param->Epola[AVAR][AIBR] = E_inhibitory;
                    }
                }else if(i==AVAL && j==AWCL){//13
                    if(arg_bit[13] == 0){
                        arg_param->Epola[AVAL][AWCL] = E_excitory;
                    }else if(arg_bit[13] == 1){
                        arg_param->Epola[AVAL][AWCL] = E_inhibitory;
                    }
                }else if(i==AVAR && j==ASHL){//14
                    if(arg_bit[14] == 0){
                        arg_param->Epola[AVAL][ASHL] = E_excitory;
                        arg_param->Epola[AVAR][ASHR] = E_excitory;
                    }else if(arg_bit[14] == 1){
                        arg_param->Epola[AVAL][ASHL] = E_inhibitory;
                        arg_param->Epola[AVAR][ASHR] = E_inhibitory;
                    }
                }else if(i==AVBL && j==AIBL){//15
                    if(arg_bit[15] == 0){
                        arg_param->Epola[AVBL][AIBL] = E_excitory;
                        arg_param->Epola[AVBR][AIBR] = E_excitory;
                    }else if(arg_bit[15] == 1){
                        arg_param->Epola[AVBL][AIBL] = E_inhibitory;
                        arg_param->Epola[AVBR][AIBR] = E_inhibitory;
                    }
                /*}else if(i==AVBL && j==AWBL){//21
                    if(arg_bit[21] == 0){
                        arg_param->Epola[AVBL][AWBL] = E_excitory;
                        arg_param->Epola[AVBR][AWBR] = E_excitory;
                    }else if(arg_bit[21] == 1){
                        arg_param->Epola[AVBL][AWBL] = E_inhibitory;
                        arg_param->Epola[AVBR][AWBR] = E_inhibitory;
                    }*/
                }else if(i==AVBR && j==ASHL){//16
                    if(arg_bit[16] == 0){
                        arg_param->Epola[AVBL][ASHL] = E_excitory;
                        arg_param->Epola[AVBR][ASHR] = E_excitory;
                    }else if(arg_bit[16] == 1){
                        arg_param->Epola[AVBR][ASHL] = E_inhibitory;
                        arg_param->Epola[AVBR][ASHR] = E_inhibitory;
                    }
                /*}else if(i==AWBL && j==AWBR){//23
                    if(arg_bit[23] == 0){
                        arg_param->Epola[AWBR][AWBL] = E_excitory;
                        arg_param->Epola[AWBL][AWBR] = E_excitory;
                    }else if(arg_bit[23] == 1){
                        arg_param->Epola[AWBR][AWBL] = E_inhibitory;
                        arg_param->Epola[AWBL][AWBR] = E_inhibitory;
                    }*/ 
                }else if(i==AWCL && j==AIAR){//17
                    if(arg_bit[17] == 0){
                        arg_param->Epola[AWCR][AIAL] = E_excitory;
                        arg_param->Epola[AWCL][AIAR] = E_excitory;
                        arg_param->Epola[AWCR][AIAR] = E_excitory;
                    }else if(arg_bit[17] == 1){
                        arg_param->Epola[AWCR][AIAL] = E_excitory;
                        arg_param->Epola[AWCL][AIAR] = E_excitory;
                        arg_param->Epola[AWCR][AIAR] = E_excitory;
                    }   
                }else if(i==AWCL && j==AIYL){//18
                    if(arg_bit[18] == 0){
                        arg_param->Epola[AWCL][AIYL] = E_excitory;
                        arg_param->Epola[AWCR][AIYL] = E_excitory;
                    }else if(arg_bit[18] == 1){
                        arg_param->Epola[AWCL][AIYL] = E_inhibitory;
                        arg_param->Epola[AWCR][AIYL] = E_inhibitory;
                    }
                }else if(i==AWCL && j==AWCR){//19
                    if(arg_bit[19] == 0){
                        arg_param->Epola[AWCL][AWCR] = E_excitory;
                        arg_param->Epola[AWCR][AWCL] = E_excitory;
                    }else if(arg_bit[19] == 1){
                        arg_param->Epola[AWCL][AWCR] = E_inhibitory;
                        arg_param->Epola[AWCR][AWCL] = E_inhibitory;
                    }
                }
            }
        }
    }

    return;
}


#endif
