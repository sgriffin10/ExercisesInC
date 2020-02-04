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

    

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    printf ("Address of var2 is %p\n", &var2);

    void *p = malloc(10);
    void *v = malloc(10);
    char *s = "Hello, World";

    printf ("p points to %p\n", p);
    printf ("s points to %p\n", v); //1.40524902e14 is this right? or 0x24F0 (9456 bytes)

    PrintAdress(var2);

    return 0;
}

