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
    //aramzenar o ultimo codigo utilizado?
};

boolean atualizar_arquivo(LISTA *lista){
    FILE *fp = fopen("googlebot.txt", "w");
    int i;

    if(fp != NULL){
        NO *p = lista->cabeca->proximo;

/*//=======

            }
            p = p->proximo;

        }
        free(word);
    }

    imprime_lista(sugestoes);

    liberar_lista(&aux);
    apagar_lista(&sugestoes);
}

boolean atualizar_arquivo(LISTA *lista){
    FILE *fp = fopen("googlebot.txt", "w");
    int i;

    if(fp != NULL){
        NO *p = lista->cabeca->proximo;

//>>>>>>> origin/master*/
        while(p != NULL){
            fprintf(fp,"%.4d,%s,%d,%s", p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link);
            for(i=0; i < tamanho_seq(p->item->palavras); i++){
                char *word = retorna_chave_posicao(p->item->palavras, i);
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

/*
    for(i=0; i < tamanho_seq(p->item->palavras); i++){
        word = retorna_chave_posicao(p->item->palavras, i);

        if(word != NULL){
            inserir_ordenado(aux->item->palavras, word);
            free(word);
        }
    }
*/
    return aux;
}

//<<<<<<< HEAD
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
    liberar_lista(&((*ptr)->item->palavras));
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
        atualizar_arquivo(*ptr); //lugar errado

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
//<<<<<<< HEAD
            //imprime_site(p);
            printf("%.4d, %s, %d, %s", p->item->codigo, p->item->nomeSite, p->item->relevancia, p->item->link);
            imprime_lista_seq(p->item->palavras);
            printf("\n");

/*//=======
            imprime_site(p);
//>>>>>>> origin/master*/
            p = p->proximo;
        }
    }
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
                inserir_ordenado(aux->item->palavras, chave);
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
        //NO *p = lista->cabeca->proximo;
        NO *p = existe_codigo(lista, codigo);
        /*while(p != NULL && p->item->codigo != codigo)
            p = p->proximo;*/

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
        //ordenaLista(lista, p);
        //insertionSort(lista);
    //printf("tentando RETIRAR da lista:\n");
        retira_no(lista, p);
    //printf("tentando INSERIR da lista:\n");
        insere_site(lista, p);
    //printf("FEITO\n");
    }

}



void busca_palavra(LISTA *lista, char *chave){
    NO *p = lista->cabeca->proximo;
    while(p != NULL){
        if(busca_chave(p->item->palavras, chave, 0, tamanho_seq(p->item->palavras)-1)){
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
        if(busca_chave(p->item->palavras, chave, 0, tamanho_seq(p->item->palavras)-1)){
            transfere(aux, p->item->palavras);
        }
        p = p->proximo;
    }

    while(!listaVazia(aux)){
        char *word = remove_fim(aux);
        p = lista->cabeca->proximo;

        while(p != NULL){
            if(busca_chave(p->item->palavras, word, 0, tamanho_seq(p->item->palavras)-1)){
printf("achei palavra\n");
                insere_site(sugestoes, copia_no(p));
//<<<<<<< HEAD

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

    liberar_lista(&aux);
    apagar_lista(&sugestoes);
    //printf("teste malosc\n");
}
