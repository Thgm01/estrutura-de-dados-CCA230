#ifndef FILA_H
#define FILA_H

#include "registro.h"

#include <stdlib.h>

typedef struct EFila
{
  Registro *dados;
  struct EFila *proximo;

}EFila;

typedef struct
{
  
  EFila *head;
  EFila *tail;
  int qtd;

}Fila;

EFila *cria_efila(Registro *registro);
Fila *cria_fila();
void enfileirar(Fila *fila, Registro *registro);
Registro *desenfileirar(Fila *fila);
void libera_efila(EFila * celula);
void libera_fila(Fila *fila);
void mostra_fila(Fila *fila);

#endif
