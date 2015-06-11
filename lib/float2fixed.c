/**
 * @file float2fixed.c
 * @brief Conversion functions from float to fixed of a given Q format
 * @author Vikas M.K
 * @version 0.1
 * @date 2015-06-11
 */
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

#define ERROR_DIVIDE_BY_ZERO (-1)
#define ERROR_NUM_OUT_OF_RANGE (-2)
#define ERROR_NOT_SUPPORTED (-3)
//#include"datatypes.h"
//
#define MAXBITLENGTH (32)

#define GEOM_SUM(N)\
    (1.0 - pow(2,-N))\



/*Notes
 *
 *
 * Sum of (2^-1 + 2^-2 + ... + 2^-N ) is required to compute the fractional
 * length
 * sum of GEOM_SUM(a,r)=a + ar + ar^2 + ar^3 ... N terms is a ( 1-r^n)/(1-r) (r!=0)
 *
 * For a bit length of N. Q format "Q" ( assume Q < N )
 * fractional part : FRACT_BITS = Q bits
 * integer part    : int_BITS=(N-Q-1) bits
 * sign bit        : SIGN_BIT=1 bit
 * Max number      : 2^(FRACT_BITS-1) + geometric_sum(0.5,0.5,FRACT_BITS)

 * Ex: Q31 format
 * fractional part : 31 bits
 * integer part    : (32-31-1) = 0 bits
 * sign bit        : 1 bit
 * :*/

float convert_fix_to_flt(int num,int qformat)
{
   return(num/pow(2,qformat));
}

/**
 * @brief converts a floating point number to fixed point of a given * format
 *
 * @param num floating point number to be converted
 * @param Q   Q format
 *
 * @return  fixed point number
 * @note    exit with error if not possible
 */
int convert_flt_to_fix(float num,int Q)
{
    float minRepresentable;
    int fract_bits;
    int integer_bits;
    int sign_bits;
    float temp;
    float temp1;
    double temp2;
    double maxRepresentable=0.0;
    int i;
    int retFixed;

    assert(Q < MAXBITLENGTH);

    fract_bits =  Q;
    integer_bits = MAXBITLENGTH - Q - 1;
    sign_bits = 1;

    /*Decide if the current Q format can represent this number*/
    /*If not exit with error*/

    maxRepresentable= (float)( (1 << integer_bits)-1);

    for(i=1;i<=Q;i++)
    {
        temp2 =  pow(2,-1*i);
        maxRepresentable += temp2;
    }

    minRepresentable = (float)(-1*(1 << integer_bits));

    /*Deal with positive numbers*/
    if(1 || num > 0.0)
    {
        if((num < minRepresentable) || (num > maxRepresentable))
        {
            printf("Float number %0.10f is out of\
                    range:\nQ%d format:\nmax %.10f\nmin %0.10f\n",
                    num,Q,maxRepresentable,minRepresentable);
            exit(ERROR_NUM_OUT_OF_RANGE);

        }

        else
        {
            /*Else, Do the conversion*/

            retFixed = (int)(num * ( 1 << fract_bits));
            /*Return the fixed point value*/
            return retFixed;
        }
    }
}

int main()
{
    int q = 30;
    int val1 = convert_flt_to_fix(-0.876,q);
    int val2 = convert_flt_to_fix(0.876,q);
    int val3;
    float fval1,fval2,fval3;
    val3 = val1 + val2;
    printf("val1 %x \nval2 %x\nval3 %x\n",val1,val2,val3);

    fval1 = convert_fix_to_flt(val1,q);
    fval2 = convert_fix_to_flt(val2,q);
    fval3 = convert_fix_to_flt(val3,q);
    printf("fval1 %.31f\nfval2 %.31f\n,fval3 %.31f\n",fval1,fval2,fval3);
    exit(0);

}
