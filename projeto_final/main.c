#include "lista.h"
#include "arquivos.h"
#include "arvore_binaria.h"
#include "fila.h"
#include "ui.h"

#include <stdlib.h>
#include <string.h>

int main()
{

  Lista *pacientes = le_arquivo();
  // ArvoreBinaria *buscar_idade =  inserir_todos_registros(pacientes, 1);

  // in_ordem(buscar_idade->raiz);
  

  Fila *atendimentos = cria_fila();

  int opt = 1;
  enum Pagina pagina = INICIAL;

  do
  {

    switch (pagina)
    {
      case INICIAL:
        initial_page();
        break;
      
      case REGISTROS:
        registros_page();
        break;

      case CADASTRO:
        cadastro_page();
        cadastrar_novo_paciente(pacientes);
        cadastrado_page();
        break;

      case MOSTRAR_PACIENTES:
        mostrar_todos_registros(pacientes);
        break;

      case CONSULTAR:
        consultar_paciente(pacientes);
        break;

      case ATUALIZAR:
        atualizar_registro(pacientes);
        break;

      case REMOVER:
        remover_registro(pacientes);
        break;

      
      case ATENDIMENTOS:
        atendimentos_page();
        break;

      case ENFILEIRAR:
        enfileirar_registro(pacientes, atendimentos);
        break;

      case DESENFILEIRAR:
        desenfileirar_registro(pacientes, atendimentos);
        break;

      case MOSTRAR_FILA:
        mostrar_toda_fila(atendimentos);
        break;

      
      case PESQUISA:
        pesquisa_page();
        break;
      
      case SOBRE:
        authors_info();
        break;

      default:
        printf("Outra Pagina");
        break;
    }

    get_opt(&opt, &pagina);

    change_page(&opt, &pagina);

  } while (opt != 5 || pagina != INICIAL);
  
  clear_screen();
  
  salva_arquivo(pacientes);

  libera_lista(pacientes);
  libera_fila(atendimentos);

}
