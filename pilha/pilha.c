#include "pilha.h"

typedef struct node{
    Tipo e;
    struct node * next;
    struct node * previous;
} Node;

Node * topo;
Node * base;
int count;

Logico stCreate(){
    topo = base = NULL;
    count = 0;
    return TRUE;
}
Logico stDestroy(){
    if (topo != NULL){
        Tipo e;
        stPop(&e);
        stDestroy();
    }
    count = 0;
    return TRUE;
}
Logico stCount(int *total){
    *total = count;
    return TRUE;
}
Logico stIsEmpty(){
    if (count<=0) return TRUE;
    return FALSE;
}
Logico stIsFull(){
    return FALSE;
}
Logico stPush(Tipo e){
    if (stIsEmpty()){
        base = topo = (Node *) malloc(sizeof(Node));
        base -> e = e;
        base -> next = NULL;
        base -> previous = NULL;
        count = 1;
        return TRUE;
    }
    Node * aux = (Node *) malloc(sizeof(Node));
    aux -> e = e;
    aux -> next = NULL;
    aux -> previous = topo;
    topo -> next = aux;
    topo = aux;
    count++;
    return TRUE;
}
Logico stPop(Tipo *e){
    if (stIsEmpty()) return FALSE;
    *e = topo -> e;
    Node * aux = topo;
    topo = topo -> previous;
    free(aux);
    count--;
    return TRUE;
}