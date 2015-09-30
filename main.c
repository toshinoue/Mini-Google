#include "miniGoogle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//assumindo que o arquivo googlebot.txt esta ordenado pelo codigo

/*strtoupper() - funcao que recebe  uma letra e retorna a versao maiuscula
    Parametros
        char c - letra a ser transformada em maiuscula
    Retorno
        char - letra maiuscula
*/
char ctolower(char c){
    if(c >= 65 && c <= 90){
        return c+32;
    }
    return c;
}

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


void leArquivo(FILE *fp, LISTA *lista){
	int codigo, relevancia, i;
	char nomeSite[TAM], link[N];

	char carac;
	char *tok;

    fscanf(fp, "%c", &carac);
	while(!feof(fp)){
		int count = 0;
		char *arq = NULL;

		while(!feof(fp) && carac != '\n'){
			arq = (char *)realloc(arq, sizeof(char) * (count+1));
			arq[count++] = carac;
			fscanf(fp, "%c", &carac);
		}

		arq = (char *)realloc(arq, sizeof(char) * (count+1));
		arq[count] = '\0';

		tok = strtok(arq, ",");
		codigo = atoi(tok);

		tok = strtok(NULL, ",");
		strcpy(nomeSite, tok);

		tok = strtok(NULL, ",");
		relevancia = atoi(tok);

		tok = strtok(NULL, ",");
		strcpy(link, tok);

        insere_site(lista, criar_no(criar_item(codigo, nomeSite, relevancia, link)));

		tok = strtok(NULL, ",");
		while(tok != NULL){

			for(i=0; i < strlen(tok); i++){
                tok[i] = ctolower(tok[i]);
			}

			insere_chave(lista, codigo, tok);
			tok = strtok(NULL, ",");
		}
		free(arq);

		fscanf(fp, "%c", &carac);
	}
}


