#ifndef UTILS_H
#define UTILS_H

#include "registro.h"
#include "ui.h"

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


#endif
