// Aluno: Guilherme Martins Rangel

#include <stdio.h>
#include <stdlib.h>

#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct {
    char nome[80]; // Nome do aluno
    float notas[4]; // Notas do aluno
    int matricula; // Número de matricula do aluno
} Aluno;

typedef Aluno Tipo;

typedef int Logico;
#define TRUE 1
#define FALSE 0

Logico qCreate(); // Criação da fila
Logico qDestroy(); // Encerramento da fila e liberação de memória
Logico qIn(Tipo e); // Entrada dos elementos na lista encadeada
Logico qOut(Tipo *e); // Saida dos elementos da lista encadeada
Logico qIsFull(); // Verifica se a fila está cheia
Logico qIsEmpty(); // Verifica se a fila está vazia
Logico qCount(int *total); // Retorna quantos elementos existem na lista encadeada

#endif // FILA_H_INCLUDED