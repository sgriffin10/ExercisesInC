int operate(int x, int y, char operator, int *result) {
    if (operator == '+') {
        *result = x + y;
        return 0;
    }
    if (operator == '*') {
        *result = x * y;
        return 0;
    }
    return -1;
}

int main(){
    // int x = 10;
    // int y = 5;
    // char *operator = '*';
    int z;
    int output = operate(3, 4, '*', &z); //'&' is address
        if (output == -1){
            printf("Error Handling");
        }else{
            printf("%d\n", z);
        }
}