#include "../Interface/shift_and.h"
#include "../Interface/in_out.h"

int shiftAnd(char **musica, char **trecho, int m, int t){
    if(t > m){
        printf("O trecho para pesquisa é maior que a música!\n");
        return -1;
    }

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
        for(int j = 0; j < t; j++){
            int index = indexNota(trecho[j]);
            if(index == -1){
                return -1; // Retorna se a nota não é válida
            }
            int deslocado = (index + i) % 12;
            mascara[i][deslocado] |= (1 << (t - 1 - j));
        }
    }

    // Faz a pesquisa pela música considerando cada deslocamento de tons
    int posicao, RTemp;
    for(int i = 0; i < 12; i++){
        R[i] = 0; // Zera o R para o deslocamento inicial
        
        for(int j = 0; j < m; j++){
            RTemp = R[i]; // Guarda o valor anterior de R
            int index =  indexNota(musica[j]);
            if(index == -1){
                return -1; // Retorna se a nota não é válida
            }

            // Atualiza o R com a máscara do deslocamento
            R[i] = ((R[i] >> 1) | (1 << (t - 1))) & mascara[i][index];

            if((R[i] ^ (1 << (t - 1))) == 0){ // Primeira vez que o R encontra um casamento entre caracteres salva a posição
                posicao = j;
            }

            if((R[i] ^ RTemp) == 0){ // Caso o R esteja igual a iteração anterior porque não houve casamento, imcrementa a posição 
                posicao++;
            }

            // Verifica se houve um casamento e retorna a posição inicial 
            if((R[i] & 1) != 0){
                return posicao;
            }
        }
    }
    return -1;
}