#ifndef LISTA_H
#define LISTA_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "registro.h"

typedef struct ELista
{
    Registro *dados;
    struct ELista * proximo;

}ELista;

typedef struct
{
    ELista *inicio;
    int qtd;
}Lista;

ELista *cria_elemento_lista();
void libera_elemento(ELista *elemento);

Lista *cria_lista();
void cadastrar_novo_paciente(Lista *lista);
void mostra_lista(Lista *lista, const int opt);
void limpa_lista(Lista *lista);

Registro *acha_registro(Lista *lista, const char *info);



#endif
