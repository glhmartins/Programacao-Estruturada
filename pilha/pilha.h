// Aluno: Guilherme Martins Rangel

#include <stdio.h>
#include <stdlib.h>

#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct {
    char nome[80]; // Nome do aluno
    float notas[4]; // Notas do aluno
    int matricula; // Número de matricula do aluno
} Aluno;

typedef Aluno Tipo;

typedef int Logico;
#define TRUE 1
#define FALSE 0

Logico stCreate(); // Criação da pilha
Logico stDestroy(); // Encerramento da pilha e liberação de memória
Logico stPush(Tipo e); // Entrada dos elementos na lista encadeada
Logico stPop(Tipo *e); // Saida dos elementos da lista encadeada
Logico stIsFull(); // Verifica se a pilha está cheia
Logico stIsEmpty(); // Verifica se a pilha está vazia
Logico stCount(int *total); // Retorna stuantos elementos existem na lista encadeada

#endif // PILHA_H_INCLUDED