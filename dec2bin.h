#ifndef __DEC2BIN_H   /* trick to avoid duplicate inclusion */
#define __DEC2BIN_H

#include <stdio.h>
#include <math.h>


/*-----decimal number to binary number (bit string)-----*/
void dec2bin( unsigned long int arg_num_dec, int arg_n_bit, int arg_bit_string[ ] ){

  int i;

  for ( i = 0; i < arg_n_bit; i++ ) {
    arg_bit_string[i] = arg_num_dec % 2;	
    arg_num_dec /= 2;
  }

  return;
}

#endif 
