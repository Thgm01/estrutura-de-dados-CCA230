#include "arquivos.h"
#include "lista.h"
#include "registro.h"


Lista *le_arquivo() // le arquivo com dados dos pacientes e adiciona em uma lista
{
  FILE *arquivo = fopen("dados.txt", "r");

  if(arquivo == NULL) return NULL;

  Lista *cadastros = cria_lista();
  
  char buffer[200];
  while(fgets(buffer, 100, arquivo) != NULL) //Enquanto não chegar no final do arquivo le as linhas
  {
    Registro *novo_registro = malloc(sizeof(Registro));
    
    // le as informações dos pacientes e adiciona em um novo registro
    char *info = strtok(buffer, ";"); //separa as informações
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

    cadastros->qtd++;

  }

  fclose(arquivo);

  return cadastros; // retorna a lista com todos os pacientes que estão no banco de dados
}

int salva_arquivo(Lista *lista) //salva novamente todos os dados dos pacientes em um arquivo
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

  
  Lista *pacientes = le_arquivo();

  arquivo = fopen("dados.txt", "w");

  if(arquivo == NULL) return 0;

  atual = pacientes->inicio;

  while(atual != NULL)
  {
    fprintf(arquivo, "%s;%d;%s;%d;%d;%d\n", atual->dados->nome, atual->dados->idade, atual->dados->rg, atual->dados->entrada.dia, atual->dados->entrada.mes, atual->dados->entrada.ano);
    atual = atual->proximo;
  }

  fclose(arquivo);

  libera_lista(pacientes);
  
  return 1;
}
