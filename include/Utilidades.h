#ifndef H_UTILIDADES
#define H_UTILIDADES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tamArquivos tamArquivos;

tamArquivos *inicializaEstrutura();
void preencheEstrutura(tamArquivos *estrutura,  char *adress);
void liberaEstrutura(tamArquivos *estrutura);


#endif