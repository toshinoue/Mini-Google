#include "lista_seq_din.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item_seq{
    CHAVE chave[TAM_C];
};

struct lista_seq{
    ITEM_SEQ *array;
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

	if(lista != NULL && lista->array != NULL){
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
    lista->tamanho = 0;
    lista->array = NULL;

    return lista;
}

void liberar_lista(LISTA_SEQ **lista){
    if(lista != NULL && (*lista) != NULL){
        if((*lista)->array != NULL){
            free((*lista)->array);
            (*lista)->array = NULL;
        }
        free(*lista);
        (*lista) = NULL;
    }
}

void inserir_ordenado(LISTA_SEQ *lista, CHAVE *chave){
    if(lista != NULL && strlen(chave) <= 50){
        lista->tamanho++;
        lista->array = (ITEM_SEQ*)realloc(lista->array, sizeof(ITEM_SEQ)*lista->tamanho);
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
