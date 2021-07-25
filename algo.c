#include<stdio.h>
#include<math.h>
#include"Trie.h"
#include"algo.h"
#include"bit.h"


void compress(char *input_filename , char *output_filename )
{
    
    trie root,p;
    FILE    *ptr ;
    FILE *pt ;
    int i=0,counter= 255;
    int code_size = 9;
    root=init(root);
    int ch ;
    char c ;
    
    ptr = fopen(input_filename,"r") ;
    pt= fopen(output_filename ,"ab") ;
   ch = fgetc(ptr) ;
    while( ch != EOF)
    {
        p=root;
        while(p!=NULL)
        {
            
            c = ch + '\0' ;
            p=search(p,c,&counter , &code_size , pt);
            ch = fgetc(ptr) ;
        }

        if(ch == EOF)
        {
            break;
        }
        else 
        {
            fseek(ptr , -2 , SEEK_CUR) ;
            //i=i-1;
        }
           ch = fgetc(ptr);
    }
   if(leftOver >0)
   {
    fputc(leftValue << (8-leftOver),pt);
   }
   leftValue = 0;
   leftOver = 0 ;
    fclose(pt) ;
    
    fclose(ptr) ;
    long int of_size =  get_file_size(output_filename,1) ;
    long int if_size = get_file_size(input_filename,1);
     print_info(if_size, of_size,input_filename);
    return  ;  
}

void decompress(char *input_filename , char *output_filename )
{
     FILE *dpt ;
     FILE *out ;
     dictionary *decode[65536] ;
     initD(decode);
     int prevcode;
     int currcode ;
     int size ;
     char ch ;
     int limiting = 255;
     int code_size = 9;
     int c ;
    dpt = fopen(input_filename,"rb") ;
    out = fopen(output_filename ,"a");
    prevcode =  read_binary(dpt,code_size) ;
    output(out ,decode , prevcode);
    currcode = read_binary(dpt , code_size) ;
     while( currcode  != -1 )                                                                           
     {
        if(currcode < limiting) 
        {
            ch = firstchar(currcode , decode) ;
            addtodictionary(decode , &limiting , prevcode , ch) ;
            output(out,decode , currcode) ;

        }
        else
        {
             ch = firstchar(prevcode , decode) ;
             addtodictionary(decode , &limiting , prevcode , ch ) ;
             output(out ,decode , prevcode) ;
        }

        prevcode = currcode ;
        if((limiting) == pow(2,code_size )-3)
                {
                    code_size++ ;
                }
                currcode = read_binary(dpt , code_size) ;

     }      
     
     leftOver = 0;
     leftValue =0 ;
     fclose(out) ;
     fclose(dpt) ;
    return ;
}



long int get_file_size(char *filename, int flag)
{

     // opening the file in read mode
        FILE* fp = fopen(filename, "rb");

        // checking if the file exist or not
        if (fp == NULL) {
            printf("File Not Found!\n");
            return -1;
        }

        fseek(fp, 0L, SEEK_END);

        // calculating the size of the file
        return  ftell(fp);

}

void print_info(long int input_file_size, long int output_file_size, char *input_file_name)
{
    float ratio = (float)input_file_size/output_file_size ;
     printf("****************************************************************\n") ;
    printf("                                                   \n") ;
    printf("            Input File Name     :     %s               \n",input_file_name) ;
    printf("            Input file size     :     %ld    bytes       \n",input_file_size) ;
    printf("            Output file size    :     %ld    bytes       \n",output_file_size) ;
    printf("            Compression Ratio   :     %.2f:1          \n",ratio) ;
    printf("                                                   \n") ;
    printf("****************************************************************\n");
}
