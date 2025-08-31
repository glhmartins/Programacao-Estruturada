#include "listaCircular.h"

typedef struct node {
    Tipo e;
    struct node * next;
    struct node * previous;
} Node;

Node * current;
int count;
funcaoDeForaQueImprime fun;
Logic fezGravacao;
char nomeArquivo[] = {"listaCircular.bin"};

void grava(char *filename){
    if (count <=0) {
        remove(filename);
        return;
    }
    FILE *fp;
    fp = fopen(filename, "wb");// abre para "write"
    Node *cur = current -> next;
    //cur = cur->next;
    while (cur != current){
        Tipo m = cur->e;
        fwrite(&m, sizeof(Tipo), 1, fp);
        cur = cur->next;
    }
    Tipo m = current->e;// grava current por ultimo
    fwrite(&m, sizeof(Tipo), 1, fp);
    fclose(fp);
}

void recupera(char *filename){
    FILE *fp;
    fp = fopen(filename, "rb");// abre para "read"
    if (fp == NULL) return;
    while (!feof(fp)){
        Tipo m;
        int itensLidos = fread(&m, sizeof(Tipo), 1, fp);
        if (itensLidos != 1) break;
        lcInsert(m);
    }
    fclose(fp);
}

Logic lcCurrent(Tipo *e){
    if (lcIsEmpty()) return FALSE;
    *e = current->e;
    return TRUE;
}// retorna o elemento corrente da lista circular

Logic lcInsert(Tipo e){
    if (current == NULL){
        current = (Node * ) malloc(sizeof(Node));
        current->e = e;
        current->next = current->previous = current;
        count = 1;
        return TRUE;
    }
    Node * novo = (Node *) malloc(sizeof(Node));
    Node * anterior = current;
    Node * proximo = current->next;
    novo->e = e;
    novo->next = proximo;
    novo->previous = anterior;
    anterior->next = novo;
    proximo->previous = novo;
    current = novo;
    count++;
    return TRUE;
}// inserir elemento apos o corrente

Logic lcDelete(Tipo *e){
    if (current == NULL) return FALSE;
    *e = current->e; // ou *e = (*current).e;
    Node * proximo = current->next;
    Node * anterior = current->previous;
    free(current);
    count--;
    if (count <= 0){ // caso do ultimo elemento
        current = NULL;
        count = 0; // s� por seguran�a, mas n�o ser� negativo
        return TRUE;
    }
    current = proximo;// apos remocao o corrente ser� o pr�ximo
    anterior->next = proximo; // o anterior aponta para o proximo
    current->previous = anterior;// o anterior do corrente ser� o antigo anterior
    return TRUE;
} // remove elemento corrente, retornando-o opcionalmente

Logic lcCount(int *total){
    *total = count;
    return TRUE;
} //retorna o total de elementos da lista circular

Logic lcCreate(funcaoDeForaQueImprime f){ // inicializacoes
    current = NULL;
    count = 0;
    fun = f;
    fezGravacao = FALSE;
    recupera(nomeArquivo);
    return TRUE;
}

Logic lcDestroy(){ // limpar a memoria
    if (fezGravacao == FALSE){
        grava(nomeArquivo); // para nao gravar mais de uma vez
        fezGravacao = TRUE;
    }
    if (!lcIsEmpty()){
        Tipo e;
        lcDelete(&e);
        //fun(e); // imprime para depuracao
        lcDestroy();
    }
    return TRUE;
}

Logic lcIsFull(){
    return FALSE;
}// saber se est� cheio

Logic lcIsEmpty(){
    if (count <= 0) return TRUE;
    return FALSE;
}// saber se est� vazio

Logic lcNext(){
    if (current == NULL) return FALSE;
    current = current->next;
    return TRUE;
}// muda o corrente para o proximo

Logic lcPrevious(){
    if (current == NULL) return FALSE;
    current = current->previous;
    return TRUE;
}// muda o corrente para o anterior


Logic lcPrint(){
    Node *p1 = current;
    printf("(%i)current->", count);
    if (current == NULL){
        printf("NULL");
        return TRUE;
    }
    while (p1 != NULL){
        printf("[");
        fun(p1->e);// o mundo exterior vai imprimir
        printf("]->");
        p1 = p1->next;
        if (p1 == current || p1 == NULL) break; 
    }
    printf("current\n");
    return TRUE;
}