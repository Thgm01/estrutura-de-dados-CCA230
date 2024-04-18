#include "lista.h"
#include "registro.h"
#include "arquivos.h"

int main()
{
  // Lista *l = cria_lista();

  // cadastrar_novo_paciente(l);
  // system("clear");
  // mostra_lista(l, 0);
  // cadastrar_novo_paciente(l);
  // mostra_lista(l, 0);
  // cadastrar_novo_paciente(l);
  // mostra_lista(l, 1);
  // cadastrar_novo_paciente(l);
  // mostra_lista(l, 2);
  
  // system("clear");

  // mostra_lista(l,0);
  // char *rg = "0987";
  // printf("\n\nRegistro com nome de: %s\n", rg);

  // mostra_registro(acha_registro(l, rg)->dados);

  // limpa_lista(l);

  Lista *l = le_arquivo("dados.txt");

  mostra_lista(l, 0);

  cadastrar_novo_paciente(l);

  salva_arquivo(l);

  return 0;
}
