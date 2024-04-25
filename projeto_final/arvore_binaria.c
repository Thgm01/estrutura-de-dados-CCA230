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

// void in_ordem(Vertice *raiz) //arrumar e passar pro ui.c
// {
//     if(raiz != NULL)
//     {
//         in_ordem(raiz->f_esq);
//         printf("%d ", raiz->valor);
//         in_ordem(raiz->f_dir);
//     }
// }

void inserir_por_entrada(ArvoreBinaria *ab, Registro *registro)
{
    Vertice *novo_vertice = criar_vertice(registro);

    Vertice *atual = ab->raiz;
    Vertice *pai = NULL;

    if(atual == NULL)
    {
        ab->raiz = registro;
        return;
    }

    while(atual != NULL)
    {
        pai = atual;

        if(data_maior(atual->registro->entrada, registro->entrada) == 1)
        {
            atual = atual->f_esq;
        }
        else
        {
            atual = atual->f_dir;
        }
    }

    novo_vertice->pai = pai;

    if(data_maior(pai->registro->entrada, registro->entrada) == 1)
    {
        pai->f_esq = novo_vertice;
    }
    else
    {
        pai->f_dir = novo_vertice;
    }   
}

void inserir_por_idade(ArvoreBinaria *ab, Registro *registro)
{

    Vertice *novo_vertice = criar_vertice(registro);

    Vertice *atual = ab->raiz;
    Vertice *pai = NULL;

    if(atual == NULL)
    {
        ab->raiz = registro;
        return;
    }

    while(atual != NULL)
    {
        pai = atual;

        if(atual->registro->idade > registro->idade)
        {
            atual = atual->f_esq;
        }
        else
        {
            atual = atual->f_dir;
        }
    }

    novo_vertice->pai = pai;

    if(pai->registro->idade > registro->idade)
    {
        pai->f_esq = novo_vertice;
    }
    else
    {
        pai->f_dir = novo_vertice;
    }       


}

