#ifndef RANDOM_NUMBER_H
#define RANDOM_NUMBER_H

#include <stdio.h>
#include <math.h>
#include "SFMT_1_3_3_all.h"
 
double generation_ranndom_number( int max_number ){

  double original_num;
  int random_num;

  init_gen_rand( 1 ); //initialize the Mersenne Twister 

  original_num = genrand_real1( );   //generate random numbers in the range of [0,1]
  printf("%lf \n",original_num);

  random_num = original_num * max_number;
  printf("%d" ,random_num);

  return random_num;
}

#endif
