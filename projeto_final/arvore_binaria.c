#include "include/arvore_binaria.h"

#include "include/utils.h"

Vertice *criar_vertice(Registro *registro) //Cria um vertice de uma arvore binaria com as infos do registro
{
    Vertice *vertice = malloc(sizeof(Vertice));
    
    vertice->pai = NULL;
    vertice->f_esq = NULL;
    vertice->f_dir = NULL;

    vertice->registro = registro;

    return vertice;
}

ArvoreBinaria *criar_arvore() //cria a estrutura base da arvore
{
    ArvoreBinaria *arvore_binaria = malloc(sizeof(ArvoreBinaria));
    
    arvore_binaria->raiz = NULL;
    arvore_binaria->qtd = 0;

    return arvore_binaria;
}

void inserir_por_data(ArvoreBinaria *ab, Registro *registro) //insere os registros com base na data de entrada do paciente
{
    Vertice *novo_vertice = criar_vertice(registro); //cria o novo vertice

    Vertice *atual = ab->raiz;
    Vertice *pai = NULL;

    if(atual == NULL)
    {
        ab->raiz = novo_vertice;
        return;
    }

    while(atual != NULL)
    {
        pai = atual;

        if(data_maior(atual->registro->entrada, registro->entrada) == 1) // compara qual a maior data de entrada
        {
            atual = atual->f_esq;
        }
        else
        {
            atual = atual->f_dir;
        }
    }

    //insere o novo vertice na arvore
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

void inserir_por_idade(ArvoreBinaria *ab, Registro *registro) //inserir na arvore com base na idade do paciente
{

    Vertice *novo_vertice = criar_vertice(registro);

    Vertice *atual = ab->raiz;
    Vertice *pai = NULL;

    if(atual == NULL)
    {
        ab->raiz = novo_vertice;
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

    //insere o novo vertice na arvore
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

ArvoreBinaria *inserir_todos_registros(Lista *lista, int por_idade) //inserir todos os registros de forma automatica na arvore
{
    ArvoreBinaria *arvore = criar_arvore();

    //utiliza os registros da lista importada previamente para inserir na arvore
    ELista *atual = lista->inicio; 
    if(atual == NULL) return arvore;

    ELista *aux = atual->proximo;

    while(aux != NULL)
    {
        if(por_idade) inserir_por_idade(arvore, atual->dados);
        else inserir_por_data(arvore, atual->dados);

        atual = aux;
        aux = atual->proximo;
    }

    if(por_idade) inserir_por_idade(arvore, atual->dados);
    else inserir_por_data(arvore, atual->dados);

    //retorna a arvore já construida
    return arvore;

}