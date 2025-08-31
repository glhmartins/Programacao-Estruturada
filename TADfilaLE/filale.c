#include "fila.h"

typedef struct node {
    Tipo e;
    struct node * next;
    struct node * previous;
} Node;

Node * primeiro;
Node * ultimo;
int count;

Logico qCreate(){
    primeiro = ultimo = NULL;
    count = 0;
    return TRUE;
}

Logico qDestroy(){
    if (primeiro!=NULL){
        Tipo e;
        qOut(&e);
        qDestroy();
    }
    primeiro = ultimo = NULL;
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
        primeiro = ultimo = (Node*) malloc(sizeof(Node));
        primeiro -> e = e;
        primeiro -> next = NULL;
        primeiro -> previous = NULL;
        count = 1;
        return TRUE;
    }
    Node * aux = (Node*) malloc(sizeof(Node));
    aux -> e = e;
    aux -> next = NULL;
    aux -> previous = ultimo;
    ultimo -> next = aux;
    ultimo = aux;
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