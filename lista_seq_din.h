#ifndef LISTA_H
#define LISTA_H

#define TAM_PALAVRA 51

typedef char CHAVE;
typedef struct item_seq ITEM_SEQ;

typedef struct lista_seq LISTA_SEQ;

LISTA_SEQ *criar_lista_seq();

void liberar_lista_seq(LISTA_SEQ **lista);

void inserir_ordenado_seq(LISTA_SEQ *lista, CHAVE *chave);

int listaVazia_seq(LISTA_SEQ *lista);

void imprime_lista_seq(LISTA_SEQ *lista);

int busca_chave_seq(LISTA_SEQ *lista, CHAVE *chave, int ini, int fim);

int tamanho_seq(LISTA_SEQ *lista);

int transfere_seq(LISTA_SEQ *lista, LISTA_SEQ *secundaria);

CHAVE *remove_fim_seq(LISTA_SEQ *lista);

CHAVE *retorna_chave_posicao_seq(LISTA_SEQ *lista, int pos);

#endif // LISTA_ESTATICA_H
