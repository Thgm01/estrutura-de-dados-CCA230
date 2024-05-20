#ifndef REGISTRO_H
#define REGISTRO_H

typedef struct Data
{
    int dia;
    int mes;
    int ano;
}Data;


typedef struct Registro //estrutura base do paciente
{
    char *nome;
    int idade;
    char *rg;
    Data entrada;
}Registro;

Registro *cria_registro();
void limpa_registro(Registro * registro);
void mostra_registro(Registro * registro);
void mostra_nome(Registro * registro);
void mostra_rg(Registro * registro);
void edita_registro(Registro *registro, const int opt);




#endif
