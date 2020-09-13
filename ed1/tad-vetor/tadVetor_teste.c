//tadVetor_teste.c

#include<stdio.h>
#include<stdlib.h>
#include "tadVetor.h"

Vetor* v;
char* vet_s;

void teste1(){
  v = criar_vetor();
  insere_final(v, 1);
  insere_final(v, 2);
  insere_final(v, 3);
  insere_final(v, 4);
  insere_final(v, 5);
  insere_final(v, 2);
  imprimir_vetor(v);
  insere_pos(v, 25, 3);
  imprimir_vetor(v);
  substituir_elem(v,3,5);
  imprimir_vetor(v);
  int valor;
  remover_elem(v,3, &valor);
  printf("Valor removido: %d\n", valor);
  imprimir_vetor(v);
  remover_val(v,2);
  imprimir_vetor(v);
  int qtd = qtd_elementos(v);
  printf("Qtd elementos %d \n", qtd);
  int elem = buscar_elemento(v, 4);
  printf("Elemento na posição 4: %d \n", elem);
  int pos = buscar_valor(v, 3);
  printf("Posição do valor 3: %d \n", pos);
  vet_imprimir(v);
  vet_toString(v,&vet_s);
}

void teste2(){
  Vetor* clone = vet_clone(v);
  int valor;
  remover_elem(v,3, &valor);
  printf("Qtd elementos original: %d \n", v->qtdOcupada);
  printf("Qtd elementos clone: %d \n", clone->qtdOcupada);
  vet_imprimir(v);
  vet_ordenarBubble(v);
  vet_imprimir(v);
  vet_ordenarSelection(v);
  vet_imprimir(v);
  vet_ordenarInsertion(v);
  vet_imprimir(v);
  int busca = vet_buscaBinaria(v, 3);
  printf("Encontrado posição: %d\n", busca);
}

void teste3(){
  Vetor* importado = vet_importar("arquivo_entrada.txt");
  printf("\nVetor importado: ");
  vet_imprimir(importado);
  vet_exportar(v,"arquivo_exportado.txt");
}

void teste4(){
  printf("Vetor aleatório:");
  Vetor* aleatorio = vet_criarAleatorio(15);
  vet_imprimir(aleatorio);
  printf("Vetor ascendente:");
  Vetor* ascendente = vet_criarAscendente(15);
  vet_imprimir(ascendente);
  printf("Vetor descendente:");
  Vetor* descendente = vet_criarDescendente(15);
  vet_imprimir(descendente);
  printf("Vetor ascendente parcial:");
  Vetor* parcial = vet_criarAscendenteParcial(100, 50);
  vet_imprimir(parcial);
}

int main(){

  teste1();
  teste2();
  teste3();
  teste4();
  vet_destruir(v);

}