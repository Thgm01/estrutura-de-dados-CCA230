#include "arquivos.h"
#include "lista.h"
#include "registro.h"


Lista *le_arquivo()
{
  FILE *arquivo = fopen("dados.txt", "r");

  if(arquivo == NULL) return NULL;

  Lista *cadastros = cria_lista();
  
  char buffer[200];
  while(fgets(buffer, 100, arquivo) != NULL)
  {
    Registro *novo_registro = malloc(sizeof(Registro));
    
    char *info = strtok(buffer, ";");
    char *nome = malloc(strlen(info) * sizeof(char));
    strcpy(nome, info);
    novo_registro->nome = nome;
    
    info = strtok(NULL, ";");
    novo_registro->idade = atoi(info);

    info = strtok(NULL, ";");
    char *rg = malloc(sizeof(char)*11);
    strcpy(rg, info);
    novo_registro->rg = rg;

    info = strtok(NULL, ";");
    novo_registro->entrada.dia = atoi(info);
    
    info = strtok(NULL, ";");
    novo_registro->entrada.mes = atoi(info);
    
    info = strtok(NULL, ";");
    novo_registro->entrada.ano = atoi(info);

    ELista *paciente = malloc(sizeof(ELista));

    paciente->dados = novo_registro;

    paciente->proximo = cadastros->inicio;
    cadastros->inicio = paciente;
  }

  fclose(arquivo);

  return cadastros;
}

int salva_arquivo(Lista *lista)
{
  FILE *arquivo = fopen("dados.txt", "w");

  if(arquivo == NULL) return 0;

  ELista *atual = lista->inicio;

  while(atual != NULL)
  {
    fprintf(arquivo, "%s;%d;%s;%d;%d;%d\n", atual->dados->nome, atual->dados->idade, atual->dados->rg, atual->dados->entrada.dia, atual->dados->entrada.mes, atual->dados->entrada.ano);
    atual = atual->proximo;
  }

  fclose(arquivo);
  
  return 1;

}