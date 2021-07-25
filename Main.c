#include<stdio.h>
#include"trie.h"
#include<stdlib.h>
#include"bit.h"
#include"algo.h"
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#define EXIT_FAILURE 1
#define EXIT_SUCESS 0



int leftOver ;
int leftValue ;

void help_function() ;
int isDirectory(const char *path) ;
void operation ( char *buffin ,  char *buffout , char flag , int f_flag) ;

int  main(int argc , char *argv[]) 
{

    int opt ;
   char flag ;
   int f_flag ;                                      //folder flag
   char *bufferin ;
   char *bufferout ;
   leftValue = 0;
   leftOver = 0 ;
   if(argc == 2)
   {
       while ((opt = getopt(argc , argv ,"h") )!= -1)
       {
           switch (opt)
           {
           case 'h':
               help_function() ;
               return 0;
               break;
           
           default:
           fprintf(stderr ,"Expected argument is not given  ") ;
           exit(EXIT_FAILURE) ;
               break;
           }
       }
   }

   else if(argc == 5)
   {

       
       while((opt = getopt(argc , argv ,"c:d:o:")) != -1)
       {
           switch (opt)
           {
               case 'c' :
                    flag = opt ;
                    bufferin = optarg ;
                    break ;
                case 'd' :
                    flag = opt ;
                    bufferin = optarg ;
                    break ;
                case 'o' :
                    bufferout = optarg ;
                    break ;
                default :
                    fprintf(stderr , "Expected arrugement is not mentioned ") ;
                    exit(EXIT_FAILURE) ;
                    break ;
                
           }
       }
   }
   else 
   {
       fprintf(stderr , "Expected arrugement is not mentioned ") ;
                    exit(EXIT_FAILURE) ;
   }

   /* Algo :
   Now we have to check that given name is a file or folder if that is folder then we will openf folder part other wise we will open file 
   */

  struct stat bufferp ;
  int exist = stat(bufferin , &bufferp ) ;
  if(exist != 0 )
  {
    fprintf(stderr ,"File does not exist") ;
      exit(0) ;
  }
  f_flag = isDirectory(bufferin) ;                     // fi f_flag ==1 then given name is of folder
  int j =0;
  int l_out ;
  l_out = strlen(bufferin) ;
  char output[260] ;
      while(bufferin[l_out] !=  '\\')
            {
                l_out-- ;
            }
            for( j =0 ; j<=l_out ;j++)
            {
                output[j] = bufferin[j] ;
            }
            output[j]='\0' ;
            strcat(output ,bufferout) ;
             //printf("\n%s",output) ;
  operation(bufferin , output , flag , f_flag) ;
    return 0 ;
}






void help_function()
{
    printf("This program can compress and decompress the text and image file \n") ;
    printf("Usage : ./a.exe [-c] | [-d] [File or Folder Name ] [-o] [Output File/Foleder name ]\n") ;
    printf("-c : Compress\n") ;
    printf("-d : Decompress\n") ;
    printf("-o : output_file_name\n");
}







int isDirectory(const char *path) 
{
    struct stat statbuf ;
    if(stat (path ,&statbuf) != 0)
    {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode) ;
}







void operation( char *buffin ,  char *buffout , char flag , int f_flag)
{
    int l_out  ; 
     int d_out ;
    if(f_flag == 1)
    {
        int i=0; 
        int k =0;
        int j=0 ;


        /*Algo : open input folder and output folder then apply while loop to get every entry of folder 
        then call operation function  for every entry 
        */
       
        struct dirent *de ;
        mkdir(buffout);
        DIR *dr = opendir(buffin) ;
        DIR  *out = opendir(buffout) ;
        if(dr == NULL)
        {
            fprintf(stderr,"Folder Not Found") ;
        }
        de = readdir(dr) ;

        while(de != NULL)
        {
            if(strcmp(de-> d_name, ".") == 0 ||  strcmp(de->d_name, "..") == 0)
            {  
            de = readdir(dr) ;
            }
            else 
            {
                int len = strlen(buffin) ;
                char input[260] ;
                char outputp[260] ;
                char per_buffout[260] ;
                int i=0 ;
                strcpy(input , buffin) ;
                strcat(input,"\\") ;
                strcat(input , de->d_name) ;
                k = isDirectory(input) ;
                if(k == 1)
                {
                        l_out = strlen(input) ;
                        d_out = strlen(input) ;
                        while(input[l_out] !=  '\\')
                        {
                            l_out-- ;
                        }
                        for(int j = l_out;j< d_out ;j++)
                        {
                            outputp[i] = input[j] ;
                            i++ ;
                        }
                        outputp[i]= '\0' ;
                        strcpy(per_buffout , buffout) ;
                        strcat(per_buffout ,  outputp) ;
                        operation(input ,per_buffout , flag , k) ;
                        de = readdir(dr) ; 


                }
                else 
                {
                        l_out = strlen(input) ;
                        d_out = strlen(input) ;
                        while(input[l_out] !=  '\\')
                        {
                            l_out-- ;
                        }
                        while(input[d_out] != '.') 
                        {
                            d_out-- ;
                        }
                        for(int j = l_out;j < d_out ;j++)
                        {
                            outputp[i] = input[j] ;
                            i++ ;
                        }
                        outputp[i]= '\0' ;
                        
                        strcpy(per_buffout,buffout) ;
                    
                        strcat(per_buffout,outputp) ;
                        operation(input ,per_buffout , flag , k) ;
                        de = readdir(dr) ; 
                }
            }
        }
        closedir(dr) ;
        closedir(out) ;


    }

    else
    {
        int i = 1 ;
        while(i)
        {
            switch(flag)
            {
                
                case 'c':
                    {
                        strcat(buffout ,".bin") ;
                        compress(buffin , buffout) ;
                    }
                    break ;
                case 'd' :
                    {
                        strcat(buffout ,".txt") ;
                       decompress(buffin,buffout) ;
                    }
                    break ;
                default :
                    fprintf(stderr ,"Syntax error  chech hepl page [-h]") ;
                    break ;
            }
            i--;
        }
    }
}