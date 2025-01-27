#include "../Interface/BMH.h"
#include "../Interface/in_out.h"

int boyerMoore(char **musica, char **trecho, int m, int t){
    int d[12]; // Array do tamanho da quantidade de notas musicais(dicionário)
    int i, j, k;

    // Inicializa o array com o valor do tamanho do padrão
    for(j = 0; j < 12; j++){
        d[j] = t;
    }

    // Preenche o array considerando as notas do padrão e o índice delas
    for(j = 1; j < t; j++){
        int index = indexNota(trecho[j]);
        if(index != -1){
            d[index] = t - j; // O valor é o tamanho do padrão menos o ídice da nota
        }
    }

    // Início da pesquisa de casamento
    i = t;
    while(i <= m){
        // São atribuidos os índices da última nota do padrão a k(índice texto) e j(índice padrão)
        k = i - 1;
        j = t - 1;

        int deslocamento = calculaDeslocamentoDeTons(musica[k], trecho[j]); // Define o deslocamento de tons das notas a serem comparadas

        while(k > 0 && j > 0){
            int deslocamentoAtual = calculaDeslocamentoDeTons(musica[k - 1], trecho[j - 1]); // Deslocamento da próxima nota é calculado
            if(deslocamentoAtual != deslocamento){ // Se deslocamentos diferentes não há casamento
                break;
            }
            k--;
            j--; // índices decrementados pois a pesquisa é feita da direita para esquerda
        }

        // Se chegou ao final do padrão retorna o índice do início do casamento 
        if(j == 0){
            return k;
        }

        // Atualiza o índice i com base no deslocamento
        int index = indexNota(musica[i - 1]);
        if(index != -1){
            i = i + d[index];
        } else {
            i++;
        }
    }
    return -1;
}