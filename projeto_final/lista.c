#include "registro.h"

typedef struct ELista
{
    Registro dados;
    struct ELista * proximo;

}ELista;

typedef struct
{
    ELista inicio;
    int qtd;
}Lista;
