#include "sets.h"

typedef struct node {
    Tipo e;
    struct node * next;
} Node;

#define MAX_SETS ('Z'-'A'+1)
Node * vetListas[MAX_SETS]; // as listas correspondem �s 26 letras do alfabeto
// cada lista manter� os elementos em ordem (alfab�tica, num�rica etc) para
// facilitar a pesquisa

funcaoDeForaQueCompara comparador;
funcaoDeForaQueImprime impri;

Logic setsCreate(funcaoDeForaQueCompara fc, funcaoDeForaQueImprime impr){
    comparador = fc;
    impri = impr;
    for(int i=0;i<MAX_SETS;i++){
        vetListas[i] = NULL;
    }
    return TRUE;
}

int mapa(char c){ // funcao interna para mapear caracter para indice do vetor de listas
    if (c >= 'A' && c <= 'Z')
        return (int) (c - 'A');
    return -1; // indice invalido
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

Logic setsAddElement(char c1, Tipo e){
    int ix = mapa(c1);
    if (ix < 0) return FALSE;
    Node *pInicio = vetListas[ix];
    if (pInicio == NULL){
        Node *aux = (Node *) malloc(sizeof(Node));
        aux->next = NULL;
        aux->e = e;
        vetListas[ix] = aux;
        return TRUE;
    }

    // caso geral come�a aqui: percorrer a lista e inserir ordenado
    Node *pAnterior = NULL;
    while (pInicio != NULL){
        Result r = comparador(e, pInicio->e);
        if ( r == LT){
            // aloquei e populei o Node
            Node *aux = (Node *) malloc(sizeof(Node));
            aux->next = NULL;
            aux->e = e;
            if (pAnterior == NULL){
                // primeiro da lista
                aux->next = vetListas[ix];
                vetListas[ix] = aux;
                return TRUE;
            }
            pAnterior->next = aux;
            aux->next = pInicio;
            return TRUE;
        } else if ( r == EQUAL){
            // j� tem o elemento
            return TRUE;
        } else { // GT
            // nada a fazer
        }
        pAnterior = pInicio;
        pInicio = pInicio->next;
    }
    // se chegou aqui, a lista que n�o era vazia e o elemento � maior que todos que existiam
    Node *aux = (Node *) malloc(sizeof(Node));
    aux->next = NULL;
    aux->e = e;
    pAnterior->next = aux;
    return TRUE;
}

Logic freeSet(char c){
    int ix = mapa(c);
    if (ix < 0) return FALSE;
    Node *pInicio = vetListas[ix];
    while (pInicio != NULL){
        Node *aux = pInicio;
        pInicio = aux->next;
        //printf(" libera %i ", aux->e);// debug
        free(aux);
    }
    vetListas[ix] = NULL;
    return TRUE;
}

Logic setsUnion(char c1, char c2, char c3){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    int ix3 = mapa(c3);
    if (ix1 < 0 || ix2 < 0 || ix3 < 0 ) return FALSE;
    // TO DO: desalocar e liberar o vetor de listas da terceira posi��o
    freeSet(c3);
    Node *p1 = vetListas[ix1];
    Node *p2 = vetListas[ix2];
    while (p1 != NULL && p2 != NULL){
       Tipo e1 = p1->e;
       Tipo e2 = p2->e;
       Result res = comparador(e1,e2);
       if (res == EQUAL){
            setsAddElement(c3, e1);// adiciona um deles
            p1 = p1->next;
            p2 = p2->next;
       } else if (res == LT){
            setsAddElement(c3, e1);
            p1 = p1->next;
       } else { // res == GT
            setsAddElement(c3, e2);
            p2 = p2->next;
       }
    }
    // o que sobrou de p1
    while (p1 != NULL ){
        Tipo e1 = p1->e;
        setsAddElement(c3, e1);
        p1 = p1->next;
    }
    // o que sobrou de p2
    while (p2 != NULL ){
        Tipo e2 = p2->e;
        setsAddElement(c3, e2);
        p2 = p2->next;
    }
    return TRUE;
}

Logic setsDestroy(){
    // TO DO: desalocar e liberar o vetor de listas
    char ch = 'A';
    while (ch<='Z'){
        freeSet(ch);
        ch++;
    }
}
Logic setsIntersection(char c1, char c2, char c3){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    int ix3 = mapa(c3);
    if (ix1 < 0 || ix2 <0 || ix3 < 0) return FALSE;
    freeSet(c3);
    Node * p1 = vetListas[ix1];
    Node * p2 = vetListas[ix2];
    while (p1 != NULL && p2 != NULL){
        Tipo e1 = p1 -> e;
        Tipo e2 = p2 -> e;
        Result res = comparador(e1, e2);
        if (res == EQUAL){
            setsAddElement(c3, e1);
            p1 = p1->next;
            p2 = p2->next;
        } else if (res == LT){
            p1 = p1->next;
        } else{
            p2 = p2->next;
        }
    }
    return TRUE;
}
Logic setsBelongsTo(char c1, Tipo e){
    int ix = mapa(c1);
    if (ix < 0) return FALSE;
    Node *p = vetListas[ix];
    while (p!=NULL){
        if (p->e == e) return TRUE;
        p = p->next;
    }
    return FALSE;
}
Logic setsNumberOfElements(char c1, int * total){
    int ix = mapa(c1);
    if (ix < 0) return FALSE;
    Node *p = vetListas[ix];
    *total = 0;
    while (p != NULL){
        p = p->next;
        *total+=1;
    }
    return TRUE;
}
Logic setsDifference(char c1, char c2, char c3){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    int ix3 = mapa(c3);
    if (ix1 < 0 || ix2 < 0 || ix3 < 0) return FALSE;
    freeSet(c3);
    Node * p1 = vetListas[ix1];
    Node * p2 = vetListas[ix2];
    while (p1!= NULL && p2 != NULL){
        Tipo e1 = p1 -> e;
        Tipo e2 = p2 -> e;
        Result res = comparador(e1,e2);
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
        setsAddElement(c3, p1->e);
        p1 = p1 -> next;
    }
    return TRUE;
}
Logic setsIsIn(char c1, char c2, Logic *result){
    int ix1 = mapa(c1);
    int ix2 = mapa(c2);
    if (ix1<0 || ix2<0) return FALSE;
    int totalc2 = 0, iguais = 0;
    setsNumberOfElements(c2, &totalc2);
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
        } else{
            p2 = p2 -> next;
        }
    }
    if (iguais == totalc2) *result = TRUE;
    else *result = FALSE;
    return TRUE;
}

Logic setsRemoveElement(char c1, Tipo e){
    int ix = mapa(c1);
    if (c1<0) return FALSE;
    if (vetListas[ix] == NULL) return FALSE;
    Tipo quant = 0;
    if (setsNumberOfElements(c1, &quant) == 1){
        Node *aux = vetListas[ix];
        if (aux -> e == e){
            free(aux);
            vetListas[ix] == NULL;
        } 
        return;
    }
    Node *aux = vetListas[ix];
    Node *anterior = vetListas[ix];
    while(aux->e != e && aux != NULL){
        if (aux->next->e == e){
            anterior = aux;
        }
        aux = aux->next;
    }
    anterior -> next = aux -> next;
    free(aux);
    return TRUE;
}