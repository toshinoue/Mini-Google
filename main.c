#include "miniGoogle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//assumindo que o arquivo googlebot.txt esta ordenado pelo codigo

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
	int codigo, relevancia;
	char nomeSite[TAM], link[N], palavra[TAM]/*gambiarra '-'*/;

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
			strcpy(palavra, tok);
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
    LISTA *lista = criar_lista();
    int oper, codigo, relevancia;
    //char *palavra;
    char palavra[TAM], nomeSite[TAM], link[N];

    leArquivo(fp, lista);

    printf("\n\n\n\n\n");


	do{
		scanf("%d", &oper);
		switch(oper){
			case 1:
			//Inserir um novo site na lista
				scanf("%d", &codigo);
				getchar();
				//nomeSite = lerString();
				scanf("%s", nomeSite);
				scanf("%d", &relevancia);
				getchar();
				//link = lerString();
				scanf("%s", link);
				insere_site( lista, criar_no(criar_item(codigo, nomeSite, relevancia, link)));
				break;
			case 2:
			//Inserir palavra chave
                scanf("%d", &codigo);
                getchar();
                //palavra = lerString();
                scanf("%s", palavra);
                insere_chave(lista, codigo, palavra);
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
                //palavra = lerString();
                scanf("%s", palavra);
                busca_palavra(lista, palavra);
                //free(palavra);
				break;
			case 7:
			//Sugestao do site
				break;
            default: break;
		}
	}while(oper != 8);

	fclose(fp);

	/*teste = criar_lista();
	insere_site(teste, criar_no(criar_item(-1, "kleber", -1, "kleber.jp")));
	insere_site(teste, criar_no(criar_item(0, "henrique", 10, "henrique.jp")));


	insere_site(teste, criar_no(criar_item(1,"Lual Lanches",600,"http://luallanches.com.br/")));
    insere_site(teste, criar_no(criar_item(2,"Hot Tiger Lanches",750,"http://hottigerlanches.com.br/")));
    insere_site(teste, criar_no(criar_item(10,"Trabalho De ALG1",1000,"http://malditotrabalho.com.br/")));
    insere_site(teste, criar_no(criar_item(101,"Cansei de fazer",290,"http://eitatrabalhochato.com.br/")));
    insere_site(teste, criar_no(criar_item(133,"Henrique Me Ajuda",990,"http://henriquemeajuda.com.br/")));
    insere_site(teste, criar_no(criar_item(913,"Vem Comigo amor eu vou",999,"http://madagascar.com.br/")));
    insere_site(teste, criar_no(criar_item(543,"uen ai meti iu",890,"http://summercalvin.com.br/")));


    insere_chave(teste, 1,"lanches");
    insere_chave(teste, 1,"lual");
    insere_chave(teste, 1,"Sao Carlos");

    insere_chave(teste, 2,"lanches");
    insere_chave(teste, 2,"Hot Tiger");

    insere_chave(teste, 10,"trabalho");
    insere_chave(teste, 10,"alg1");
    insere_chave(teste, 10,"porra de alg1");

    insere_chave(teste, 101,"trabalho");
    insere_chave(teste, 101,"alg1");
    insere_chave(teste, 101,"aff");

    insere_chave(teste, 133,"trabalho");
    insere_chave(teste, 133,"alg1");
    insere_chave(teste, 133,"help me");

    insere_chave(teste, 913,"madagascar");
    insere_chave(teste, 913,"edy lemond");

    insere_chave(teste, 543,"calvin harris");
    insere_chave(teste, 543,"summer");
    insere_chave(teste, 543,"remix");


	imprime_lista(teste);
printf("\n\n");
	remove_site(teste, 543);

	imprime_lista(teste);
printf("\n\n");

    atualiza_relevancia(teste, 10, 1);
    imprime_lista(teste);*/

	apagar_lista(&lista);

	return 0;
}
