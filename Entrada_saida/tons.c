/* Módulo que trata os cálculos relacionados às notas musicais */

#include "../Interface/tons.h"

// Retorna a lista de notas e equivalências
char* (*listaNotas())[2]{
    static char *notas[][2] = {
        {"C", "B#"}, {"C#", "Db"}, {"D", " "}, {"D#", "Eb"},
        {"E", "Fb"}, {"F", "E#"}, {"F#", "Gb"}, {"G", " "},
        {"G#", "Ab"}, {"A", " "}, {"A#", "Bb"}, {"B", "Cb"}
    };
    return notas;
}

// Retorna o índice da nota presente na lista, considerando equivalências
int indexNota(char *nota){
    char *(*notas)[2] = listaNotas();

    for(int i = 0; i < 12; i++){
        if(strcmp(nota, notas[i][0]) == 0 || (notas[i][1] != NULL && strcmp(nota, notas[i][1]) == 0)){
            return i;
        }
    }
    return -1; // Retorna se nota é inválida
}

// Sobe meio tom nas notas do padrão
void subirMeioTom(char **trecho, int t){
    char *(*notas)[2] = listaNotas();

    for(int i = 0; i < t; i++){
        int index = indexNota(trecho[i]);
        if(index != -1){
            char *meioTom = strdup(notas[(index + 1) % 12][0]); // Aloca dinâmicamente uma nova nota
            if(meioTom == NULL){
                printf("Erro ao alocar nova nota!\n");
                exit(EXIT_FAILURE);
            }
            free(trecho[i]); // Libera a memória anteriormente alocada
            trecho[i] = meioTom;
        }
    }
}

// Calcula o deslocamento de tons entre duas notas 
int calculaDeslocamentoDeTons(char *tom1, char *tom2){
    int index1 = indexNota(tom1);
    int index2 = indexNota(tom2);

    if(index1 == -1 || index2 == -1){
        return -1; //Retorna caso as notas não existem ou não possuem equivalência
    }
    return (index2 - index1 + 12) % 12;
}