  /*
    *Spencer Griffin
    *Software Systems Exercise 1

*/

#include <stdio.h>
#include <stdlib.h>

/* Updates the numeric value of card name inputted by user and returns the value.
It converts string arrays into integers.
*/
int ValueAssignment(char card_name[3]);


/* Checks the validity of the card value
   If the value is 0 or greater than 11, we have an invalid case.
   Returns 1 for invalid values and 0 for valid values.
*/
int Validity(int val);

/* Updates count based on card value.
   Increases count for values between 2 and 7 and decrease when the value
   equals 10.
*/
void Counts(int val);

int main()
{
    char card_name[3];
    do {
        int val;
        puts("Enter the card_name: ");
        scanf("%2s", card_name);
        val = ValueAssignment(card_name);
        if (Validity(val)){
          continue;
        }
        Counts(val);
    } while (card_name[0] != 'X');
    return 0;
}

void Counts(int val){
    static int count = 0;
    if ((val > 2) && (val < 7)) {
        count++;
    } else if (val == 10) {
        count--;
    }
    printf("Current count: %i\n", count);
}

int Validity(int val){
  if((val < 1) || (val > 11)){
    puts("I don't understand that value!");
    return 1;
  }
  else {
    return 0;
  }
}

int ValueAssignment(char card_name[3]){
  int val;
  switch(card_name[0]) {
  case 'K':
  case 'Q':
  case 'J':
    val = 10;
    break;
  case 'A':
    val = 11;
    break;
  default:
    val = atoi(card_name); 
    break;
  }
  return val;
}

