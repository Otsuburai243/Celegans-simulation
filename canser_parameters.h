/*=========================================================================
Define the common parameters and variables for the simulation.
=========================================================================*/
#ifndef CANSER_PARAMETERS_H
#define CANSER_PARAMETERS_H

#include <stdio.h>

#define N 18      // the number of variables
#define N_BIT 20
#define DT 1.0e-3 // time
/* ----- constants -----*/
#define Gche 6.0e-3         //mS
#define Ggap 5.0e-2         //mS (Siemens)
#define Vrange 5.0          //mV
#define Vshift -30.0         //mV
#define E_inhibitory -60    //mV
#define E_excitory 0.0      //mV
#define E_unknown 0.05
#define AIAL 0
#define AIAR 1
#define AIBL 2
#define AIBR 3
#define AIYL 4
#define AIYR 5
#define AIZL 6
#define AIZR 7
#define ASHL 8
#define ASHR 9
#define AVAL 10
#define AVAR 11
#define AVBL 12
#define AVBR 13
#define AWBL 14
#define AWBR 15
#define AWCL 16
#define AWCR 17

/*-----paramerters  Iion,Istim-----*/
//#define Rgb 1.9         //A
#define R_stim 10.0       //pA
#define t1_stim 1.0       //second
#define t2_stim 0.1       //second

/*----- variables in the equations -----*/
typedef struct _variables{
    double v[N];
    double Ca[N];
    double fluorescence[N];
} Variable;

// ----- parameters in the equations -----
typedef struct _parameter{
    double  Nche[N][N];
    double  Ngap[N][N];
    double Epola[N][N];
    double       Cm[N];
    double    FFmax[N];
    double      Rgb[N];
    double       Va[N];
    double       Vc[N];
    double       Vd[N];
    double       Ve[N];

} Parameter;

#endif


