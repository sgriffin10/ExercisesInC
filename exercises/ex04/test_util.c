#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "minunit.h"
#include "util.h"

int tests_run = 0;

static char *test1() {
    char *res = icmpcode_v4(0);
    char *correct = "network unreachable";
    char *message = "test 1 failed: icmpcode_v4(0) should return \"network unreachable\"";
    mu_assert(message, strcmp(res, correct) == 0);
    return NULL;
}

static char *test2() {
    char *res = icmpcode_v4(1);
    char *correct = "host unreachable";
    char *message = "test 2 failed: icmpcode_v4(1) should return \"host unreachable\"";
    mu_assert(message, strcmp(res, correct) == 0);
    return NULL;
}

static char *test3() {
    char *res = icmpcode_v4(2);
    char *correct = "protocol unreachable";
    char *message = "test 3 failed: icmpcode_v4(2) should return \"protocol unreachable\"";
    mu_assert(message, strcmp(res, correct) == 0);
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    mu_run_test(test3);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result !=0;
  }