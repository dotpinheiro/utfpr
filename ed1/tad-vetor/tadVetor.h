//tadVetor.h

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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
Boolean substituir_elem(Vetor* v, int pos, TipoVetor val);
void remover(Vetor* v, int pos);
Boolean remover_elem(Vetor* v, int pos, TipoVetor* endereco);
Boolean remover_val(Vetor* v, TipoVetor val);
int qtd_elementos(Vetor* v);
TipoVetor buscar_elemento(Vetor* v, int pos);
int buscar_valor(Vetor* v, TipoVetor val);
void vet_imprimir(Vetor* v);
Boolean vet_toString(Vetor* v, char** enderecoString);
void vet_destruir(Vetor* v);
Vetor* vet_clone(Vetor* v);
void vet_ordenarBubble(Vetor* v);
void vet_ordenarSelection(Vetor* v);
void vet_ordenarInsertion(Vetor* v);
int vet_buscaBinaria(Vetor* v, TipoVetor elemento);
Vetor* vet_importar(char* nomeArquivo);
Boolean vet_exportar(Vetor* v, char* nomeArquivo);
Vetor* vet_criarAleatorio(int tam);
Vetor* vet_criarAscendente(int tam);
Vetor* vet_criarDescendente(int tam);
Vetor* vet_criarAscendenteParcial(int tam, int percentual);

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
    float percent_ocupado = (float) v->qtdOcupada / v->tamVetor;

    if(percent_ocupado <= 0.25){
        v->tamVetor /= 2;
        v->vetor = (TipoVetor*) realloc(v->vetor, v->tamVetor * sizeof(TipoVetor));
        return true;
    }else if(percent_ocupado == 1){
        v->tamVetor *= 2;
        v->vetor = (TipoVetor*) realloc(v->vetor, v->tamVetor * sizeof(TipoVetor) );
        return true;
    }

    return false;

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

Boolean insere_pos(Vetor* v, TipoVetor val, int pos){
    Boolean status = validar_vetor(v);
    
    if(pos >= v->tamVetor) return false;
    
    if(pos < 0 ) pos += v->tamVetor;
    
    expandir_vetor(v);

    for(int i = v->qtdOcupada; i >= pos; i--)
        v->vetor[i + 1] = v->vetor[i];
    
    v->vetor[pos] = val;
    v->qtdOcupada++;
    return status;
}

Boolean substituir_elem(Vetor* v, int pos, TipoVetor val){
    Boolean status = validar_vetor(v);

    if(pos >= v->tamVetor) return false;

    if(pos < 0 ) pos += v->tamVetor;

    v->vetor[pos] = val;
    return status;
}


void remover(Vetor* v, int pos){
    for(int i = pos; i < v->qtdOcupada; i++)
        v->vetor[i] = v->vetor[i + 1];
    
    v->qtdOcupada--;
}

Boolean remover_elem(Vetor* v, int pos, TipoVetor* endereco){
    Boolean status = validar_vetor(v);

    if(pos >= v->tamVetor) return false;

    if(pos < 0 ) pos += v->tamVetor;
    
    *endereco = v->vetor[pos];
    remover(v, pos);

    return status;
}

