#ifndef UTILS_H
#define UTILS_H

#include "registro.h"


char * recebe_nome();
int recebe_idade();
char * recebe_rg();
Data recebe_data();

struct tm * recebe_dia_atual();
char * stdin_dinamico();

#endif
