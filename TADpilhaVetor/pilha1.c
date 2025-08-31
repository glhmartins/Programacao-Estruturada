#include "pilha.h"

#define MAX 4
Tipo vet[MAX];
int pos;

Logico stCreate(){
    stDestroy();
    return TRUE;
}
Logico stDestroy(){
    pos = -1;
    return TRUE;
}
Logico stIsEmpty(){
    if (pos<0) return TRUE;
    return FALSE;
}
Logico stIsFull(){
    if (pos>= (MAX-1)) return TRUE;
    return FALSE;
}
Logico stPush(Tipo e){
    if (stIsFull()) return FALSE;
    vet[++pos] = e;
    return TRUE;
}
Logico stPop(Tipo *e){
    if (stIsEmpty()) return FALSE;
    *e = vet[pos--];
    return TRUE;
}