#include <stdio.h>

void test(int *x, char *y){
    *x+=1;
    *y+=1;
}

int main(){
    int n = 123;
    char letter = 'A';
    test(&n, &letter);
    printf("%d %c\n", n, letter);
    return 0;
}