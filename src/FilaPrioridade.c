#include "../include/FilaPrioridade.h"

struct filaPrioridade{
    int qtd;
    disco **vetDisco;
};

filaPrioridade *inicializaFP(vector* vet){
    filaPrioridade *fp = malloc(sizeof(filaPrioridade));
    fp->vetDisco = malloc(sizeof(disco*)*getTam(vet));
    fp->qtd = 0;
    
    for(int i=0; i<getTam(vet) ;i++){
        fp->vetDisco[i] = NULL;
    }
    return fp;
}

void insereFilaPrioridade(filaPrioridade* fp, disco *disc){
    fp->vetDisco[fp->qtd] = disc;
    promoveElemento(fp, fp->qtd);
    fp->qtd++;
}

void promoveElemento(filaPrioridade *fp, int filho){
    int pai;
    disco* discAux;
    pai = (filho - 1)/2;
    //ficar de olho
    while((filho > 0) && (getCapacidade(fp->vetDisco[pai]) <= getCapacidade(fp->vetDisco[filho]))){

        discAux = fp->vetDisco[filho];
        fp->vetDisco[filho] = fp->vetDisco[pai];
        fp->vetDisco[pai] = discAux;
        filho = pai;
        pai = (pai - 1)/2;
    }
}

void rebaixaElemento(filaPrioridade *fp, int pai){
    disco *discAux;
    int filho = 2 * pai + 1;
    while(filho < fp->qtd){
        if(filho < fp->qtd-1){
            if(getCapacidade(fp->vetDisco[filho]) < getCapacidade(fp->vetDisco[filho+1])){
                filho++;
            }
        } 
        if(getCapacidade(fp->vetDisco[pai]) >= getCapacidade(fp->vetDisco[filho]))
            break;

        discAux = fp->vetDisco[pai];
        fp->vetDisco[pai] = fp->vetDisco[filho];
        fp->vetDisco[filho] = discAux;
        pai = filho;
        filho = 2*pai + 1;
    }
}

void liberaFilaPrioridade(filaPrioridade *fp){
    for(int i = 0; i < fp->qtd; i++){
        liberaDisco(fp->vetDisco[i]);
    }
    free(fp->vetDisco);
    free(fp);
}

void worstFit(filaPrioridade *fp, vector *vet){
    disco *disc = inicializaDisco();
    setCapacidade(disc,getVetTamanhos(vet)[0]);
    insereFilaPrioridade(fp,disc);
    
    
    
    for(int i = 1; i < getTam(vet) ;i++){
        if(getCapacidade(fp->vetDisco[0]) < getVetTamanhos(vet)[i]){
            disco *newDisc = inicializaDisco();
            setCapacidade(newDisc, getVetTamanhos(vet)[i]);
            insereFilaPrioridade(fp,newDisc);

            
        }else{
            setCapacidade(fp->vetDisco[0],getVetTamanhos(vet)[i]);
            rebaixaElemento(fp, 0);

           
        }
    }
}

void bestFit(filaPrioridade *fp, vector *vet){
    disco *disc = inicializaDisco();
    setCapacidade(disc,CAPACIDADE_TOTAL - getVetTamanhos(vet)[0]);
    insereFilaPrioridade(fp,disc);
    printf("Pri : %d\n",getCapacidade(fp->vetDisco[0]));
    for(int i=1; i<getTam(vet) ;i++){
        if(CAPACIDADE_TOTAL - getCapacidade(fp->vetDisco[0]) < getVetTamanhos(vet)[i]){
            int index = buscaFila(fp,getVetTamanhos(vet)[i],0);
            printf("index : %d\n",index);
            if(index != -1){
                incrementaCapacidade(fp->vetDisco[index],getVetTamanhos(vet)[i]);
                promoveElemento(fp, index);  
                //printf("old : %d\n",getCapacidade(fp->vetDisco[index]));     
            }
            else{
                disco *newDisc = inicializaDisco();
                setCapacidade(newDisc, CAPACIDADE_TOTAL - getVetTamanhos(vet)[i]);
                insereFilaPrioridade(fp,newDisc);
                //printf("New : %d\n",getCapacidade(fp->vetDisco[0]));
            }
        }else{
            incrementaCapacidade(fp->vetDisco[0],getVetTamanhos(vet)[i]);
            //printf("old2 : %d\n",getCapacidade(fp->vetDisco[0]));
        }
    }
}


int getQtdDiscos(filaPrioridade *fp){
    return fp->qtd;
}

int buscaFila(filaPrioridade *fp, int tamanhoArq, int filho){
    int direita = 2*filho + 2, esquerda = 2*filho + 1;
    if(fp->vetDisco[filho] == NULL)
        return -1;
    if(CAPACIDADE_TOTAL - getCapacidade(fp->vetDisco[filho]) >= tamanhoArq)
        return filho;
    if(fp->vetDisco[direita] == NULL && fp->vetDisco[esquerda] == NULL){
        return -1;
    }else if(fp->vetDisco[direita] == NULL){
        return buscaFila(fp,tamanhoArq,esquerda);
    }else if(fp->vetDisco[esquerda] == NULL){
        return buscaFila(fp,tamanhoArq,direita);
    }
    if(getCapacidade(fp->vetDisco[direita]) >= getCapacidade(fp->vetDisco[esquerda])){
        int id = buscaFila(fp,tamanhoArq,direita);
        if(id == -1)
            id = buscaFila(fp,tamanhoArq,esquerda);
        return id;
    }
    else{
        int id = buscaFila(fp,tamanhoArq,esquerda);
        if(id == -1)
            id = buscaFila(fp,tamanhoArq,direita);
        return id;
    }
}