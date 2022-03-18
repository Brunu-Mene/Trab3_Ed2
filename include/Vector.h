#ifndef H_VECTOR
#define H_VECTOR

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vector vector;

/**
* @brief:Funcao para alocar uma estrutura Vector;
* @return: Ponteiro vector para um espaço na memoria heap;
*/
vector *inicializaVector();

/**
* @brief: Função para preencher uma estrutura vector com base em um arquivo de entrada;
* @param vec: Ponteiro para a estrutura a ser preenchida
* @param andress: Caminho para o arquivo de entrada a ser lido; 
*/
void preencheVector(vector *vec,  char *adress);

/**
* @brief: Função para liberar da memória uma estrutura vector;
* @param vec: Ponteiro para a estrutura a ser liberada;
*/
void liberaVector(vector *vec);

/**
* @brief: Função de acesso ao valor tam dentro da estrutura vector;
* @param vet: Ponteiro para a estrutura a ser acesada;
* @return: Um inteiro correspondente ao tamanho contido na variavel interna da estrutura;
*/
int getTam(vector *vet);

/**
* @brief: Função de acesso ao valor *vetTamanhos dentro da estrutura vector;
* @param vet: Ponteiro para a estrutura a ser acesada;
* @return: Um inteiro correspondente ao tamanho contido em *vetTamanhos;
*/
int *getVetTamanhos(vector *vet);

/**
* @brief:Funcao para realizar a comparação entre dois inteiros;
* @param a: Primeiro ponteiro a ser comparado;
* @param b: Sugundo ponteiro a ser comparado;
* @return: Inteiro resultando da comparação entre dois inteiros;
*/
int comparaVetor(const void *a, const void *b);

/**
* @brief: Função para realizar a ordenação do vector utilizando como algoritmo o qsort;
* @param vet: Ponteiro para a estrutura vector a ser ordenada;
*/
void ordenaVetor(vector *vet);

/**
* @brief:Funcao para realizar a soma dos componentes internos da estrutura;
* @param vec: Um ponteiro para um estrutura vector previamente preenchida;
* @return: Um double correspondente a soma dos componentes em escala de 1000000;
*/
double somaVetorEmEscala(vector *vec);


#endif