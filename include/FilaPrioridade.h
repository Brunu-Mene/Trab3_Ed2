#ifndef H_FILA_PRIORIDADE
#define H_FILA_PRIORIDADE

#include "Disco.h"
#include "vector.h"
#include <stdbool.h>

typedef struct filaPrioridade filaPrioridade;

filaPrioridade *inicializaFP(vector *vet);
void promoveElemento(filaPrioridade *fp, int filho);
void liberaFilaPrioridade(filaPrioridade *fp);
void worstFit(filaPrioridade *fp, vector *vet);
void bestFit(filaPrioridade *fp, vector *vet);
int buscaFila(filaPrioridade *fp, int tamanhoArq, int filho);
int getQtdDiscos(filaPrioridade *fp);

#endif