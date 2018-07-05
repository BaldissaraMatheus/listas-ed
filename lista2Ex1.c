#include <stdio.h>
#define TMAX 7
#define T 4


/* 1. Suponha que, a parte do vetor P de TMAX elementos seja ocupada por uma pilha somente
entre as posições de 1 a T , sendo T < TMAX. Escreva o código das funções empilha(),
desempilha(), para essa pilha considerando os limites estabelecidos. */

void empilha(int arr[], int *i, int el) {
  if (*i < T) {
    arr[*i] = el;
    *i += 1;
  }
}

void desempilha(int arr[], int *i) {
  if (*i != 0) {
    *i -= 1;
  }
}

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void main() {
  int p[TMAX];
  int i = 0;

  empilha(p, &i, 0);
  empilha(p, &i, 1);
  empilha(p, &i, 2);
  empilha(p, &i, 3);
  empilha(p, &i, 4);
  printArray(p, i);

  desempilha(p, &i);
  empilha(p, &i, 9);
  // Último elemento não empilha porque ele só empilha até t elementos
  empilha(p, &i, 8);
  printArray(p, i);
}
