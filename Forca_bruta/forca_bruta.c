#include "../Interface/forca_bruta.h"

int forcaBruta(char **musica, char **trecho, int m, int t){
    for(int i = 0; i <= m - t; i++){
        int j;
        for(j = 0; j < t; j++){
            if(strcmp(musica[i + j], trecho[j]) != 0){
                break;
            }
        }
        
        if(j == t){
            return i;
        }
    }
    return -1;
}