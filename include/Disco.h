#ifndef H_DISCO
#define H_DISCO

#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE_TOTAL 1000000

typedef struct disco disco;

disco* inicializaDisco();
void liberaDisco(disco *disc);
void setCapacidade(disco* disc, int tamanhoArq);
int getCapacidade(disco *disc);
void incrementaCapacidade(disco *disc, int tamanhoArq);


#endif