
#include "listaCircular.c"

void imprime(Tipo t);

char codigoTecla = 0;
void menu(){
    system("cls");
    if (codigoTecla != 0)
        printf("%d\n", codigoTecla);
    printf("Menu:\n");
    printf("digite c(cadastro) f(fim) \n");
    printf("d(delete)  \n");
    printf("ou setas dir e esq\n");
    printf("\nLista Circular:\n");
    lcPrint(); // imprimir a pilha sem modificar seu conte�do
    printf("\n\n");
}

void interacao(){
    char ch;

    lcCreate(imprime);// inicializacoes
    menu();
    while (TRUE){
        ch = getch();
        codigoTecla = ch;
        if (ch == 'f' || ch == 'e'){ // fim ou end
            break;
        } else if (ch == 'c'){
            Tipo e;
            printf("digite um nome ");
            scanf("%s", &(e.nome) );
            lcInsert(e);
            codigoTecla = 0;
        } else if (ch == 77){//right arrow
            lcNext();
            codigoTecla = 0;
        } else if (ch == 75){//left arrow
            lcPrevious();
            codigoTecla = 0;
        } else if (ch == 'd'){//left arrow
            Tipo e;
            lcDelete(&e);
            // apaguei fulano
            codigoTecla = 0;
        } else {
            codigoTecla = ch;
        }
        menu();
    } // fim while
    lcDestroy();// limpar a memoria
}

void main(){
    interacao();
}


void imprime(Tipo t){
    printf(" %s", t.nome); // essa fun��o sabe quem � Tipo, no caso, um real
}
