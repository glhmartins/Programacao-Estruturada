// Aluno: Guilherme Martins Rangel

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct { // Definindo o struct como Aluno, o struct Aluno contem o nome do aluno, notas do aluno e seu número de matricula
    char nome[80]; // Nome do aluno
    float notas[4]; // Notas do aluno
    int matricula; // Número de matricula do aluno
} Aluno;

typedef Aluno Tipo; // Definindo o nome da estrutura Aluno para o nome Tipo

#define Logico int // Definindo o nome do tipo de dados INT como Logico
#define TRUE 1 // Definindo TRUE (Verdadeiro) com o valor 1
#define FALSE 0 // Definindo FALSE (Falso) com o valor 0

Logico qCreate();// criação ou construção
Logico qDestroy();// destruição
Logico qIsFull();//  operação para saber se a fila está  cheia
Logico qIsEmpty();// operação para saber se a fila está  vazia
Logico qIn(Tipo e); // operação para colocar coisas na fila
Logico qOut(Tipo *e); // operação para retirar coisas da fila

#endif