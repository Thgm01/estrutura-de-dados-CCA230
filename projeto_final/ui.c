#include "ui.h"

#include "utils.h"
#include "lista.h"
#include "fila.h"

void draw_menu_header(char* title)
{
    draw_top_line(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    center_text(SIZE_MENU, title, 1);
    draw_blank_line(SIZE_MENU);
}

void draw_initial_menu_options()
{
    draw_line_cross(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    draw_initial_options();
    draw_blank_line(SIZE_MENU);
    draw_botton_line(SIZE_MENU, 1);
}

void draw_registros_menu_options()
{
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "REGISTROS", 1);
    draw_line_cross(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    draw_registros_options();
    draw_blank_line(SIZE_MENU);
    draw_botton_line(SIZE_MENU, 1);
}

void new_line()
{
    printf("\n");
}

void draw_horizontal_line(int length)
{
    for(int i=0; i<length;i++) printf("%s", HL);
}

void draw_top_line(int length, int end_line)
{
    printf("%s", LT);
    draw_horizontal_line(length);
    printf("%s", RT);
    if(end_line)
    {
        new_line();
    }
}

void draw_line_cross(int length, int end_line)
{
    printf("%s", LC);
    draw_horizontal_line(length);
    printf("%s", RC);
    if(end_line)
    {
        new_line();
    }

}

void draw_botton_line(int length, int end_line)
{
    printf("%s", LB);
    draw_horizontal_line(length);
    printf("%s", RB);
    if(end_line)
    {
        new_line();
    }
}

void center_text(int length, char* text, int end_line)
{
    int text_length = strlen(text);
    int space_length = (length - text_length)/2;

    draw_vertical_line(1);
    
    //Add spaces before the text
    for(int i=0; i<space_length; i++){
        printf("%s", SP);
    }
    printf("%s", text);

    //If the text is odd, we need to add one more space after the text
    if(text_length%2 != 0){
        space_length++;
    }

    for(int i=0; i<space_length; i++)
    {
        printf("%s", SP);
    }
    
    draw_vertical_line(1);
    if(end_line)
    {
        new_line();
    }
}

void draw_vertical_line(int length)
{
    for(int i = 0; i < length-1; i++){
        printf("%s\n", VL);
    }
    printf("%s", VL);
}

void draw_blank_line(int length)
{
    draw_vertical_line(1);
    for(int i = 0; i < length; i++){
        printf("%s", SP);
    }
    draw_vertical_line(1);
    new_line();
}

void draw_top_registro(int qnt_tasks)
{
    draw_vertical_line(1);
    for(int i=0; i< qnt_tasks; i++)
    {
        draw_top_line(SIZE_TASK, 0);
    }
    draw_spaces(160 - (SIZE_TASK+2)*qnt_tasks);
    draw_vertical_line(1);
    new_line();
}

void draw_nome_registro(char *nome, int end_line)
{
    if(!end_line) draw_vertical_line(1);

    center_text(SIZE_TASK, nome, 0);

    if (end_line)
    {
        draw_vertical_line(1);
        new_line();
    }
}

void draw_empty_registro()
{
    draw_spaces(160 - (SIZE_TASK+2));
    draw_vertical_line(1);
    new_line();
}

void draw_spaces(int size)
{
    for(int i=0; i<size; i++) printf("%s", SP);
}

void draw_task_titles(int qnt_tasks, char ** titles)
{
    draw_vertical_line(1);
    for(int i=0; i<qnt_tasks; i++)
    {
        center_text(SIZE_TASK, titles[i], 0);
    }
    draw_spaces(160 - (SIZE_TASK+2)*qnt_tasks);
    draw_vertical_line(1);
    new_line();
}

void draw_registro_cross(int qnt_tasks)
{
    draw_vertical_line(1);
    for(int i=0; i<qnt_tasks; i++)
    {
        draw_line_cross(SIZE_TASK, 0);
    }
    draw_spaces(160 - (SIZE_TASK+2)*qnt_tasks);
    draw_vertical_line(1);
    new_line();
}

void draw_botton_registo(int qnt_tasks)
{
    draw_vertical_line(1);
    for(int i=0; i< qnt_tasks; i++)
    {
        draw_botton_line(SIZE_TASK, 0);
    }
    draw_spaces(160 - (SIZE_TASK+2)*qnt_tasks);
    draw_vertical_line(1);
    new_line();
}

void draw_initial_options()
{
    center_text(SIZE_MENU, "1 - Registros    ",1);
    center_text(SIZE_MENU, "2 - Atendimentos ",1);
    center_text(SIZE_MENU, "3 - Pesquisa     ",1);
    center_text(SIZE_MENU, "4 - Sobre Autores", 1);
    center_text(SIZE_MENU, "5 - Sair         ", 1);
}

void draw_registros_options()
{
    center_text(SIZE_MENU, "1 - Cadastrar Paciente     ",1);
    center_text(SIZE_MENU, "2 - Mostrar Todos Pacientes",1);
    center_text(SIZE_MENU, "3 - Consultar Paciente     ",1);
    center_text(SIZE_MENU, "4 - Atualizar Dados        ", 1);
    center_text(SIZE_MENU, "5 - Remover Paciente       ", 1);
    center_text(SIZE_MENU, "6 - Voltar                 ", 1);
}

void editar_registro_page()
{
    center_text(SIZE_MENU, "1 - Editar Nome ",1);
    center_text(SIZE_MENU, "2 - Editar Idade",1);
    center_text(SIZE_MENU, "3 - Editar RG   ",1);
    draw_botton_line(SIZE_MENU, 1);
}

void clear_screen()
{
    system("clear");
}


void initial_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_initial_menu_options();
}


void registros_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_registros_menu_options();
}