int main(int argc, char const *argv[])
{
    FILE *fp = fopen("googlebot.txt", "r");
//<<<<<<< HEAD
    LISTA *lista = criar_lista();
    int oper, codigo, relevancia, i;
    //char *palavra;
    char *palavra, *nomeSite, *link;

    leArquivo(fp, lista);

    fclose(fp);
//VERIFICAR SE AS STRINGS ESTAO COM TAMANHO CERTO
	do{
        printf("1 - Inserir site\n2 - Inserir palavra chave\n3 - Remover um site\n4 - Atualizar relevancia\n");
        printf("5 - Mostrar lista\n6 - Busca por palavra chave\n7 - Sugestoes de sites\n8 - Sair\n\n");
		scanf("%d", &oper);
		switch(oper){
			case 1:
			//Inserir um novo site na lista
				do{
                    printf("Codigo: ");
                    scanf("%d", &codigo);
                    if(codigo < 0 || codigo > 9999)
                        printf("Codigo invalido. Digite um valor entre 0 e 9999\n");
				}while(codigo < 0 || codigo > 9999);

				getchar();
				printf("Nome Site: ");
				nomeSite = lerString();
				if(strlen(nomeSite) > 50)
                    nomeSite[50] = '\0';

				do{
                    printf("Relevancia: ");
                    scanf("%d", &relevancia);
                    if(relevancia < 0 || relevancia > 1000)
                        printf("Relevancia invalido. Digite um valor entre 0 e 1000\n");
				}while(relevancia < 0 || relevancia > 1000);

				getchar();
				printf("Link: ");
				link = lerString();
				if(strlen(link) > 100)
                    link[100] = '\0';

				insere_site( lista, criar_no(criar_item(codigo, nomeSite, relevancia, link)));
				free(link);
				free(nomeSite);
				break;
			case 2:
			//Inserir palavra chave
                do{
                    printf("Codigo: ");
                    scanf("%d", &codigo);
                    if(codigo < 0 || codigo > 9999)
                        printf("Codigo invalido. Digite um valor entre 0 e 9999\n");
				}while(codigo < 0 || codigo > 9999);

                getchar();
                printf("Palvra chave: ");
                palavra = lerString();
                if(strlen(palavra) > 50)
                    palavra[50] = '\0';

                for(i=0; i < strlen(palavra); i++){
                    palavra[i] = ctolower(palavra[i]);
                }

                insere_chave(lista, codigo, palavra);
                free(palavra);
				break;
			case 3:
			//Remover um site
                do{
                    printf("Codigo: ");
                    scanf("%d", &codigo);
                    if(codigo < 0 || codigo > 9999)
                        printf("Codigo invalido. Digite um valor entre 0 e 9999\n");
				}while(codigo < 0 || codigo > 9999);

                remove_site(lista, codigo);
				break;
			case 4:
			//Atualizar relevancia
                do{
                    printf("Codigo: ");
                    scanf("%d", &codigo);
                    if(codigo < 0 || codigo > 9999)
                        printf("Codigo invalido. Digite um valor entre 0 e 9999\n");
				}while(codigo < 0 || codigo > 9999);

                do{
                    printf("Relevancia: ");
                    scanf("%d", &relevancia);
                    if(relevancia < 0 || relevancia > 1000)
                        printf("Relevancia invalido. Digite um valor entre 0 e 1000\n");
				}while(relevancia < 0 || relevancia > 1000);

                atualiza_relevancia(lista, codigo, relevancia);
				break;
			case 5:
			//Mostrar a lista
                imprime_lista(lista);
				break;
			case 6:
			//Busca por palavra chave
                getchar();
                printf("Palavra chave: ");
                palavra = lerString();
                if(strlen(palavra) > 50)
                    palavra[50] = '\0';

                for(i=0; i < strlen(palavra); i++){
                    palavra[i] = ctolower(palavra[i]);
                }

                busca_palavra(lista, palavra);
                free(palavra);
				break;
			case 7:
			//Sugestao do site
                getchar();
                printf("Palavra chave: ");
                palavra = lerString();
                if(strlen(palavra) > 50)
                    palavra[50] = '\0';

                for(i=0; i < strlen(palavra); i++){
                    palavra[i] = ctolower(palavra[i]);
                }

                sugestao_site(lista, palavra);
                free(palavra);
				break;
            default: break;
		}
	}while(oper != 8);

	apagar_lista(&lista);
//=======

 /*   if(fp != NULL){
	    LISTA *lista = criar_lista();
	    int oper, codigo, relevancia, i;
	    //char *palavra;
	    char *palavra, *nomeSite, *link;

	    leArquivo(fp, lista);

	    fclose(fp);
	//VERIFICAR SE AS STRINGS ESTAO COM TAMANHO CERTO
		do{
			scanf("%d", &oper);
			switch(oper){
				case 1:
				//Inserir um novo site na lista
					scanf("%d", &codigo);
					getchar();
					nomeSite = lerString();
					scanf("%d", &relevancia);
					getchar();
					link = lerString();
					insere_site( lista, criar_no(criar_item(codigo, nomeSite, relevancia, link)));
					free(link);
					free(nomeSite);
					break;
				case 2:
				//Inserir palavra chave
	                scanf("%d", &codigo);
	                getchar();
	                palavra = lerString();
	                for(i=0; i < strlen(palavra); i++){
	                    palavra[i] = ctolower(palavra[i]);
	                }
	                insere_chave(lista, codigo, palavra);
	                free(palavra);
					break;
				case 3:
				//Remover um site
	                scanf("%d", &codigo);
	                remove_site(lista, codigo);
					break;
				case 4:
				//Atualizar relevancia
	                scanf("%d %d", &codigo, &relevancia);
	                atualiza_relevancia(lista, codigo, relevancia);
					break;
				case 5:
				//Mostrar a lista
	                imprime_lista(lista);
					break;
				case 6:
				//Busca por palavra chave
	                getchar();
	                palavra = lerString();
	                for(i=0; i < strlen(palavra); i++){
	                    palavra[i] = ctolower(palavra[i]);
	                }
	                busca_palavra(lista, palavra);
	                free(palavra);
					break;
				case 7:
				//Sugestao do site
	                getchar();
	                palavra = lerString();
	                for(i=0; i < strlen(palavra); i++){
	                    palavra[i] = ctolower(palavra[i]);
	                }
	                sugestao_site(lista, palavra);
	                free(palavra);
					break;
	            default: break;
			}
		}while(oper != 8);

		apagar_lista(&lista);
    } else {
    	printf("Could not open googlebot.txt\n");
    }*/
//>>>>>>> origin/master

	return 0;
}
