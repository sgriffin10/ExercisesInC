/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    int i;
    int array[SIZE];

    printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}


/* Question 1: It will print out the address of both arrays in bar() and foo(). It should also print out "42" five times.

Question 2: warning: address of stack memory associated with local variable 'array' returned [-Wreturn-stack-address]
    return array;

Question 3: The segmentation fault that appears is due to the main function pointing towards the address of a stack allocated data.

Question 4: Get a warning saying local variable array in bar function is set but not used.
*/