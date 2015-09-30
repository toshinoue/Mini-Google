#include "lista_seq_din.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item_seq{
    CHAVE chave[TAM_PALAVRA];
};

struct lista_seq{
    ITEM_SEQ *array;
    int tamanho;
};



void troca_seq(ITEM_SEQ *array, int i, int j){
    CHAVE aux[51];
    if(array != NULL){
        strcpy(aux, array[i].chave);
        strcpy(array[i].chave, array[j].chave);
        strcpy(array[j].chave, aux);
    }
}

void insertion_sort_seq(LISTA_SEQ *lista){
    int i, j;

    if(lista != NULL && lista->tamanho > 0){
        for (i = 1; i < lista->tamanho; i++) {
            j = i;
            while (j > 0 && strcmp(lista->array[j-1].chave, lista->array[j].chave) > 0 ) {
                troca_seq(lista->array, j, j-1);
                j--;
            }
        }
    }
}

LISTA_SEQ *criar_lista_seq(){
    LISTA_SEQ *lista = (LISTA_SEQ*)malloc(sizeof(LISTA_SEQ));
    if(lista != NULL){
        lista->tamanho = 0;
        lista->array = NULL;
    }

    return lista;
}

void liberar_lista_seq(LISTA_SEQ **lista){
    if(lista != NULL && (*lista) != NULL){
        if((*lista)->array != NULL){
            free((*lista)->array);
            (*lista)->array = NULL;
        }
        free(*lista);
        (*lista) = NULL;
    }
}

void inserir_ordenado_seq(LISTA_SEQ *lista, CHAVE *chave){
    if(lista != NULL && strlen(chave) <= TAM_PALAVRA-1){
        lista->tamanho++;
        lista->array = (ITEM_SEQ*)realloc(lista->array, sizeof(ITEM_SEQ)*lista->tamanho);
        strcpy(lista->array[lista->tamanho-1].chave, chave);

        insertion_sort_seq(lista);
    }
}

int listaVazia_seq(LISTA_SEQ *lista){
    if(lista != NULL && lista->array != NULL && lista->tamanho > 0){
        return 0;
    } else {
        return 1;
    }
}

void imprime_lista_seq(LISTA_SEQ *lista){
    int i;
    if(lista != NULL){
        for(i=0; i < lista->tamanho; i++){
            printf(", %s", lista->array[i].chave);
        }
    }
}

int busca_chave_seq(LISTA_SEQ *lista, CHAVE *chave, int ini, int fim){
    if(!listaVazia_seq(lista)){
        if(ini <= fim){
            int centro = (int)((fim+ini)/ 2.0);

            if(strcmp(lista->array[centro].chave, chave) == 0) {
                return 1;
            }
            if(strcmp(lista->array[centro].chave, chave) < 0) return busca_chave_seq(lista, chave, centro+1, fim);
            else return busca_chave_seq(lista, chave, ini, centro-1);
        }
    }
    return 0;
}

int tamanho_seq(LISTA_SEQ *lista){
    return (lista->tamanho);
}

int transfere_seq(LISTA_SEQ *lista, LISTA_SEQ *secundaria){
    int i;

    if(secundaria != NULL && lista != NULL){
        for(i = 0; i < secundaria->tamanho; i++){
            if(listaVazia_seq(lista) || !(busca_chave_seq(lista, secundaria->array[i].chave, 0, lista->tamanho-1))){
                inserir_ordenado_seq(lista, secundaria->array[i].chave);
            }
        }
        return 1;
    }
    return 0;
}

CHAVE *remove_fim_seq(LISTA_SEQ *lista){
    CHAVE *ret = (char *)malloc(sizeof(char) * strlen(lista->array[lista->tamanho - 1].chave)+1);
    lista->tamanho--;
    strcpy(ret, lista->array[lista->tamanho].chave);
    lista->array = (ITEM_SEQ*)realloc(lista->array, sizeof(ITEM_SEQ)*lista->tamanho);
    return ret;
}

CHAVE *retorna_chave_posicao_seq(LISTA_SEQ *lista, int pos){
    if(pos < lista->tamanho && pos >= 0){
        CHAVE *ret = (char *)malloc(sizeof(char) * strlen(lista->array[pos].chave)+1);
        strcpy(ret, lista->array[pos].chave);
        return ret;
    }
    return NULL;
}
