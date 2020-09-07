//tadData.h

#include<stdio.h>
#include<stdlib.h>

/**************************************
* DADO
**************************************/
typedef enum boolean{ false=0, true=1 } Boolean;

typedef struct{
	int dia;
    int mes;
    int ano;
}Data;

char* mesesAbreviados[] = { "jan", "fev", "mar", "abr", "mai", "jun", "jul", "ago", "set", "out", "nov", "dez" }; 

/**************************************
* PROTÓTIPOS
**************************************/

Data* criar_data(int dia, int mes, int ano);
void imprimir_data(Data* data);
Boolean validar_data(Data* data);
Data* alterar_data(Data* data, int dia, int mes, int ano);
char* formatar_data_br(Data* data);
char* formatar_data_us(Data* data);
int recuperar_dia(Data* data);
int recuperar_mes(Data* data);
int recuperar_ano(Data* data);
char* recuperar_mes_abreviado(Data* data);


/**************************************
* IMPLEMENTAÇÃO
**************************************/

Data* criar_data(int dia, int mes, int ano){
    Data* d = (Data*) malloc(sizeof(Data));
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    return d;
}

void imprimir_data(Data* data){
    printf("Data: \n");
    printf("%d/%d/%d\n",data->dia, data->mes, data->ano);
}

Boolean validar_data(Data* data){
    Boolean status = true;

    if(data == NULL ) status = false;

    if(data->dia >= 31 || data->dia <= 0){
        printf("Dia inválido!");
        status = false;
    }

    if(data->mes >= 12 || data->mes <= 0){
        printf("Mês inválido!");
        status = false;
    }

    if(data->ano <= 0 ){
        printf("Ano inválido!");
        status = false;
    }

    return status;
}

Data* alterar_data(Data* data, int dia, int mes, int ano){
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;
    return data;
}

char* formatar_data_br(Data* data){
    char* data_br = (char*) malloc(sizeof(char));
    sprintf(data_br, "%d/%d/%d\n",data->dia, data->mes, data->ano);
    printf("%s", data_br);
    return data_br;
}

char* formatar_data_us(Data* data){
    char* data_br = (char*) malloc(sizeof(char));
    sprintf(data_br, "%d/%d/%d\n",data->mes, data->dia, data->ano);
    return data_br;
}

int recuperar_dia(Data* data){
    return data->dia;
}

int recuperar_mes(Data* data){
    return data->mes;
}

int recuperar_ano(Data* data){
    return data->ano;
}

char* recuperar_mes_abreviado(Data* data){
    validar_data(data);
    char* mes = malloc(sizeof(char*));
    mes = mesesAbreviados[data->mes - 1];
    return mes;
}
