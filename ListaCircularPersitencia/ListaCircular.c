#include "listaCircular.h"

typedef struct node {
    Tipo e;
    struct node * next;
    struct node * previous;
} Node;

Node * current;
int count;
FunctionOutside fun;
Logic fezgravacao;
char arquivo[] = "ListaCircular.bin";

void guarda(char *filename){
    if (count<=0){
        remove(filename);
        return;
    }
    FILE *f;
    f = fopen(filename, "wb");
    Node * cur = current -> next;
    while (cur != current){
        Tipo m = cur -> e;
        fwrite(&m, sizeof(Tipo), 1, f);
        cur = cur -> next;
    }
    Tipo m = current -> e;
    fwrite(&m, sizeof(Tipo), 1, f);
    fclose(f);
    return TRUE;
}

void recupera(char *filename){
    FILE *f;
    f = fopen(filename, "rb");
    if (f == NULL) return;
    while(!feof(f)){
        Tipo m;
        int lidos = fread(&m, sizeof(Tipo), 1, f);
        if (lidos != 1) break;
        lcInsert(m);
    }
    return TRUE;
}

Logic lcCreate(FunctionOutside i){
    current = NULL;
    count = 0;
    fezgravacao = FALSE;
    fun = i;
    recupera(arquivo);
    return TRUE;
}

Logic lcDestroy(){
    if (fezgravacao == FALSE){
        fezgravacao = TRUE;
        guarda(arquivo);
    }
    if (!lcIsEmpty()){
        Tipo e;
        lcDelete(&e);
        lcDestroy();
    }
    count = 0;
    return TRUE;
}

Logic lcCount(int *total){
    *total = count;
    return TRUE;
}

Logic lcCurrent(Tipo *e){
    if (lcIsEmpty()) return FALSE;
    *e = current -> e;
    return TRUE;
}

Logic lcNext(){
    if (lcIsEmpty()) return FALSE;
    current = current -> next;
    return TRUE;
}

Logic lcPrevious(){
    if (lcIsEmpty()) return FALSE;
    current = current -> previous;
    return TRUE;
}

Logic lcIsEmpty(){
    if(count<=0) return TRUE;
    return FALSE;
}

Logic lcIsFull(){
    return FALSE;
}

Logic lcPrint(){
    Node *p;
    p = current;
    printf("(%d)current -> ");
    if (current == NULL){
        prinf("NULL");
        return TRUE;
    }
    while (p != NULL){
        printf("[");
        Tipo aux = p -> e;
        fun(aux);
        printf("]");
        p = p -> next;
        if (p == current || p == NULL) break;
    }
    return TRUE;
}

Logic lcInsert(Tipo e){
    if (lcIsEmpty()){
        current = (Node*) malloc(sizeof(Node));
        current -> e = e;
        current -> next = current;
        current -> previous = current;
        count = 1;
        return TRUE;
    }
    Node * aux = (Node*) malloc(sizeof(Node));
    Node * proximo = current -> next;
    Node * anterior = current;
    aux -> e = e;
    aux -> next = proximo;
    aux -> previous = anterior;
    anterior -> next = aux;
    proximo -> previous = aux;
    current = aux;
    count++;
    return TRUE;
}

Logic lcDelete(Tipo *e){
    if (lcIsEmpty()) return FALSE;
    *e = current -> e;
    Node * proximo = current -> next;
    Node * anterior = current -> previous;
    free(current);
    count--;
    if (count<=0){
        current = NULL;
        count = 0;
        return TRUE;
    }
    current = proximo;
    proximo -> previous = anterior;
    anterior -> next = proximo;
    return TRUE;
}