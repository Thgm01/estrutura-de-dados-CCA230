#include "registro.h"

int main()
{
  Registro * r = cria_registro();
  mostra_registro(r);
  remove_registro(r);
  return 0;
}