void cadastro_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "NOVO REGISTRO", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void atendimentos_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    atendimento_menu_options();
    draw_blank_line(SIZE_MENU);
    draw_botton_line(SIZE_MENU, 1);
}

void pesquisa_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    pesquisa_options();
}

void pesquisa_options()
{
    draw_line_cross(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    center_text(SIZE_MENU, "1 - Mostar Registros Ordenados por Idade         ",1);
    center_text(SIZE_MENU, "2 - Mostar Registros Ordenados por Data de Castro",1);
    center_text(SIZE_MENU, "3 - Voltar                                       ",1); 
    draw_blank_line(SIZE_MENU);
    draw_botton_line(SIZE_MENU, 1);
}

void atendimento_menu_options()
{
    center_text(SIZE_MENU, "1 - Adicionar paciente na Fila",1);
    center_text(SIZE_MENU, "2 - Remover paciente da Fila  ",1);
    center_text(SIZE_MENU, "3 - Mostrar Fila              ",1);
    center_text(SIZE_MENU, "4 - Voltar                    ",1);  
}

void cadastrado_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "PACIENTE CADASTRADO COM SUCESSO", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void consultar_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "PESQUISAR PACIENTE", 1);
    draw_botton_line(SIZE_MENU, 1);
}


void get_opt(int *opt, const enum Pagina *pagina)
{
    int lim[2];
    switch (*pagina)
    {
    case INICIAL:
        lim[0] = 1;
        lim[1] = 4;
        break;

    case REGISTROS:
        lim[0] = 1;
        lim[1] = 6;
        break;
    
    case ATENDIMENTOS:
        lim[0] = 1;
        lim[1] = 4;
        break;

    case PESQUISA:
        lim[0] = 1;
        lim[1] = 3;
        break;
    default:
        lim[0] = 1;
        lim[1] = 3;
        break;
    }

    if (*pagina == SOBRE || *pagina == CADASTRO || *pagina == CONSULTAR || *pagina == MOSTRAR_PACIENTES || *pagina == ATUALIZAR || *pagina == REMOVER || *pagina == ENFILEIRAR || *pagina == DESENFILEIRAR || *pagina == MOSTRAR_FILA || *pagina == MOSTRAR_ORDEM_DATA || *pagina == MOSTRAR_ORDEM_IDADE)
    {
        getchar();
        return;
    }

    
    if(*opt < lim[0] || *opt > lim[1])
    {
        draw_spaces(SIZE_MENU/2 - 15/2);
        printf("OPÇÃO INVALIDA!\n");
    }

    draw_spaces(SIZE_MENU/2 - 7);
    printf("OPÇÂO: ");
    scanf("%d", opt);
    getchar();
}

