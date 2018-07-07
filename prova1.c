#include <stdio.h>
#define TMAX 10

/* 1. Responda os itens abaixo, explicando devidamente:
(a) O que é complexidade do pior caso?
R: Complexidade do pior caso indica o maior tempo de execução dada qualquer entrada de tamanho n.
  É utilizada para comparar a eficiência de algoritmos.

(b) Diga a complexidade do trecho do código abaixo:
  for (int i=0; i < n; i++)
    for (j = i; j < n; j++) j+=i;
R: O(n^2): Executa n intruções no primeiro laço de repetição e n instruções no segundo laço
para cada instrução do primeiro laço, portanto n*n.

(c) Preencha a tabela abaixo:
  NÚMERO DE PASSOS || COMPLEXIDADE ASSINTÓTICA O( )
  100n^3           || O(n^3)
  10^10000         || O(1)
  5^n + 999        || O(5^n)
  5^n + n^1000     || O(5^n)
  log n + n^100    || O(n^100)
*/

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


 /* .3 Seja um conjunto de inteiros armazenados em uma lista sequêncial ou vetor S
 com N elementos. Escreva um pseudo-algoritmo do algoritmo de ordenação insertionSort, definido
 de acordo com os seguintes passos:
 - O primeiro elemento da lista está ordenado (ou seja, na posição correta);
 - A partir do segundo elemento, insere cada elemento na posição correta entre aqueles já ordenados
 - O elemento já inserido na posição adequada movendo-se todos os elementos maiores para a
 posição seguinte do vetor.
 Obs.: Essa procura deve ser realizada por busca binária.
 
 Eu realmente não sei oq fazer nessa questão, 
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


/* 4. Sejam duas listas encadeadas apontadas pelos ponteiros head1 e head 2. Especifique um
pseudo-algoritmo que identifique se as duas listas são iguais ou não. */

typedef struct lista{
  int valor;
  struct no* prox;
} No;

void verificaIgualdade(No* l1, No* l2) {
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


void main() {
  // 2.
  int l1[TMAX] = {1, 3, 5, 6, 7, 8, 9, 10, 11, 12};
  int l2[TMAX] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

  comparaListas(l1, l2);
}