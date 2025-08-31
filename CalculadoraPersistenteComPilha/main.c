#include "Pilha.c"


void imprime(Tipo t);


void printStack(){
    if (stIsEmpty('A')) return;
    Tipo n;
    stPop('A', &n);
    printf("\n%f", n);
    printStack();
    stPush('A', n);
}

void menu(){
    system("cls");
    printf("Menu (m)\n");
    printf("Type float numbers followed by enter\n");
    printf("Operations: *, -, +, / \n");
    printf("Operations: s (signal change), c (clear), e (end)\n");
    printf("\nCurrent Stack:\n");
    stPrint('A', imprime); // imprimir a pilha sem modificar seu conte�do
    printf("\n\n");
}

void calculadora(){
    char ch;
    char strNumero[100];
    int algarismo=0;

    stCreate();
    menu();
    while (TRUE){
        ch = getche();
        if (ch == 'f' || ch == 'e'){ // fim ou end
            break;
        } else if (((ch >= '0') && (ch <= '9')) || (ch == '.')){
            strNumero[algarismo++] = ch;
        } else if (ch  == 'm'){
            menu();
        } else if (ch == 13){ // enter
            strNumero[algarismo] = '\0';// terminador de string
            Tipo num = atof(strNumero);
            printf("\n%f\n",num);
            stPush('A', num);
            algarismo = 0;
            menu();
        } else if (ch == 's'){
            Tipo num;
            stPop('A', &num);
            num = -num;
            printf("\n%f\n",num);
            stPush('A', num);
            menu();
        } else if (ch == 'c'){
            Tipo num;
            if (!stIsEmpty('A')){ // cancela digita��o atual e mostra �ltimo
                stPop('A', &num);
                printf("\n\n %f\n",num);
                stPush('A', num);
            }
        } if (ch == '+'){
            Tipo n1=0,n2=0, n3;
            stPop('A', &n2);
            stPop('A', &n1);
            n3 = n1 + n2;
            stPush('A', n3);
            menu();
            printf("\n >%f \n", n3);
        } if (ch == '-'){
            Tipo n1=0,n2=0, n3;
            stPop('A', &n2);
            stPop('A', &n1);
            n3 = n1 - n2;
            stPush('A', n3);
            menu();
            printf("\n >%f \n", n3);
        } if (ch == '*'){
            Tipo n1=0,n2=0, n3;
            stPop('A', &n2);
            stPop('A', &n1);
            n3 = n1 * n2;
            stPush('A', n3);
            menu();
            printf("\n >%f \n", n3);
        } if (ch == '/'){
            Tipo n1=0,n2=0, n3;
            stPop('A', &n2);
            stPop('A', &n1);
            if (n2 == 0.0){
                stPush('A', n1);
                menu();
                printf("\ncan not divide by zero, try another number\n");
            } else {
                n3 = n1 / n2;
                stPush('A', n3);
                menu();
                printf("\n >%f \n", n3);
            }
        }
    }
    stDestroy();
}

void main(){
    calculadora();
}


void imprime(Tipo t){
    printf("%f", t); // essa fun��o sabe quem � Tipo, no caso, um real
}
