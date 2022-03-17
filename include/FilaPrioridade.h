#ifndef H_FILA_PRIORIDADE
#define H_FILA_PRIORIDADE

#include "Disco.h"
#include "vector.h"
#include <stdbool.h>

typedef struct filaPrioridade filaPrioridade;

/**
* @brief:Funcao para alocar uma estrutura do tipo filaPrioridade;
* @param vet: Ponteiro para um estrutura do tipo vector utilizada para saber o tamanho da fila que será alocada;
* @return: A estrutura do tipo filaPrioridade alocada;
*/
filaPrioridade *inicializaFP(vector *vet);

/**
* @brief:Funcao para realizar a promoção de um elemento em uma fila de prioridade;
* @param fp: Fila de prioridade a qual o elemento será incrementando;
* @param filho: Posição do elemento a ser incrementando dentro da fila de prioridade;
*/
void promoveElemento(filaPrioridade *fp, int filho);

/**
* @brief:Funcao para realizar a libeação de uma fila previamente alocada;
* @param fp: Ponteiro para a fila que será liberada
*/
void liberaFilaPrioridade(filaPrioridade *fp);

/**
* @brief:Funcao para realizar o armazenamento dos arquivos baseada na heuristica worst-fit;
* @param fp: Ponteiro para a fila de prioridade que contém os discos a serem preenchidos;
* @param vet: Ponteiro para a estrutura de vetores onde estão os "arquivos" a serem armazenados nos discos
*/
void worstFit(filaPrioridade *fp, vector *vet);

/**
* @brief:Funcao para preencher discos com base nos inteiros dados de entrada, com a abordagem best-fit; 
* @param fp: Ponteiro para a fila de prioridade a qual os discos serão inseridos; 
* @param vet: Ponteiro para uma estrutura vector a qual terá os tamanho de entrada armazenados;
*/
void bestFit(filaPrioridade *fp, vector *vet);

/**
* @brief:Função recursiva para realizar a busca do disco ótimo para ser armazenado o arquivo na função best-fit;
* @param fp: Ponteiro para a fila de prioridade que contém os discos a serem preenchidos;
* @param tamanhoArq: inteiro que representa o tamanho do arquivo a ser armazenado;
* @param filho: indice passado para a função para que ela possa caminhar na filha de prioridade;
* @return: inteiro que corresponde a posição do disco ótimo na fila de prioridade;
*/
int buscaFila(filaPrioridade *fp, int tamanhoArq, int filho);

/**
* @brief:Funcao de acesso a variável "qtd" dentro da estrutura da fila de prioridade;
* @param fp: Ponteiro para uma fila de prioridade a qual terá sua variavel acessada;
* @return: Inteiro correspondente a quantidade de discos presentes dentro de uma fila de prioridade de discos;
*/
int getQtdDiscos(filaPrioridade *fp);

#endif