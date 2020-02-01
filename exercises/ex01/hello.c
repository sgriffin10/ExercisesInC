#include <stdio.h>

int main() {
    int val;
    int x = 5;
    int y = x + 1;
    printf("Hello, World!\n");
    printf("y is %d\n",y);
    val = RandomValue(3);
    printf(val);
    return 0;
}

void RandomValue(int ){
    return 69;
}

/*
1.  I get:
    subq $16, %rsp 
    movl $5, -8(%rbp)

2. The lines disappear

3. Movl	$5 and %es is added

4. The conclusion is that optimization decreases runtime by reducing the code size. 
 */