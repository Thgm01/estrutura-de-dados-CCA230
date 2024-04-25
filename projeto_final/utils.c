#include "utils.h"

char * recebe_nome()
{
  draw_spaces(SIZE_MENU/2 - 20);
  printf("Nome do Paciente: ");
  char * nome = stdin_dinamico();

  return nome;
}

int recebe_idade()
{
  int idade;

  draw_spaces(SIZE_MENU/2 - 20);
  printf("Idade do Paciente: ");
  scanf("%d", &idade);

  return idade;
}

char * recebe_rg()
{
  char *rg = malloc(11 * sizeof(char));
  
  draw_spaces(SIZE_MENU/2 - 20);
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

int data_maior(Data data1, Data data2)
{
  if(data1.ano > data2.ano) return 1;
  else if(data1.ano < data2.ano) return 2;
  else
  {
    if(data1.mes > data2.mes) return 1;
    else if(data1.mes < data2.mes) return 2;
    else
    {
      if(data1.dia > data2.dia) return 1;
      else return 2;
    }
  }
}

