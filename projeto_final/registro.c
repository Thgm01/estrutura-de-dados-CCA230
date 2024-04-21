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

void limpa_registro(Registro *registro)
{
    free(registro->nome);
    free(registro->rg);
    free(registro);
}

void mostra_registro(Registro *registro)
{
    if(registro != NULL)
    {
        printf("------------------------------\n");
        printf("Nome: %s\n", registro->nome);
        printf("Idade: %d\n", registro->idade);
        printf("RG: %s\n", registro->rg);
        printf("%d/%d/%d\n", registro->entrada.dia, registro->entrada.mes, registro->entrada.ano);
        printf("------------------------------\n");
    }
    else
    {
        printf("Paciente Não Encontrado\n");
    }
}

void mostra_nome(Registro *registro)
{
    printf(" - %s\n", registro->nome);
}

void mostra_rg(Registro *registro)
{
    printf(" - %s\n", registro->rg);
}

void edita_registro(Registro *registro, const int opt)
{
    if(registro != NULL)
    {
        switch (opt)
        {
            case 1:
            {
                char *novo_nome = recebe_nome(); 
                registro->nome = realloc(registro->nome, strlen(novo_nome)*sizeof(char));
                strcpy(registro->nome, novo_nome);

                free(novo_nome);
                break;
            }
            case 2:
                registro->idade = recebe_idade();
                break;
            
            case 3:
            {
                char *novo_rg = recebe_rg();
                strcpy(registro->rg, novo_rg);

                free(novo_rg);
                break;
            }

        }
    }
    else
    {
        printf("Paciente Não Encontrado");
    }
}
