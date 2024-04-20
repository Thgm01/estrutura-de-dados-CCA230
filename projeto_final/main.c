#include "lista.h"
#include "arquivos.h"
#include "fila.h"
#include "ui.h"

#include <stdlib.h>
#include <string.h>

int main()
{

  Lista *pacientes = le_arquivo();

  // Registro *paciente = acha_registro(pacientes, "Thiago Moura");
  // Registro *paciente2 = acha_registro(pacientes, "Lucas Lagoeiro");
  
  


  // consultar_page();
  // mostra_registro2(paciente, paciente2);
  // draw_botton_line(SIZE_MENU, 1);
  // mostra_registro(paciente);

  // draw_top_line(SIZE_MENU, 1);
  // draw_top_registro(1);


  // draw_nome_registro(paciente->nome, 0);
  // draw_empty_registro();
  // draw_registro_cross(1);

  // char dado[SIZE_TASK];


  // draw_vertical_line(1);
  // sprintf(dado, "Idade: %d", paciente->idade);
  // draw_vertical_line(1);
  // draw_spaces(SIZE_TASK/2 - 5);
  // printf("%s", dado);
  // draw_spaces(SIZE_TASK/2 + 5 - strlen(dado));
  // draw_vertical_line(1);
  // draw_empty_registro();

  // draw_vertical_line(1);
  // sprintf(dado, "RG: %s", paciente->rg);
  // draw_vertical_line(1);
  // draw_spaces(SIZE_TASK/2 - 5);
  // printf("%s", dado);
  // draw_spaces(SIZE_TASK/2 + 5 - strlen(dado));
  // draw_vertical_line(1);
  // draw_empty_registro();

  // draw_vertical_line(1);
  // sprintf(dado, "Entrada: %d/%d/%d", paciente->entrada.dia, paciente->entrada.mes, paciente->entrada.ano);
  // draw_vertical_line(1);
  // draw_spaces(SIZE_TASK/2 - 5);
  // printf("%s", dado);
  // draw_spaces(SIZE_TASK/2 + 5 - strlen(dado));
  // draw_vertical_line(1);
  // draw_empty_registro();

  // draw_botton_registo(2);



  // draw_vertical_line(1);
  // sprintf(dado, "RG: %s", paciente->rg);
  // center_text(SIZE_TASK, dado, 0);
  // draw_empty_registro();

  // draw_vertical_line(1);
  // sprintf(dado, "%d/%d/%d", paciente->entrada.dia, paciente->entrada.mes, paciente->entrada.ano);
  // center_text(SIZE_TASK, dado, 0);
  // draw_empty_registro();




  









  

  // draw_vertical_line(1);
  // center_text(SIZE_TASK, paciente->nome, 0);
  // draw_spaces(160 - (SIZE_TASK+2));
  // draw_vertical_line(1);
  // new_line();
  // draw_registro_cross(1);

  //getchar();



  int opt = 1;
  enum Pagina pagina = ATUALIZAR;

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
  




  // // Lista *l = cria_lista();

  // // cadastrar_novo_paciente(l);
  // // system("clear");
  // // mostra_lista(l, 0);
  // // cadastrar_novo_paciente(l);
  // // mostra_lista(l, 0);
  // // cadastrar_novo_paciente(l);
  // // mostra_lista(l, 1);
  // // cadastrar_novo_paciente(l);
  // // mostra_lista(l, 2);
  
  // // system("clear");

  // // mostra_lista(l,0);
  // // char *rg = "0987";
  // // printf("\n\nRegistro com nome de: %s\n", rg);

  // // mostra_registro(acha_registro(l, rg)->dados); // FAZER IF ANTES PARA NN DAR NULL->DADOS (erro)

  // // limpa_lista(l);

  // Lista *l = le_arquivo();
  // Fila *f = cria_fila();

  // mostra_lista(l, 0);

  // //cadastrar_novo_paciente(l);
  // enfileirar(f, acha_registro(l, "Thiago Moura"));
  // enfileirar(f, acha_registro(l, "Lucas Lagoeiro"));
  // //edita_registro(acha_registro(l, "1234"), 1);
  

  // system("clear");

  // mostra_fila(f);

  // getchar();

  // system("clear");

  // mostra_registro(desenfileirar(f));

  // getchar();

  // system("clear");

  // mostra_fila(f);

  // libera_fila(f); 
  
  // salva_arquivo(l);

  // return 0;
}
