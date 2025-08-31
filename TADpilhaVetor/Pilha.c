#include "Pilha.h"

#define MAX 4
Tipo vetorPilha[MAX];
int posicao;

Logico stCreate(){
    posicao = -1;
    return TRUE;
}
Logico stDestroy(){
    posicao = -1;
    return TRUE;
}
Logico stIsFull(){
    if (posicao >= (MAX-1)) return TRUE;
    return FALSE;
}
Logico stIsEmpty(){
    if (posicao < 0) return TRUE;
    return FALSE;
}
Logico stPush(Tipo e){
    if (stIsFull()) return FALSE;
    vetorPilha[++posicao] = e;
    return TRUE;
}
Logico stPop(Tipo *e){
    if (stIsEmpty()) return FALSE;
    *e = vetorPilha[posicao--];
    return TRUE;
}