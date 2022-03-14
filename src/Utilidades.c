#include "../include/Utilidades.h"

struct tamArquivos{
    int *vetTamanhos;
    int tam;
};

tamArquivos *inicializaEstrutura(){
    return malloc(sizeof(tamArquivos));
}

void preencheEstrutura(tamArquivos *estrutura,  char *adress){
    FILE *arq = fopen(adress,"r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo de entrada!\n");
        exit(1);
    }

    fscanf(arq,"%d",&estrutura->tam);
    estrutura->vetTamanhos = malloc(sizeof(int)*estrutura->tam);

    int i = 0;
    while(fscanf(arq,"%d",&estrutura->vetTamanhos[i]) == 1)
        i++;
    

    fclose(arq);
}

void liberaEstrutura(tamArquivos *estrutura){
    free(estrutura->vetTamanhos);
    free(estrutura);
}