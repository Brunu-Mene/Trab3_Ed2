#include "../include/Disco.h"

struct disco{
    int capRestante;
};

disco* inicializaDisco(){
    disco *disc = malloc(1*sizeof(disco));
    disc->capRestante = CAPACIDADE_TOTAL;

    return disc;
}

void liberaDisco(disco *disc){
    free(disc);
}

void decrementaCapacidade(disco* disc, int tamanhoArq){
    disc->capRestante -= tamanhoArq;
}

void incrementaCapacidade(disco *disc, int tamanhoArq){
    disc->capRestante += tamanhoArq;
}

int getCapacidade(disco *disc){
    return disc->capRestante;
}