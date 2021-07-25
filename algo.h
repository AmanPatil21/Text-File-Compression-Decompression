#include<stdio.h>
void compress(char *input_filename , char *output_filename );
void decompress(char *input_filename , char *output_filename); 
long int get_file_size(char *filename, int flag);
void print_info(long int input_file_size, long int output_file_size, char *input_file_name);