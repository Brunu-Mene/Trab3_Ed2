#include "../include/FilaPrioridade.h"

int main(int argv, char ** args){
    vector *vet = inicializaVector();
    preencheVector(vet, args[1]);
    filaPrioridade *fp = inicializaFP(vet);
    worstFit(fp,vet);
    printf("%d\n",getQtdDiscos(fp));
    //
    filaPrioridade *fp2 = inicializaFP(vet);
    worstFitOrdenado(fp2,vet);
    printf("%d\n",getQtdDiscos(fp2));

    liberaVector(vet);
    liberaFilaPrioridade(fp);
    liberaFilaPrioridade(fp2);
    return 0;
}