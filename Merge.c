#include <stdio.h>
#include <stdlib.h>

void merge(int vet[], int inicio, int meio, int fim, int* count){
    int i = inicio, j = meio+1, k = 0, aux[fim-inicio+1];
    while (i<=meio && j<=fim){
        if (vet[i]<=vet[j]) aux[k++] = vet[i++];
        } else {
            aux[k++] = vet[j++];
            (*count)++;
        }
    }
    while (i<=meio){
        aux[k++] = vet[i++];
    }
    while (j<=fim){
        aux[k++] = vet[j++];
    }
    for (k = inicio; k<=fim; k++){
        vet[k] = aux[k-inicio];
    }
}

void mergesort(int vet[], int inicio, int fim, int *count){
    if (inicio<fim){
        int meio = (inicio+fim)/2;
        mergesort(vet, inicio, meio, count);
        mergesort(vet, meio+1, fim, count);
        merge(vet, inicio, meio, fim, count);
    }
}

int main(){
    int lista[] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30}, tamanho;
    tamanho = sizeof(lista)/sizeof(lista[0]);
    mergesort(lista, 0, tamanho);
    for (int i = 0; i<tamanho; i++){
        printf("%d ", lista[i]);
    } 
    return 0;
}