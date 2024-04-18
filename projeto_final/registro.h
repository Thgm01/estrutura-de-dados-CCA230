#ifndef REGISTRO_H
#define REGISTRO_H

typedef struct Data
{
    int dia;
    int mes;
    int ano;
}Data;


typedef struct Registro
{
    char *nome;
    int idade;
    char *rg;
    Data entrada;
}Registro;

Registro *cria_registro();
void remove_registro(Registro * registro);
void mostra_registro(Registro * registro);
void mostra_nome(Registro * registro);
void mostra_rg(Registro * registro);



#endif
