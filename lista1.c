#include <stdio.h>
#define TMAX 10


/* 1. Escreva um programa em C que lê três números inteiros do teclado, e imprime os três
números em ordem crescente. */

void imprimeOrdemCrescente() {
  int num[3];

  for (int i=0; i<3; i++) {
    printf("Digite o %d número: \n", i);
    scanf("%d", &num[i]);
  }

  if (num[0] > num[1]) {
    int aux = num[0];
    num[0] = num[1];
    num[1] = aux;
  }

  if (num[1] > num[2]) {
    int aux = num[1];
    num[1] = num[2];
    num[2] = aux;
  }

  if (num[0] > num[1]) {
    int aux = num[0];
    num[0] = num[1];
    num[1] = aux;
  }

  for (int i=0; i<3; i++) {
    printf("%d ", num[i]);
  }
}


/* 2. Escreva um programa que recebe como entrada uma temperatura em o C ou em o F e con-
verte a temperatura para a outra escala. A escala em que está a temperatura de entrada é
indicada pela letra C ou F. */

int converteParaC(int fahrenheit) {
  int celsius = (fahrenheit - 32)/1.8;
  return celsius;
}

int converteParaF(int celsius) {
  int fahrenheit = (celsius * 1.8) + 32;
  return fahrenheit;
}

void converteTemperatura() {
  int valIn;
  int valOut;
  char escala;

  printf("Digite a temperatura: \n");
  scanf("%d", &valIn);

  printf("Digite a escala: \n");
  scanf(" %c", &escala);

  if (escala == 'c' || escala == 'C') {
    valOut = converteParaF(valIn);

  } else if (escala == 'f' || escala == 'F') {
    valOut = converteParaC(valIn);

  } else {
    printf("Insira uma escala válida");
    return;
  }

  printf("%d \n", valOut);
}


/* 3. Escreva uma função com protótipo
int contaLetra(char *s);
que calcula o número de letras (maiúsculas e minúsculas) da cadeia s.
*/
int contaLetra(char* s) {
  int cont = 0;
  
  for(int i=0; s[i]!='\0'; i++) {
    if (s[i] != ' ') {
      cont += 1;
    }
  }

  return cont;
}

void imprimeNumeroLetras() {
  char string[256];
  int cont;

  printf("Digite o conteúdo da string: \n");
  fgets(string, sizeof(string), stdin); //scanf para ao encontrar o primeiro espaço e gets é uma alternativa insegura, por isso o uso do fgets

  cont = contaLetra(string);
  printf("A string tem %d letras \n", cont);
}


/* 4. Implemente uma função que receba como parâmetro um vetor de números inteiros de ta-
manho N e retorno quantos números negativos estão armazenados neste vetor. */
int contaNumerosNegativos(int arr[], int len) {
  int cont = 0;

  for (int i=0; i<len; i++) {
    if (arr[i] < 0) {
      cont += 1;
    }
  }

  return cont;
}

void imprimeQuantNumerosNegativos() {
  int arr[TMAX];
  int cont;

  for (int i=0; i<TMAX; i++) {
    printf("Digite o valor da posição %d: \n", i);
    scanf("%d", &arr[i]);
  }

  cont = contaNumerosNegativos(arr, TMAX);
  printf("O vetor possui %d números negativos\n", cont);
}


/* 5. Escreva um procedimento que inverta uma lista sequencial de N inteiros, dada como en-
trada. */

void inverteLista() {
  int arr[TMAX];
  int j = 0;

  for (int i=0; i<TMAX; i++) {
    printf("Digite o valor da posição %d: \n", i);
    scanf("%d", &arr[i]);
  }

  for (int i=TMAX-1; i!=TMAX/2; i--) {
    int aux = arr[i];
    arr[i] = arr[j];
    arr[j] = aux;

    j+=1;
  }

  printf("Nova lista: ");
  for (int i=0; i<TMAX; i++) {
    printf("%d ", arr[i]);
  }
}


/* 6. Faça um programa que imprima a soma dos N primeiros termos da série de Fibonacci,
lembrando que esta série é definida da seguinte forma:
termo 1 = 1;
termo 2 = 2;
termo i = termo i−1 + termo i−2 .
Observe que N deve ser dado como entrada.
*/

int somaSequencia(int n) {
  if (n <= 1) {
    return n;
  } else {
    return somaSequencia(n-1) + somaSequencia(n-2);
  }
}

void calculaFibonacci() {
  int n;
  int result;

  printf("Digite o número de elementos da sequência que deseja calcular: \n");
  scanf("%d", &n); 
  result = somaSequencia(n);

  printf("%d \n", result);
}


/* 7. Escreva uma função
int igual(char *s1, char *s2);
para descobrir se as cadeias de caracteres s1 e s2 são iguais, retornando verdadeiro ou
falso, de acordo com a comparação. */

int verificaIgualdadeStrings(char* s1, char* s2) {
  int i = 0;
  
  while (s1[i] != '\0' || s2[i] != '\0' ) {
    if (s1[i] != s2[i]) {
      return 0;
    } else {
      i+=1;
    }
  }

  if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] != '\0' && s2[i] == '\0')) {
    return 0;
  } else {
    return 1;
  }
}

void comparaStrings() {
  char string1[256];
  char string2[256];

  printf("Digite a primeira string: \n");
  fgets(string1, sizeof(string1), stdin);

  printf("Digite a segunda string: \n");
  fgets(string2, sizeof(string2), stdin);

  int ver = verificaIgualdadeStrings(string1, string2);

  if (ver == 1) {
    printf("As strings são iguais \n");
  } else {
    printf("As strings são diferentes \n");
  }
}


/* 8. Escrever um programa que lê duas cadeias s1 e s2, e imprime uma cadeia s3 que contém
todos os caracteres que aparecem em s1, mas não aparecem em s2. */
void imprimeCharEmStr1MasNaoEmStr2() {
  char str1[256];
  char str2[256];
  char str3[256];
  int k = 0;

  printf("Digite a primeira string: \n");
  fgets(str1, sizeof(str1), stdin);

  printf("Digite a segunda string: \n");
  fgets(str2, sizeof(str2), stdin);

  for (int i=0; str1[i]!='\0'; i++) {
    int ver = 0;

    for (int j=0; str2[j]!='\0'; j++) {
      if (str1[i] == str2[j]) {
        ver = 1;
        break;
      }
    }

    if (ver==0) {
      str3[k] = str1[i];
      k+=1;
    }
  }

  printf("String resultante: "); 
  for (int i=0; i<=k; i++) {
    printf("%c", str3[i]);
  }
}


void main() {
  // .1
  //imprimeOrdemCrescente();

  // .2
  //converteTemperatura();

  // .3
  //imprimeNumeroLetras();

  // .4
  //imprimeQuantNumerosNegativos();

  // .5
  //inverteLista();

  // .6
  //calculaFibonacci();

  // .7
  //comparaStrings();

  // .8
  //imprimeCharEmStr1MasNaoEmStr2();
  
}