#include <stdio.h>
#include <stdlib.h>

// Structs
typedef struct arvore {
  int valor;
  int nivel;
  struct arvore* esq;
  struct arvore* dir;
} Arvore;

typedef struct fila{
  Arvore* no;
  struct fila *prox;
} Fila;

// Funções de fila
Fila* insereNaFila(Fila* header, Arvore* no) {
  Fila* aux = header;
  Fila* novo = (Fila*)malloc(sizeof(Fila));
  novo->no = no;
  novo->prox = NULL;

  if (aux == NULL) {
    return novo;
    
  } else {
    while (aux->prox != NULL) {
      aux = aux->prox;
    }

    aux->prox = novo;
    return header;
  }
}

// Em dúvida quanto a essa função e sua aplicação no exercício 2
Arvore* removeDaFila(Fila **header) {
  if ((*header) != NULL){
    Fila *auxFila = (*header);
    Arvore* auxArvore = (*header)->no;
    (*header) = (*header)->prox;
    free(auxFila);

    return auxArvore;
  }
}

/* 1. Descreva um algoritmo min_value_ABB que forneça o menor valor armazenado em B. */
int min_value_ABB(Arvore* raiz) {
  Arvore* aux = raiz;
  int minValor = aux->valor;
  int minEsq;
  int minDir;

  if (raiz->esq != NULL) {
    minEsq = in_value_ABB(aux->esq);

    if (minEsq < minValor) {
      minValor = minEsq;
    }       
  }
  
  if (raiz->dir != NULL) {
    minDir = in_value_ABB(aux->dir);
    
    if (minDir < minValor) {
      minValor = minDir;
    }       
  }       

  return minValor;
}

/* 1. Descreva um algoritmo max_value_ABB que forneça o maior valor armazenado em B. */
int max_value_ABB(Arvore* raiz) {
  Arvore* aux = raiz;
  int maxValor = aux->valor;
  int maxEsq;
  int maxDir;

  if (raiz->esq != NULL) {
    maxEsq = max_value_ABB(aux->esq);

    if (maxEsq > maxValor) {
      maxValor = maxEsq;
    }       
  }
  
  if (raiz->dir != NULL) {
    maxDir = max_value_ABB(aux->dir);
    
    if (maxDir > maxValor) {
      maxValor = maxDir;
    }       
  }       

  return maxValor;
}

/* 3. Seja value um dado valor inteiro. Especifique um algoritmo que mostre
o valor inteiro imediatamente maior que value armazenado em B, caso
exista. */

// Ignorando que o nó possa não ter descendentes a direita (mais simples)
int procuraMaiorImediato(Arvore *raiz, int valor){
if (raiz != NULL) {
    Arvore *aux = raiz;
    Fila *fila = NULL;

    while ((aux !=  NULL) && (valor != aux->valor)) {
      if (valor > aux->valor) {        
        aux = aux->dir;

      } else {
        aux = aux->esq;
      }
    }

    if (valor == aux->valor) {
      aux = aux->dir;

      while (aux->esq != NULL)
        aux = aux->esq;

      return aux->valor;
    }
  }
  return -1;
}

// Implicando que o nó possa não ter descendentes a direita (mais complexo)
int procuraMaiorImediato(Arvore *raiz, int valor){
  int retorno = -1;

  if (raiz != NULL) {
    Arvore *aux = raiz;
    Fila *fila = NULL;

    while ((aux !=  NULL) && (valor != aux->valor)) {
      fila = insereNaFila(fila, aux);

      if (valor > aux->valor) {        
        aux = aux->dir;

      } else {
        aux = aux->esq;
      }
    }

    if (valor == aux->valor) {
      if (aux->dir != NULL) {
        aux = aux->dir;

        while (aux->esq != NULL)
          aux = aux->esq;

        retorno = aux->valor;

      } else {
        int verif = 1;

        while ((fila != NULL) && (verif != 0)) {
          int compare = removeDaFila(fila)->valor;

          if (compare > valor) {
            retorno = compare;
            verif = 0;
          }
        }
      }
    }
  }

  return retorno;
}


/* 5. Seja v um dado valor inteiro. Especifique um algoritmo que procure o
valor inteiro imediatamente menor que v armazenado em B. Caso tal
elemento exista, remova-o. */

// Ignorando que o nó possa não ter descendentes a direita (mais simples)
int procuraMaiorImediato(Arvore *raiz, int valor){
if (raiz != NULL) {
    Arvore *aux = raiz;
    Fila *fila = NULL;

    while ((aux !=  NULL) && (valor != aux->valor)) {
      if (valor > aux->valor) {        
        aux = aux->dir;

      } else {
        aux = aux->esq;
      }
    }

    if (valor == aux->valor) {
      aux = aux->esq;

      while (aux->dir != NULL)
        aux = aux->dir;

      return aux->valor;
    }
  }
  return -1;
}