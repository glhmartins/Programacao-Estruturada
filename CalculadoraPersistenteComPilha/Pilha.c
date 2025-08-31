#include "Pilha.h"

// implementacao de Pilha usando lista encadeada
typedef struct node {
    Tipo conteudo;
    struct node *next;
} Node;


void grava(char *filename, Node *p);
void recupera(char *filename, int ix);
// completar com toda a API restante
// Application Program interface

// tenho as pilhas de A a Z
#define TAM ('Z'-'A'+1)
Node *pPilha[TAM];  // vetor de pilhas feitas por listas encadeadas
int pCount[TAM]; // conta quantos itens tem em cada pilha

int mapa(char letra){
    return (int) (letra - 'A');
}

// nao faz parte da interface publica da TAD
void libera(Node *p){ // fazer recursivamente
    if (p == NULL)
        return;
    //Node *aux = p; Nem � necess�rio variavel auxiliar
    libera(p->next);
    free(p); // free (aux)
    return;
}

Logico stPrint(char letra, funcaoDeForaQueImprime fun){
    int ix = mapa(letra);
    if(ix < 0 || ix >= TAM) return FALSE;
    Node *p1;
    p1 = pPilha[ix];

    printf("pilha(%c)->", letra);
    while (p1 != NULL){
        printf("[");
        //printf("%i", p1->conteudo);// nao esta certo
        Tipo aux = p1->conteudo;
        fun(aux);// o mundo exterior vai imprimir
        printf("]->");
        p1 = p1->next;
    }
    printf("NULL\n");
    return TRUE;
}


Logico stCreate(){
    for(int i=0;i<TAM;i++){
        libera(pPilha[i]);// estou liberando uma lista, um ponteiro por vez
        pPilha[i] = NULL; // zerar elemento a elemento do vetor de conjuntod
        pCount[i] = 0;
        char letra = 'A' + i;
        char filename[80];
        sprintf(filename, "set%c.bin", letra );
        recupera(filename, i);
    }
    return TRUE;
}

Logico stDestroy(){
    for(int i=0;i<TAM;i++){
        char filename[80];
        sprintf(filename, "set%c.bin", 'A'+i );
        //printf("gravou %s\n", filename);
        grava(filename, pPilha[i]);
        libera(pPilha[i]);// estou liberando uma lista, um ponteiro por vez
        pPilha[i] = NULL; // zerar elemento a elemento do vetor de conjuntod
        // uma coisa � liberar a lista outra � zerar o vetor de ponteiros por seguranca
        pCount[i] = 0;
    }
    return TRUE;
}

Logico stIsFull(char letra){
    return FALSE;// em geral sempre FALSE
}// pilha ta cheia ou nao?

Logico stIsEmpty(char letra){
    int ix = mapa(letra);
    if(ix < 0 || ix >= TAM) return FALSE;
    if (pPilha[ix] == NULL)
        return TRUE;
    return FALSE;
}// pilha ta vazia ou nao?

Logico stPush(char letra, Tipo c){
    int ix = mapa(letra);
    if(ix < 0 || ix >= TAM) return FALSE;
    // primeiro preciso alocar o node
    //printf("tamanho alocado=%i\n", sizeof(Node));
    Node *aux = (Node *) malloc(sizeof(Node));
    aux->conteudo = c;
    aux->next = pPilha[ix];
    pPilha[ix] = aux;
    pCount[ix]++;
    return TRUE;
}

Logico stPop(char letra, Tipo * c){
    int ix = mapa(letra);
    if(ix < 0 || ix >= TAM) return FALSE;
    if (!stIsEmpty(letra)){
        *c = pPilha[ix]->conteudo;
        Node *aux = pPilha[ix];
        pPilha[ix] = pPilha[ix]->next;
        // liberar a memoria que nao interessa mais
        free(aux);
        pCount[ix]--;
        return TRUE;
    }
    return FALSE;
}

Logico stCount(char letra, int *total){
    int ix = mapa(letra);
    *total = 0;
    if(ix < 0 || ix >= TAM) return FALSE;
    *total = pCount[ix];
    return TRUE;
}

void grava(char *filename, Node *p){
    if (p == NULL) {
        remove(filename);
        return;
    }
    FILE *fp;
    fp = fopen(filename, "wb");// abre para "write"
    while (p != NULL){
        Tipo m = p->conteudo;
        //printf("grava %f\n", m);
        fwrite(&m, sizeof(Tipo), 1, fp);
        p = p->next;
    }
    fclose(fp);
}


void recupera(char *filename, int ix){
    FILE *fp;
    fp = fopen(filename, "rb");// abre para "read"
    if (fp == NULL) return;
    Node *p=NULL;
    pPilha[ix] = NULL;
    while (!feof(fp)){
        Tipo m;
        int itensLidos = fread(&m, sizeof(Tipo), 1, fp);
        if (itensLidos != 1)
            break;
        //printf("leu %f\n", m);
        Node *aux = (Node *) malloc (sizeof(Node));
        aux->conteudo = m;
        aux->next = NULL;
        if (pPilha[ix] == NULL){
            pPilha[ix] = aux;
        } else {
            p->next = aux;
        }
        p = aux;
    }
    fclose(fp);
}