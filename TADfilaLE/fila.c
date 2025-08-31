#include "fila.h"

typedef struct no {
    int info;
    struct no * prox;
} TNO;

TNO * ultimo;
int count;

Logico qCreate(){
    ultimo = NULL;
    count = 0;
    return TRUE;
}
Logico qDestroy(){
    if (ultimo != NULL){
        Tipo e;
        qOut(&e);
        qDestroy();
    }
    count = 0;
    return TRUE;
}
Logico qCount(int *total){
    *total = count;
    return TRUE;
}
Logico qIsEmpty(){
    if (count<=0) return TRUE;
    return FALSE;
}
Logico qIsFull(){
    return FALSE;
}
Logico qIn(Tipo e){
    if (qIsEmpty()){
        primeiro = (Node*) malloc(sizeof(Node));
        
        count = 1;
        return TRUE;
    }
    Node * aux = (Node*) malloc(sizeof(Node));
    
    count++;
    return TRUE;
}
Logico qOut(Tipo *e){
    if (qIsEmpty()) return FALSE;
    *e = primeiro -> e;
    Node * aux = primeiro;
    primeiro = primeiro -> next;
    free(aux);
    count--;
    return TRUE;
}