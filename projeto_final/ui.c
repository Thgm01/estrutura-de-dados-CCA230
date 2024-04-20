#include "ui.h"

#include "utils.h"
#include "lista.h"

void draw_menu_header(char* title)
{
    draw_top_line(SIZE_MENU, 1);
    draw_blank_line(SIZE_MENU);
    center_text(SIZE_MENU, title, 1);
    draw_blank_line(SIZE_MENU);
}

void draw_tasks(int qnt_tasks, char ** titles, char **descriptions, char **initial_dates, char **final_dates, int *status)
{
    if(qnt_tasks == 0)
    {
        draw_blank_line(SIZE_MENU);
        center_text(SIZE_MENU, "Nenhuma Tarefa!", 1);
        draw_blank_line(SIZE_MENU);
        draw_blank_line(SIZE_MENU);
    }
    else 
    {
        draw_top_tasks(qnt_tasks);
        draw_task_titles(qnt_tasks, titles);
        draw_tasks_cross(qnt_tasks);
        write_descriptions(qnt_tasks, descriptions);
        draw_tasks_cross(qnt_tasks);
        write_date(qnt_tasks, initial_dates, final_dates);
        draw_tasks_cross(qnt_tasks);
        write_status(qnt_tasks, status);
        draw_botton_tasks(qnt_tasks);
        draw_blank_line(SIZE_MENU);
    }
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

void draw_top_tasks(int qnt_tasks)
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

void draw_tasks_cross(int qnt_tasks)
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

void write_descriptions(int qnt_tasks, char ** descriptions)
{
    draw_vertical_line(1);
    for(int i=0; i<qnt_tasks; i++)
    {
        center_text(SIZE_TASK, descriptions[i], 0);
    }
    draw_spaces(160 - (SIZE_TASK+2)*qnt_tasks);
    draw_vertical_line(1);
    new_line();
}

void write_date(int qnt_tasks, char ** inicial_dates, char** final_dates) // Falta terminar
{
    draw_vertical_line(1);
    for(int i=0; i<qnt_tasks; i++)
    {
        char formated_dates[SIZE_TASK];
        
        snprintf(formated_dates, SIZE_TASK, "Criado em %s / Data Final %s", inicial_dates[i], final_dates[i]);
        center_text(SIZE_TASK, formated_dates, 0);
    }
    draw_spaces(160 - (SIZE_TASK+2)*qnt_tasks);
    draw_vertical_line(1);
    new_line();
}

void write_status(int qnt_tasks, int *status) // 0 - a fazer, 1 - fazendo, 2 - Travado, 3 - Feito
{
    draw_vertical_line(1);

    for(int i=0; i<qnt_tasks; i++)
    {
        char status_text[30] = "Status: ";

        switch (status[i])
        {
        case 0:
            strcat(status_text, "A Fazer.");
            break;
        
        case 1:
            strcat(status_text, "Fazendo.");
            break;
        
        case 2:
            strcat(status_text, "Travado.");
            break;

        case 3:
            strcat(status_text, "Feito.");
            break;
        } 
        center_text(SIZE_TASK, status_text, 0);
    }
    draw_spaces(160 - (SIZE_TASK+2)*qnt_tasks);
    draw_vertical_line(1);
    new_line();
}

void draw_botton_tasks(int qnt_tasks)
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
    center_text(SIZE_MENU, "1 - Cadastrar Paciente ",1);
    center_text(SIZE_MENU, "2 - Mostrar Pacientes  ",1);
    center_text(SIZE_MENU, "3 - Consultar Paciente ",1);
    center_text(SIZE_MENU, "4 - Atualizar Dados    ", 1);
    center_text(SIZE_MENU, "5 - Remover Paciente   ", 1);
    center_text(SIZE_MENU, "6 - Voltar             ", 1);
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

    default:
        lim[0] = 0;
        lim[1] = 0;
        break;
    }

    if (*pagina == SOBRE || *pagina == CADASTRO || *pagina == CONSULTAR)
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

    case SOBRE:
        *pagina = INICIAL;
        break;

    case CADASTRO:
    case CONSULTAR:
        *pagina = REGISTROS;
        break;

    default:
        break;
    }
}

void consultar_paciente(Lista *lista)
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
        return;
    }

    mostra_registro(registro);

    free(info);

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
