#ifndef IN_OUT_H
#define IN_OUT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lerArquivos(int argc, char *argv[], FILE **entrada, FILE **saida);

char** criaListaCaracter(FILE *entrada, int tamanho);

void destroiLista(char **lista, int tamanho);

int calculaDeslocamentoDeTons(char *tom1, char *tom2);

void escreveResultado(FILE *saida, int posicao);

#endif