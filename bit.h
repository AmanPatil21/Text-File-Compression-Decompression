#ifndef BIT_H  
#define BIT_H /* contents */ 


#include<stdio.h>
#include<stdlib.h>

extern  int leftOver ;
extern  int leftValue ;
int read_binary(FILE *ip, int size);

void write_binary(FILE *op, int code, int size);
#endif