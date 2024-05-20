#include "include/fila.h"

EFila *cria_efila(Registro *registro)
{
  EFila *nova_celula = malloc(sizeof(EFila));
  
  nova_celula->dados = registro;
  nova_celula->proximo = NULL;

  return nova_celula;
}

Fila *cria_fila()
{
  Fila *fila = malloc(sizeof(Fila));

  fila->head = NULL;
  fila->tail = NULL;
  fila->qtd = 0;

  return fila;
}

void enfileirar(Fila *fila, Registro *registro)
{
  EFila *novo_registro = cria_efila(registro);

  if(fila->qtd == 0)
  {
    fila->head = novo_registro;
  }
  else
  {
    fila->tail->proximo = novo_registro;
  }
  fila->tail = novo_registro;
  
  fila->qtd++;
}

Registro *desenfileirar(Fila *fila)
{
  if(fila->qtd == 0) return NULL;

  EFila *registro_removido = fila->head;
  Registro *paciente = registro_removido->dados;
  
  if(fila->qtd == 1)
  {
    fila->tail = NULL;
  }  
  fila->head = fila->head->proximo;

  libera_efila(registro_removido);

  fila->qtd--;
  return paciente;
}

void libera_fila(Fila *fila)
{
  EFila *atual = fila->head;
  if(atual == NULL) return;

  EFila *aux = atual->proximo;

  while(aux != NULL)
  {
    libera_efila(atual);

    atual = aux;
    aux = atual->proximo;
  }
  libera_efila(atual);
}

void libera_efila(EFila * celula)
{
  free(celula);
}

void mostra_fila(Fila *fila)
{
  EFila *atual = fila->head;
  while(atual != NULL)
  {
    mostra_registro(atual->dados);
    atual = atual->proximo;
  }
}
