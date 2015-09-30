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

boolean atualizar_arquivo(LISTA *lista){
    FILE *fp = fopen("googlebot.txt", "w");
    int i;

    if(fp != NULL){
        NO *p = lista->cabeca->proximo;

        while(p != NULL){
            fprintf(fp,"%.4d,%s,%d,%s", p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link);
            for(i=0; i < tamanho_seq(p->item->palavras); i++){
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


NO *copia_no(NO *p){
    NO *aux;
    int i;
    char *word;

    aux = criar_no(criar_item(p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link));
if(aux == NULL) printf("aux eh null\n\n");

    return aux;
}

void imprime_site_busca(NO *p){
    printf("%s - %s", p->item->nomeSite, p->item->link);
    printf("\n");
}


boolean retira_no(LISTA *lista, NO *p){
    if(p != NULL){
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

void apaga_no(NO **ptr){
    liberar_lista_seq(&((*ptr)->item->palavras));
    free((*ptr)->item);
    free(*ptr);
    *ptr = NULL;
}

NO *existe_codigo(LISTA *lista, int code){
    NO *p = lista->cabeca->proximo;

    while(p != NULL && p->item->codigo != code){
        p = p->proximo;
    }
    if(p != NULL){
        return p;
    }else return NULL;
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
    NO *n = (NO *) malloc(sizeof(NO));

    if ((n != NULL) && (item != NULL)){
        n->item = item;
        n->anterior = NULL;
        n->proximo = NULL;
        return(n);
    }
    else
        return(NULL);
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
        atualizar_arquivo(*ptr);

        if(vazia(*ptr) == FALSE){
            esvazia_lista((*ptr)->cabeca->proximo);
        }
        free((*ptr)->cabeca);
        free(*ptr);
        *ptr = NULL;
     }
}

void esvazia_lista(NO *ptr){
    if(ptr->proximo != NULL)
        esvazia_lista(ptr->proximo);

    apaga_no(&ptr);
}

boolean vazia(LISTA *lista){
    if(lista->cabeca->proximo == NULL)
        return(TRUE);

    return(FALSE);
}

int tamanho(LISTA *lista){
    return(lista->tamanho);
}

void imprime_lista(LISTA *lista){
    NO *p;
    if(!vazia(lista) && (lista!=NULL)){
        p = lista->cabeca->proximo;
        while(p != NULL){
            printf("%.4d, %s, %d, %s", p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link);
            imprime_lista_seq(p->item->palavras);
            printf("\n");
            p = p->proximo;
        }
    }else printf("Lista vazia.\n");
}

//inserir no final e chamar funcao de ordenacao
boolean insere_site(LISTA *lista, NO *p){
    if(lista != NULL && p != NULL){
        if((existe_codigo(lista, p->item->codigo)) == NULL){
            if(vazia(lista)){
                lista->cabeca->proximo = p;
                lista->fim = p;
                lista->tamanho++;

                p->anterior = lista->cabeca;
                p->proximo = NULL;
            }
            else{
                NO *n = lista->cabeca->proximo;

                while(n != NULL && n->item->relevancia > p->item->relevancia){
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
    if (!vazia(lista)) {
        NO *p = existe_codigo(lista, codigo);

        if(retira_no(lista, p)){
            apaga_no(&p);
            return (TRUE);
        }
    }
    return (FALSE);
}

void atualiza_relevancia(LISTA *lista, int code, int relevancia){
    NO *p = existe_codigo(lista, code);
    if(p != NULL){
        p->item->relevancia = relevancia;

        retira_no(lista, p);
        insere_site(lista, p);
    }else printf("Codigo nao encontrado!\n");

}


void busca_palavra(LISTA *lista, char *chave){
    NO *p = lista->cabeca->proximo;
    while(p != NULL){
        if(busca_chave_seq(p->item->palavras, chave, 0, tamanho_seq(p->item->palavras)-1)){
            imprime_site_busca(p);
        }
        p = p->proximo;
    }

}

void sugestao_site(LISTA *lista, char *chave){
    LISTA *sugestoes = criar_lista();
    LISTA_SEQ *aux = criar_lista_seq();

    NO *p = lista->cabeca->proximo;
    while(p != NULL){
        if(busca_chave_seq(p->item->palavras, chave, 0, tamanho_seq(p->item->palavras)-1)){
            transfere_seq(aux, p->item->palavras);
        }
        p = p->proximo;
    }

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

    //imprime_lista(sugestoes);
    if(!vazia(sugestoes) && (sugestoes!=NULL)){
        p = sugestoes->cabeca->proximo;
        while(p != NULL){
            imprime_site_busca(p);
            p = p->proximo;
        }
    }

    liberar_lista_seq(&aux);
    apagar_lista(&sugestoes);
}
