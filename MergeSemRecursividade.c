#include <stdio.h>

int min(int x, int y){return (x<y)? x:y;}

void merge(int vet[], int inicio, int meio, int fim){
    int i, j, k = inicio, n1 = meio-inicio+1, n2 = fim-meio;
    int L[n1], R[n2];
    for (i = 0; i<n1; i++){
        L[i] = vet[i+inicio];
    }
    for (j = 0; j<n2; j++){
        R[j] = vet[j+meio+1];
    }
    i = j = 0;
    while (i<n1 && j<n2){
        if(L[i]<=R[j]){
            vet[k++] = L[i++];
        } else {
            vet[k++] = R[j++];
        }
    }
    while (i<n1){
        vet[k++] = L[i++];
    }
    while (j<n2){
        vet[k++] = R[j++];
    }
}

void mergesort(int vet[], int size){
    int aux, inicio;
    for (aux = 1; aux<size; aux *= 2){
        for (inicio = 0; inicio<size-1; inicio += 2*aux){
            int meio = min(aux+inicio-1,size-1);
            int fim = min(inicio + 2*aux-1,size-1);
            merge(vet, inicio, meio, fim);
        }
    }
}

int main(){
    int lista[] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30}, tamanho;
    tamanho = sizeof(lista)/sizeof(lista[0]);
    mergesort(lista, tamanho);
    for (int i = 0; i<tamanho; i++){
        printf("%d ", lista[i]);
    } 
    return 0;
}