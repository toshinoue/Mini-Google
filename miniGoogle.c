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
};

/* atualizar_arquivo() - Funcao que atualiza o arquivo googlebot.txt com as informacoes contida na lista recebida, reescrevendo o arquivo inteiro
	Parametros:
		LISTA *lista - ponteiro para lista de sites
	Retorno:
		boolean(int) - retorna TRUE se a funcao conseguir atualizar o arquivo com sucesso, caso contrario FALSE
*/
boolean atualizar_arquivo(LISTA *lista){
    FILE *fp = fopen("googlebot.txt", "w");
    int i;

    if(fp != NULL && lista != NULL){
        NO *p = lista->cabeca->proximo;

        while(p != NULL){
            fprintf(fp,"%.4d,%s,%d,%s", p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link);
            for(i=0; i < tamanho_seq(p->item->palavras); i++){
                //palavras chaves
                char *word = retorna_chave_posicao_seq(p->item->palavras, i);
                if(word != NULL){
                    fprintf(fp,",%s", word);
                    free(word);
                }
            }
            if(p->proximo != NULL){
                fprintf(fp, "\n");
            }
            p = p->proximo;
        }

        fclose(fp);

        return TRUE;
    }

    return FALSE;
}

/* copia_no() - Funcao que copia as informacoes de um NO recebido para outro que eh retornado
	Parametros:
		NO *p - ponteiro para um NO
	Retorno:
		NO* - retorna um NO alocado dinamicamente
*/
NO *copia_no(NO *p){
    NO *aux = NULL;
    if(p != NULL)
        aux = criar_no(criar_item(p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link));

    return aux;
}

/* imprime_site_busca() - Funcao que imprime o nome e o link de um site provindo de uma busca
	Parametros:
		NO *p - ponteiro para um NO
	Retorno:
		Nao ha
*/
void imprime_site_busca(NO *p){
    if(p != NULL){
        printf("%s - %s", p->item->nomeSite, p->item->link);
        printf("\n");
    }
}

/* retira_no() - Funcao que retira um NO recebido da lista, mas nao o libera
	Parametros:
        LISTA *lista - ponteiro para lista de sites
		NO *p - ponteiro para um NO que sera retirado da lista
	Retorno:
		boolean(int) - retorna TRUE se a funcao conseguiu retirar o NO com sucesso, caso contrario FALSE
*/
boolean retira_no(LISTA *lista, NO *p){
    if(lista != NULL && p != NULL){
        p->anterior->proximo = p->proximo;

        if(p != lista->fim)
            p->proximo->anterior = p->anterior;
        else
            lista->fim = p->anterior;

        lista->tamanho--;

        return (TRUE);
    }

    return (FALSE);
}

/* apaga_no() - Funcao que libera um NO recebido
	Parametros:
		NO **ptr - ponteiro que aponta para um ponteiro para um NO
	Retorno:
		Nao ha
*/
void apaga_no(NO **ptr){
    if(ptr != NULL && (*ptr) != NULL){
        liberar_lista_seq(&((*ptr)->item->palavras));
        free((*ptr)->item);
        free(*ptr);
        *ptr = NULL;
    }
}

/* esvazia_lista() - Funcao que percorre todos os NOS de uma lista recursivamente e liberando-os
	Parametros:
		NO *p - ponteiro para um NO
	Retorno:
		Nao ha
*/
void esvazia_lista(NO *ptr){
    if(ptr != NULL && ptr->proximo != NULL)
        esvazia_lista(ptr->proximo);

    apaga_no(&ptr);
}

/* existe_codigo() - Funcao que verifica se existe algum site com o codigo recebido dentro da lista
	Parametros:
		LISTA *lista - ponteiro para lista de sites
		int code - codigo a ser procurado
	Retorno:
		NO* - NO que contem o codigo, ou NULL caso nao exista um NO ocm o codigo
*/
NO *existe_codigo(LISTA *lista, int code){
    if(lista != NULL){
        NO *p = lista->cabeca->proximo;

        while(p != NULL && p->item->codigo != code){
            p = p->proximo;
        }
        if(p != NULL){
            return p;
        }
    }
    return NULL;
}



ITEM *criar_item(int codigo, char *nomeSite, int relevancia, char *link){
    ITEM *item;

    item = (ITEM *) malloc(sizeof(ITEM));

    if (item != NULL){
        item->codigo = codigo;
        strcpy(item->nomeSite, nomeSite);
        strcpy(item->link, link);
        item->relevancia = relevancia;
        item->palavras = criar_lista_seq();
        return(item);
    }
    return(NULL);
}

