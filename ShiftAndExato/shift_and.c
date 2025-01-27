#include "../Interface/shift_and.h"
#include "../Interface/in_out.h"

int shiftAnd(char **musica, char **trecho, int m, int t){
    int mascara[12][12]; // Primeiro índice é o deslocamento de tons, e o segundo índice é a nota deslocada
    int R[12]; // Array para os deslocamentos

    // Inicializa as mascaras com 0
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            mascara[i][j] = 0;
        }
    }

    // Define as máscaras para cada deslocamento de tons
    for(int i = 0; i < 12; i++){
        for (int j = 0; j < t; j++) {
            int index = indexNota(trecho[j]);
            if (index == -1) {
                return -1; // Retorna se a nota não é válida
            }
            int deslocado = (index + i) % 12;
            mascara[i][deslocado] |= (1 << (t - 1 - j));
        }
    }

    // Faz a pesquisa pela música considerando cada deslocamento de tons
    for(int i = 0; i < 12; i++){
        R[i] = 0; // Zera o R para o deslocamento inicial
        
        for(int j = 0; j < m; j++){
            int index = indexNota(musica[j]);
            if(index == -1){
                return -1; // Retorna se a nota não é válida
            }

            // Atualiza o R com a máscara do deslocamento
            R[i] = ((R[i] >> 1) | (1 << (t - 1))) & mascara[i][index];

            // Verifica se houve um casamento e retorna a posição inicial 
            if((R[i] & 1) != 0){
                return j - t + 1;
            }
        }
    }
    return -1;
}