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

int calculaDeslocamentoDeTons(char *tom1, char *tom2){
    char *tons[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    char *equivalencia[] = {"B#", "Db", "-", "Eb", "Fb", "E#", "Gb", "-", "Ab", "-", "Bb", "-"};
    
    int index1 = -1, index2 = -1;
    for(int i = 0; i < 12; i++){
        if(strcmp(tom1, tons[i]) == 0 || (strcmp(equivalencia[i], "-") != 0 && strcmp(tom1, equivalencia[i]) == 0)){
            index1 = i;
        }
        if(strcmp(tom2, tons[i]) == 0 || (strcmp(equivalencia[i], "-") != 0 && strcmp(tom2, equivalencia[i]) == 0)){
            index2 = i;
        }
    }

    if(index1 == -1 || index2 == -1){
        printf("As notas não são válidas: (%s, %s)\n", tom1, tom2);
        return -1;
    }

    return (index2 - index1 + 12) % 12;
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