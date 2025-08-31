#include "sets1.c"
// TAD de conjuntos


// observe que a fun��o aqui, no mundo da aplicacao
// sabe quem � Tipo e pode fazer a comparacao desejada
// Ex: comparacao de nomes de alunos, de n�meros, de precos de mercadorias etc
Result compareTo(Tipo a, Tipo b){
    if (a > b) return GT;
    if (a == b) return EQUAL;
    return LT;
}

void imprime(Tipo t){
    printf("%i", t); // essa fun��o sabe quem � Tipo, no caso, um inteiroe
}


char conjuntoCorrente = 'A';
char conjuntosExibidos[]= {'A', 'B', 'C', 'D'};
void defineOrdemExibicaoConjuntos(){
    int tamanho = sizeof(conjuntosExibidos)/sizeof(char);
    int ix = -1;
    for (int i=0;i<tamanho;i++){
        if (conjuntoCorrente == conjuntosExibidos[i]){
            ix = i;
            break;
        }
    }
    if (ix==-1){
        for (int i=tamanho-1;i>0;i--){
            // cai de prioridade na lista
            conjuntosExibidos[i]=conjuntosExibidos[i-1];
        }
    } else {
        for (int i=ix;i>=0;i--){
            // cai de prioridade na lista
            conjuntosExibidos[i]=conjuntosExibidos[i-1];
        }
    }
    conjuntosExibidos[0]=conjuntoCorrente;
}
void menu(){
    system("cls");

    defineOrdemExibicaoConjuntos();
    printf("Menu (m)\n");
    printf("Type int numbers followed by enter to add to current set\n");
    printf("Operations: \n");
    printf("e: end\n");
    //printf("b:");
    printf("c: %c is contained in %c\n", conjuntosExibidos[1], conjuntosExibidos[0]);
    printf("r: remove element in %c\n", conjuntosExibidos[0]);
    printf("d: %c difference %c -> %c\n", conjuntosExibidos[0], conjuntosExibidos[1], conjuntosExibidos[2]);
    printf("i: %c intersection %c -> %c\n", conjuntosExibidos[0], conjuntosExibidos[1], conjuntosExibidos[2]);
    printf("u: %c union %c -> %c\n", conjuntosExibidos[0], conjuntosExibidos[1], conjuntosExibidos[2]);
    printf("define first (current) set: A..Z \n");
    printf("current set: %c\n", conjuntoCorrente);
    printf("\nSets:\n");
    int tamanho = sizeof(conjuntosExibidos)/sizeof(char);
    for (int i=0;i<tamanho;i++){
        int total=0;
        setsNumberOfElements(conjuntosExibidos[i], &total);
        printf("total %d ", total);
        setsPrint(conjuntosExibidos[i], imprime); // imprimir o conjunto
    }
    printf("\n\n");
}

void conjuntos(){
    char ch;
    char strNumero[100];
    int algarismo=0;

    setsCreate(compareTo, imprime);
    menu();
    while (TRUE){
        char cA=conjuntosExibidos[0], cB=conjuntosExibidos[1], cC=conjuntosExibidos[2];
        ch = getche();
        if (ch == 'e'){
            break;
        } else if (((ch >= '0') && (ch <= '9')) || (ch == '.')){
            strNumero[algarismo++] = ch;
        } else if (ch  == 'm'){
            menu();
        } else if (ch == 13){ // enter
            strNumero[algarismo] = '\0';// terminador de string
            Tipo num = atoi(strNumero);
            //printf("\n%i\n",num);
            if (num != 0)
                setsAddElement(conjuntoCorrente, num);
            algarismo = 0;
            menu();
        } else if (ch == 'u'){
            // TODO operacoes
            setsUnion(cA, cB, cC);
            menu();
        } else if (ch == 'c'){
            Logic contained;
            setsIsIn(cB, cA, &contained);
            menu();
            if (contained == TRUE) printf("TRUE\n");
            else printf("FALSE\n");
        } else if (ch >= 'A' && ch <= 'Z'){
            conjuntoCorrente = ch;
            menu();
        } else if (ch == 'i'){
            setsIntersection(cA, cB, cC);
            menu();
        } /*else if (ch == 'p'){
            if (setsBelongsTo(cA, e) == TRUE) printf("yes\n");
            else printf("No\n");
            menu();
        }*/ else if (ch == 'd'){
            setsDifference(cA, cB, cC);
            menu();
        } else if (ch == 'r'){
            Tipo e;
            scanf("%d", &e);
            setsRemoveElement(cA, e);
            menu();
        }
    }
    setsDestroy();
}

int main(){
    conjuntos();
}