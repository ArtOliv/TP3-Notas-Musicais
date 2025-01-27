#include "../Interface/in_out.h"
#include "../Interface/forca_bruta.h"
#include "../Interface/KMP.h"
#include "../Interface/BMH.h"
#include "../Interface/shift_and.h"

int main(int argc, char *argv[]){
    FILE *entrada = NULL;
    FILE *saida = NULL;
    int m, t;

    lerArquivos(argc, argv, &entrada, &saida);

    int algoritmo = atoi(argv[2]);
    while(fscanf(entrada, "%d %d", &m, &t), m != 0 || t != 0){
        char **musica = criaListaCaracter(entrada, m);
        char **trecho = criaListaCaracter(entrada, t);

        printf("musica: ");
        for(int i = 0; i < m; i++){
            printf("%s ", musica[i]);
        }
        printf("\n");
        
        printf("trecho: ");
        for(int j = 0; j < t; j++){
            printf("%s ", trecho[j]);
        }
        printf("\n");

        int posicao = -1;
        switch(algoritmo){
            case 1:
                printf("Resolvendo com força Bruta!\n");
                posicao = forcaBruta(musica, trecho, m, t);
                break;
            case 2:
                printf("Resolvendo com KMP!\n");
                posicao = KMP(musica, trecho, m, t);
                break;
            case 3:
                printf("Resolvendo com BMH!\n");
                posicao = boyerMoore(musica, trecho, m, t);
                break;
            case 4:
                printf("Resolvendo com Shift-And!\n");
                posicao = shiftAnd(musica, trecho, m, t);
                break;
        }

        printf("Posição: %d\n", posicao);

        escreveCasamento(saida, posicao);

        destroiLista(musica, m);
        destroiLista(trecho, t);
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}