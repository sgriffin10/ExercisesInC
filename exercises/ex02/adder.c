/*Create a file named `adder.c` and write a program that allows the user to enter integers, one per line, until the user hits Control-D, which is the end-of-file (EOF) character.

It should convert the numbers from input strings to integers and store the integers in an array.  The program should produce appropriate error messages if the user enters something that exceeds the length of the input buffer, or can't be converted to an integer.  It should also produce an error message if the user enters more numbers than will fit in the array.

After the user enters Control-D, the program should add up the numbers in the array and print the result.  

Your program should be divided into at least two functions with well designed interfaces.

Optionally, the program should produce an error if the sum exceeds the largest integer that can be represented.

Hint: You will probably want to use two functions we haven't seen yet:

* strlen: [Read about it here](https://www.tutorialspoint.com/c_standard_library/c_function_strlen.htm)

* atoi: [Read about it here](https://www.tutorialspoint.com/c_standard_library/c_function_atoi.htm)

Before you use their functions, you need to `#include <string.h>`. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInput(int *newArray, int *buffer, int *count){
    char input[*buffer + 10];
    puts("Enter a number: ");
    int flag = scanf("%19s", input);
    if (flag == EOF){
        return flag;
    }
    else{
        int number = atoi(input);
        if (strlen(input)> *buffer - 1){
            printf("The number you entered is too big! \n");
        }
        else if (number == 0){
            printf("You entered an invalid number!\n");
        }
        else{
            newArray[*count] = number;
            *count += 1;
        }
    return flag;
    }
}

int MaxAmount(int *buffer){
  int max = 1;
  for (int i = 0; i < *buffer - 1; i++){
    max = max * 10;
    /*printf("max is %d.", max);*/
  }
  return max;
}

void addArray(int *newArray, int *count, int *buffer){
    int sum = 0;
    int maxNumber = MaxAmount(buffer);
    for (int i = 0; i < (10); i++){
        sum += newArray[i];
    }
    if (sum <= maxNumber){
        printf("The sume of all integers is %d\n", sum);
    }
    else{
        printf("Sum exceeds largest integer.\n");
    }

}

int main(){
    int count = 0;
    int MaxNumber = 10;
    int buffer = 8;
    int newArray[MaxNumber];
    int flag = 0;
    while (flag != EOF){
        if (count > MaxNumber - 1){
            printf("Storage limit has been reached.\n");
            break;
        }
        flag = getInput(newArray, &count, &buffer);
    }
    addArray(newArray, &count, &buffer);
    return 0;
}
