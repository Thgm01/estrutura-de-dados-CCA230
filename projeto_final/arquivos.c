#include "arquivos.h"
#include "lista.h"
#include "registro.h"


Lista *le_arquivo(const char *nome_arquivo)
{
  FILE *arquivo = fopen(nome_arquivo, "r");

  if(arquivo == NULL) return NULL;

  Lista *cadastros = cria_lista();
  
  char buffer[100];
  while(fgets(buffer, 100, arquivo))
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
    novo_registro->rg = rg;

    info = strtok(NULL, ";");
    novo_registro->entrada.dia = atoi(info);
    
    info = strtok(NULL, ";");
    novo_registro->entrada.mes = atoi(info);
    
    info = strtok(NULL, ";");
    novo_registro->entrada.ano = atoi(info);

    
  }


  return cadastros;
}
