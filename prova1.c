#include <stdio.h>
#define TMAX 10

/* 2. Sejam duas sequencias L1 e L2 referente a alunos matriculados em 
duas disciplinas distintas. Elabore um pseudo-algoritmo que resolva o problema
especificado abaixo. Cada elemento da lista deve conter o número da matrícula
do aluno (inteiro). Assuma que o número máximo de alunos matriculados é NMAX
Ache as matrículas que aparecem em L1, mas não aparecem em L2. Tais matrículas
devem ser inseridas em uma lista sequêncial resultante L3 */

void comparaListas(int l1[], int l2[]) {
  int k = 0;
  int l3[TMAX];

  for (int i=0; i<TMAX; i++) {
    int ver = 0;

    for (int j=0; j<TMAX; j++) {
      if (l1[i] == l2[j]) {
        ver = 1;
        break;
      }
    }

    if (ver == 0) {
      l3[k] = l1[i];
      k++;
    }
  }

  printf("L1: ");
  for (int i=0; i<TMAX; i++) {
    printf("%d ", l1[i]);
  }

  printf("\nL2: ");
  for (int i=0; i<TMAX; i++) {
    printf("%d ", l2[i]);
  }

  printf("\nL3: ");
  if (k != 0) {
    for (int i=0; i<k; i++) {
      printf("%d ", l3[i]);
    }
  }
}


 /* .3 Eu realmente não sei oq fazer nessa questão, 
 mas tão aí os algoritmos de busca binaria e insertion sort */

int buscaBinaria(int arr[], int val, int com, int fim) {
  while (fim > com) {
    int meio = (com + fim)/2;

    if (val == arr[meio]) {
      return meio;

    } else {
      if (val < arr[meio]) {
        return buscaBinaria(arr, val, com, meio);

      } else {
        return buscaBinaria(arr, val, meio, fim);
      }
    }
  }
  return -1;
}

void insertionSort(int arr[], int len) {
  for (int i = 1; i < len; i++) {
    int j = i;

    while (j > 0 && arr[j-1] > arr[j]) {
      int aux = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = aux;
      j--;
    }
  }
}

void main() {
  // 2.
  int l1[TMAX] = {1, 3, 5, 6, 7, 8, 9, 10, 11, 12};
  int l2[TMAX] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

  comparaListas(l1, l2);
}