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

Arvore* removeDaFila(Fila *header) {
  if (header != NULL){
    Arvore* auxNo = header->no;
    header = header->prox;

    return auxNo;
  }
}

/* 1. Especifique um pseudo algoritmo que calcule o nível de cada nó da ár-
vore, armazenando o valor calculado no campo nível. Ao final do algo-
ritmo, forneça a altura da árvore A. */

int retornaProfundidade(Arvore* raiz, int val) {
  if (raiz == NULL) {
    return NULL;

  } else {
    if (raiz->valor == val) {
      return 0;   

    } else {
      if (raiz->valor > val) {
        return 1 + retornaProfundidade(raiz->esq, val);    

      } else {
        return 1 + retornaProfundidade(raiz->dir, val);
      }
    }
  }
}

// Atribui profundidade para cada nó e retorna altura da árvore
int atribuiProfundidade(Arvore* raiz, int nivel) {  
  int esq;
  int dir;

  if (raiz == NULL) {
    return NULL;

  } else {
    raiz->nivel = nivel;

    if ((raiz->esq == NULL) && (raiz->dir == NULL)) {
      return nivel;

    } else {
      if (((raiz->esq == NULL) && (raiz->dir != NULL))) {
        dir = atribuiProfundidade(raiz->dir, nivel+1);
        return dir;

      } else if ((raiz->esq != NULL) && (raiz->dir == NULL)) {
        esq = atribuiProfundidade(raiz->esq, nivel+1);
        return esq;
          
      } else {
        dir = atribuiProfundidade(raiz->dir, nivel+1);
        esq = atribuiProfundidade(raiz->esq, nivel+1);

        if (esq > dir) 
           return esq;
        else 
           return dir;          
      }
    }
  }
}
  

/* 2. Percursos em largura de uma árvore (binária ou mária, em que os nós
são percorridos pelo seu nível. Especifique um algoritmo que dado uma
árvore binária, os nós são percorridos por nível. */

void percorrePorNivel(Arvore* raiz) {
  if(raiz != NULL){
    Fila* fila = NULL;
    fila = insereNaFila(fila, raiz);

    while (fila != NULL) {
      Arvore* aux = removeDaFila(&fila);
      printf("%d ", aux->valor);

      if (aux->esq != NULL) {
        fila = insereNaFila(fila, aux->esq);
      }
      
      if (aux->dir != NULL) {
        fila = insereNaFila(fila, aux->dir);
      }        
    }
  }
}


/* 3. Escreva a função int tamanho(Arvore T) que recebe uma árvore binária
e retorna o seu número de nós. */

int retornaTamanho(Arvore* raiz) {
  if (raiz == NULL) {
    return 0;
  } else {
    return 1 + retornaTamanho(raiz->esq) + retornaTamanho(raiz->dir);
  }
}


/* 4. Escreva um pseudo-algoritmo de um procedimento minmax() que recebe
um ponteiro para a raiz de uma árvore binária e retorna o maior valor e o
menor valor dentre todos os nós da árvore. */

int retornaMenorValor(Arvore* raiz) {
  Arvore* minNo = raiz;
  int minValor = minNo->valor;
  int minEsq;
  int minDir;

  if (raiz->esq != NULL) {
    minEsq = retornaMenorValor(minNo->esq);

    if (minEsq < minValor) {
      minValor = minEsq;
    }       
  }
  
  if (raiz->dir != NULL) {
    minDir = retornaMenorValor(minNo->dir);
    
    if (minDir < minValor) {
      minValor = minDir;
    }       
  }       

  return minValor;
}

int retornaMaiorValor(Arvore* raiz) {
  Arvore* maxNo = raiz;
  int maxValor = maxNo->valor;
  int maxEsq;
  int maxDir;

  if (raiz->esq != NULL) {
    maxEsq = retornaMenorValor(maxNo->esq);

    if (maxEsq > maxValor) {
      maxValor = maxEsq;
    }       
  }
  
  if (raiz->dir != NULL) {
    maxDir = retornaMenorValor(maxNo->dir);
    
    if (maxDir > maxValor) {
      maxValor = maxDir;
    }       
  }       

  return maxValor;
}

// Implementação INCORRETA (porque não é possível retornar array em c) que pode ser dada como correta na prova
/*
void minMaxVoid(Arvore* raiz) {
  if(raiz == NULL) {
    printf("Árvore vazia");

  } else {
    int numeros[2];

    arrMaxMin[0] = retornaMenorValor(raiz);
    arrMaxMin[1] = retornaMaiorValor(raiz);

    return arrMaxMin;;
  }
}
*/

// Implementação CORRETA que pode ser dada como errada na prova por não retornar valor nenhum
void minMaxVoid(Arvore* raiz) {
  if(raiz == NULL) {
    printf("Árvore vazia");

  } else {
    int arrMaxMin[2];

    arrMaxMin[0] = retornaMenorValor(raiz);
    arrMaxMin[1] = retornaMaiorValor(raiz);

    printf("%d %d", arrMaxMin[0], arrMaxMin[1]);
  }
}


/* 5. Escreva um pseudo-algoritmo de um procedimento first(Arvore T)
que, dada uma árvore binária T , retorna o primeiro elemento que seria
impresso num percurso em-Ordem. Faça o mesmo para os percursos
Pré-Ordem e Pós-Ordem. */

// Em Ordem ou Ordem Simétrica - esq, head, dir
Arvore* firstEmOrdem (Arvore* raiz) {
  return raiz->esq;
}

// Pré-ordem - head, esq, dir
Arvore* firstPreOrdem (Arvore* raiz) {
  return raiz;
}
// Pós-ordem - esq, dir, head
Arvore* firstPosOrdem (Arvore* raiz) {
  return raiz->esq;
}


void main() {

}