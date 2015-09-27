#ifndef LISTA_H
#define LISTA_H

typedef char CHAVE;
typedef struct item_seq ITEM_SEQ;

//com a definicao da struct aqui da certo, porem quebra o tad
/*typedef struct lista_seq{
    ITEM_SEQ *array;
    int tamanho;

} LISTA_SEQ;*/
typedef struct lista_seq LISTA_SEQ;

LISTA_SEQ *criar_lista_seq();

void liberar_lista(LISTA_SEQ **lista);

void inserir_ordenado(LISTA_SEQ *lista, CHAVE *chave);

int listaVazia(LISTA_SEQ *lista);

#endif // LISTA_ESTATICA_H
