#include <stdio.h>
#include <stdlib.h>

#ifndef LISTACIRCULAR_H_INCLUDED
#define LISTACIRCULAR_H_INCLUDED

typedef struct {
    char nome[80]; // nome do aluno
    float notas[4];
    int cpf;
} Aluno;

//typedef int Tipo;
// vamos mudar o Tipo (de int para Aluno), mas nada precisa ser mudado em Pilha.c
typedef Aluno Tipo;
typedef int Logic;
#define TRUE 1
#define FALSE 0

typedef void (*funcaoDeForaQueImprime)(Tipo); // ponteiro para fun��o
Logic lcCurrent(Tipo *e);// retorna o elemento corrente da lista circular
Logic lcInsert(Tipo e);// inserir elemento apos o corrente
Logic lcDelete(Tipo *e); // remove elemento corrente, retornando-o opcionalmente
Logic lcCount(int *total); //retorna o total de elementos da lista circular
Logic lcCreate(funcaoDeForaQueImprime fun); // inicializacoes
Logic lcDestroy();// limpar a memoria
Logic lcIsFull();// saber se est� cheio
Logic lcIsEmpty();// saber se est� vazio
Logic lcNext();// muda o corrente para o proximo
Logic lcPrevious();// muda o corrente para o anterior
Logic lcPrint();

#endif // LISTACIRCULAR_H_INCLUDED