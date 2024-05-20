#ifndef UTILS_H
#define UTILS_H

#include "registro.h"
#include "ui.h"
#include "arvore_binaria.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char * recebe_nome();
int recebe_idade();
char * recebe_rg();
Data recebe_data();

struct tm * recebe_dia_atual();
char * stdin_dinamico();

Vertice *acha_filho_direito(Vertice *v);
int e_filho_esq(Vertice *v);
int num_filhos(Vertice *v);
int data_maior(Data data1, Data data2);

#endif
