#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef    struct {
                char nome[80]; // Aluno
                float notas[4];
                int matricula;
            } Aluno;

//typedef int Tipo;
// vamos mudar o Tipo (de int para Aluno), mas nada precisa ser mudado em Pilha.c
typedef Aluno Tipo;

#define Logico int
#define TRUE 1
#define FALSE 0

Logico stCreate();// criação ou construção
Logico stDestroy();// destruição
Logico stIsFull();// para saber se a pilha esta ou não cheia
Logico stIsEmpty();// para saber se a pilha esta ou nao vazia
Logico stPush(Tipo e); // operaçao para colocar coisas na pilha
Logico stPop(Tipo *e); // operaçao para retirar coisas da pilha


#endif // PILHA_H_INCLUDED
