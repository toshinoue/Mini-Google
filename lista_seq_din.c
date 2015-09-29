#include "lista_seq_din.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item_seq{
    CHAVE chave[51];
};

struct lista_seq{
    ITEM_SEQ array[10];
    int tamanho;
};


void troca(ITEM_SEQ *array, int i, int j){
	CHAVE aux[51];
	if(array != NULL){
		strcpy(aux, array[i].chave);
		strcpy(array[i].chave, array[j].chave);
		strcpy(array[j].chave, aux);
	}
}

void insertion_sort(LISTA_SEQ *lista){
    int i, j;

	if(lista != NULL && lista->tamanho > 0){
		for (i = 1; i < lista->tamanho; i++) {
			j = i;
			while (j > 0 && strcmp(lista->array[j-1].chave, lista->array[j].chave) > 0 ) {
				troca(lista->array, j, j-1);
				j--;
			}
		}
	}
}

LISTA_SEQ *criar_lista_seq(){
    LISTA_SEQ *lista = (LISTA_SEQ*)malloc(sizeof(LISTA_SEQ));
    if(lista != NULL){
        lista->tamanho = 0;
    }

    return lista;
}

void liberar_lista(LISTA_SEQ **lista){
        free(*lista);
        (*lista) = NULL;
}

void inserir_ordenado(LISTA_SEQ *lista, CHAVE *chave){
    if(lista != NULL && strlen(chave) <= 50){
        lista->tamanho++;
        strcpy(lista->array[lista->tamanho-1].chave, chave);

        insertion_sort(lista);
    }
}

int listaVazia(LISTA_SEQ *lista){
    if(lista != NULL && lista->tamanho > 0){
        return 0;
    } else {
        return 1;
    }
}

void imprime_lista_seq(LISTA_SEQ *lista){
    int i;
    if(lista != NULL){
        //printf("\n\ntamanho: %d\n\n", lista->tamanho);
        for(i=0; i < lista->tamanho; i++){
            printf(", %s", lista->array[i].chave);
        }
    }
}
/*
int busca_chave(LISTA_SEQ *lista, CHAVE *chave){
    int i;
    for(i = 0; i < lista->tamanho; i++){
        if(strcmp(lista->array[i].chave, chave) == 0){
            //return TRUE;
            return 1;
        }
    }
    //return FALSE;
    return 0;
}
*/
