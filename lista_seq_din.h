#ifndef LISTA_H
#define LISTA_H

#define TAM_PALAVRA 51

typedef char CHAVE;
typedef struct item_seq ITEM_SEQ;

typedef struct lista_seq LISTA_SEQ;

LISTA_SEQ *criar_lista_seq();

void liberar_lista(LISTA_SEQ **lista);

void inserir_ordenado(LISTA_SEQ *lista, CHAVE *chave);

int listaVazia(LISTA_SEQ *lista);

void imprime_lista_seq(LISTA_SEQ *lista);

int busca_chave(LISTA_SEQ *lista, CHAVE *chave, int ini, int fim);

int tamanho_seq(LISTA_SEQ *lista);

int transfere(LISTA_SEQ *lista, LISTA_SEQ *secundaria);

CHAVE *remove_fim(LISTA_SEQ *lista);

CHAVE *retorna_chave_posicao(LISTA_SEQ *lista, int pos);

#endif // LISTA_ESTATICA_H
