#ifndef H_FILA_PRIORIDADE
#define H_FILA_PRIORIDADE

#include "Disco.h"
#include "vector.h"

typedef struct filaPrioridade filaPrioridade;

filaPrioridade *inicializaFP(vector *vet);
void promoveElemento(filaPrioridade *fp, int filho);
void liberaFilaPrioridade(filaPrioridade *fp);
void worstFit(filaPrioridade *fp, vector *vet);
void worstFitOrdenado(filaPrioridade *fp, vector *vet);
int getQtdDiscos(filaPrioridade *fp);

#endif