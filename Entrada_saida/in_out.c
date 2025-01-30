/* Módulo que manipula os arquivos */

#include "../Interface/in_out.h"

// Abre os arquivos de entrada e saída para leitura e escrita
int lerArquivos(int argc, char *argv[], FILE **entrada, FILE **saida){
    if(argc != 3){
        printf("Argumentos insuficientes!\n");
        return 1;
    }
    
    *entrada = fopen("./Entrada_saida/Arquivos/entrada.txt", "r");
    if(*entrada == NULL){
        printf("Erro ao ler o arquivo de entrada!\n");
        return 1;
    }

    *saida = fopen("./Entrada_saida/Arquivos/saida.txt", "w");
    if(*saida == NULL){
        printf("Erro ao abrir o arquivo de saída!\n");
        if(*entrada){
            fclose(*entrada);
        }
        return 1;
    }
    return 0;
}

// Aloca e preenche lista com as notas musicais
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
        fscanf(entrada, "%s", lista[i]); // Preenche a lista com as notas
    }
    return lista;
}

// Libera a memória alocada para a lista de caracteres
void destroiLista(char **lista, int tamanho){
    if(lista != NULL){
        for(int i = 0; i < tamanho; i++){
            free(lista[i]);
        }
    }
    free(lista);
}

// Escreve no arquivo de saída o resultado dos algoritmos
void escreveCasamento(FILE *saida, int posicao){
    if(posicao != -1){
        fprintf(saida, "S %d\n", posicao);
    } else {
        fprintf(saida, "N\n");
    }
}