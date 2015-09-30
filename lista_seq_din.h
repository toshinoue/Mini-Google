#ifndef LISTA_H
#define LISTA_H

#define TAM_PALAVRA 51

typedef char CHAVE;
typedef struct item_seq ITEM_SEQ;

typedef struct lista_seq LISTA_SEQ;

/* criar_lista_seq() - Funcao que aloca uma lista dinamica, inicializando seu tamanho a 0
		e seu ponteiro para NULL
	Parametros:
		Nao ha
	Retorno:
		LISTA_SEQ* - lista alocada dinamica
*/
LISTA_SEQ *criar_lista_seq();

/* liberar_lista_seq() - Funcao que libera a lista
	Parametros:
		LISTA_SEQ **lista - ponteiro para um ponteiro de LISTA_SEQ
	Retorno:
		Nao ha
*/
void liberar_lista_seq(LISTA_SEQ **lista);

/* inserir_ordanado_seq() - Funcao que insere ordenado uma string(chave) na lista
	Parametros:
		LISTA_SEQ *lista - ponteiro para lista de chaves
		CHAVE *chave - string da palavra chave
	Retorno:
		Nao ha
*/
void inserir_ordenado_seq(LISTA_SEQ *lista, CHAVE *chave);

/* listaVazia_seq() - Funcao que verifica se a lista esta vazia
	Parametros:
		LISTA_SEQ *lista - ponteiro para lista de chaves
	Retorno:
		int - retorna 0 se a lista nao estiver vazia, caso contrario retorna 0
*/
int listaVazia_seq(LISTA_SEQ *lista);

/* imprime_lista_seq() - Funcao que imprime a lista de palavras chaves
	Parametros:
		LISTA_SEQ *lista - ponteiro para lista de chaves
	Retorno:
		Nao ha
*/
void imprime_lista_seq(LISTA_SEQ *lista);

/* busca_chave_seq() - Funcao que busca uma chave na lista de palavras chaves
	Parametros:
		LISTA_SEQ *lista - ponteiro para lista de chaves
		CHAVE *chave - string da palavra chave
		int ini - variavel inteira para o inicio
		int fim - variavel inteira para o fim

	Retorno:
		int - caso a chave seja encontrada a funcao retorna 1, caso contrario retorna 0
*/
int busca_chave_seq(LISTA_SEQ *lista, CHAVE *chave, int ini, int fim);

/* tamanho_seq() - Funcao que retorna o tamanho da lista
	Parametros:
		LISTA_SEQ *lista - ponteiro para lista de chaves
	Retorno:
		int - retorna o tamanho da lista
*/
int tamanho_seq(LISTA_SEQ *lista);

/* transfere_seq() - Funcao que transfere o conteudo da lista secundaria para lista
	Parametros:
		LISTA_SEQ *lista - ponteiro para lista de chaves
		LISTA_SEQ *secundaria - ponteiro para lista secundaria de chaves
	Retorno:
		int - retorna 1 se a transferencia foi bem sucedida, caso contrario retorna 0
*/
int transfere_seq(LISTA_SEQ *lista, LISTA_SEQ *secundaria);

/* remove_fim_seq() - Funcao que remove o ultimo elemento da lista
	Parametros:
		LISTA_SEQ *lista - ponteiro para lista de chaves
	Retorno:
		CHAVE* - retorna a string(chave) removida da lista
*/
CHAVE *remove_fim_seq(LISTA_SEQ *lista);

/* retorna_chave_posicao_seq - Dado uma posicao(int), a funcao retorna o elemento da lista que esta na posicao dada
	Parametros:
		LISTA_SEQ *lista - ponteiro para lista de chaves
		int pos - posicao da lista
	Retorno:
		CHAVE* - Retorna a string(chave) que esta na posicao dada pelo usuario
*/
CHAVE *retorna_chave_posicao_seq(LISTA_SEQ *lista, int pos);

#endif // LISTA_ESTATICA_H
