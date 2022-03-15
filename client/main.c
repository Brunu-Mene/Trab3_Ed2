#include "../include/FilaPrioridade.h"

int main(int argv, char ** args){
    vector *vet = inicializaVector();
    vector *vetOrdenado = inicializaVector();
    preencheVector(vet, args[1]);
    preencheVector(vetOrdenado, args[1]);
    ordenaVetor(vetOrdenado);

    filaPrioridade *fp = inicializaFP(vet);
    worstFit(fp,vet);
    printf("%d\n",getQtdDiscos(fp));
    //
    filaPrioridade *fp2 = inicializaFP(vetOrdenado);
    worstFit(fp2,vetOrdenado);
    printf("%d\n",getQtdDiscos(fp2));
    //
    filaPrioridade *fp3 = inicializaFP(vet);
    bestFit(fp3,vet);
    printf("%d\n",getQtdDiscos(fp3));
    //
    filaPrioridade *fp4 = inicializaFP(vetOrdenado);
    bestFit(fp4,vetOrdenado);
    printf("%d\n",getQtdDiscos(fp4));

    liberaVector(vet);
    liberaVector(vetOrdenado);
    liberaFilaPrioridade(fp);
    liberaFilaPrioridade(fp2);
    liberaFilaPrioridade(fp3);
    liberaFilaPrioridade(fp4);
    return 0;
}