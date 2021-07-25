#include<stdio.h>
#include"trie.h"
#include"bit.h"
#include<stdlib.h>
#include<math.h>

trie init(trie p)
{
    trie t;
    t=(node *)malloc(sizeof(node));
    for(int i=0;i<256;i++)
    {
        t->b[i]=createnode( i+'\0' ,  i );
    }
    printf("\n");
    return t;
}
trie createnode( char data , int encoding)
{
    trie t;
    t=(node *)malloc(sizeof(node));
    if(!t)
        return NULL;
    t->a = data;
    for(int i=0;i<256;i++)
        t->b[i]=NULL;
    t->wordend = encoding;
    return t;
}
trie search( trie p , char data , int *q, int *a , FILE *pt)               
{
    trie t;
    int ch;
    ch = data + '\0' ;
    if(p->b[ch]!=NULL)
    {
        return p->b[ch] ;
    }
    else
        {
            (*q)++;
            t=createnode(data,*q); 
            p->b[ch]=t;
            if(!t)
                return NULL;
                if((*q) == pow(2,(*a)) -1)            
                {
                    (*a)++ ;
                }
                  write_binary(pt,p->wordend, *a);
            return NULL;
        }
}







//Decoding 


 char firstchar(int code , dictionary *d[])
 {
    char ch ;
    if(d[code]->prev == -1 )
    {
        return d[code]->ch ;
    }
    else 
    {
        ch =firstchar(d[code]->prev , d) ;
        return ch ;
    }
 }
 void addtodictionary(dictionary *d[] , int *p , int prev , char ch )
 {
    (*p)++ ;
    dictionary *tmp ; 
    tmp = (dictionary*)malloc(sizeof(dictionary)) ;
    tmp->prev = prev ;
    tmp->ch = ch ;
    d[*p] = tmp ;
    
}
void output(FILE *pt,dictionary *d[] ,int code) 
{
    if(d[code]->prev == -1)
    {
        fputc(d[code]->ch , pt) ;
        return ;
    }
    else
    {
        output(pt, d, d[code]->prev) ;
        fputc(d[code]->ch ,pt) ;
        return ;
    }

}
void initD(dictionary *decode[])
{
    for(int i=0 ; i < 256 ; i++) 
    {
        dictionary *tmp ;
        tmp = (dictionary*)malloc(sizeof(dictionary)) ;
        tmp->prev =-1;
        tmp->ch = i + '\0' ;
        decode[i] =  tmp ;
    }
}
