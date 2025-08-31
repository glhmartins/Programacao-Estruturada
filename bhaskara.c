#include <stdio.h>
#include "matlib.h"

double Bhaskara(double a, double b, double c, double *raiz1, double *raiz2){
    double delta;
    if (a == 0) return NOT_2ND_DEGREE;
    delta = b*b -4.0*a*c;
    if (delta < 0.0) return NO_ROOTS;
    *raiz1 = (-b + sqrt(delta))/2.0;
    *raiz2 = (-b - sqrt(delta))/2.0;
    if (delta == 0.0) return ONE_ROOT;
    return TWO_ROOTS;
}
    
int main(){
    double a,b,c, raiz1, raiz2; // Coefiecientes e raizes
    int status; // Resultado do calculo
    scanf("%lf %lf %lf", &a, &b, &c);
    status = Bhaskara(a,b,c, &raiz1, &raiz2);
    if (status == 2) { // Duas raizes reais distintas
        printf("%lf %lf\n", raiz1, raiz2);
    } else if (status == 1){ // Uma raiz real
        printf("%lf\n", raiz1);
    } else if (status == 0){ // Nenhuma raiz real
        printf("Sem raizes brother\n");
    } else if (status == -1){
        printf("Nem eh equation de el second grau\n");
    }
    return 0;
}