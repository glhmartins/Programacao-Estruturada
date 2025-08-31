// Aluno: Guilherme Martins Rangel

#include "Fila.h"

typedef struct node {
    Tipo e;
    struct node * next;
} Node;

Node * first;
Node * last;

int count;

Logico qIn(Tipo e){
    if (qIsEmpty()){
        first = last = malloc(sizeof(Node));
        last -> e = e;
        last -> next = NULL;
        count = 1;
        return TRUE; 
    }
    count++;
    Node *aux = malloc(sizeof(Node));
    aux -> e = e;
    aux -> next = NULL; 
    last -> next = aux;
    last = aux;
    return TRUE;
}
Logico qOut(Tipo *e){
    if (qIsEmpty()) return FALSE;
    *e = first -> e;
    Node *aux = first;
    first = first -> next;
    free(aux);
    count--;
    if (count == 0) {
        first = last = NULL;
    }
    return TRUE;
}

Logico qCreate(){
    qDestroy();
    return TRUE;
}
Logico qDestroy(){
    while (first != NULL){
        Node *aux = first;
        first = first -> next;
        free(aux);
    }
    count = 0;
    first = last = NULL;
    return TRUE;
}
Logico qIsFull(){
    return FALSE;
}
Logico qIsEmpty(){
    if (count == 0)
        return TRUE;
    return FALSE;
}
Logico qCount(int *total){
    *total = count;
    return TRUE;
}