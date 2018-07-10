#include <stdio.h>
#include <stdlib.h>
#define TMAX 11

/* 1. Explique onde o maior elemento inteiro pode residir em uma min_heap,
assumindo que todos os elementos da lista em forma de min_heap sejam
inteiros e distintos. */

/* R: Em uma folha, uma vez que no min_heap a raiz deve ser menor que seus descendentes */


/* 2. Faça o algoritmo build_min_heap() que construa, dada uma sequencia
de n elementos, uma min_heap. */

void sort_minHeap (int arr[], int i){
  if((i > 1) && (arr[i/2] > arr[i])){
    int aux = arr[i];
    arr[i] = arr[i/2];
    arr[i/2] = aux;
    sort_minHeap(arr, i/2);
  }
}

void build_minHeap(int arr[], int len) {
  for (int i=0; i<len; i++) {
    sort_minHeap(arr, i);
  }
}


/* 4. Faça o algoritmo build_max_heap() que construa, dada uma sequencia
de n elementos, uma max_heap. */

void sort_maxHeap (int arr[], int i){
  if((i > 1) && (arr[i/2] < arr[i])){
    int aux = arr[i];
    arr[i] = arr[i/2];
    arr[i/2] = aux;
    sort_maxHeap(arr, i/2);
  }
}

void build_maxHeap(int arr[], int len) {
  for (int i=0; i<len; i++) {
    sort_maxHeap(arr, i);
  }
}


/* 6. O vetor com os inteiros nesta ordem: [ 23, 17, 14, 6, 13, 20, 10, 11, 5,
7, 12] é uma max_heap? Senão for, converta para max_heap. Qual o
algoritmo que você usaria? */

/* R: Não é um max_heap porque no max_heap o pai deve ser maior que seus filhos.
Usaria o algoritmo da questão 4. */


/* 7. Dada um vetor H de n elementos, descreva um algoritmo que verifique
se H é um max_heap. */

void ver_max_heap(int arr[], int len) {
  for (int i=0; i<len/2; i++) {
    if(arr[(i*2)+1] > arr[i] || arr[(i*2)+2] > arr[i]) {
      printf("Não é max_heap.\n");
      return;
    }
  }

  printf("É max_heap.\n");
}


void main() {  
  int arr[TMAX] = {40, 17, 14, 13, 20, 30, 28, 7, 2, 25, 35};
  for (int i=0; i<TMAX; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
  ver_max_heap(arr, TMAX);

  build_maxHeap(arr, TMAX);

  for (int i=0; i<TMAX; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
  ver_max_heap(arr, TMAX);

} 