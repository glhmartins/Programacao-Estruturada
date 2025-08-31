#include "pilha1.c"

int main(){
    Aluno vet[] = {
        { "Ana", {8,7,0,0}, 1234567},
        { "Bia", {8,10,0,0}, 1234568},
        { "Edu", {9,8,0,0}, 1234569}
    };
    stCreate();
    int tamanho = sizeof(vet)/sizeof(Aluno);
    for (int i=0; i<tamanho; i++){
        printf("tento colocar %s\n", vet[i].nome);
        if (stPush(vet[i]) == FALSE)
            printf("fila esta cheia!\n");
    }
    while(stIsEmpty() == FALSE){
        Aluno aux;
        stPop(&aux);
        printf("saiu %s\n", aux.nome);
    }
    stDestroy();
    return 0;
}