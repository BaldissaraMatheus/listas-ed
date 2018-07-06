#include <stdio.h>

/* 7. Escreva uma função que verifique se um vetor V de N elementos
 está em ordem crescente. */


void verifica(int arr[], int len) {
  for (int i = 0; i < len - 1; i++) {
    if (arr[i] > arr[i+1]) {
      printf("Lista desordenada \n");
      return;
    }
  }
  printf("Lista ordenada \n");
}

void main() {
  int v1[] = {1, 4, 6, 2, 3};
  int v2[] = {1, 2, 3, 7, 7};
  int len = sizeof(v1)/sizeof(int);

  verifica(v1, len);
  verifica(v2, len);
}
