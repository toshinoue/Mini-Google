#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_seq_din.h"
#include "miniGoogle.h"

struct tipo_item{
	int codigo;
	char nomeSite[TAM];
	int relevancia;
	char link[N];
	LISTA_SEQ *palavras;
};

struct node{
	ITEM *item;
	struct node *anterior;
	struct node *proximo;
};

struct lista{
	NO *inicio;
	NO *fim;
	int tamanho;
};

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

int geraCodigo(LISTA *lista){

}

void apaga_no(no **ptr){
    liberar_lista(&((*ptr)->palavras));
    free((*ptr)->item);
    free(*ptr);
    *ptr = NULL;
}

//mudar nome??? -> busca_codigo
NO *existe_codigo(LISTA *lista, int code){
	NO *p = lista->inicio;

	while(p != NULL && p->item->codigo != code){
		p = p->proximo;
	}
	if(p != NULL){
		return p;
	}else return NULL;
}

//se o site for novo (nao foi lido do txt), o codigo sera igual a -1
ITEM *criar_item(int codigo, char nomeSite[TAM], int relevancia){
    ITEM *item;

    item = (ITEM *) malloc(sizeof(ITEM));

    if (item != NULL){
        item->codigo = codigo; //verificar se o codigo ja existe caso seja um codigo valido
        strcpy(item->nomeSite, nomeSite);
        item->relevancia = relevancia;
        item->palavras = NULL;
        return(item);
    }
    return(NULL);
}

NO *criar_no(ITEM *item){
    NO *n = (NO *) malloc(sizeof(NO));

    if ((n != NULL) && (item != NULL)){
        n->item = item;
        n->anterior = NULL;
        n->proximo = NULL;
        return(n);
    }
    else
        return(NULL);
}

LISTA *criar_lista(){
	LISTA *lista = (LISTA *)malloc(sizeof(LISTA));

	if(lista != NULL){
		lista->inicio = NULL;
		lista->fim = NULL;
		lista->tamanho = 0;
		return lista;
	}

	return NULL;
}


void apagar_lista(LISTA **ptr){
    if(ptr != NULL && (*ptr) != NULL){

        if(vazia(*ptr) == FALSE){
            esvazia_lista((*ptr)->inicio);
        }
        free(*ptr);
        *ptr = NULL;
     }
}

void esvazia_lista(NO *ptr){
    if(ptr->proximo != NULL)
        esvazia_lista(ptr->proximo);

    apaga_no(ptr);
}

boolean vazia(LISTA *lista){
	if(lista->inicio == NULL)
		return(TRUE);

	return(FALSE);
}

int tamanho(LISTA *lista){
    return(lista->tamanho);
}

void imprime_lista(LISTA *lista){
	NO *p;
	if(!vazia(lista) && (lista!=NULL)){
        p = lista->inicio;
        while(p != NULL){
            //FALTA PALAVRAS CHAVES
            printf("%d, %s, %d, %s\n", p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link);
            p = p->proximo;
        }
	}
}

//passar o NO como parametro....
// -> criar função criar_no/criar_item (ler parametros na main.....)
boolean insere_site(LISTA *lista, NO *p){
	int code;

	scanf("%d", &code);

	char *siteName = NULL;

	while(siteName == NULL /*&& strlen(siteName) > 50*/){
		siteName = lerString();
	}

	if(!(existe_codigo(lista, code))){
		if(vazia(lista)){
			lista->inicio->item->codigo = code;
			strcpy(lista->inicio->item->nomeSite, siteName);
		}
		else{
			lista->fim->item->codigo = code;
			strcpy(lista->fim->item->nomeSite, siteName);
		}
		return TRUE;
	}
	else return FALSE;
}

boolean insere_chave(LISTA *lista, int codigo){
	char *chave = NULL;
	while(chave == NULL && strlen(chave) > 50){
		chave = lerString();
	}
	int i = 0;
	if(vazia(lista)){
		lista->inicio->item->chave = (char *)realloc(lista->inicio->item->chave, sizeof(char [50]) * (i+1));
		strcpy(lista->inicio->item->chave[i], chave);
		i++;
	}
	else{
		lista->fim->item->chave = (char *)realloc(lista->fim->item->chave, sizeof(char) * (i+1));
		strcpy(lista->fim->item->chave[i], chave);
		i++;
	}
	return TRUE;
}

boolean remove_site(LISTA *lista, int codigo){
	int code;
	scanf("%d", &code);
	if(existe_codigo(lista, code)){
        NO *p = lista->inicio;
		while(p->item->codigo != code) p = p->proximo;
		if(p == lista->inicio){
		    lista->inicio = p->proximo;
      		p->anterior = NULL;
		}
	    else if(p->proximo == NULL){
			p->anterior->proximo = NULL;
			lista->fim = p->anterior;
    	}
        else{
			p->proximo->anterior = p->anterior;
			p->anterior->proximo = p->proximo;
			p->proximo = NULL;
			p->anterior = NULL;
    	}
		return TRUE;
	}
	else return FALSE;
}

void atualiza_relevancia(LISTA *lista, int code){
	NO *p = existe_codigo(lista, code);
	if(p != NULL){
		p->item->relevancia++; //TEM QUE ORDENAR ESSA BAGAÇA
	}
}

void busca_chave(LISTA *lista, char *chave);

void sugestao_site(LISTA *lista, char *chave);