NO *criar_no(ITEM *item){
    if(item != NULL){
        NO *n = (NO *) malloc(sizeof(NO));

        if (n != NULL){
            n->item = item;
            n->anterior = NULL;
            n->proximo = NULL;
            return(n);
        }
        else
            return(NULL);
    }
    return (NULL);
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

boolean vazia(LISTA *lista){
    if(lista == NULL)
        return (TRUE);
    if(lista->cabeca->proximo == NULL)
        return(TRUE);

    return(FALSE);
}

int tamanho(LISTA *lista){
    if(lista!=NULL)
        return(lista->tamanho);
    return 0;
}

void imprime_lista(LISTA *lista){
    NO *p;

    if(lista!=NULL && !vazia(lista)){
        p = lista->cabeca->proximo;
        while(p != NULL){
            printf("%.4d, %s, %d, %s", p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link);
            imprime_lista_seq(p->item->palavras);
            printf("\n");
            p = p->proximo;
        }
    }else printf("Lista vazia.\n");
}

boolean insere_site(LISTA *lista, NO *p){
    if(lista != NULL && p != NULL){
        if((existe_codigo(lista, p->item->codigo)) == NULL){
            if(vazia(lista)){ //inserindo em lista vazia
                lista->cabeca->proximo = p;
                lista->fim = p;
                lista->tamanho++;

                p->anterior = lista->cabeca;
                p->proximo = NULL;
            }
            else{
                NO *n = lista->cabeca->proximo;

                //verificando a posicao referente a relevancia
                while(n != NULL && n->item->relevancia > p->item->relevancia){
                    n = n->proximo;
                }

                //em caso de relevancias iguais, o codigo eh utilizado como desempate
                while(n != NULL && n->item->relevancia == p->item->relevancia && n->item->codigo < p->item->codigo){
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
        } else {
            apaga_no(&p);
            return FALSE;
        }
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
            if(tamanho_seq(aux->item->palavras) < 10){
                inserir_ordenado_seq(aux->item->palavras, chave);
            } else {
                printf("ERRO: Numero max de 10 palavras ja atingido! Palavra nao foi inserida.\n");
            }
        }
    } else {
        return FALSE;
    }

    return TRUE;
}

boolean remove_site(LISTA *lista, int codigo) {
    if (lista != NULL && !vazia(lista)) {
        NO *p = existe_codigo(lista, codigo);

        if(retira_no(lista, p)){
            apaga_no(&p);
            return (TRUE);
        }
    }
    return (FALSE);
}

void atualiza_relevancia(LISTA *lista, int code, int relevancia){
    if(lista != NULL){
        NO *p = existe_codigo(lista, code);
        if(p != NULL){
            p->item->relevancia = relevancia;

            retira_no(lista, p);
            insere_site(lista, p);
        }else printf("Codigo nao encontrado!\n");
    }
}


void busca_palavra(LISTA *lista, char *chave){
    NO *p = lista->cabeca->proximo;
    int flag = 0;

    if(lista != NULL && chave != NULL){
        while(p != NULL){
            if(busca_chave_seq(p->item->palavras, chave, 0, tamanho_seq(p->item->palavras)-1)){
                imprime_site_busca(p);
                flag = 1;
            }
            p = p->proximo;
        }

        if(flag == 0){
            printf("Nenhum resultado encontrado!\n");
        }
    }

}

void sugestao_site(LISTA *lista, char *chave){
    LISTA *sugestoes = criar_lista();
    LISTA_SEQ *aux = criar_lista_seq();
    int flag = 0;

    if(lista != NULL && chave != NULL){
        NO *p = lista->cabeca->proximo;
        //primeira busca e preenchendo a lista 'aux' com as palavras chaves de todos os resultados encontrados
        while(p != NULL){
            if(busca_chave_seq(p->item->palavras, chave, 0, tamanho_seq(p->item->palavras)-1)){
                transfere_seq(aux, p->item->palavras);
                flag = 1;
            }
            p = p->proximo;
        }

        //segunda busca - utilizando todas as palavras chaves
        while(!listaVazia_seq(aux)){
            char *word = remove_fim_seq(aux);
            p = lista->cabeca->proximo;

            while(p != NULL){
                if(busca_chave_seq(p->item->palavras, word, 0, tamanho_seq(p->item->palavras)-1)){
                    insere_site(sugestoes, criar_no(criar_item(p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link)));
                }
                p = p->proximo;
            }

            free(word);
        }

        //imprimindo os resultados
        if(!vazia(sugestoes) && (sugestoes!=NULL)){
            p = sugestoes->cabeca->proximo;
            while(p != NULL){
                imprime_site_busca(p);
                p = p->proximo;
            }
        }

        if(flag == 0){
            printf("Nenhum resultado encontrado!\n");
        }

        liberar_lista_seq(&aux);
        apagar_lista(&sugestoes);
    }
}

void finaliza_lista(LISTA **ptr){
    if(ptr != NULL && (*ptr) != NULL){
        atualizar_arquivo(*ptr);
        apagar_lista(ptr);
    }
}