Boolean remover_val(Vetor* v, TipoVetor val){
    Boolean status = validar_vetor(v);

    for(int i = 0; i < v->qtdOcupada; i++){
        if(v->vetor[i] == val){
            remover(v, i);
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

int buscar_valor(Vetor* v, TipoVetor val){
    validar_vetor(v);
    for(int i = 0; i < v->qtdOcupada; i++)
        if(v->vetor[i] == val)
            return i;
    return -1;
}

void vet_imprimir(Vetor* v){
    printf("\n[");
    for(int i = 0; i < v->qtdOcupada; i++){
        printf("%d", v->vetor[i]);
        if(i < v->qtdOcupada - 1)
            printf(",");
    }
    printf("]\n");
}


Boolean vet_toString(Vetor* v, char** enderecoString){
    Boolean status = validar_vetor(v);

    char* vet_string = (char*) malloc(sizeof(char));
    strcat(vet_string,"\n[");
    for(int i = 0; i < v->qtdOcupada; i++){
        char* val;
        sprintf(val,"%d", v->vetor[i]);
        strcat(vet_string,val);
        if(i < v->qtdOcupada - 1)
            strcat(vet_string,",");
    }
    strcat(vet_string,"]\n");

    *enderecoString = vet_string;

    return status;
    
}

void vet_destruir(Vetor* v){
    free(v);
}

Vetor* vet_clone(Vetor* v){
    Vetor* clone = (Vetor*) malloc(sizeof(Vetor));
    memcpy(clone,v,sizeof(Vetor));
    return clone;
}

void vet_ordenarBubble(Vetor* v){
    int aux = 0;
    int indice = v->qtdOcupada - 1;
    for(int i = 0; i < indice; i++){
        for(int j = 0; j < indice - i; j++ ){
            if(v->vetor[j] > v->vetor[j + 1]){
                aux = v->vetor[j];
                v->vetor[j] = v->vetor[j + 1];
                v->vetor[j + 1] = aux;
            }
        }
    }
}

void vet_ordenarSelection(Vetor* v){
    int aux = 0;
    int menor = 0;
    int indice = v->qtdOcupada - 1;
    for(int i = 0; i < indice; i++){
        menor = i;
        for(int j = i + 1; j <= indice; j++)
            if(v->vetor[j] < v->vetor[menor]) 
                menor = j;
        
        if(v->vetor[i] != v->vetor[menor]){
            aux = v->vetor[i];
            v->vetor[i] = v->vetor[menor];
            v->vetor[menor] = aux;
        }
    }
}

void vet_ordenarInsertion(Vetor* v){
    for(int i = 1; i < v->qtdOcupada; i++){
        int key = v->vetor[i];
        int j = i - 1;
        while(j >= 0 && v->vetor[j] > key){
            v->vetor[j + 1] = v->vetor[j];
            j--;
        }
        v->vetor[j + 1] = key;

    }
} 

int vet_buscaBinaria(Vetor* v, TipoVetor elemento){
    int menor = 0;
    int maior = v->qtdOcupada - 1;
    while(menor <= maior){
        int meio = (maior + menor) / 2;
        if(elemento == v->vetor[meio])
            return meio;
        else if(elemento < v->vetor[meio])
            maior = meio - 1;
        else
            menor = meio + 1;
    }
    return -1;
}

Vetor* vet_importar(char* nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "r");
    Vetor* v = criar_vetor();
    if(arq == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s \n", nomeArquivo);
        return v;
    }
    char linha[512];
    while(fgets(linha, sizeof(linha), arq) != NULL)
        insere_final(v,atoi(linha));
    
    fclose(arq);
    return v;
}

Boolean vet_exportar(Vetor* v, char* nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "w");
        if(arq == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s \n", nomeArquivo);
        return false;
    }
    for(int i = 0; i < v->qtdOcupada; i++){
        fprintf(arq,"%d\n", v->vetor[i]);
    }
    fclose(arq);
    return true;
}

Vetor* vet_criarAleatorio(int tam){
    Vetor* v = criar_vetor();
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        insere_final(v, rand() % tam);
    }
    return v;
}

Vetor* vet_criarAscendente(int tam){
    Vetor* v = criar_vetor();
    for(int i = 0; i < tam; i++){
        insere_final(v, i + 1);
    }
    return v;
}

Vetor* vet_criarDescendente(int tam){
    Vetor* v = criar_vetor();
    int val = tam;
    for(int i = 0; i < tam; i++){
        insere_final(v, val);
        val--;
    }
    return v;
}

Vetor* vet_criarAscendenteParcial(int tam, int percentual){
    Vetor* v = criar_vetor();
    int tamAsc = (float) tam * ((float)percentual / 100);
    printf("tamAsc %d", tamAsc);
    srand(time(NULL));
    for(int i = 0; i < tam; i++){
        if(i < tamAsc)
            insere_final(v, i + 1);
        else
            insere_final(v, rand() % tam);
    }
    return v;
}