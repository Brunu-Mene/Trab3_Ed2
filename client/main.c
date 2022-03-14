#include <stdio.h>
#include "Utilidades.h"

int main(int argv, char ** args){
    tamArquivos *estrutura = inicializaEstrutura();
    preencheEstrutura(estrutura, args[1]);



    liberaEstrutura(estrutura);
    return 0;
}