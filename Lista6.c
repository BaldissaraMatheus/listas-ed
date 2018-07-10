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
Fila* insereNaFila(Fila* fila, Arvore* no) {
  Fila* aux = fila;
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
    return fila;
  }
}

Arvore* removeDaFila(Fila *fila) {
  if (fila != NULL){
    Arvore* auxNo = fila->no;
    fila = fila->prox;

    return auxNo;
  }
}

/* 1. Descreva um algoritmo min_value_ABB que forneça o menor valor armazenado em B. */
int min_value_ABB(Arvore* raiz) {
  Arvore* aux = raiz;
  int minValor = aux->valor;
  int minEsq;
  int minDir;

  if (raiz->esq != NULL) {
    minEsq = min_value_ABB(aux->esq);

    if (minEsq < minValor) {
      minValor = minEsq;
    }       
  }
  
  if (raiz->dir != NULL) {
    minDir = min_value_ABB(aux->dir);
    
    if (minDir < minValor) {
      minValor = minDir;
    }       
  }       

  return minValor;
}

/* 2. Descreva um algoritmo max_value_ABB que forneça o maior valor armazenado em B. */
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


/* 4. Sejam B1 e B2 duas árvores binárias apontadas por no_ABB* T1 e
no_ABB* T2 respectivamente. Faça um procedimento merge_ABB (T1, T2)
que faça a junção das duas árvores de forma eficiente, resultando em
uma árvore binária de busca apontada por no_ABB* T3. Atenção, as
árvores originais não devem ser perdidas. */

typedef struct fila{
  Arvore* no;
  struct fila *prox;
} Fila;

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

Fila* removeDaFila(Fila *header) {
  if (header != NULL){
    Arvore* auxNo = header->no;
    header = header->prox;

    return auxNo;
  }
}

Arvore* insere(Arvore* head, int val) {
  Arvore* novo = (Arvore*) malloc(sizeof(Arvore));
  novo->valor = val;
}

void insereAbb(Arvore* no, int valor) {
  if(no == NULL) {
    no = insere(no, valor);

  } else {
    if(valor == no->valor) {
      return;

    } else if(valor > no->valor) {
      if(no->dir != NULL) {
        insere(no->dir, valor);
        
      } else {
        no->dir = insere(no->dir, valor);
      }
    } else if(valor < no->valor) {
      if(no->esq != NULL) {
        insere(no->esq, valor);
          
      } else {
        no->esq = insere(no->esq, valor);

      }
    }
  }
}

Arvore* merge_ABB(Arvore* t1, Arvore* t2) {
  if (t1==NULL && t2==NULL) return;

  Arvore* t3 = t1;
  Arvore* aux = t2;

  Fila* fila;
  insereNaFila(fila, aux);

  while (fila!=NULL) {

    aux = removeDaFila(fila);    
    insereAbb(t3, aux->valor);

    if (aux->esq != NULL) {
      insereNaFila(fila, t3->esq);
      aux = aux->esq;
    }
    
    if (aux->dir != NULL) {
      insereNaFila(fila, t3->dir);
      aux = aux->esq;    
    }
  }
  return t3;
}


/* 5. Seja v um dado valor inteiro. Especifique um algoritmo que procure o
valor inteiro imediatamente menor que v armazenado em B. Caso tal
elemento exista, remova-o. */

// Ignorando que o nó possa não ter descendentes a direita (mais simples)
int procuraMaiorImediato(Arvore *raiz, int valor){
if (raiz != NULL) {
    Arvore *aux = raiz;

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
