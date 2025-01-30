/* Módulo que trata os cálculos relacionados às notas musicais */

#include "../Interface/tons.h"

// Retorna o índice da nota presente na lista, considerando equivalências
int indexNota(char *nota){
    char *notas[][2] = {
        {"C", "B#"}, {"C#", "Db"}, {"D", NULL}, {"D#", "Eb"},
        {"E", "Fb"}, {"F", "E#"}, {"F#", "Gb"}, {"G", NULL},
        {"G#", "Ab"}, {"A", NULL}, {"A#", "Bb"}, {"B", "Cb"}
    };

    for(int i = 0; i < 12; i++){
        if(strcmp(nota, notas[i][0]) == 0 || (notas[i][1] != NULL && strcmp(nota, notas[i][1]) == 0)){
            return i;
        }
    }
    return -1; // Retorna se nota é inválida
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