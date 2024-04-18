#include <stdio.h>
#include <stdlib.h>

#define tam_hash 11

typedef struct Celula{
  int valor;
  struct Celula * proximo;
}Celula;

typedef struct {
  Celula * primeiro;
  int qtd;
}Lista;

typedef struct {
  Lista * valores[tam_hash];
  int qtd;
}Hash;

Lista *criar_lista(void)
{
  Lista *l = malloc(sizeof(Lista));
  
  l->qtd = 0;
  l->primeiro = NULL;

  return l;
}

Celula *criar_celula(int valor)
{
  Celula *c = malloc(sizeof(Celula));
  
  c->valor = valor;
  c->proximo = NULL;

  return c;
}

void inserir_valor(Lista *l, int valor)
{
  Celula *nova = criar_celula(valor);
  
    nova->proximo = l->primeiro;
    l->primeiro = nova;
  l->qtd ++;

}

void remover(Lista *l, int valor) {
	if(l->qtd == 0)
	  return;
  
  Celula *atual = l->primeiro;
  Celula *anterior = NULL;

	while(atual->valor != valor)
	{
	  anterior = atual;
	  atual = atual->proximo;
      if(atual == NULL) break;
	}
    if (atual != NULL) {
        if (anterior == NULL) {
        l->primeiro = atual->proximo;
        } else {
        anterior->proximo = atual->proximo;
        }
        free(atual);
        l->qtd --;
    }
}

Hash* start_hash(){
  Hash *h = malloc(sizeof(Hash));
  for(int i = 0; i<tam_hash; i++)
  {
    h->valores[i] = criar_lista();
  }
  return h;
}

void inserir_hash(Hash* hash, int valor){
  inserir_valor(hash->valores[valor%tam_hash], valor);
}

void remover_hash(Hash* hash, int valor){
  remover(hash->valores[valor%tam_hash], valor);
}

void imprimir_lista(Lista *l){
	Celula *atual = l->primeiro;
    if(l->qtd == 0) return;
	while(atual != NULL){
		printf("%d ", atual->valor);
		atual = atual->proximo;
	}
}

void imprimir(Hash* hash){
    printf("---------------------");
  for(int i=0; i<tam_hash; i++)
  {
    printf("\n%d -> ", i);
    imprimir_lista(hash->valores[i]);
  }
    printf("\n---------------------\n");

}

int main(void) {
  Hash* hash = start_hash();
  int valor;
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    inserir_hash(hash, valor);
  }
  imprimir(hash);
  while(1){
    scanf("%d", &valor);
    if(valor == 0)
      break;
    remover_hash(hash, valor);
  }
  imprimir(hash);
  return 0;
}