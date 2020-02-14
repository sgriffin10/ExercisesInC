/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regex.h"

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Matches track with given input pattern
//Prints track numbers along with the corresponding title
void find_track_regex(char pattern[])
{
    regex_t regex;
    int input;
    char errorcode [100];
    input = regcomp(&regex, pattern, 0);
    if (input){
        regerror(input, &regex, errorcode, 100);
        printf("you have an error\n");
        exit(1);
    }
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        input = regexec(&regex, tracks[i], 0, NULL, 0);
        if (!input) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
        else if (input != REG_NOMATCH){
            regerror(input,&regex,errorcode, 100);
            printf("Regex failed. No match found with error\n");
            exit(1);
        }
    }
    regfree(&regex);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);
    // find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
