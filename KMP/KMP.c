#include "../Interface/KMP.h"
#include "../Interface/tons.h"

int KMP(char **musica, char **trecho, int m, int t){
    if(t > m){
        printf("O trecho para pesquisa é maior que a música!\n");
        return -1;
    }

    int aux_vetor[t]; // Array auxiliar do tamanho do padrão
    int index = 0, i = 0, j = 1;

    // Inicializa todas as posições do array com 0
    for(int i = 0; i < t; i++){
        aux_vetor[i] = 0;
    }

    // Preenche o array auxiliar considerando os deslocamentos de tons
    while(j < t){
        int deslocamento = calculaDeslocamentoDeTons(trecho[index], trecho[j]);
        if(deslocamento == calculaDeslocamentoDeTons(trecho[0], trecho[j - index])){
            index++;
            aux_vetor[j] = index; // Se o deslocamento é igual o array é preenchido
            j++;
        } else {
            if(index > 0){
                index = aux_vetor[index - 1]; // Se o deslocamento não é igual index é atualizado
            } else if(index == 0){
                j++;
            }
        }
    }

    // Pesquisa para o casamento
    j = 0;
    int deslocamentoAtual;
    while(i < m){
        int deslocamento = calculaDeslocamentoDeTons(trecho[j],  musica[i]);
        if(j == 0){ // Caso seja o início do casamento o deslocamento de tons é definido 
            deslocamentoAtual = deslocamento;
        }

        // Se para as notas seguintes o deslocamneto é igual os indices são incrementados
        if(deslocamento == deslocamentoAtual){
            i++;
            j++;
        } else { // Caso contrário a pesquisa é atualizada com base no array auxiliar
            if(j > 0){
                j = aux_vetor[j - 1];
                deslocamentoAtual = calculaDeslocamentoDeTons(trecho[0], musica[i - j]); // Deslocamento é atualizado
            } else {
                i++;
            }
        }

        if(j == t){ // Há casamento caso j chegue ao fim do padrão
            return i - j;
        }
    }

    return -1;
}