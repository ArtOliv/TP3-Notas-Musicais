#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerArquivos(int argc, char *argv[], FILE **entrada, FILE **saida);

char** criaListaCaracter(FILE *entrada, int tamanho);

void destroiLista(char **lista, int tamanho);

void escreveResultado(FILE *saida, int posicao);