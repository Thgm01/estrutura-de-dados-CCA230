#include "lista.h"
#include "registro.h"

int main()
{
  Lista *l = cria_lista();

  cadastrar_novo_paciente(l);
  system("clear");
  mostra_lista(l, 0);
  cadastrar_novo_paciente(l);
  mostra_lista(l, 0);
  cadastrar_novo_paciente(l);
  mostra_lista(l, 1);
  cadastrar_novo_paciente(l);
  mostra_lista(l, 2);
  
  system("clear");

  mostra_lista(l,0);
  char *rg = "0987";
  printf("\n\nRegistro com nome de: %s\n", rg);

  mostra_registro(acha_registro(l, rg));

  limpa_lista(l);
  return 0;
}
