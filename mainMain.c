#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "miniGoogle.h"

char *lerString(){
    char *string = NULL;
    char c;
    int cont = 1, fim;

    do{
        fim = scanf("%c", &c);
        string = (char*)realloc(string, sizeof(char)*cont++);
        string[cont-2] = c;
	}while(c!=10 || fim <= 0);

    string[cont-2] = '\0';

    return string;
}

ITEM *passaStruct(FILE *fp){
	ITEM *item = (ITEM *)malloc(sizeof(ITEM));

	char carac;
	char *tok;

	while(!feof(fp)){

		int count = 0;
		char *arq = NULL;

		fscanf(fp, "%c", &carac);
		while(!feof(fp) && carac != '\n'){
			arq = (char *)realloc(arq, sizeof(char) * (count+1));
			arq[count++] = carac;
			fscanf(fp, "%c", &carac);
		}

		arq = (char *)realloc(arq, sizeof(char) * (count+1));
		arq[count] = '\0';

		tok = strtok(arq, ",");
		item->codigo = atoi(tok);
		//printf("CODIGO: %.4d\n", item->codigo);

		tok = strtok(NULL, ",");
		strcpy(item->nomeSite, tok);
		//printf("NOME SITE: %s\n", item->nomeSite);

		tok = strtok(NULL, ",");
		item->relevancia = atoi(tok);
		//printf("RELEVANCA: %d\n", item->relevancia);

		tok = strtok(NULL, ",");
		strcpy(item->link, tok);
		//printf("LINK: %s\n", item->link);

		int i = 0;
		tok = strtok(NULL, ",");
		while(tok != NULL){
			//printf("%s\n", tok);
			strcpy(item->chave[i], tok);
			//printf("CHAVE %d: %s\n", i, item->chave[i]);
			i++;
			tok = strtok(NULL, ",");
		}
		printf("\n");
		free(arq);
	}

	return item;
}

int main(int argc, char const *argv[])
{
	FILE *fp = fopen("googlebot.txt", "r");

	char *lista = NULL;
	char fileElement;
	int count = 0;
	fscanf(fp, "%c", &fileElement);
	while(!feof(fp)){

	}
	printf("%s\n", lista);

	char *nomeSite = NULL;

	int oper, codigo;
	do{
		scanf("%d", &oper);
		switch(oper){
			case 1:
			//Inserir um novo site na lista
				scanf("%d", &codigo);
				nomeSite = lerString();
				n->item->codigo = codigo;
				strcpy(n->item->nomeSite, nomeSite);
				insere_site(lista, n);
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
