#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 1. Considerando as seguintes declaração de uma lista encadeada, 
para representar o cadastro de alunos de uma disciplina: */

typedef struct lista{
  char nome[81];
  char matricula[8];
  char turma;
  float p1;
  float p2;
  float p3;
  struct no *prox;
} No;

/* Implemente uma função que dada uma lista encadeada definida pela estrutura acima, 
ela seja copiada para uma outra lista encadeada.  */

No* criaLista() {
  return NULL;
}
No* insereInicio(No* head, char* nome, char* matricula, char turma, float p1, float p2, float p3) {
  No* lista = (No*)malloc(sizeof(No));;
  strcpy(lista->nome, nome);
  strcpy(lista->matricula, matricula);
  lista->turma = turma;
  lista->p1 = p1;
  lista->p2 = p2;
  lista->p3 = p3;
  lista->prox = head;
}

No* insereFinal(No* head, char* nome, char* matricula, char turma, float p1, float p2, float p3) {
  No* lista = (No*)malloc(sizeof(No));;
  strcpy(lista->nome, nome);
  strcpy(lista->matricula, matricula);
  lista->turma = turma;
  lista->p1 = p1;
  lista->p2 = p2;
  lista->p3 = p3;
  lista->prox = NULL;

  No* aux = head;

  if (head == NULL) {
    return lista;
  } else {
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = lista;
  }
  return head;
}

No* copiaLista(No* head) {
  No* aux = head;
  No* novaLista = criaLista();

  while(aux != NULL) {
    novaLista = insereFinal(novaLista, aux->nome, aux->matricula, aux->turma, aux->p1, aux->p2, aux->p3);
    aux = aux->prox;
  }

  return novaLista;
}

void imprimeLista(No* head) {
  No* aux = (No*)malloc(sizeof(No));
  for (aux=head; aux!=NULL; aux=aux->prox) {
    printf("|| %s | %s | %c | %.1f | %.1f | %.1f ||\n", aux->nome, aux->matricula, aux->turma, aux->p1, aux->p2, aux->p3);
  }
}

/* 2. Considerando a estrutura especificada acima, especifique um algoritmo que crie
uma nova lista encadeada, com os elementos originais, mas ordenados de acordo 
com ordem crescente de média do aluno, onde média do aluno é dada pela fórmula 
(p1+p2+p3)/3 */

void main() {
  No* lista1 = criaLista();
  lista1 = insereFinal(lista1, "Matheus", "1243", 'B', 8.1, 1.5, 0.5);
  lista1 = insereFinal(lista1, "Samir", "1243", 'B', 1.3, 9.0, 10.0);
  No* lista2 = copiaLista(lista1);
  imprimeLista(lista2);
}