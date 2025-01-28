#include "../Interface/forca_bruta.h"
#include "../Interface/in_out.h"

int forcaBruta(char **musica, char **trecho, int m, int t){
    if(t > m){
        printf("O trecho para pesquisa é maior que a música!\n");
        return -1;
    }

    // Pesquisa de casamento
    for(int i = 0; i <= m - t; i++){
        // Deslocamento de tons das primeiras notas do texto e do padrão é calculado
        int deslocamento = calculaDeslocamentoDeTons(musica[i], trecho[0]);
        if(deslocamento == -1){ // Se nota inválida avança a pesquisa no texto
            continue;
        }
        
        int j; 
        for(j = 1; j < t; j++){
            // Calcula deslocamento das duas próximas notas do texto e do padrão
            int deslocamentoAtual = calculaDeslocamentoDeTons(musica[i + j], trecho[j]);
            if(deslocamentoAtual != deslocamento){ // Se deslocamento de tons for diferente não há casamento
                break;  
            }
        }
        
        if(j == t){ // Se chegou no fim do padrão retorna o índice do início do casamento
            return i;
        }
    }
    return -1;
}