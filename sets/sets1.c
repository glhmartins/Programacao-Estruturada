#include "sets.h"

typedef struct node{
    Tipo e;
    struct node * next;
} Node;

#define MAX_SETS ('Z'-'A'+1)
Node *vetListas[MAX_SETS];
funcaoDeForaQueCompara comparador;
funcaoDeForaQueImprime impri;

int mapa(char c1){
    if (c1>='A' && c1<='Z') return (int) (c1-'A');
    return -1;
}

Logic freeSet(char c){
    int ix = mapa(c);
    if (c<0) return FALSE;
    Node *p = vetListas[ix];
    if (p!=NULL){
        Node * aux = p;
        p = p-> next;
        free(aux);
        freeSet(c);
    }
    vetListas[ix] = NULL;
    return TRUE;
}

Logic setsPrint(char letra, funcaoDeForaQueImprime impri){
    int ix = mapa(letra);
    if (ix < 0) return FALSE;
    Node *p1;
    p1 = vetListas[ix];

    printf("set(%c)->", letra);
    while (p1 != NULL){
        printf("[");
        Tipo aux = p1->e;
        impri(aux);// o mundo exterior vai imprimir
        printf("]->");
        p1 = p1->next;
    }
    printf("NULL\n");
    return TRUE;
}

Logic setsCreate(funcaoDeForaQueCompara c, funcaoDeForaQueImprime i){
    comparador = c;
    impri = i;
    for (int i = 0; i<MAX_SETS; i++){
        vetListas[i] = NULL;
    }
    return TRUE;
}

Logic setsDestroy(){
    char c = 'A';
    while (c<='Z'){
        freeSet(c);
        c++;
    }
    return TRUE;
}

Logic setsBelongsTo(char c1, Tipo e){
    int ix = mapa(c1);
    if (ix<0) return FALSE;
    Node * p = vetListas[ix];
    while (p != NULL){
        if (p->e == e) return TRUE;
        p = p -> next;
    }
    return FALSE;
}

Logic setsIsIn(char c1, char c2, Logic *result){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    if (ix1 < 0 || ix2 < 0) return FALSE;
    int elementos = 0, iguais = 0;
    setsNumberOfElements(c1, &elementos);
    Node * p1 = vetListas[ix1];
    Node * p2 = vetListas[ix2];
    while (p1 != NULL && p2 != NULL){
        Tipo e1 = p1 -> e;
        Tipo e2 = p2 -> e;
        Result res = comparador(e1, e2);
        if (res == EQUAL){
            iguais++;
            p1 = p1 -> next;
            p2 = p2 -> next;
        } else if (res == LT){
            p1 = p1 -> next;
        } else {
            p2 = p2 -> next;
        }
    }
    if (elementos == iguais) *result = TRUE;
    else *result = FALSE;
    return TRUE;
}

Logic setsNumberOfElements(char c1, int *total){
    int ix = mapa(c1);
    if (ix<0) return FALSE;
    *total = 0;
    Node *p = vetListas[ix];
    while (p!=NULL){
        p = p->next;
        *total += 1;
    }
    return TRUE;
}

Logic setsDifference(char c1, char c2, char c3){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    int ix3 = mapa(c3);
    if (ix1<0 || ix2<0 || ix3<0) return FALSE;
    freeSet(c3);
    Node *p1 = vetListas[ix1];
    Node *p2 = vetListas[ix2];
    while(p1 != NULL && p2 != NULL){
        Tipo e1 = p1 -> e;
        Tipo e2 = p2 -> e;
        Result res = comparador(e1, e2);
        if (res == EQUAL){
            p1 = p1 -> next;
            p2 = p2 -> next;
        } else if (res == GT){
            p2 = p2 -> next;
        } else {
            setsAddElement(c3, e1);
            p1 = p1 -> next;
        }
    }
    while (p1 != NULL){
        Tipo e = p1 -> e;
        setsAddElement(c3, e);
        p1 = p1 -> next;
    }
    return TRUE;
}

Logic setsUnion(char c1, char c2, char c3){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    int ix3 = mapa(c3);
    if (ix1 < 0 || ix2 < 0 || ix3 < 0) return FALSE;
    freeSet(c3);
    Node *p1 = vetListas[ix1];
    Node *p2 = vetListas[ix2];
    while (p1 != NULL && p2 != NULL){
        Tipo e1 = p1 -> e;
        Tipo e2 = p2 -> e;
        Result res = comparador(e1, e2);
        if (res == EQUAL){
            setsAddElement(c3, e1);
            p1 = p1 -> next;
            p2 = p2 -> next;
        } else if (res == LT){
            setsAddElement(c3, e1);
            p1 = p1 -> next;
        } else {
            setsAddElement(c3, e2);
            p2 = p2 -> next;
        }
    }
    while (p1 != NULL){
        setsAddElement(c3, p1 -> e);
        p1 = p1 -> next;
    }
    while (p2 != NULL){
        setsAddElement(c3, p2 -> e);
        p2 = p2 -> next;
    }
    return TRUE;
}

Logic setsIntersection(char c1, char c2, char c3){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    int ix3 = mapa(c3);
    if (ix1 < 0 || ix2 < 0 || ix3 < 0 ) return FALSE;
    freeSet(c3);
    Node *p1 = vetListas[ix1];
    Node *p2 = vetListas[ix2];
    while (p1 != NULL && p2 != NULL){
        Tipo e1 = p1 -> e;
        Tipo e2 = p2 -> e;
        Result res = comparador(e1, e2);
        if (res == EQUAL){
            setsAddElement(c3, e1);
            p1 = p1 -> next;
            p2 = p2 -> next;
        } else if (res == LT){
            p1 = p1 -> next;
        } else {
            p2 = p2 -> next;
        }
    }
    return TRUE;
}

Logic setsAddElement(char c1, Tipo e){
    int ix = mapa(c1);
    if (ix < 0) return FALSE;
    Node *p = vetListas[ix];
    if (p == NULL){
        Node *aux = (Node*) malloc(sizeof(Node));
        aux -> e = e;
        aux -> next = NULL;
        vetListas[ix] = aux;
        return TRUE;
    }
    Node *anterior = NULL;
    while (p != NULL){
        Result res = comparador(e, p -> e);
        if (res == EQUAL) return TRUE;
        else if (res == LT){
            Node * aux = (Node*) malloc(sizeof(Node));
            aux -> next = NULL;
            aux -> e = e;
            if (anterior == NULL){
                aux -> next = vetListas[ix];
                vetListas[ix] = aux;
                return TRUE;
            }
            anterior -> next = aux;
            aux -> next = p;
            return TRUE;
        } 
        anterior = p;
        p = p->next;
    }
    Node * aux = (Node*) malloc(sizeof(Node));
    aux -> next = NULL;
    aux -> e = e;
    anterior -> next = aux;
    return TRUE;
}

Logic setsRemoveElement(char c1, Tipo e){
    int ix = mapa(c1);
    if (ix < 0) return FALSE;
    Node *p = vetListas[ix];
    if (p == NULL) return FALSE;
    Node *anterior = NULL;
    while (p != NULL){
        Result res = comparador(e, p -> e);
        if (res == EQUAL){
            Node * aux = p;
            p = p -> next;
            anterior -> next = p;
            free(aux);
            return TRUE;
        } else if (res == LT){
            return FALSE;
        } else {
            anterior = p;
            p = p-> next;
        }
    }
}