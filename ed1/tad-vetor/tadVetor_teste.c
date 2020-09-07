//tadVetor_teste.c

#include<stdio.h>
#include<stdlib.h>
#include "tadVetor.h"

int main(){

  Vetor* v = criar_vetor();
  insere_final(v, 1);
  insere_final(v, 2);
  insere_final(v, 3);
  insere_final(v, 4);
  insere_final(v, 5);
  insere_final(v, 2);
  imprimir_vetor(v);
  insere_pos(v, 3, 25);
  imprimir_vetor(v);
  substituir_elem(v,3,5);
  imprimir_vetor(v);
  remover_elem(v,3);
  imprimir_vetor(v);
  remover_val(v,2);
  imprimir_vetor(v);
  int qtd = qtd_elementos(v);
  printf("Qtd elementos %d \n", qtd);
  int elem = buscar_elemento(v, 4);
  printf("Elemento na posição 4: %d \n", elem);
  int pos = buscar_valor(v, 3);
  printf("Posição do valor 3: %d \n", pos);

}