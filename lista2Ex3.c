#include <stdio.h>


/* 3. Seja um vetor P de TMAX elementos inteiros. Duas pilhas podem ser manipuladas neste
mesmo vetor. A pilha P1 vai ser manipulada em uma extremidade e a pilha P2 na outra
extremidade do vetor. 
(a) escreva o procedimento empilha(Pilha, valor) que empilha um elemento na Pilha (que
pode ser P1 ou P2) e o valor dado.
(b) escreva o procedimento desempilha(Pilha) que desempilha o topo da Pilha (que pode
ser P1 ou P2 .*/


void empilha(int arr[], int *p, int len, int el) {
    if (*p < len) {
      arr[*p] = el;
      *p += 1;
    }
}

void desempilha(int arr[], int *p, int len) {
  if (*p != 0 || len < *p * len) {
    *p -= 1;
  }
}

void printArray(int arr[], int beg, int end) {
  for (int i = beg; i < end; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void main() {
  int arr[] = {0, 0, 0, 0, 0, 0};
  int lenA = (sizeof(arr)/sizeof(int))/2;
  int lenB = (sizeof(arr)/sizeof(int));
  
  // Pilha B começa onde a A acaba
  int topoA = 0;
  int topoB = lenA;

  // Empilha 2 elementos em cada pilha
  empilha(arr, &topoA, lenA, 4);
  empilha(arr, &topoB, lenB, 5);
  empilha(arr, &topoA, lenA, 4);
  empilha(arr, &topoB, lenB, 5);
  printArray(arr, 0, topoA);
  printArray(arr, lenA, topoB);

  // Desempilha 1 elemento de cada pilha
  desempilha(arr, &topoA, lenA);
  desempilha(arr, &topoB, lenB);
  printArray(arr, 0, topoA);
  printArray(arr, lenA, topoB);
}
