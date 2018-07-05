#include <stdio.h>
#include <string.h>


/* 2. Escreva um algoritmo que use uma pilha para inverter a ordem das letras de cada palavra
de uma string, preservando a ordem das palavras. Por exemplo, para a string for: ESTE
EXERCICIO E MUITO FACIL, o resultado deve ser ETSE OICICREXE E OTIUM LICAF. */

void empilha(char frase[], char el, int tmax, int *topo) {
  if (*topo < tmax) {
    frase[*topo] = el;
    *topo += 1;
  }
}

void inverte(char fraseIn[], char fraseOut[], int tmax, int *topo) {
  int i = 0;
  int inicio = i;

  while (i < tmax) {
    if (fraseIn[i] == ' ' && i != 0) {      
      for (int j = i-1; j >= inicio; j--) {
        empilha(fraseOut, fraseIn[j], tmax, topo);
      }  

      empilha(fraseOut, fraseIn[i], tmax, topo);
      inicio = i + 1;
    }

    i++;
  }

  for (int j=i-1; j >= inicio; j--) {
    empilha(fraseOut, fraseIn[j], tmax, topo);
  }
}

void main() {
  char fraseIn[50] = "Qual doce eh mais doce que o doce de batata doce?";
  char fraseOut[50] = "";
  int len = strlen(fraseIn);
  int topo = 0;

  inverte(fraseIn, fraseOut, len, &topo);
  printf("%s\n", fraseIn);
  printf("%s\n", fraseOut);
}
