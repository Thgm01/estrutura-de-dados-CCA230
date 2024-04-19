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
    limpa_registro(elemento->dados);
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

void libera_lista(Lista *lista) // Função para liberar a memória alocada da lista de registros
{
    ELista *atual = lista->inicio;
    if(atual == NULL) return;

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

    while(strcmp(atual->dados->rg, info) != 0 && strcmp(atual->dados->nome, info) != 0)
    {
        atual = atual->proximo;
        if(atual == NULL) return NULL;
    }
    return atual->dados;
} 

int remove_registro(Lista *lista, const char *info)
{
    if(lista->qtd == 0) return 0;

    ELista *atual = lista->inicio;
    ELista *anterior = NULL;

    while(strcmp(atual->dados->rg, info) != 0 && strcmp(atual->dados->nome, info) != 0 && atual!=NULL)
    {
        anterior = atual;
        atual = anterior->proximo;
    }
    
    if(atual==NULL) return 0;
    else if(anterior == NULL)
    {
        lista->inicio = atual->proximo;
    }
    else
    {
        anterior->proximo = atual->proximo;
    }

    libera_elemento(atual);
    lista->qtd --;

    return 1;
}

void edita_registro(ELista *registro, const int opt)
{
    if(registro != NULL)
    {
        switch (opt)
        {
            case 1:
            {
                char *novo_nome = recebe_nome(); 
                registro->dados->nome = realloc(registro->dados->nome, strlen(novo_nome)*sizeof(char));
                strcpy(registro->dados->nome, novo_nome);

                free(novo_nome);
                break;
            }
            case 2:
            {
                char *novo_rg = recebe_rg();
                strcpy(registro->dados->rg, novo_rg);

                free(novo_rg);
                break;
            }
            case 3:
                registro->dados->idade = recebe_idade();
                break;
        }
    }
    else
    {
        printf("Paciente Não Encontrado");
    }
}

