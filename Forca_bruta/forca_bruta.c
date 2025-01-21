#include "../Interface/forca_bruta.h"
#include "../Interface/in_out.h"

int forcaBruta(char **musica, char **trecho, int m, int t){
    for(int i = 0; i <= m - t; i++){
        int deslocamento = calculaDeslocamentoDeTons(musica[i], trecho[0]);
        if(deslocamento == -1){
            continue;
        }
        
        int j;
        for(j = 1; j < t; j++){
            int deslocamentoAtual = calculaDeslocamentoDeTons(musica[i + j], trecho[j]);
            if(deslocamentoAtual != deslocamento){
                break;
            }
        }
        
        if(j == t){
            return i;
        }
    }
    return -1;
}