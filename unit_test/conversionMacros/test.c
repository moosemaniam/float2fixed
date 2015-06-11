/** 
 * @file test.c
 * @brief 
 * @author VikasMK
 * @version 0.1
 * @date 2015-06-12
 */
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

#include"float2fixed.h"

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
