#include "../Interface/in_out.h"

int lerArquivos(int argc, char *argv[], FILE **entrada, FILE **saida){
    if(argc != 3){
        printf("Foram passados argumentos insuficientes\n");
        return 1;
    }
    
    *entrada = fopen("./Entrada_saida/Arquivos/tp3.in", "r");
    if(*entrada == NULL){
        printf("Erro ao ler o arquivo de entrada!\n");
        return 1;
    }

    *saida = fopen("./Entrada_saida/Arquivos/tp3.out", "w");
    if(*saida == NULL){
        printf("Erro ao criar o arquivo de saída!\n");
        if(*entrada){
            fclose(*entrada);
        }
        return 1;
    }
    return 0;
}

char** criaListaCaracter(FILE *entrada, int tamanho){
    char **lista = (char**) malloc (tamanho * sizeof(char*));
    if(lista == NULL){
        printf("Erro ao alocar a lista de caracteres!\n");
        return NULL;
    }

    for(int i = 0; i < tamanho; i++){
        lista[i] = (char*) malloc (3 * sizeof(char));
        if(lista[i] == NULL){
            printf("Erro ao alocar a posição da lista de caracteres!\n");
            destroiLista(lista, i);
            return NULL;
        }
        fscanf(entrada, "%s", lista[i]);
    }
    return lista;
}

void destroiLista(char **lista, int tamanho){
    if(lista != NULL){
        for(int i = 0; i < tamanho; i++){
            free(lista[i]);
        }
    }
    free(lista);
}

void escreveResultado(FILE *saida, int posicao){
    if(posicao != -1){
        printf("Escrevendo no arquivo: S %d\n", posicao);
        fprintf(saida, "S %d\n", posicao);
    } else {
        printf("Escrevendo no arquivo: N\n");
        fprintf(saida, "N\n");
    }
}