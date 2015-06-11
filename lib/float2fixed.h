#ifndef FLOAT_2_FIXED_H
#define FLOAT_2_FIXED_H
#define ERROR_DIVIDE_BY_ZERO (-1)
#define ERROR_NUM_OUT_OF_RANGE (-2)
#define ERROR_NOT_SUPPORTED (-3)
//#include"datatypes.h"
//
#define MAXBITLENGTH (32)

int convert_flt_to_fix(float num,int Q);
float convert_fix_to_flt(int num,int qformat);
#endif
