#include "lista_seq_din.h"
#include "miniGoogle.h"
#include <stdio.h>
#include <stdlib.h>


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


int main(int argc, char const *argv[])
{
    //LISTA_SEQ palavras;
    LISTA * teste;

	/*FILE *fp = fopen("googlebot.txt", "r");
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
	fclose(fp);*/

	teste = criar_lista();
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

	apagar_lista(&teste);

	return 0;
}
