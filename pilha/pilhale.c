#include "pilha.h"

typedef struct node {
    Tipo e;
    struct node *next;
} Node;

Node *topo;
int count;

Logico stCreate(){
    topo = NULL;
    count = 0;
    return TRUE;
}
Logico stDestroy(){
    if (topo !=NULL){
        Tipo e;
        stPop(&e);
        stDestroy();
    }
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
        topo = (Node*) malloc(sizeof(Node));
        topo -> e = e;
        topo -> next = NULL;
        count = 1;
        return TRUE;
    }
    Node *aux = (Node *) malloc(sizeof(Node));
    aux -> e = e;
    aux -> next = topo;
    topo = aux;
    count++;
    return TRUE;
}
Logico stPop(Tipo *e){
    if (stIsEmpty()) return FALSE;
    *e = topo ->e;
    Node *aux = topo;
    topo = topo->next;
    free(aux);
    count--;
    return TRUE;
}