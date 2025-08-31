// Aluno: Guilherme Martins Rangel

#include "Fila.c"

int main(){
    printf("Teste da Fila!\n");

    Aluno vet[] = {
        { "Ana", {8,7,0,0}, 1234567},
        { "Bia", {8,10,0,0}, 1234568},
        { "Dri", {8,10,0,0}, 1234570},
        { "Juli", {8,10,0,0}, 1234571},
        { "Edu", {9,8,0,0}, 1234569}
    };
    qCreate();
    int tamanho = sizeof(vet)/sizeof(Tipo);
    for (int i=0;i<tamanho;i++){
        if (qIn(vet[i]) == FALSE) printf("nao consegui colocar %s\n", vet[i].nome);
        else printf("Entra %s\n", vet[i].nome);
    }
    while (!qIsEmpty()){
        Tipo e;
        qOut(&e);
        printf("sai %s\n", e.nome);
    }
    qDestroy();
    return 0;
}