#include <stdio.h>
#include <stdlib.h>

// Struct de lista encadeada
typedef struct lista{
  int valor;
  struct no* prox;
} No;

// Funções da lista
No* criaLista() {
  return NULL;
}

No* verificaVazia(No* head) {
  return (head == NULL);
}

No* insereInicio(No* head, int val) {
  No* novo = (No*) malloc(sizeof(No));
  novo->valor = val;
  novo->prox = head;
}

No* insereFinal(No* head, int val) {
  No* novo = (No*)malloc(sizeof(No));

  novo->valor = val;
  novo->prox = NULL;
  
  No* aux = head;

  if (head==NULL) {
    return novo;
    
  } else {
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
  }
  return head;
}

No* removeElemento(No* head, int val) {
  No* aux = head;
  No* ant = head;

  while (aux->valor != val && aux != NULL) {
    ant = aux;
    aux = aux->prox;
  }

  if (aux == NULL) {
    return head;
  }
}

No* buscaElemento(No* head, int val) {
  No* aux = (No*)malloc(sizeof(No));;
  for (aux=head; aux!=NULL; aux=aux->prox) {
    if (aux->valor == val) {
      return aux;
    }
  }
  return NULL;
}

void imprimeLista(No* head) {
  No* aux = (No*)malloc(sizeof(No));
  for (aux=head; aux!=NULL; aux=aux->prox) {
    printf("%d ", aux->valor);
  }
}

void main() {

}