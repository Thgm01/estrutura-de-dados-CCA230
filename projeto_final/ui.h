#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "registro.h"
#include "fila.h"

#define SIZE_MENU 160
#define SIZE_TASK (SIZE_MENU/2 - 2)

#define RB "\e(0\x6a\e(B" // 188 Right Bottom corner
#define RT "\e(0\x6b\e(B" // 187 Right Top corner
#define LT "\e(0\x6c\e(B" // 201 Left Top cornet
#define LB "\e(0\x6d\e(B" // 200 Left Bottom corner
#define MC "\e(0\x6e\e(B" // 206 Midle Cross
#define HL "\e(0\x71\e(B" // 205 Horizontal Line
#define LC "\e(0\x74\e(B" // 204 Left Cross
#define RC "\e(0\x75\e(B" // 185 Right Cross
#define BC "\e(0\x76\e(B" // 202 Bottom Cross
#define TC "\e(0\x77\e(B" // 203 Top Cross
#define VL "\e(0\x78\e(B" // 186 Vertical Line
#define SP " " 		  // space string

enum Pagina
{
    INICIAL,
    
    REGISTROS,
    CADASTRO,
    MOSTRAR_PACIENTES,
    CONSULTAR,
    ATUALIZAR,
    REMOVER,

    ATENDIMENTOS,
    ENFILEIRAR,
    DESENFILEIRAR,
    MOSTRAR_FILA,

    PESQUISA,
    SOBRE
};

void draw_menu_header(char* title);
// void draw_tasks(int qnt_tasks, char ** titles, char **descriptions, char **initial_dates, char **final_dates, int *status);

void draw_initial_menu_options();
void draw_registros_menu_options();

void new_line();
void draw_horizontal_line(int length);
void draw_top_line(int length, int end_line);
void draw_botton_line(int length, int end_line);
void draw_line_cross(int length, int end_line);
void center_text(int length, char* text, int end_line);
void draw_vertical_line(int length);
void draw_blank_line(int length);
void draw_top_registro(int qnt_tasks);
void draw_nome_registro(char *nome, int end_line);
void draw_empty_registro();
void draw_space_registro(int qtd);
void draw_spaces(int size);
void draw_task_titles(int qnt_tasks, char ** titles);
void draw_registro_cross(int qnt_tasks);
void draw_botton_registo(int qnt_tasks);
void clear_screen();

void draw_initial_options();
void draw_registros_options();
void atendimento_menu_options();


void initial_page();
void registros_page();
void atendimentos_page();
void cadastro_page();
void cadastrado_page();
void consultar_page();
void atualizar_registro_page();
void registro_atualizado_page();
void remove_registro_page();
void confirmar_remover_page();
void registro_removido_page();
void remocao_cancelada_page();
void enfileirar_page();
void registro_enfileirado_page();
void agendamento_cancelado_page();
void desenfileirar_page();
void registro_desenfileirado_page();
void registro_desenfileirado_cancelado();
void mostrar_todos_registros_header();

void get_opt(int *opt, const enum Pagina *pagina);
void change_page(int *opt, enum Pagina *pagina);
void authors_info();
void mostra_registro2(Registro *registro1, Registro *registro2);
void mostra_nome_registro(Registro *registro1, Registro *registro2);
void draw_info_registros(Registro *registro1, Registro *registro2);
void center_task_info(char *info, int end_line);


void consultar_paciente(Lista *lista);
void mostrar_todos_registros(Lista *lista);
void atualizar_registro(Lista *lista);
void remover_registro(Lista *lista);
void enfileirar_registro(Lista *lista, Fila *fila);
void desenfileirar_registro(Lista *lista, Fila *fila);


#endif
