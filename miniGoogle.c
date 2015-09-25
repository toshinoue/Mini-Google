#include <stdio.h>
#include <stdlib.h>
#include "miniGoogle.h"

struct site{
	short int codigo;
	char nomeSite[TAM];
	short int relevancia;
	char link[N];
	char *chave[50];
};
