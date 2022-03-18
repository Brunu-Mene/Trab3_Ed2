#include "../include/Vector.h"

struct vector{
    int *vetTamanhos;
    int tam;
};

vector *inicializaVector(){
    return malloc(sizeof(vector));
}

void preencheVector(vector *vec,  char *adress){
    FILE *arq = fopen(adress,"r");
    if(arq == NULL){
        printf("Erro na abertura do arquivo de entrada!\n");
        exit(1);
    }

    fscanf(arq,"%d",&vec->tam);
    vec->vetTamanhos = malloc(sizeof(int)*vec->tam);

    int i = 0;
    while(fscanf(arq,"%d",&vec->vetTamanhos[i]) == 1)
        i++;
    

    fclose(arq);
}

int getTam(vector *vet){
    return vet->tam;
}

int *getVetTamanhos(vector *vet){
    return vet->vetTamanhos;
}

int comparaVetor(const void *a, const void *b){
    int *v1 = (int *) a;
    int *v2 = (int *) b;
    return (*v2) - (*v1);
}

void ordenaVetor(vector *vet){
    qsort(getVetTamanhos(vet),getTam(vet),sizeof(int), comparaVetor);
}

void liberaVector(vector *vec){
    free(vec->vetTamanhos);
    free(vec);
}

double somaVetorEmEscala(vector *vec){
    double soma = 0.0;
    for(int i=0; i<vec->tam ;i++){
        soma += vec->vetTamanhos[i];
    }
    return soma/1000000;
}