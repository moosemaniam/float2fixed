/**
 * @file float2fixed.c
 * @brief Conversion functions from float to fixed of a given Q format
 * @author Vikas M.K
 * @version 0.1
 * @date 2015-06-11
 */
#include<math.h>
#include"datatypes.h"

inline FLOAT geometric_sum(FLOAT a,FLOAT r, INT n)
{
    if(r==0)
    {
        printf("Tried to divide by 0. Exiting file: %s line %d function: %s\n",__FILE__,__LINE__,__FUNC__);
            exit(ERROR_DIVIDE_BY_ZERO);
    }
    return(a*(1.0 - pow(r,n))/(1.0 - r));
}

/*Notes
 *
 *
 * Sum of (2^-1 + 2^-2 + ... + 2^-N ) is required to compute the fractional
 * length
 * sum of GEOM_SUM(a,r)=a + ar + ar^2 + ar^3 ... N terms is a ( 1-r^n)/(1-r) (r!=0)
 *
 * For a bit length of N. Q format "Q" ( assume Q < N )
 * fractional part : FRACT_BITS = Q bits
 * integer part    : INT_BITS=(N-Q-1) bits
 * sign bit        : SIGN_BIT=1 bit
 * Max number      : 2^(FRACT_BITS-1) + GEOM_SUM(

 * Ex: Q31 format
 * fractional part : 31 bits
 * integer part    : (32-31-1) = 0 bits
 * sign bit        : 1 bit
 * :*/

/**
 * @brief converts a floating point number to fixed point of a given * format
 * @param num floating point number to be converted
 * @param Q   Q format
 * @return  fixed point number
 * @note    exit with error if not possible
 */
//INT convert_flt_to_fix(FLOAT num,INT Q)
//{
//   /*Decide if the current Q format can represent this number*/
//
//    /*If not exit with error*/
//
//    /*Else, Do the conversion*/
//
//    /*Return the fixed point value*/
//}
