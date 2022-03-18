#include "../include/FilaPrioridade.h"
#include <time.h>

int main(int argv, char ** args){
    clock_t t_init,t_final;
    vector *vet = inicializaVector();
    vector *vetOrdenado = inicializaVector();
    preencheVector(vet, args[1]);
    preencheVector(vetOrdenado, args[1]);
    ordenaVetor(vetOrdenado);

    printf("Results:\n\nN: %d\n",getTam(vet));
    printf("Total size (GB): %.2f\n\nNumber of disks:\n",somaVetorEmEscala(vet));
    
    t_init = clock();

    filaPrioridade *fp = inicializaFP(vet);
    worstFit(fp,vet);
    printf(" - Worst Fit: %d\n",getQtdDiscos(fp));
   
    filaPrioridade *fp2 = inicializaFP(vet);
    bestFit(fp2,vet);
    printf(" - Best Fit: %d\n",getQtdDiscos(fp2));
  
    filaPrioridade *fp3 = inicializaFP(vetOrdenado);
    worstFit(fp3,vetOrdenado);
    printf(" - Worst-Fit Decreasing: %d\n",getQtdDiscos(fp3));

    filaPrioridade *fp4 = inicializaFP(vetOrdenado);
    bestFit(fp4,vetOrdenado);
    printf(" - Best-Fit Decreasing: %d\n\n",getQtdDiscos(fp4));

    t_final = clock();
    printf("Spend Time: %.3f (s)\n\n",(float)(t_final - t_init)/1000000);

    liberaVector(vet);
    liberaVector(vetOrdenado);
    liberaFilaPrioridade(fp);
    liberaFilaPrioridade(fp2);
    liberaFilaPrioridade(fp3);
    liberaFilaPrioridade(fp4);
    return 0;
}