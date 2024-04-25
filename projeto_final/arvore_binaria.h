#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <stdio.h>
#include <stdlib.h>

#include "registro.h"
#include "lista.h"

typedef struct Vertice
{
    Registro *registro;
    struct Vertice *pai;
    struct Vertice *f_esq;
    struct Vertice *f_dir;

}Vertice;

typedef struct 
{
    Vertice *raiz;
    int qtd;
}ArvoreBinaria;

Vertice *criar_vertice(Registro *registro);
ArvoreBinaria *criar_arvore();

void in_ordem(Vertice *raiz);

void inserir_por_data(ArvoreBinaria *ab, Registro *registro);
void inserir_por_idade(ArvoreBinaria *ab, Registro *registro);
ArvoreBinaria *inserir_todos_registros(Lista *lista, int por_idade);

#endif 