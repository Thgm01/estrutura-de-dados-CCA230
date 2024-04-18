#include "registro.h"
#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

Registro *cria_registro()
{
    Registro *novo_registro = malloc(sizeof(Registro));
    novo_registro->nome     = recebe_nome();
    novo_registro->idade    = recebe_idade();
    novo_registro->rg       = recebe_rg();
    novo_registro->entrada  = recebe_data();

    return novo_registro;
}

void remove_registro(Registro *registro)
{
    free(registro->nome);
    free(registro->rg);
    free(registro);
}

void mostra_registro(Registro *registro)
{
    printf("Nome: %s\n", registro->nome);
    printf("Idade: %d\n", registro->idade);
    printf("RG: %s\n", registro->rg);
    printf("%d/%d/%d\n", registro->entrada.dia, registro->entrada.mes, registro->entrada.ano);
}
