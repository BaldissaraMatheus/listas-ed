#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
  int valor;
  struct no* prox;
} No;

No* criaLista() {
  return NULL;
}

No* insereInicio(No* head, int val) {
  No* novo = (No*) malloc(sizeof(No));
  novo->valor = val;
  novo->prox = head;
}

void imprimeLista(No* head) {
  No* aux = (No*)malloc(sizeof(No));
  for (aux=head; aux!=NULL; aux=aux->prox) {
    printf("%d ", aux->valor);
  }
}


/* 3. Sejam duas listas encadeadas apontadas pelos ponteiros head1 e head 2. Especifique um
pseudo-algoritmo que identifique se as duas listas são iguais ou não. */

void comparaListas(No* l1, No* l2) {
  No* aux1 = l1;
  No* aux2 = l2;

  while (aux1->prox != NULL && aux2->prox != NULL) {
    if (aux1->valor != aux2->valor) {
      printf("Listas diferentes");
      return;

    } else {
      aux1 = aux1->prox;
      aux2 = aux2->prox;
    }
  }

  if ((aux1->prox == NULL && aux1->prox != NULL) || (aux1->prox != NULL && aux2->prox == NULL)) {
    printf("Listas diferentes");
    return;

  } else {
    printf("Listas iguais");
  }
}


/* 4. Seja a lista encadeada apontada por head1 conforme especificada no item anterior. Supo-
nha que a lista esteja ordenada. Especifique o pseudo-algoritmo de busca por valor. Se
existente, esse elemento deve ser atualizado para novo_valor. No entanto, para atualizar,
a lista encadeada ao final deve continuar ordenada. */

No* insereOrdenado(No* lista, int val) {
  No* novo = (No*)malloc(sizeof(No)); 
  No* aux = lista;
  No* ant = lista;

  novo->valor = val;

  while(aux!=NULL) {

    if (novo->valor <= aux->valor) {

      if (aux == ant) {
        novo->prox = aux;
        return novo;

      } else {
        ant->prox = novo;
        novo->prox = aux;
        return lista;

      }
    } else {
      ant = aux;
      aux = aux->prox;
    }    
  }
  
  ant->prox = novo;
  return lista;
}


/* 5. Escreva uma função recursiva e outra não recursiva para contar o número de elementos na
lista encadeada apontada por p */

void contaElementosRecursivo(No* lista, int cont) {
  No* aux = lista;

  if (aux->prox == NULL) {
    printf("%d\n", (cont+1));

  } else {
    cont+=1;
    contaElementosRecursivo(aux->prox, cont);
  }
}

void contaElementosNaoRecursivo(No* lista) {
  No* aux = lista;
  int cont = 1;

  while (aux->prox != NULL) {
    cont += 1;
    aux = aux->prox;
  }

  printf("%d\n", cont);
}

void main() {

  /* 3.
  No* lista1 = criaLista();
  lista1 = insereInicio(lista1, 5);
  lista1 = insereInicio(lista1, 4);

  No* lista2 = criaLista();
  lista2 = insereInicio(lista2, 5);
  lista2 = insereInicio(lista2, 6);

  comparaListas(lista1, lista2);
  */

  /* 4. 
  No* lista1 = criaLista();
  lista1 = insereInicio(lista1, 6);
  lista1 = insereInicio(lista1, 4);

  lista1 = insereOrdenado(lista1, 3);
  imprimeLista(lista1);
  */

 /* 5. 
  No* lista1 = criaLista();
  lista1 = insereInicio(lista1, 6);
  lista1 = insereInicio(lista1, 4);
  lista1 = insereInicio(lista1, 6);
  lista1 = insereInicio(lista1, 4);
  
  
  // Recursivo
  contaElementosRecursivo(lista1, 0);

  //Não recursivo
  contaElementosNaoRecursivo(lista1);
*/
}