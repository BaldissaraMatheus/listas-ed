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

void main() {
  int l1[TMAX] = {1, 3, 5, 6, 7, 8, 9, 10, 11, 12};
  int l2[TMAX] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

  comparaListas(l1, l2);
}