#ifndef H_VECTOR
#define H_VECTOR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vector vector;

vector *inicializaVector();
void preencheVector(vector *vec,  char *adress);
void liberaVector(vector *vec);
int getTam(vector *vet);
int *getVetTamanhos(vector *vet);
int comparaVetor(const void *a, const void *b);
void ordenaVetor(vector *vet);


#endif