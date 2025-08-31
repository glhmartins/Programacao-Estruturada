#include <stdio.h>
#include <stdlib.h>

//typedef int Tipo;
//*
typedef struct aluno {
    char nome[80];
    long cpf;
    float notas[2];
} Tipo;
//*/

#define MENOR -1
#define MAIOR 1
#define IGUAL 0

typedef int (*funcaoComparacao)(Tipo, Tipo) ; // pense para que serve isso?
void mergeSort(Tipo *vet, int a, int b); // prototipo da fun��o

/* // para comparar numeros inteiros
int compara(Tipo x, Tipo y){
    if (x>y) return MAIOR;
    if (x<y) return MENOR;
    return IGUAL;
}
//*/

//* // para comparar nomes de alunos
int compara(Tipo x, Tipo y){
    if (strcmp(x.nome, y.nome)>0) return MAIOR;
    if (strcmp(x.nome, y.nome)<0) return MENOR;
    return IGUAL;
}
//*/

void merge(Tipo *vet, int a, int m, int b){
    if (b <= a) return; // um elemento, nada a fazer
    if ((b - a) == 1) { // caso de dois elementos
        if (compara(vet[a], vet[b]) == MAIOR){
            Tipo aux = vet[a];
            vet[a] = vet[b];
            vet[b] = aux;
        }
        return;
    }
    int tamanho = b-a+1;
    int esq = a, dir = m+1;
    Tipo vetAux[tamanho];
    int iAux=0;
    while (esq<=m && dir<=b){
        if (compara(vet[esq], vet[dir]) == MENOR){
            vetAux[iAux] = vet[esq];
            iAux++; esq++;
        } else if (compara(vet[esq], vet[dir]) == MAIOR){
            vetAux[iAux] = vet[dir];
            iAux++; dir++;
        } else {
            vetAux[iAux] = vet[dir]; // sao iguais
            iAux++; dir++;
            vetAux[iAux] = vet[esq]; // copia os dois
            iAux++; esq++;
        }
    }
    // o que sobrou � esquerda
    while (esq <= m){
        vetAux[iAux] = vet[esq];
        iAux++; esq++;
    }
    // o que sobrou � direita
    while (dir <= b){
        vetAux[iAux] = vet[dir];
        iAux++; dir++;
    }
    // copia de vetAux para vet
    for (int i=0; i< tamanho; i++){
        vet[i+a] = vetAux[i];
    }
}

typedef int logico;
#define TRUE 1
#define FALSE 0

void bubbleSort(Tipo vet[], int tamanho){
    // ordenando crescentemente
    logico trocou = TRUE;
    while (trocou){
        trocou = FALSE;// aposto que est� em ordem, ser�?
        for(int i=0;i<(tamanho-1);i++){// vou at� o penultimo
            if (compara(vet[i], vet[i+1]) == MAIOR){
                trocou = TRUE;
                Tipo aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }
}

#define MAX 50000
int main(){
    srand(time(NULL));
    Tipo vet[MAX] = {3,4,1,2,7,6,5,0} ;
    for (int k=0;k<MAX;k++){
        vet[k] = rand()%MAX; // gera inteiros aleat�rios
    }
    Tipo vet[] = {
        {"Juliana", 100, {8,9}}, // nome. cpf e notas AV1 e AV2
        {"Ze", 101, {7,9}},
        {"Ana", 201, {8,10}},
        {"Bia", 202, {10,9}},
        {"Edu", 402, {7,9}},
        {"Joao", 302, {7,9}},
        {"Zulmira", 802, {7,9}},
        {"Pedro", 702, {9,9}}
    } ;
    //*/
    int tamanho = sizeof(vet)/sizeof(Tipo);
    merge(vet, 0, 1, 3);// intercala��o de parte do vetor apenas
    //bubbleSort(vet, tamanho); // ordena��o ruim (O(N2))
    mergeSort(vet, 0, tamanho-1); // ordena��o boa (O(N*logN))
    for (int i=0; i< tamanho; i++){
        if (i < 10 || i > (tamanho-10)){
            printf("v[%i]=%i\n", i, vet[i]); // Tipo int
            //printf("%i=%s\n", i, vet[i].nome); // Tipo aluno
        }
    }
    printf("\nacabou\n");
    return 0;
}





















void mergeSort(Tipo *vet, int a, int b){
    if (a<b){
        int m = a + (b-a)/2;
        mergeSort(vet, a, m);
        mergeSort(vet, m+1, b);
        merge(vet, a,m,b);
    }
}