void change_page(int *opt, enum Pagina *pagina)
{
    switch (*pagina)
    {
    case INICIAL:
    {
        if      (*opt == 1) *pagina = REGISTROS;
        else if (*opt == 2) *pagina = ATENDIMENTOS;
        else if (*opt == 3) *pagina = PESQUISA;
        else if (*opt == 4) *pagina = SOBRE;
        else break;

        *opt = 1;
        break;
    }
    case REGISTROS:
    {
        if      (*opt == 1) *pagina = CADASTRO;
        else if (*opt == 2) *pagina = MOSTRAR_PACIENTES;
        else if (*opt == 3) *pagina = CONSULTAR;
        else if (*opt == 4) *pagina = ATUALIZAR;
        else if (*opt == 5) *pagina = REMOVER;
        else if (*opt == 6) *pagina = INICIAL;
        else break;

        *opt = 1;
        break;
    }

    case ATENDIMENTOS:
    {
        if      (*opt == 1) *pagina = ENFILEIRAR;
        else if (*opt == 2) *pagina = DESENFILEIRAR;
        else if (*opt == 3) *pagina = MOSTRAR_FILA;
        else if (*opt == 4) *pagina = INICIAL;
        else break;

        *opt = 1;
        break;
    }
    case ENFILEIRAR:
    case DESENFILEIRAR:
    case MOSTRAR_FILA:
        *pagina = ATENDIMENTOS;
        break;

    case PESQUISA:
        if      (*opt == 1) *pagina = MOSTRAR_ORDEM_IDADE;
        else if (*opt == 2) *pagina = MOSTRAR_ORDEM_DATA;
        else if (*opt == 3) *pagina = INICIAL;
        else break;

        *opt = 1;
        break;

    case MOSTRAR_ORDEM_IDADE:
    case MOSTRAR_ORDEM_DATA:
        *pagina = PESQUISA;

    case SOBRE:
        *pagina = INICIAL;
        break;

    case CADASTRO:
    case CONSULTAR:
    case MOSTRAR_PACIENTES:
    case ATUALIZAR:
    case REMOVER:
        *pagina = REGISTROS;
        break;

    default:
        break;
    }
}

