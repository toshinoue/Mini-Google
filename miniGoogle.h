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

/* criar_lista() - Funcao que aloca uma lista dinamica, apontando seus ponteiros para NULL
		e inicializando o tamanho com o valor 0.
	Parametros:
		Nao ha
	Retorno:
		LISTA - lista alocada dinamica
*/
LISTA *criar_lista();

/* criar_item() - Funcao que recebe as informacoes do site e as armazena em uma struct item.
	Parametros:
		int codigo - codigo do site
		char *nomeSite - string do nome do site
		int relevancia - relevancia do site
		char *link - string do link do site
	Retorno:
		ITEM - retorna um ITEM contendo as informacoes do site
*/
ITEM *criar_item(int codigo, char *nomeSite, int relevancia, char *link);

/* criar_no() - Funcao que aloca um NO dinamicamente e aponta os ponteiros para NULL
	Parametros:
		ITEM *item - ponteiro para ITEM que contem as informacoes do site
	Retorno:
		NO - retorna um NO alocado dinamicamente
*/
NO *criar_no(ITEM *item);

/* apagar_lista() - funcao que libera a lista, liberando o NO juntamente
	Parametros:
		LISTA **ptr - ponteiro para um ponteiro de LISTA
	Retorno:
		Nao ha
*/
void apagar_lista(LISTA **ptr);

/* vazia() - Funcao que verifica se a funcao esta vazia
	Parametros:
		LISTA **ptr - ponteiro para um ponteiro de LISTA
	Retorno:
		boolean(int) - retorna TRUE caso a lista esta vazia ou FALSE caso contrario
*/
boolean vazia(LISTA *lista);

/* tamanho() - Funcao que retorna o tamanho da lista, o numero de sites que esta contido na lista
	Parametros:
		LISTA *lista - ponteiro para lista de sites
	Retorno:
		int - retorna o tamanho da lista
*/
int tamanho(LISTA *lista);

/* imprime_lista() - Funcao que imprime a lista, usando a funcao imprime_lista_seq que contem uma lista
		que possui as palavras chaves de cada ITEM
	Parametros:
		LISTA *lista - ponteiro para lista de sites
	Retorno - 
		Nao ha.
*/
void imprime_lista(LISTA *lista);

/* insere_site() - Funcao que insere um NO na lista ordenado baseado na relevancia e, em caso de empate, no codigo.
		O NO dado eh liberado caso nao seja possivel inserir na lista, retornando TRUE ou FALSE
	Parametros:
		LISTA **ptr - ponteiro para um ponteiro de LISTA
		NO *p - ponteiro para um NO
	Retorno:
		boolean(int) - retorna TRUE se a funcao conseguiu inserir com sucesso, caso contrario FALSE
*/
boolean insere_site(LISTA *lista, NO *p);

/* insere_chave() - Dado um codigo, a funcao verifica se o codigo existe e  insere uma chave(string) no NO que contem o codigo
		usando a funcao inserir_ordenado_seq, retornando TRUE ou FALSE
	Parametros:
		LISTA *lista - ponteiro para lista de sites
		int codigo - codigo do site
		char *chave - string da palavra chave
	Retorno:
		boolean(int)- retorna TRUE caso a funcao conseguiu inserir a palavra, caso contrario FALSE
*/
boolean insere_chave(LISTA *lista, int codigo, char *chave);

/* remove_site() - Dado um codigo, a funcao verifica se o codigo existe e remove um site da lista,
		liberando-a da memoria juntamente com o NO
	Parametros:
		LISTA *lista - ponteiro para lista de sites
		int codigo - codigo do site
	Retorno:
	boolean(int) - retorna TRUE caso a funcao conseguiu remover o site da lista, caso contrario FALSE
*/
boolean remove_site(LISTA *lista, int codigo);

/* atualiza_relevancia() - Dado um codigo, a funcao verifica se o codigo existe e atualiza a relevancia do ITEM,
		e reordena a lista baseado na relevancia e, em caso de empate, no codigo
	Parametros:
		LISTA *lista - ponteiro para lista de sites
		int codigo - codigo do site
		int relevancia - nova relevancia dada pelo usuario
	Retorno:
		Nao ha
*/
void atualiza_relevancia(LISTA *lista, int codigo, int relevancia);

/* busca_palavra() - Dado uma chave(string), a funcao faz uma busca binaria na lista de palavra chaves dos sites
		e caso encontre a palavra, sera impresso na tela o ITEM.
	Parametros:
		LISTA *lista - ponteiro para lista de sites
		char *chave - string digitada pelo usuario
	Retorno:
		Nao ha
*/
void busca_palavra(LISTA *lista, char *chave);

/* sugestao_site() - Dado uma chave(string), a funcao cria uma lista para as sugestoes (LISTA *sugestoes) e uma lista das palavras chaves (LISTA_SEQ *aux),
		apos faz uma busca da palavra chave digitada pelo usuario e armazena todas as palavras chaves encontradas dos sites que contem a chave dada pelo usuario em aux,
		depois de armazenar todas as palavras chaves, a funcao faz uma lista de sugestoes usando as palavras chaves que estao contidas em aux.
		No fim, a funcao imprime os sites obtidos em sugestoes
	Parametros:
		LISTA *lista - ponteiro para lista de sites
		char *chave - string digitada pelo usuario
	Retorno:
		Nao ha
*/
void sugestao_site(LISTA *lista, char *chave);

/* finaliza_lista() - Funcao que atualiza o arquivo, sobrescrevendo o arquivo lido inicialmente,
		apos atualizar, a funcao apaga a lista, liberando todos os NOS contidos nele.
	Parametros:
		LISTA **ptr - ponteiro para um ponteiro de LISTA
	Retorno:
		Nao ha
*/
void finaliza_lista(LISTA **ptr);


#endif
