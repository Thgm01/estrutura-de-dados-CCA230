#include "include/lista.h"

#include "include/utils.h"


ELista *cria_elemento_lista()
{
    ELista *novo_elemento =  malloc(sizeof(ELista));
    
    novo_elemento->dados = cria_registro();
    novo_elemento->proximo = NULL;

    return novo_elemento;
}

void libera_elemento(ELista *elemento, int libera_registro)  // Função para liberar a memoria alocada de um elemento (elemento = dados de um paciente na lista)
{
    if(libera_registro) limpa_registro(elemento->dados);
    free(elemento);
}

Lista *cria_lista()
{
    Lista *nova_lista = malloc(sizeof(Lista));
    
    nova_lista->inicio = NULL;
    nova_lista->qtd = 0;

    return nova_lista;
}

void inserir_na_lista(Lista *lista, Registro *registro)
{
    ELista *novo_elemento = malloc(sizeof(ELista));

    novo_elemento->dados = registro;

    novo_elemento->proximo = lista->inicio;
    lista->inicio = novo_elemento;

    lista->qtd ++;
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

void libera_lista(Lista *lista, int libera_pont, int libera_registro) // Função para liberar a memória alocada da lista de registros
{
    ELista *atual = lista->inicio;
    if(atual == NULL) return;

    ELista *aux = atual->proximo;

    while(aux != NULL)
    {
        libera_elemento(atual, libera_registro);

        atual = aux;
        aux = atual->proximo;
    }
    libera_elemento(atual, libera_registro);
    if(libera_pont) free(lista);
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

    libera_elemento(atual, 1);
    lista->qtd --;

    return 1;
}

Lista *inverte_lista(Lista *lista)
{
    Lista *lista_invertida = cria_lista();

    ELista *atual = lista->inicio;

    while(atual != NULL)
    {
        inserir_na_lista(lista_invertida, atual->dados);
        atual = atual->proximo;
    }    

    libera_lista(lista, 1, 0);

    printf("%s\n", lista_invertida->inicio->dados->nome);

    return lista_invertida;
}