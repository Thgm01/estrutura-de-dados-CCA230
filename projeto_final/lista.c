#include "include/lista.h"

#include "include/utils.h"


ELista *cria_elemento_lista() //cria celula da lista
{
    ELista *novo_elemento =  malloc(sizeof(ELista));
    
    novo_elemento->dados = cria_registro(); //cria um registros automatico
    novo_elemento->proximo = NULL;

    return novo_elemento;
}

void libera_elemento(ELista *elemento, int libera_registro)  // Função para liberar a memoria alocada de um elemento (elemento = dados de um paciente na lista)
{  
    if(libera_registro) limpa_registro(elemento->dados); //desaloca também os registros
    free(elemento);
}

Lista *cria_lista() //cria estrutura base da lista 
{
    Lista *nova_lista = malloc(sizeof(Lista));
    
    nova_lista->inicio = NULL;
    nova_lista->qtd = 0;

    return nova_lista;
}

void inserir_na_lista(Lista *lista, Registro *registro) //insere um registro na lista de pacientes
{
    ELista *novo_elemento = malloc(sizeof(ELista));

    novo_elemento->dados = registro;

    //insere o registro no inicio
    novo_elemento->proximo = lista->inicio;
    lista->inicio = novo_elemento;

    lista->qtd ++;
}

void cadastrar_novo_paciente(Lista *l) //cadastrar um novo paciente
{
    ELista * novo_paciente = cria_elemento_lista();

    novo_paciente->proximo = l->inicio;
    l->inicio = novo_paciente;

    l->qtd ++;
}

void mostra_lista(Lista *lista, const int opt) //mostra os pacientes na lista
{
    ELista *atual = lista->inicio;

    while(atual != NULL)
    {
        switch (opt)
        {
            case 0: //mostra o registro todo
                mostra_registro(atual->dados);
                break;
            case 1: //mostra apenas os nomes dos pacientes
                mostra_nome(atual->dados); 
                break;

            case 2: //mostra apenas os rg's dos pacientes 
                mostra_rg(atual->dados);
                break;
        }
        atual = atual->proximo;
    }
}

void libera_lista(Lista *lista, int libera_pont, int libera_registro) // Função para liberar a memória alocada da lista de registros
{
    ELista *atual = lista->inicio;
    if(atual == NULL) return; //caso não tenha registros encera a função

    ELista *aux = atual->proximo;

    while(aux != NULL)
    {
        libera_elemento(atual, libera_registro);

        atual = aux;
        aux = atual->proximo;
    }
    libera_elemento(atual, libera_registro); //libera o elemento e/ou os registros
    if(libera_pont) free(lista); //libera os ponteiros
}

Registro *acha_registro(Lista *lista, const char *info)
{
    ELista *atual = lista->inicio;

    while(strcmp(atual->dados->rg, info) != 0 && strcmp(atual->dados->nome, info) != 0) //achar tanto nome como rg
    {
        atual = atual->proximo;
        if(atual == NULL) return NULL; //caso não ache retorna vazio
    }
    return atual->dados; //caso ache retorna o registro do paciente
} 

int remove_registro(Lista *lista, const char *info)
{
    if(lista->qtd == 0) return 0; //se estiver vaiza não continua

    ELista *atual = lista->inicio;
    ELista *anterior = NULL;

    while(strcmp(atual->dados->rg, info) != 0 && strcmp(atual->dados->nome, info) != 0 && atual!=NULL) //acha o registro tanto pelo nome como pelo rg
    {
        anterior = atual;
        atual = anterior->proximo;
    }
    
    if(atual==NULL) return 0; // caso não encontre retorna 0
    //remove o elemento da lista de pacientes
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

Lista *inverte_lista(Lista *lista) // inverte a lista
{
    Lista *lista_invertida = cria_lista(); //cria uma nova lista

    ELista *atual = lista->inicio;
    
    //inverte os regsitros
    while(atual != NULL)
    {
        inserir_na_lista(lista_invertida, atual->dados);
        atual = atual->proximo;
    }    

    //libera a lista antiga
    libera_lista(lista, 1, 0);

    printf("%s\n", lista_invertida->inicio->dados->nome);

    return lista_invertida; //retorna a lista invertida
}