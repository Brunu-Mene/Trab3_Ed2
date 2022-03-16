#include "../include/FilaPrioridade.h"
#include <time.h>

int main(int argv, char ** args){
    clock_t t_init,t_final;
    vector *vet = inicializaVector();
    vector *vetOrdenado = inicializaVector();
    preencheVector(vet, args[1]);
    preencheVector(vetOrdenado, args[1]);
    ordenaVetor(vetOrdenado);
    
    filaPrioridade *fp = inicializaFP(vet);
    t_init = clock();
    worstFit(fp,vet);
    t_final = clock();
    printf("Worst Fit: %d\n",getQtdDiscos(fp));
    printf("Tempo gasto: %.3f (s)\n\n",(float)(t_final - t_init)/1000000);

    filaPrioridade *fp2 = inicializaFP(vet);
    t_init = clock();
    bestFit(fp2,vet);
    t_final = clock();
    printf("Best Fit: %d\n",getQtdDiscos(fp2));
    printf("Tempo gasto: %.3f (s)\n\n",(float)(t_final - t_init)/1000000);

    filaPrioridade *fp3 = inicializaFP(vetOrdenado);
    t_init = clock();
    worstFit(fp3,vetOrdenado);
    t_final = clock();
    printf("Worst-Fit Decreasing: %d\n",getQtdDiscos(fp3));
    printf("Tempo gasto: %.3f (s)\n\n",(float)(t_final - t_init)/1000000);

    filaPrioridade *fp4 = inicializaFP(vetOrdenado);
    t_init = clock();
    bestFit(fp4,vetOrdenado);
    t_final = clock();
    printf("Best-Fit Decreasing: %d\n",getQtdDiscos(fp4));
    printf("Tempo gasto: %.3f (s)\n\n",(float)(t_final - t_init)/1000000);

    liberaVector(vet);
    liberaVector(vetOrdenado);
    liberaFilaPrioridade(fp);
    liberaFilaPrioridade(fp2);
    liberaFilaPrioridade(fp3);
    liberaFilaPrioridade(fp4);
    return 0;
}