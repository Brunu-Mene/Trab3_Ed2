#ifndef H_DISCO
#define H_DISCO

#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE_TOTAL 1000000

typedef struct disco disco;

disco* inicializaDisco();
void liberaDisco(disco *disc);
int getCapacidade(disco *disc);
void decrementaCapacidade(disco* disc, int tamanhoArq);
void incrementaCapacidade(disco *disc, int tamanhoArq);


#endif