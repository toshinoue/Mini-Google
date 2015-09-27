#include "lista_seq_din.h"
#include "miniGoogle.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //LISTA_SEQ palavras;
    LISTA * teste;

	FILE *fp = fopen("googlebot.txt", "r");
	char *lista = NULL;
	char fileElement;
	int count = 0;
	fscanf(fp, "%c", &fileElement);
	while(!feof(fp)){
		lista = (char *)realloc(lista, sizeof(char) * (count+1));
		lista[count++] = fileElement;
		fscanf(fp, "%c", &fileElement);
	}
	printf("%s\n", lista);
	int oper; //pelo
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
	}while(oper != 8);
	fclose(fp);
	return 0;
}
