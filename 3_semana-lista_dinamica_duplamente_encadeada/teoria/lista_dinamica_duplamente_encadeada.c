#include <stdio.h>
#include <stdlib.h>

typedef struct celula
{
  int valor;
  struct celula *proximo;
  struct celula *anterior;
} celula;

typedef struct
{
  int qtde;
  celula *primeiro;
} lista;

lista *criar_lista()
{
  lista *l = malloc(sizeof(lista));
  l->primeiro = NULL;
  l->qtde = 0;
  return l;
}

celula *criar_celula(int valor)
{
  celula *c = malloc(sizeof(celula));
  c->valor = valor;
  c->proximo = NULL;
  c->anterior = NULL;
  return c;
}

void inserir(lista *l, int valor)
{
  celula *nova = criar_celula(valor);
  
  if (l->qtde == 0)
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
    if(atual == NULL)
    {
      anterior->proximo = nova;
      nova->anterior = anterior;
    }else if (anterior == NULL)
    {
      l->primeiro = nova;
      nova->proximo = atual;
      atual->anterior = nova;
    }else
    {
      atual->anterior = nova;
      anterior->proximo = nova;

      nova->anterior = anterior;
      nova->proximo = atual;
    }
    /*
    while (atual->proximo != NULL && atual->valor < valor)
    {
      atual = atual->proximo;
    }
    if(atual->proximo == NULL)
    {
      //printf("1");
      atual->proximo = nova;
      nova->anterior = atual;
    } else if(atual->anterior == NULL)
    {
      printf("2");
      l->primeiro = nova;
      nova->proximo = atual;
      atual->anterior = nova;
    }
    else
    {
      printf("3");
      nova->proximo = atual;
      nova->anterior = atual->anterior;

      atual->anterior->proximo = nova;
      atual->anterior = nova;
    }*/    
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

int main(void)
{
  lista *l = criar_lista();
  int valores[] = {5, 9, 3, 6, 8};

  for(int i=0; i<5; i++)
  {
    inserir(l, valores[i]);
    mostrar(l);
  }
}
