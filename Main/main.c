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

        int posicao = -1;
        switch(algoritmo){
            case 1:
                posicao = forcaBruta(musica, trecho, m, t);
                break;
            case 2:
                posicao = KMP(musica, trecho, m, t);
                break;
            case 3:
                posicao = boyerMoore(musica, trecho, m, t);
                break;
            case 4:
                posicao = shiftAnd(musica, trecho, m, t);
                break;
        }

        escreveCasamento(saida, posicao);

        destroiLista(musica, m);
        destroiLista(trecho, t);
    }

    fclose(entrada);
    fclose(saida);
    return 0;
}