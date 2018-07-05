#include <stdio.h>
#define TMAX 100


/* 4. Sejam três filas Fila2, Fila5 e Fila7, armazenar respectivamenete, números inteiros divi-
síveis por 2, 5 e 7. Escreva um procedimento enfila, que percorre um vetor, e enfila o valor
na Fila correta. */

void enfila(int arr2[], int arr5[], int arr7[], int *fim2, int *fim5, int *fim7, int el) {
  if (el%2 == 0) {
    arr2[*fim2] = el;
    *fim2 += 1;
  }

  if (el%5 == 0) {
    arr5[*fim5] = el;
    *fim5 += 1;
  }
  
  if (el%7 == 0) {
    arr7[*fim7] = el;
    *fim7 += 1;
  }
}

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void main() {
  int fila2[TMAX];
  int fila5[TMAX];
  int fila7[TMAX];
  int fim2 = 0;
  int fim5 = 0;
  int fim7 = 0;
  
  enfila(fila2, fila5, fila7, &fim2, &fim5, &fim7, 2);
  enfila(fila2, fila5, fila7, &fim2, &fim5, &fim7, 4);
  enfila(fila2, fila5, fila7, &fim2, &fim5, &fim7, 5);
  enfila(fila2, fila5, fila7, &fim2, &fim5, &fim7, 7);
  enfila(fila2, fila5, fila7, &fim2, &fim5, &fim7, 8);
  enfila(fila2, fila5, fila7, &fim2, &fim5, &fim7, 10);
  enfila(fila2, fila5, fila7, &fim2, &fim5, &fim7, 12);
  enfila(fila2, fila5, fila7, &fim2, &fim5, &fim7, 14);
  enfila(fila2, fila5, fila7, &fim2, &fim5, &fim7, 15);

  printArray(fila2, fim2);
  printArray(fila5, fim5);
  printArray(fila7, fim7);
}
