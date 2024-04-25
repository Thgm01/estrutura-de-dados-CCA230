#include "arvore_binaria.h"

Vertice *criar_vertice(Registro *registro)
{
    Vertice *vertice = malloc(sizeof(Vertice));
    
    vertice->pai = NULL;
    vertice->f_esq = NULL;
    vertice->f_dir = NULL;

    vertice->registro = registro;

    return vertice;
}

ArvoreBinaria *criar_arvore()
{
    ArvoreBinaria *arvore_binaria = malloc(sizeof(ArvoreBinaria));
    
    arvore_binaria->raiz = NULL;
    arvore_binaria->qtd = 0;

    return arvore_binaria;
}

void in_ordem(Vertice *raiz) //arrumar e passar pro ui.c
{
    if(raiz != NULL)
    {
        in_ordem(raiz->f_esq);
        printf("%d ", raiz->valor);
        in_ordem(raiz->f_dir);
    }
}