void consultar_paciente(Lista *lista)
{
    enfileirar_page();

    char *info;
    draw_spaces(SIZE_MENU/2 - 12);
    printf("Nome ou RG: ");
    info = stdin_dinamico();

    Registro *registro = acha_registro(lista, info);
    
    if(registro == NULL)
    {
        draw_spaces(SIZE_MENU/2 - (24+strlen(info))/2);
        printf("Paciente %s nao encontrado\n", info);
        return;
    }
    draw_top_line(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    mostra_registro2(registro, NULL);
    draw_blank_line(SIZE_MENU);
    draw_botton_line(SIZE_MENU, 1);

    free(info);

}

void mostra_registro2(Registro *registro1, Registro *registro2) // terminar
{
    int qtd = (registro2 == NULL) ?  1 : 2;
    draw_top_registro(qtd);
    draw_space_registro(qtd);
    mostra_nome_registro(registro1, registro2);
    draw_space_registro(qtd);
    draw_registro_cross(qtd);
    draw_space_registro(qtd);
    draw_info_registros(registro1, registro2);
    draw_space_registro(qtd);
    draw_botton_registo(qtd);
    draw_blank_line(SIZE_MENU);    
}

void draw_space_registro(int qtd)
{
    draw_vertical_line(1);
    center_text(SIZE_TASK, "",0);

    if(qtd == 2)
    {
        center_text(SIZE_TASK, "",0);
        draw_vertical_line(1);
        new_line();
    }
    else draw_empty_registro();
}

void mostra_nome_registro(Registro *registro1, Registro *registro2)
{
    draw_nome_registro(registro1->nome, 0);

    if(registro2 == NULL) draw_empty_registro();
    else draw_nome_registro(registro2->nome, 1);

}

void draw_info_registros(Registro *registro1, Registro *registro2)
{
    char info[SIZE_TASK];

    sprintf(info, "Idade: %d", registro1->idade);
    center_task_info(info, 0);

    if(registro2 != NULL)
    {
        sprintf(info, "Idade: %d", registro2->idade);
        center_task_info(info, 1);
    } 
    else draw_empty_registro();


    sprintf(info, "RG: %s", registro1->rg);
    center_task_info(info, 0);

    if(registro2 != NULL)
    {
        sprintf(info, "RG: %s", registro2->rg);
        center_task_info(info, 1);
    }   
    else draw_empty_registro(); 


    sprintf(info, "Entrada: %d/%d/%d", registro1->entrada.dia, registro1->entrada.mes, registro1->entrada.ano);
    center_task_info(info, 0);

    if(registro2 != NULL)
    {
        sprintf(info, "Entrada: %d/%d/%d", registro2->entrada.dia, registro2->entrada.mes, registro2->entrada.ano);
        center_task_info(info, 1);
    }   
    else draw_empty_registro();
}

void center_task_info(char *info, int end_line)
{
    if(!end_line) draw_vertical_line(1);

    draw_vertical_line(1);
    draw_spaces(SIZE_TASK/2 - 5);
    printf("%s", info);
    draw_spaces(SIZE_TASK/2 + 5 - strlen(info));
    draw_vertical_line(1);

    if(end_line)
    {
        draw_vertical_line(1);
        new_line();
    }

}

void authors_info()
{
    clear_screen();
    draw_top_line(SIZE_TASK, 1);
    draw_blank_line(SIZE_TASK);
    center_text(SIZE_TASK, "SOBRE OS AUTORES", 1);
    draw_blank_line(SIZE_TASK);
    draw_line_cross(SIZE_TASK, 1);

    draw_blank_line(SIZE_TASK);
    center_text(SIZE_TASK, "Thiago T. Moura                      ", 1);
    center_text(SIZE_TASK, "Eng. de Controle e Automacao, 7o Sem.", 1);
    center_text(SIZE_TASK, "Centro Universitario FEI, 2024       ", 1);
    center_text(SIZE_TASK, "https://github.com/Thgm01            ", 1);
    draw_blank_line(SIZE_TASK);

    draw_line_cross(SIZE_TASK, 1);
    draw_blank_line(SIZE_TASK);
    center_text(SIZE_TASK, "Lucas Lagoeiro                       ", 1);
    center_text(SIZE_TASK, "Engenharia de Robos, 7o Sem.         ", 1);
    center_text(SIZE_TASK, "Centro Universitario FEI, 2024       ", 1);
    center_text(SIZE_TASK, "https://github.com/LucasLagoeiro     ", 1);
    draw_blank_line(SIZE_TASK);

    draw_line_cross(SIZE_TASK, 1);
    draw_blank_line(SIZE_TASK);
    center_text(SIZE_TASK, "Presione qualquer tecla para voltar (menos Crtl+C)", 1);
    draw_blank_line(SIZE_TASK);
    draw_botton_line(SIZE_TASK, 1);
}

void mostrar_todos_registros(Lista *lista)
{
    mostrar_todos_registros_header();

    if(lista->qtd != 0)
    {
        ELista *atual = lista->inicio;

        for(int i=0; i < (lista->qtd/2)+(lista->qtd%2); i++)
        {
            Registro * paciente1 = atual->dados;
            Registro * paciente2;
            if(atual->proximo != NULL) paciente2 = atual->proximo->dados;
            else paciente2 = NULL;
            
            mostra_registro2(paciente1, paciente2);

            if(paciente2 == NULL) break;
            atual = atual->proximo->proximo;
        }
    }
    
    draw_botton_line(SIZE_MENU, 1);
}

void mostrar_todos_registros_header()
{
    clear_screen();
    draw_top_line(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    center_text(SIZE_MENU, "TODOS OS PACIENTES", 1);
    draw_blank_line(SIZE_MENU);
    draw_line_cross(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
}

void atualizar_registro(Lista *lista)
{
    atualizar_registro_page();

    char *info;
    draw_spaces(SIZE_MENU/2 - 12);
    printf("Nome ou RG: ");
    info = stdin_dinamico();

    Registro *registro = acha_registro(lista, info);

    free(info);

    if (registro == NULL)
    {
        printf("Paciente nao encontrado");
        return;
    }

    draw_top_line(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    mostra_registro2(registro, NULL);
    draw_blank_line(SIZE_MENU);
    draw_line_cross(SIZE_MENU, 1);
    editar_registro_page();
    draw_spaces(SIZE_MENU/2 - 7);
    
    int opt;
    printf("OPÇÂO: ");
    scanf("%d", &opt);
    getchar();
    
    if(opt > 3 || opt < 1)
    {
        draw_spaces(SIZE_MENU/2 - 7);
        printf("OPÇÃO INVALIDA\n");
        return;
    }

    edita_registro(registro, opt);

    registro_atualizado_page();
    
}

void registro_atualizado_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "DADOS ATUALIZADOS COM SUCESSO", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void atualizar_registro_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "EDITAR REGISTRO", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void remove_registro_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "REMOVER REGISTRO", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void remover_registro(Lista *lista)
{
    remove_registro_page();

    char *info;
    draw_spaces(SIZE_MENU/2 - 12);
    printf("Nome ou RG: ");
    info = stdin_dinamico();

    Registro *registro = acha_registro(lista, info);

    if (registro == NULL)
    {
        printf("Paciente nao encontrado");
        return;
    }

    draw_top_line(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    mostra_registro2(registro, NULL);
    draw_blank_line(SIZE_MENU);
    draw_line_cross(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    
    char buffer[100];
    sprintf(buffer, "Confirmar Remocao de %s?", registro->nome);
    center_text(SIZE_MENU, buffer, 1);
    confirmar_remover_page();

    draw_spaces(SIZE_MENU/2 - 7);
    int opt;
    printf("OPÇÂO: ");
    scanf("%d", &opt);
    getchar();
    if(opt == 1)
    {
        remove_registro(lista, info);
        registro_removido_page();
    }
    else if(opt == 2)
    {
        remocao_cancelada_page();
    }

    free(info);
}

void remocao_cancelada_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "REMOCAO DE REGISTRO CANCELADA", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void registro_removido_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "REGISTRO REMOVIDO COM SUCESSO", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void confirmar_remover_page()
{
    draw_blank_line(SIZE_MENU);

    center_text(SIZE_MENU, "1 - SIM",1);
    center_text(SIZE_MENU, "2 - NAO",1);
    draw_blank_line(SIZE_MENU);
    draw_botton_line(SIZE_MENU, 1);
}

void enfileirar_registro(Lista *lista, Fila *fila)
{
    consultar_page();

    char *info;
    draw_spaces(SIZE_MENU/2 - 12);
    printf("Nome ou RG: ");
    info = stdin_dinamico();

    Registro *registro = acha_registro(lista, info);
    
    if(registro == NULL)
    {
        draw_spaces(SIZE_MENU/2 - (24+strlen(info))/2);
        printf("Paciente %s nao encontrado\n", info);
        free(info);
        return;
    }
    free(info);

    draw_top_line(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    mostra_registro2(registro, NULL);
    draw_blank_line(SIZE_MENU);
    draw_line_cross(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);


    char buffer[100];
    sprintf(buffer, "Confirmar agendamento de %s?", registro->nome);
    center_text(SIZE_MENU, buffer, 1);
    confirmar_remover_page();
    
    draw_spaces(SIZE_MENU/2 - 7);
    int opt;
    printf("OPÇÂO: ");
    scanf("%d", &opt);
    getchar();

    if(opt == 1)
    {
        registro_enfileirado_page();
        enfileirar(fila, registro);
        mostra_fila(fila);
    }
    else if(opt == 2) agendamento_cancelado_page();
}

void agendamento_cancelado_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "AGENDAMENTO CANCELADO", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void registro_enfileirado_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "REGISTRO AGENDADO COM SUCESSO", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void enfileirar_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "ADICIONAR PACIENTE NA FILA", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void desenfileirar_registro(Lista *lista, Fila *fila)
{
    desenfileirar_page();
    if(fila->qtd == 0)
    {
        center_text(SIZE_MENU, "FILA VAZIA", 1);
        draw_blank_line(SIZE_MENU);
        draw_botton_line(SIZE_MENU, 1);
        return;
    }

    Registro *registro = fila->head->dados;

    mostra_registro2(registro, NULL);
    draw_line_cross(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);


    char buffer[100];
    sprintf(buffer, "Confirmar retirada do agendamento de %s da fila?", registro->nome);
    center_text(SIZE_MENU, buffer, 1);
    confirmar_remover_page();
    
    draw_spaces(SIZE_MENU/2 - 7);
    int opt;
    printf("OPÇÂO: ");
    scanf("%d", &opt);
    getchar();

    if(opt == 1)
    {
        registro_desenfileirado_page();
        desenfileirar(fila);
        return;
    }
    else if(opt == 2) registro_desenfileirado_cancelado();
}

void desenfileirar_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
}

void registro_desenfileirado_page()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "PACIENTE REMOVIDO DA FILA", 1);
    draw_botton_line(SIZE_MENU, 1);
}

void registro_desenfileirado_cancelado()
{
    clear_screen();
    draw_menu_header("Hospital Universitario FEI");
    draw_line_cross(SIZE_MENU, 1);
    center_text(SIZE_MENU, "REMOCAO DO PACIENTE CANCELADA", 1);
    draw_botton_line(SIZE_MENU, 1);

}

void mostrar_toda_fila(Fila *fila)
{
    mostrar_fila_header();

    if(fila->qtd != 0)
    {
        EFila *atual = fila->head;

        for(int i=0; i < (fila->qtd/2)+(fila->qtd%2); i++)
        {
            Registro * paciente1 = atual->dados;
            Registro * paciente2;
            if(atual->proximo != NULL) paciente2 = atual->proximo->dados;
            else paciente2 = NULL;
            
            mostra_registro2(paciente1, paciente2);

            if(paciente2 == NULL) break;
            atual = atual->proximo->proximo;
        }
    }
    
    draw_botton_line(SIZE_MENU, 1);


}

void mostrar_fila_header()
{
    clear_screen();
    draw_top_line(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    center_text(SIZE_MENU, "TODOS OS PACIENTES NA FILA", 1);
    draw_blank_line(SIZE_MENU);
    draw_line_cross(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);

}