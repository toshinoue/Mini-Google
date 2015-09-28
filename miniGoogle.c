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
	NO *cabeca;
	NO *fim;
	int tamanho;
	//aramzenar o ultimo codigo utilizado?
};

int geraCodigo(LISTA *lista){
    return -1;
}

void apaga_no(NO **ptr){
    liberar_lista(&((*ptr)->item->palavras));
    free((*ptr)->item);
    free(*ptr);
    *ptr = NULL;
}

//mudar nome??? -> busca_codigo
NO *existe_codigo(LISTA *lista, int code){
	NO *p = lista->cabeca->proximo;

	while(p != NULL && p->item->codigo != code){
		p = p->proximo;
	}
	if(p != NULL){
		return p;
	}else return NULL;
}

//se o site for novo (nao foi lido do txt), o codigo sera igual a -1
ITEM *criar_item(int codigo, char nomeSite[TAM], int relevancia, char link[N]){
    ITEM *item;

    item = (ITEM *) malloc(sizeof(ITEM));

    if (item != NULL){
        item->codigo = codigo; //verificar se o codigo ja existe caso seja um codigo valido
        strcpy(item->nomeSite, nomeSite);
        strcpy(item->link, link);
        item->relevancia = relevancia;
        item->palavras = criar_lista_seq();
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
		lista->cabeca = (NO*)malloc(sizeof(NO));
		if(lista->cabeca == NULL)
            return NULL;
        lista->cabeca->proximo = NULL;
		lista->fim = NULL;
		lista->tamanho = 0;
		return lista;
	}

	return NULL;
}


void apagar_lista(LISTA **ptr){
    if(ptr != NULL && (*ptr) != NULL){

        if(vazia(*ptr) == FALSE){
            esvazia_lista((*ptr)->cabeca->proximo);
        }
        free((*ptr)->cabeca);
        free(*ptr);
        *ptr = NULL;
     }
}

void esvazia_lista(NO *ptr){
    if(ptr->proximo != NULL)
        esvazia_lista(ptr->proximo);

    apaga_no(&ptr);
}

boolean vazia(LISTA *lista){
	if(lista->cabeca->proximo == NULL)
		return(TRUE);

	return(FALSE);
}

int tamanho(LISTA *lista){
    return(lista->tamanho);
}

void imprime_lista(LISTA *lista){
	NO *p;
	if(!vazia(lista) && (lista!=NULL)){
        p = lista->cabeca->proximo;
        while(p != NULL){
            //FALTA PALAVRAS CHAVES
            printf("%.4d, %s, %d, %s", p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link);
            imprime_lista_seq(p->item->palavras);
            printf("\n");
            p = p->proximo;
        }
	}
}


boolean insere_site(LISTA *lista, NO *p){
    if(lista != NULL && p != NULL){
        /*if(p->item->codigo == -1){
            p->item->codigo = geraCodigo(lista);
        }*/
        if((existe_codigo(lista, p->item->codigo)) == NULL){
            if(vazia(lista)){
                lista->cabeca->proximo = p;
                lista->fim = p;
                lista->tamanho++;

                p->anterior = lista->cabeca;
                p->proximo = NULL;
            }
            else{
                NO *n = lista->cabeca->proximo;

                while(n != NULL && n->item->relevancia > p->item->relevancia){
                    n = n->proximo;
                }

                if(n == NULL){
                    p->anterior = lista->fim;
                    p->proximo = NULL;

                    lista->fim->proximo = p;
                    lista->fim = p;
                } else {
                    p->proximo = n;
                    p->anterior = n->anterior;
                    p->anterior->proximo = p;
                    n->anterior = p;
                }

                lista->tamanho++;
            }
            return TRUE;
        }
        else return FALSE;
    }
    return FALSE;
}

boolean insere_chave(LISTA *lista, int codigo, char *chave){

	if(lista != NULL && chave != NULL){
        if(!vazia(lista)){
            NO *aux = existe_codigo(lista, codigo);

            if(aux == NULL){
                return FALSE;
            }
            inserir_ordenado(aux->item->palavras, chave);
        }
	} else {
        return FALSE;
	}

	return TRUE;
}

boolean remove_site(LISTA *lista, int codigo){
	/*int code;
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
	else */return FALSE;
}

void atualiza_relevancia(LISTA *lista, int code){
	NO *p = existe_codigo(lista, code);
	if(p != NULL){
		p->item->relevancia++; //TEM QUE ORDENAR ESSA BAGAÇA
	}
}

void busca_chave(LISTA *lista, char *chave);

void sugestao_site(LISTA *lista, char *chave);
