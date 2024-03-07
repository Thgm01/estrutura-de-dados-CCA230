#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
  int valor;
  struct celula *proximo;
} celula;

typedef struct
{
  int qtde;
  celula *primeiro;
} lista;

lista *criar_lista(void)
{
  lista *l = malloc(sizeof(lista));
  
  l->qtde = 0;
  l->primeiro = NULL;

  return l;
}

celula *criar_celula(int valor)
{
  celula *c = malloc(sizeof(celula));
  
  c->valor = valor;
  c->proximo = NULL;

  return c;
}

void inserir_valor(lista *l, int valor)
{
  celula *nova = criar_celula(valor);

  if(l->qtde == 0)
  {
    l->primeiro = nova;
  } 
  else
  {
    celula *atual = l->primeiro;
    celula *anterior = NULL;

    while(atual != NULL && atual->valor < valor)
    {
      anterior = atual;
      atual = atual->proximo;
    }
    if(anterior == NULL)
    { //verificar
      
      nova->proximo = l->primeiro;
      l->primeiro = nova;
    }
    else
    {
      anterior->proximo = nova;
      nova->proximo = atual;
    }
  }
  l->qtde ++;

}

void mostrar(lista *l)
{
  celula *atual = l->primeiro;

  while(atual != NULL)
  {
    printf("%d ", atual->valor);
    atual = atual->proximo;
  }
  printf("\n");
}

celula *remove_valor(lista *l, int valor);

int main(void)
{
  lista *l = criar_lista();
  int valores[] = {5, 2, 1, 8, 3, 0, 6, 7, 9, 4};
  for(int i=0; i<10; i++)
  {
    inserir_valor(l, valores[i]);
    mostrar(l);
  }
}
