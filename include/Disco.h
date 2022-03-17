#ifndef H_DISCO
#define H_DISCO

#include <stdio.h>
#include <stdlib.h>

#define CAPACIDADE_TOTAL 1000000

typedef struct disco disco;

/**
* @brief:Funcao para inicializar e preencher uma estrutura do tipo disco;
* @return: Ponteiro do tipo disco com o endereço rezervado;
*/
disco* inicializaDisco();

/**
* @brief:Funcao para realizar a liberação da memoria de uma estrutura disco previamente alocada;
* @param disc: Ponteiro do tipos disco previamente alocado para ser liberado;
*/
void liberaDisco(disco *disc);

/**
* @brief:Funcao de acesso ao valor capacidade contido dentro da estrutura disco;
* @param disc: Ponteiro para estrutura a qual terá seu valor acessado;
* @return: Inteiro correspondente ao valor capacidade armazenado dentro da estrutura disco;
*/
int getCapacidade(disco *disc);

/**
* @brief:Função para realizar a decrementação da capacidade de um disco;
* @param disc: Ponteiro para uma estrutura disco a qual será decrementado a sua capacidade;
* @param tamanhoArq: Tamanho do arquivo a ser decrementado da capacidade do disco;
*/
void decrementaCapacidade(disco* disc, int tamanhoArq);

/**
* @brief: Funcção para realizar a incrementação de um disco com base em um valor passado;
* @param disc: Ponteiro para o disco a ter sua capacidade incrementada; 
* @param tamanhoArq: Inteiro corresponde ao valor a ser incrementando dentro do disco ja existente;
*/
void incrementaCapacidade(disco *disc, int tamanhoArq);


#endif