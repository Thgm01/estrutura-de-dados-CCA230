#include <stdio.h>
#include <stdlib.h>


typedef struct Vertice
{
    int valor;
    struct Vertice *pai;
    struct Vertice *f_esq;
    struct Vertice *f_dir;

}Vertice;


typedef struct 
{
    Vertice *raiz;
}ArvoreBinaria;

int num_filhos(Vertice *v)
{
    int num = 0; 
    if(v->f_esq) num++;
    if(v->f_dir) num++;

    return num;
}

int e_filho_esq(Vertice *v)
{
    return v->pai->f_esq == v;
}

Vertice *acha_filho_direito(Vertice *v)
{
    Vertice *atual = v;
    Vertice *pai = NULL;
    
    while(atual != NULL)
    {
        pai = atual;
        atual = atual->f_dir;
    }

    return pai;

}

void in_ordem(Vertice *v)
{
    if(v != NULL)
    {
        in_ordem(v->f_esq);
        printf("%d ", v->valor);
        in_ordem(v->f_dir);
    }
}

void pre_ordem(Vertice *v)
{
    if(v != NULL)
    {
        printf("%d ", v->valor);
        pre_ordem(v->f_esq);
        pre_ordem(v->f_dir);
    }
}

void pos_ordem(Vertice *v)
{
    if(v != NULL)
    {
        pos_ordem(v->f_esq);
        pos_ordem(v->f_dir);
        printf("%d ", v->valor);
    }
}

Vertice *criar_vertice(int valor)
{
    Vertice *vertice = malloc(sizeof(Vertice));
    
    vertice->pai = NULL;
    vertice->f_esq = NULL;
    vertice->f_dir = NULL;

    vertice->valor = valor;

    return vertice;
}

ArvoreBinaria *criar_arvore()
{
    ArvoreBinaria *arvore_binaria = malloc(sizeof(ArvoreBinaria));
    arvore_binaria->raiz = NULL;

    return arvore_binaria;
}

void inserir(ArvoreBinaria *ab, int valor)
{
    Vertice *novo_vertice = criar_vertice(valor);

    Vertice *atual = ab->raiz;
    Vertice *pai = NULL;

    if(atual == NULL)
    {
        ab->raiz = novo_vertice;
        return;
    }

    while(atual != NULL)
    {
        pai = atual;

        if(atual->valor > valor)
        {
            atual = atual->f_esq;
        }
        else
        {
            atual = atual->f_dir;
        }
    }

    novo_vertice->pai = pai;

    if(pai->valor > valor)
    {
        pai->f_esq = novo_vertice;
    }
    else
    {
        pai->f_dir = novo_vertice;
    }   

}

void remover_vertice(ArvoreBinaria *ab, Vertice *v)
{
    if(num_filhos(ab->raiz) == 0) 
    {
        ab->raiz = NULL;
        free(v);
        return;
    }
    int qtd_f = num_filhos(v);

    // printf("debug 1\n");

    if(qtd_f == 0)
    {
        if(v->pai == NULL) ab->raiz = NULL;
        if(e_filho_esq(v)) v->pai->f_esq = NULL;
        else v->pai->f_dir = NULL;
        free(v);
    }
    else if (qtd_f == 1)
    {
        if(v->f_dir == NULL)
        {
            int aux = v->f_esq->valor;
            v->f_esq->valor = v->valor;
            v->valor = aux;
            remover_vertice(ab, v->f_esq);
        }
        else
        {
            int aux = v->f_dir->valor;
            v->f_dir->valor = v->valor;
            v->valor = aux;
            remover_vertice(ab, v->f_dir);
        }

    }
    else
    {
        Vertice *mudar_filho = acha_filho_direito(v->f_esq); 
        int aux = mudar_filho->valor;
        mudar_filho->valor = v->valor;
        v->valor = aux;
        remover_vertice(ab, mudar_filho);
    }
}

Vertice *buscar_valor(ArvoreBinaria* arvore, int valor){
	Vertice* atual = arvore->raiz;
	while(atual != NULL){
		if(valor < atual->valor){
			atual = atual->f_esq;
		}else{
			if(valor > atual->valor){
				atual = atual->f_dir;
			}else{
				return atual;
			}
		}
	}
	return NULL;
}

int main(void) {
	int dados[] = {5, 3, 8, 2, 4, 7, 9, 1, 6, 10};
  	ArvoreBinaria *arvore = criar_arvore();
  	
	for(int i = 0; i < 8; i++){
		inserir(arvore, dados[i]);
		printf("Inseriu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Inseriu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}
	
	for(int i = 0; i < 10; i++){
		Vertice *vertice = buscar_valor(arvore, dados[i]);
		if(vertice != NULL){
			remover_vertice(arvore, vertice);
		}
		printf("Removeu %d mostra em ordem -> ", dados[i]);
		in_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pré-ordem -> ", dados[i]);
		pre_ordem(arvore->raiz);
		printf("\n");
		printf("Removeu %d mostra em pós-ordem -> ", dados[i]);
		pos_ordem(arvore->raiz);
		printf("\n");
	}
		
  return 0;

}