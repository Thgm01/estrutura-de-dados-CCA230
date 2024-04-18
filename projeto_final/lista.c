#include "lista.h"


ELista *cria_elemento_lista()
{
    ELista *novo_elemento =  malloc(sizeof(ELista));
    
    novo_elemento->dados = cria_registro();
    novo_elemento->proximo = NULL;

    return novo_elemento;
}

void libera_elemento(ELista *elemento)  // Função para liberar a memoria alocada de um elemento (elemento = dados de um paciente na lista)
{
    remove_registro(elemento->dados);
    free(elemento);
}

Lista *cria_lista()
{
    Lista *nova_lista = malloc(sizeof(Lista));
    
    nova_lista->inicio = NULL;
    nova_lista->qtd = 0;

    return nova_lista;
}

void cadastrar_novo_paciente(Lista *l)
{
    ELista * novo_paciente = cria_elemento_lista();

    novo_paciente->proximo = l->inicio;
    l->inicio = novo_paciente;

    l->qtd ++;
}

void mostra_lista(Lista *lista, const int opt)
{
    ELista *atual = lista->inicio;

    while(atual != NULL)
    {
        switch (opt)
        {
            case 0:
                mostra_registro(atual->dados);
                break;
            case 1:
                mostra_nome(atual->dados); 
                break;

            case 2:
                mostra_rg(atual->dados);
                break;
        }
        atual = atual->proximo;
    }
}

void limpa_lista(Lista *lista) // Função para liberar a memória alocada da lista de registros
{
    ELista *atual = lista->inicio;
    ELista *aux = atual->proximo;

    while(aux != NULL)
    {
        libera_elemento(atual);

        atual = aux;
        aux = atual->proximo;
    }
    libera_elemento(atual);
    free(lista);
}

Registro *acha_registro(Lista *lista, const char *info)
{
    ELista *atual = lista->inicio;

    while(strcmp(atual->dados->rg, info) != 0 && strcmp(atual->dados->nome, info))
    {
        atual = atual->proximo;
        if(atual == NULL) return NULL;
    }
    return atual->dados;
} 

