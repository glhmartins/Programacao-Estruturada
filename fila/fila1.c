#include "fila.h"

#define MAX 4
Tipo vetor[MAX];
int pos, aux;

Logico qCreate(){
    qDestroy();
    return TRUE;
}
Logico qDestroy(){
    pos = -1;
    aux = 0;
    return TRUE;
}
Logico qIsEmpty(){
    if (pos<0) return TRUE;
    return FALSE;
}
Logico qIsFull(){
    if (pos>=(MAX-1)) return TRUE;
    return FALSE;
}
Logico qIn(Tipo e){
    if (qIsFull()) return FALSE;
    vetor[++pos] = e;
    return TRUE;
}
Logico qOut(Tipo *e){
    if (qIsEmpty()) return FALSE;
    *e = vetor[aux++];
    pos--;
    return TRUE;
}