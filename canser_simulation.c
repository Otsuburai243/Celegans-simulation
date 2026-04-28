/*===========================================================================
This project simulates the olfactory neural circuit of C. elegans
using a nonlinear mathematical model to analyze responses to
cancer-related volatile compounds.

The focus is on the AWC neuron and its relationship to
chemotactic behavior.

## Simulation Details
The main function configures the simulation conditions, including
the total simulation time, output criteria, and validation checks
such as duplicate random number detection.
===========================================================================*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h> 
#include <time.h>
#include <stdlib.h>
#include "canser_parameters.h"
#include "canser_runge-kutta.h"
#include "canser_set_parameters.h"
#include "canser_init_variables.h"
#include "dec2bin.h"
#include "SFMT_1_3_3_all.h"

#define Pmin (1ULL << 0)
#define Pmax (1ULL << N_BIT)



// ----- main function -----
int main(void){

    int i,k;
    unsigned long int random_value;
    int bit[N_BIT];
    int counts;
    double t, t0, t_end;
    Variable v;              // variables in the equation
    Parameter param;         // parameters in the equation

    t0 = 0.0;
    t_end = 20.0;
    double SAVE_TIME   = 4.0;                
    double steady_AVAL = 0.0;         //steady solution
    double steady_AVAR = 0.0;
    double steady_AVBL = 0.0;
    double steady_AVBR = 0.0;
    double second_steady_AVAL = 0.0;  //second steady solution
    double second_steady_AVAR = 0.0;
    double second_steady_AVBL = 0.0;
    double second_steady_AVBR = 0.0;
    double juge_time1  = 7.0;
    double juge_time2  = 9.0;
    double juge_time3  = 11.0;
    //double juge_time3  = 16.0;
    //double juge_time4  = 18.0;
    double juge_value  = 5.0;
    time_t start_time;
    time_t end_time;


    char filename[][20] = {"result_polality","result_membrane","to_confirm"};
    FILE *fp[3];
    for(i=0; i<3; i++){

        char full_filename[25];
        strcpy(full_filename, filename[i]);
        strcat(full_filename, ".txt");
        fp[i] = fopen(full_filename, "w");

        if (fp[i] == NULL) {
            printf("Error opening file: %s\n", full_filename);
            return 1;
        }

    }

    k = 1;
    counts = 0;
    start_time = time(NULL);

/*---Check of Random Numbers-----------------------------------------------*/
    int *random_check = malloc((Pmax / 4) * sizeof(int));
    if (random_check == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (i = 0; i < Pmax / 4; i++) {
        random_check[i] = 0; // Initialize
    }
    init_gen_rand(1); //Initialization of Random Numbers

/*--- start simulation ----------------------------------------------------*/
    while(counts<=Pmax/4){

        do {
            random_value = Pmin + (unsigned long int)((Pmax - Pmin) * genrand_real1());
        } while (random_value >= Pmax || random_check[random_value / 4] == 1); // Range check

        random_check[random_value / 4] = 1;  //Confirmed

        //Operation check
        if (counts % 1024 == 0) { //(counts & 1023) == 0
            end_time = time(NULL);
            double interval_time = end_time - start_time;
            //reset starttimer
            start_time = time(NULL);
            fprintf(fp[2],"interval_time:%6.2f[s]  counts:%d \n",interval_time, counts);
            fflush(fp[0]);  //polarity
            fflush(fp[1]);  //parameters that meet the conditions
            fflush(fp[2]);  //verification counts
        }

        
        dec2bin( random_value , N_BIT, bit );
        

        // set the parameters
        set_parameters(&param, bit);

        // initialization of the variables
        init_variables(&v);

        bool juge1_met = false;
        bool juge2_met = false;
        bool juge3_met = false;

        //Save steady solution
        for (t = t0; t <= t_end; t += DT){
            if(fabs(t - SAVE_TIME) < DT){
                steady_AVAL = v.v[AVAL];
                steady_AVAR = v.v[AVAR];
                steady_AVBL = v.v[AVBL];
                steady_AVBR = v.v[AVBR];
            }
        
            //judgment conditions
            if (!juge1_met                   &&
                fabs(t - juge_time1) < DT    &&
                v.v[AVBL]> v.v[AVAL]         &&
                v.v[AVBR]> v.v[AVAR]         &&
                v.v[AVBL]-steady_AVBL>1      &&
                v.v[AVBR]-steady_AVBR>1      &&
                v.v[AVAL]<=steady_AVAL       &&
                v.v[AVAR]<=steady_AVAR)
            {     

                juge1_met = true;
            }

            //additional candition2
            if (juge1_met                         &&
                !juge2_met                        &&
                fabs(t - juge_time2) < DT         &&
                v.v[AVBL]> v.v[AVAL]              &&
                v.v[AVBR]> v.v[AVAR]              &&
                v.v[AVBL]> steady_AVBL            &&
                v.v[AVBR]> steady_AVBR            &&
                v.v[AVAL]<=steady_AVAL            &&
                v.v[AVAR]<=steady_AVAR            &&
                v.v[AVBL]-v.v[AVAL] >juge_value   &&
                v.v[AVBR]-v.v[AVAR] >juge_value     //&&               
                )    
            {
                juge2_met = true;               
            }

            //additional candition3
            if (juge1_met                         &&
                juge2_met                         &&
                !juge3_met                        &&
                fabs(t - juge_time3) < DT         &&
                v.v[AVBL]> v.v[AVAL]              &&
                v.v[AVBR]> v.v[AVAR]              &&
                v.v[AVBL]> steady_AVBL            &&
                v.v[AVBR]> steady_AVBR            &&
                v.v[AVAL]<=steady_AVAL            &&
                v.v[AVAR]<=steady_AVAR            &&
                v.v[AVBL]-v.v[AVAL] >juge_value   &&
                v.v[AVBR]-v.v[AVAR] >juge_value     //&&               
                )    
            {
                juge3_met = true;                              
            }

            //additional candition3
            if (juge1_met                     &&
                juge2_met                     &&
                juge3_met
               )                    
            {
        
                fprintf(fp[0],"%-6d",k);
                for(i=0; i<N_BIT; i++){
                    fprintf(fp[0],"%d",bit[i]);
                }
                fprintf(fp[0],"\n");

                fprintf(fp[1],"%-3d %.3f  %9.6f %9.6f %9.6f %9lu \n",k, t,(v.v[AVBL]-steady_AVBL)-(v.v[AVAL]-steady_AVAL), v.v[AVBL], v.v[AVAL],random_value);

                k++;
                
                break;        //end time loop
            }

            // 4th-order Runge Kutta method
            v = Runge_Kutta(t, v, param);
        }

        counts++;

    }

    fclose(fp[0]);
    fclose(fp[1]);
    fclose(fp[2]);

    return 0;
}