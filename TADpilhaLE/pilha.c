// Aluno: Guilherme Martins Rangel

#include "pilha.h"

typedef struct node {
    Tipo e;
    struct node * next;
} Node;

Node * top;
Node * base;

int count;

Logico stPush(Tipo e){
    if (stIsEmpty()){
        top = base = malloc(sizeof(Node));
        base -> e = e;
        base -> next = NULL;
        count = 1;
        return TRUE; 
    }
    count++;
    Node *aux = malloc(sizeof(Node));
    aux -> e = e;
    aux -> next = NULL; 
    top -> next = aux;
    top = aux;
    return TRUE;
}
Logico stPop(Tipo *e){
    if (stIsEmpty()) return FALSE;
    *e = top -> e;
    Node *aux = top;
    Node *temp = base;
    while ((temp -> next) != top && count > 1){ // While percorre os Nodes da base da pilha até o Node anterior ao topo da pilha que é o top
        temp = temp -> next;
    }
    top = temp;
    free(aux);
    count--;
    if (count == 0) {
        top = base = NULL;
    }
    return TRUE;
}

Logico stCreate(){
    stDestroy();
    return TRUE;
}
Logico stDestroy(){
    while (top != NULL){
        Node *aux = top;
        top = top -> next;
        free(aux);
    }
    count = 0;
    top = base = NULL;
    return TRUE;
}
Logico stIsFull(){
    return FALSE;
}
Logico stIsEmpty(){
    if (count == 0)
        return TRUE;
    return FALSE;
}
Logico stCount(int *total){
    *total = count;
    return TRUE;
}