#ifndef MINI_GOOGLE_H
#define MINI_GOOGLE_H


#define TAM 51
#define N 101
#define TRUE 1
#define FALSE 0

typedef struct tipo_item ITEM;
typedef struct node NO;
typedef struct lista LISTA;
typedef int boolean;

LISTA *criar_lista();
ITEM *criar_item(/*parametros para criar site*/);
NO *criar_no(ITEM *item);

void apagar_lista(LISTA **ptr);
void esvazia_lista(NO *ptr);

boolean vazia(LISTA *lista);
int tamanho(LISTA *lista);
void imprime_lista(LISTA *lista);

boolean insere_site(LISTA *lista, NO *p);
boolean insere_chave(LISTA *lista, int codigo, char *chave);
boolean remove_site(LISTA *lista, int codigo);

void atualiza_relevancia(LISTA *lista, int codigo, int relevancia);

void busca_chave(LISTA *lista, char *chave);
void sugestao_site(LISTA *lista, char *chave);


#endif
