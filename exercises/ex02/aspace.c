/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

Name: Spencer Griffin
Date: February 3, 2020
Class: Software Systems Spring 2020

*/

#include <stdio.h>
#include <stdlib.h>

int var1;

void PrintAdress(int var){
    printf("Address of var2 is %p\n", &var);
    return;
}

int main ()
{
    int var2 = 5;
    void *g = malloc(128);
    void *e = malloc(128);
    char *s = "Hello, World";

    

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);
    PrintAdress(var2);
    //Stack grows downwards towards lower addresses. Local variables are lower than address of var2

    void *p = malloc(10);
    void *v = malloc(10);
  

    printf ("p points to %p\n", p);
    printf ("s points to %p\n", v); 
    //Space between the two is 0x24F0 (9456 bytes)



    return 0;
}

