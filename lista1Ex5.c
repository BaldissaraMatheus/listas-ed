#include <stdio.h>
#define TMAX 10

/* 5. Considere uma pilha P vazia e uma fila F não vazia. Utilizando apenas os testes de fila
e pilha vazias, as operações enfila(), desenfila(), empilha(), desempilha(), de acordo com a
necessidade, escreva uma função que inverta a ordem dos elementos da fila F . */

void empilha(int pilha[], int *topo, int val) {
  if (*topo < TMAX) {
    pilha[*topo] = val;
    *topo += 1;   
  }
}

int desempilha(int pilha[], int *topo) {
  if (*topo > 0) {
    *topo -= 1;
    int val = pilha[*topo];

    return val;

  } else {
    return -1;
  }
}

void enfila(int fila[], int *fim, int val) {
  if ((*fim+1)%TMAX) {
    fila[*fim] = val;
    *fim = ((*fim+1)%TMAX);
  }
}

int desenfila(int fila[], int *inicio, int *fim) {
  if (*fim != *inicio) {
    int val = fila[*inicio];
    *inicio = (*inicio+1)%TMAX;

    if (*fim == *inicio) {
      *fim = 0;
      *inicio = 0;
    }
    return val;

  } else {
    return -1;
  }
}

void main() {
  int finalFila1 = 5;
  int inicioFila1 = 0;
  int finalFila2 = 0;
  int topo = 0;

  int fila1[TMAX] = {1, 2, 3, 4, 5};
  int pilha[TMAX] = {};
  int fila2[TMAX] = {};

  for (int i = 0; i<finalFila1; i++) {
    printf("%d ", fila1[i]);
  }

  for (int i = 0; i<finalFila1; i++) {
    int val = desenfila(fila1, &inicioFila1, &finalFila1);
    empilha(pilha, &topo, val);
  }

  while (topo != 0) {
    int val = desempilha(pilha, &topo);
    enfila(fila2, &finalFila2, val);
  }

  printf("\n"); 
  for (int i = 0; i<finalFila2; i++) {
    printf("%d ", fila2[i]);
  }
}