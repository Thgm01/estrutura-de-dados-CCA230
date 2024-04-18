#include <stdio.h>
#include <stdlib.h>

#define LEN 10

typedef struct {
    int valores[LEN];
    int qtde;
} heap;

int filho_esq(int pai) { return (2 * pai) + 1; }

int filho_dir(int pai) { return (2 * pai) + 2; }

int pai(int filho) { return (filho - 1) / 2; }

int ultimo_pai(heap *h) { return (h->qtde / 2) - 1; }

int tem_filho_esquerda(heap *h, int pai) { return filho_esq(pai) < h->qtde; }

int tem_filho_direita(heap *h, int pai) { return filho_dir(pai) < h->qtde; }

void peneirar(heap *h, int pai) {
    int maior = pai;
    int f_esq = filho_esq(pai);
    int f_dir = filho_dir(pai);

    if (tem_filho_direita(h, pai) && h->valores[f_dir] > h->valores[maior])  maior = f_dir;
    if (tem_filho_esquerda(h, pai) && h->valores[f_esq] > h->valores[maior]) maior = f_esq;
    if (maior != pai) {
        int aux = h->valores[pai];

        h->valores[pai] = h->valores[maior];
        h->valores[maior] = aux;
        
        peneirar(h, maior);
    }
}

void mostrar(heap *h) {
    for (int i=0; i<h->qtde; i++) {
        printf("%d ", h->valores[i]);
    }
    printf("\n");
}

void construir(heap *h) {
    for (int i=ultimo_pai(h); i>=0; i--) {
        peneirar(h, i);
    }
}

void inserir(heap *h, int valor) {
    h->valores[h->qtde] = valor;
    h->qtde++;

    construir(h);
}

void remover(heap *h) {
    h->valores[0] = h->valores[h->qtde - 1];
    h->qtde--;
    peneirar(h, 0);
}

int main(void) {
  heap *h = malloc(sizeof(heap));
  int valor;
  h->qtde = 0;
  for (int i = 0; i < LEN; i++) {
    scanf("%d", &valor);
    inserir(h, valor);
    mostrar(h);
  }
  for (int i = 0; i < LEN; i++) {
    remover(h);
    mostrar(h);
  }

  return 0;
}