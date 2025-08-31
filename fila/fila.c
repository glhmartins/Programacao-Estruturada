// Aluno: Guilherme Martins Rangel

#include "fila.h"

#define MAX 4 // Tamanho máximo da fila
Tipo Fila[MAX]; // Criando a fila usando a estrutura Tipo com o tamanho MAX
int pos, pos_aux = 0; // pos é a variavel usada para as posições, pos_aux é uma variavel usada na hora de devolver os elementos da fila

Logico qCreate(){ // Operação para criar a fila
    pos = -1;
    return TRUE;
}
Logico qDestroy(){ // Operação para finalizar a fila
    pos = -1;
    return TRUE;
}
Logico qIsFull(){ // Operação para saber se a fila esta ou não cheia
    if (pos >= (MAX-1)) return TRUE;
    return FALSE; // Caso a posição não seja maior q o máximo permitido retorna falso, indicando que ainda existe vaga na fila
}
Logico qIsEmpty(){ // Operação para saber se a fila esta ou não vazia
    if (pos < 0) {
        pos = pos_aux = 0;
        return TRUE;
    }
    return FALSE; // Caso a fila não esteja 100% vazia retorna-se FALSE
}
Logico qIn(Tipo e){ // Operação para colocar coisas na fila
    if (qIsFull()) return FALSE;
    Fila[++pos] = e; // O vetor fila na posição POS recebe "e", sendo "e" 
    return TRUE;
} 
Logico qOut(Tipo *e){ // Operação para retirar coisas da fila
    if (qIsEmpty() == TRUE) // Caso a fila esteja vazia retornamos FALSE para indicar que não existem elementos a serem retirados da fila
        return FALSE;
    *e = Fila[pos_aux++]; 
    pos--; 
    return TRUE;
} 