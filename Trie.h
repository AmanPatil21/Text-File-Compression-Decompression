
#ifndef TRIE_H  
#define TRIE_H /* contents */ 

typedef struct node {
    char a;
    struct node *b[256];
    int wordend;
}node;

typedef node * trie;

trie init(trie p);
trie createnode( char data , int encoding);
trie search( trie p , char data, int *q , int *a ,FILE *pt);                  // search function is noting but a insert function



//Decoding 

 typedef struct decoder {
     int prev ;
     char ch ;
 }dictionary ;
 void initD(dictionary *decode[]);
 char firstchar(int code , dictionary *d[]);
 void addtodictionary(dictionary *d[] , int *p , int prev , char ch );
 void output(FILE *pt, dictionary *d[] , int code) ;


 

#endif