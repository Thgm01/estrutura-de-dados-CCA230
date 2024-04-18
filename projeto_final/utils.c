#include "utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char * recebe_nome()
{
  printf("Nome do Paciente: ");
  char * nome = stdin_dinamico();

  return nome;
}

int recebe_idade()
{
  int idade;
  
  printf("Idade do Paciente: ");
  scanf("%d", &idade);

  return idade;
}

char * recebe_rg()
{
  char *rg = malloc(11 * sizeof(char));
  
  printf("Rg do Paciente: ");
  scanf("%s", rg);
  getchar();

  return rg;
}

Data recebe_data()
{
  Data tempo_atual;
  
  struct tm * data_atual = recebe_dia_atual();
  
  tempo_atual.dia = data_atual->tm_mday;
  tempo_atual.mes = data_atual->tm_mon + 1;
  tempo_atual.ano = data_atual->tm_year + 1900;

  return tempo_atual;
}



struct tm * recebe_dia_atual()
{
  time_t s;

  time(&s);

  return localtime(&s);
}

char * stdin_dinamico()
{
  char * buffer = malloc(100 * sizeof(char));
  int len = 0;
  char caracter;
  while((caracter = fgetc(stdin)) != '\n' && !feof(stdin) && len != 100)
  {
    buffer[len++] = caracter;
  }

  buffer = realloc(buffer, (len+1)*sizeof(char));
    
  buffer[len] = '\0';

  return buffer;
}
