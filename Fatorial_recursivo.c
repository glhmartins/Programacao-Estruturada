#include <stdio.h>

int fatorial(int n){
    if (n<=1){
        n = 1;
    } else {
        n *= fatorial(n-1);
    }
    return n;
}

int main(){
    int n;
    scanf("%d", &n);
    n = fatorial(n);
    printf("%d\n", n);
    return 0;
}