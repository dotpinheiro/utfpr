//tadVetor.h

#include<stdio.h>
#include<stdlib.h>

/**************************************
* DADOS
**************************************/
typedef enum boolean{ false=0, true=1 } Boolean;
typedef int TipoVetor;

typedef struct{
    TipoVetor* vetor;
    int qtdOcupada;
	int tamVetor;
}Vetor;

/**************************************
* PROTÓTIPOS
**************************************/
Vetor* criar_vetor();
Boolean expandir_vetor();
Boolean validar_vetor();
void imprimir_vetor(Vetor* v);
Boolean insere_final(Vetor* v, TipoVetor val);
Boolean insere_pos(Vetor* v, int pos, TipoVetor val);
Boolean substituir_elem(Vetor* v, int pos, int val);
Boolean remover_elem(Vetor* v, int pos);
Boolean remover_val(Vetor* v, TipoVetor val);
int qtd_elementos(Vetor* v);
TipoVetor buscar_elemento(Vetor* v, int pos);
int buscar_valor(Vetor* v, int val);

/**************************************
* IMPLEMENTAÇÃO
**************************************/
Vetor* criar_vetor(){
    Vetor* v = (Vetor*) malloc(sizeof(Vetor));
    v->tamVetor = 3;
    v->qtdOcupada = 0;
    v->vetor = (TipoVetor*) calloc(v->tamVetor,sizeof(TipoVetor));
    return v;
}

Boolean expandir_vetor(Vetor* v){
    if(v->qtdOcupada != v->tamVetor) return false;
    v->vetor = (TipoVetor*) realloc(v->vetor, v->tamVetor * sizeof(TipoVetor) );
    return true;
}

Boolean validar_vetor(Vetor * v){
     return v != NULL;
}

void imprimir_vetor(Vetor* v){
    for(int i = 0; i < v->qtdOcupada; i++)
        printf("V[%d] = %d\n", i, v->vetor[i]);
    printf("\n");
}

Boolean insere_final(Vetor* v, TipoVetor val){
    Boolean status = validar_vetor(v);
    expandir_vetor(v);
    v->vetor[v->qtdOcupada++] = val;
    return status;
}

Boolean insere_pos(Vetor* v, int pos, TipoVetor val){
    Boolean status = validar_vetor(v);
    expandir_vetor(v);

    for(int i = v->qtdOcupada; i >= pos; i--)
        v->vetor[i + 1] = v->vetor[i];
    
    v->vetor[pos] = val;
    v->qtdOcupada++;
    return status;
}

Boolean substituir_elem(Vetor* v, int pos, int val){
    Boolean status = validar_vetor(v);
    v->vetor[pos] = val;
    return status;
}

Boolean remover_elem(Vetor* v, int pos){
    Boolean status = validar_vetor(v);
    
    for(int i = pos; i < v->qtdOcupada; i++)
        v->vetor[i] = v->vetor[i + 1];
    
    v->qtdOcupada--;

    return status;
}

Boolean remover_val(Vetor* v, TipoVetor val){
    Boolean status = validar_vetor(v);

    for(int i = 0; i < v->qtdOcupada; i++){
        if(v->vetor[i] == val){
            remover_elem(v, i);
            return status;
        }
        
    }

    return status;
}

int qtd_elementos(Vetor* v){
    return v->qtdOcupada;
}

TipoVetor buscar_elemento(Vetor* v, int pos){
    return v->vetor[pos];
}

int buscar_valor(Vetor* v, int val){
    validar_vetor(v);
    for(int i = 0; i < v->qtdOcupada; i++)
        if(v->vetor[i] == val)
            return i;
    return -1;
}
