#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#define TRUE 1
#define FALSE 0
typedef int Logico;
typedef float Tipo;

typedef void (*funcaoDeForaQueImprime)(Tipo);

Logico stCreate();
Logico stIsFull(char letra);// pilha ta cheia ou nao?
Logico stIsEmpty(char letra);// pilha ta vazia ou nao?
Logico stPush(char letra, Tipo c);
Logico stPop(char letra, Tipo * c);
Logico stCount(char letra, int *total);
Logico stDestroy();
Logico stPrint(char letra, funcaoDeForaQueImprime fun);

#endif // PILHA_H_INCLUDED
