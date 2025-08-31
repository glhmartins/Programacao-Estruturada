// Aluno: Guilherme Martins Rangel

#include "pilhale.c"

int main(){
    printf("Teste da Pilha!\n");

    Aluno vet[] = {
        { "Ana", {8,7,0,0}, 1234567},
        { "Bia", {8,10,0,0}, 1234568},
        { "Dri", {8,10,0,0}, 1234570},
        { "Juli", {8,10,0,0}, 1234571},
        { "Edu", {9,8,0,0}, 1234569}
    };
    stCreate();
    int tamanho = sizeof(vet)/sizeof(Tipo);
    for (int i=0;i<tamanho;i++){
        if (stPush(vet[i]) == FALSE) printf("nao consegui colocar %s\n", vet[i].nome);
        else printf("Entra %s\n", vet[i].nome);
    }
    while (!stIsEmpty()){
        Tipo e;
        stPop(&e);
        printf("sai %s\n", e.nome);
    }
    stDestroy();
    return 0;
}