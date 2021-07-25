#include<stdio.h>
#include<stdlib.h>
#include"bit.h"
#include"Trie.h"

int read_binary(FILE *ip, int size)
{
    int read = fgetc(ip);
    if(read == EOF)return -1;
    int code;
    if((leftOver + 8) >= size)
    {


        int code1 = (leftValue << (size - leftOver));
        int code2 =  (read >> ((8-(size-leftOver))));
        code = code1 + code2;
        int tmp = leftOver;
        leftOver = (8-(size-tmp) );
        leftValue = read & ((1<< (8-(size-tmp)))-1);
    }
    else
    {
        code = (leftValue << 8 )+ read;


        leftValue = 0;

        read = fgetc(ip);


        size = size- (8+leftOver);


        code = (code << size);
        code = code + (read >> (8-size));
        leftOver = 8-size;

        leftValue = (read & ((1<<(8-size))-1));



    }
    return code;


}

void write_binary(FILE *op, int code, int size)
{
    int pre = (leftValue << (8-leftOver));                                     // remaining bit that are left  in previous itration 
    int curr = (code>>(size-(8-leftOver)));                                   
    leftOver = leftOver+size-8;                                               //updating value of leftover
    leftValue = code&((1<<(size-(8-leftOver)))-1);                           // updating value of  leftvalue

    int print = pre + curr;                                                 // bit pattern that we are going to print in file
    fputc(print,op);

    while(leftOver >=8 )
    {
        print = (leftValue >> (leftOver-8));
        leftValue = leftValue & ((1<<(leftOver-8))-1);
        leftOver = leftOver-8;
        fputc(print,op);

    }
}