#include <stdio.h>
#include <stdlib.h>
#include "miniGoogle.h"
#include "miniGoogle.c"

int main(int argc, char const *argv[])
{
	FILE *fp = fopen("googlebot.txt", "r");

	int oper;
	do{
		scanf("%d", &oper);
		switch(oper){
			case 1:
			//Inserir um novo site na lista
				break;
			case 2:
			//Inserir palavra chave
				break;
			case 3:
			//Remover um site
				break;
			case 4:
			//Atualizar relevancia
				break;
			case 5:
			//Mostrar a lista
				break;
			case 6:
			//Busca por palavra chave
				break;
			case 7:
			//Sugestao do site
				break;
		}
	}while(oper != 8)

	fclose(fp);
	return 0;
}
