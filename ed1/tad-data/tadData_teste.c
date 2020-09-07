//tadData_teste.c

#include<stdio.h>
#include<stdlib.h>
#include "tadData.h"

int main(){

    Data* data = criar_data(01,11,2004);
    imprimir_data(data);
    char* br = formatar_data_br(data);
    char* us = formatar_data_us(data);
    printf("Data br: %s", br);
    printf("Data us: %s", us);
    int dia = recuperar_dia(data);
    int mes = recuperar_mes(data);
    int ano = recuperar_ano(data);
    printf("Dia: %d, mês %d ano %d\n",dia,mes,ano);
    char* mes_abreviado = recuperar_mes_abreviado(data);
    printf("Mês: %s", mes_abreviado);
}