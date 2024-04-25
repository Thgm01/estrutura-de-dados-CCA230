#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <stdio.h>
#include <stdlib.h>

#include "registro.h"

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

#endif 