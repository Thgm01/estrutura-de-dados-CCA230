#include "lista.h"
#include "arquivos.h"
#include "fila.h"

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

  // mostra_registro(acha_registro(l, rg)->dados); // FAZER IF ANTES PARA NN DAR NULL->DADOS (erro)

  // limpa_lista(l);

  Lista *l = le_arquivo();
  Fila *f = cria_fila();

  mostra_lista(l, 0);

  //cadastrar_novo_paciente(l);
  enfileirar(f, acha_registro(l, "Thiago Moura"));
  enfileirar(f, acha_registro(l, "Lucas Lagoeiro"));
  //edita_registro(acha_registro(l, "1234"), 1);
  

  system("clear");

  mostra_fila(f);

  getchar();

  system("clear");

  mostra_registro(desenfileirar(f));

  getchar();

  system("clear");

  mostra_fila(f);

  libera_fila(f); 
  
  salva_arquivo(l);

  return 0;
}
